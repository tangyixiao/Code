const assert = require('node:assert/strict');
const fs = require('node:fs');
const http = require('node:http');
const path = require('node:path');

const modules = process.env.CODEX_NODE_MODULES;
const { chromium } = require(modules ? path.join(modules, 'playwright') : 'playwright');

async function saveScreenshot(page, target) {
  if (!target) return;
  fs.mkdirSync(path.dirname(target), { recursive: true });
  await page.screenshot({ path: target, fullPage: true });
}

async function mockRawSources(page, sha) {
  await page.route('https://api.github.com/repos/tangyixiao/Code/actions/workflows/pages.yml/runs**', (route) => route.fulfill({
    status: 200, contentType: 'application/json; charset=utf-8',
    body: JSON.stringify({ workflow_runs: [{ id: 1, head_sha: sha, created_at: '2026-09-29T02:00:00Z', status: 'completed', conclusion: 'success', html_url: 'https://github.com/tangyixiao/Code/actions/runs/1' }] }),
  }));
  await page.route('https://raw.githubusercontent.com/**', (route) => {
    const url = decodeURIComponent(route.request().url());
    const body = url.endsWith('P9709 [KMOI R1] 军事行动.md')
      ? `# 军事行动\n\n$ x_1 + x_2 = 10 $\n\n$ y = ax^2 + bx + c $\n\n$ \\sum_{i=1}^{n} i $\n\n$ \\frac{a}{b} $\n\n$ \\alpha + \\beta = \\gamma $\n\n$ \\int_0^1 x^2 dx $\n\n:::info[信息]\n普通提示。\n:::\n\n:::success[展开提示]{open}\n默认展开。\n:::\n\n:::warning[嵌套提示]\n::::error[错误]\n嵌套错误。\n::::\n:::\n\n:::align{center}\n居中内容。\n:::\n\n:::epigraph[——otto]\n引文内容。\n:::\n\n::cute-table{three}\n| 测试点 | n | m |\n| --- | --- | --- |\n| 1 | 100 | 100 |\n| ^ | 200 | 200 |\n\n::cute-table{tuack=3}\n| a | b | c |\n| --- | --- | --- |\n| x | > | z |\n| y | q | < |\n\n~~~cpp lines=2-3,5\nint main() {\n  int x = 1;\n  x += 1;\n  return x;\n}\n~~~\n`
      : url.endsWith('.tsx')
        ? 'export const app = () => 1\n'
        : url.endsWith('P1241 括号序列.md')
        ? '# 括号序列\n\n配对题解内容保留。\n'
        : url.endsWith('P1241 括号序列.cpp')
          ? '#include <bits/stdc++.h>\n// 配对括号\nusing namespace std;\nint main() {\n    int answer = 42;\n    cout << "done" << answer << "\\n";\n    return 0;\n}\n'
        : 'int main() { return 0; }\n';
    return route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body });
  });
}

function serveBuiltSite() {
  const root = path.resolve(process.env.SITE_ROOT || path.join(__dirname, '..', '_site'));
  assert.ok(fs.existsSync(path.join(root, 'index.html')), `built site is missing at ${root}`);
  const server = http.createServer((request, response) => {
    const pathname = decodeURIComponent(new URL(request.url, 'http://127.0.0.1').pathname);
    if (!pathname.startsWith('/Code/')) {
      response.statusCode = 404;
      response.end('not found');
      return;
    }
    const relative = pathname.slice('/Code/'.length) || 'index.html';
    const target = path.resolve(root, relative || 'index.html');
    if (target !== root && !target.startsWith(`${root}${path.sep}`)) {
      response.statusCode = 400;
      response.end('bad path');
      return;
    }
    if (!fs.existsSync(target) || !fs.statSync(target).isFile()) {
      response.statusCode = 404;
      response.end('not found');
      return;
    }
    if (target.endsWith('.html')) response.setHeader('content-type', 'text/html; charset=utf-8');
    if (target.endsWith('.json')) response.setHeader('content-type', 'application/json; charset=utf-8');
    if (target.endsWith('.js')) response.setHeader('content-type', 'text/javascript; charset=utf-8');
    if (target.endsWith('.css')) response.setHeader('content-type', 'text/css; charset=utf-8');
    response.end(fs.readFileSync(target));
  });
  return new Promise((resolve) => server.listen(Number(process.env.SITE_PORT || 18767), '127.0.0.1', () => resolve(server)));
}

async function main() {
  let siteUrl = process.env.SITE_URL;
  const server = siteUrl ? null : await serveBuiltSite();
  siteUrl ??= `http://127.0.0.1:${server.address().port}/Code/`;
  assert.equal(new URL(siteUrl).pathname, '/Code/', 'SITE_URL must be mounted at /Code/');
  const browser = await chromium.launch({ headless: true, executablePath: process.env.CHROME_PATH, args: ['--enable-webgl', '--use-angle=swiftshader'] });
  const pageErrors = [];

  try {
    const manifest = await (await fetch(new URL('files.json', siteUrl))).json();
    assert.equal(manifest.schemaVersion, 2);
    assert.ok(manifest.count > 2000, `expected a full archive, received ${manifest.count}`);
    assert.ok(manifest.files.every((file) => file.updatedAt && file.lastCommit));
    assert.ok(manifest.files.every((file, index) => index === 0 || Date.parse(manifest.files[index - 1].updatedAt) >= Date.parse(file.updatedAt)));
    assert.ok(manifest.files.some((file) => file.path.includes('/') && file.type === 'py'));
    const rootFiles = manifest.files.filter((file) => !file.path.includes('/'));
    const historyData = await (await fetch(new URL('history.json', siteUrl))).json();
    assert.equal(historyData.schemaVersion, 1);
    assert.ok(historyData.rows.some((row) => row.sha === manifest.commit), 'the build commit must appear in the graph');
    assert.ok(historyData.branches.some((branch) => branch.name === 'origin/main'));

    const desktop = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    desktop.setDefaultTimeout(15000);
    desktop.on('pageerror', (error) => pageErrors.push(error.message));
    desktop.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await mockRawSources(desktop, manifest.commit);
    await desktop.goto(siteUrl, { waitUntil: 'domcontentloaded' });
    await desktop.getByRole('heading', { name: /代码与题解/ }).waitFor();
    await desktop.getByRole('button', { name: 'Git 历程' }).click();
    await desktop.getByRole('heading', { name: 'Git 历程' }).waitFor();
    assert.ok(await desktop.locator('.commit-row').count() > 100);
    await desktop.getByText('部署成功').first().waitFor();
    assert.equal(await desktop.locator('.commit-ref-list .push-ref').count(), 1);
    await desktop.getByRole('button', { name: /origin\/main/ }).click();
    assert.match(await desktop.locator('.history-detail').textContent(), new RegExp(historyData.remoteMain.slice(0, 7)));
    await saveScreenshot(desktop, process.env.HISTORY_SCREENSHOT);
    const otherBranch = historyData.branches.find((branch) => branch.name === 'origin/School');
    if (otherBranch) {
      await desktop.getByRole('button', { name: /origin\/School/ }).click();
      assert.match(await desktop.locator('.history-detail').textContent(), new RegExp(otherBranch.sha.slice(0, 7)));
      assert.equal(await desktop.locator('.commit-row.selected').isVisible(), true);
      await saveScreenshot(desktop, process.env.HISTORY_BRANCH_SCREENSHOT);
    }
    await desktop.getByRole('button', { name: '切换为浅色模式' }).click();
    assert.equal(await desktop.locator('.app-shell').getAttribute('data-theme'), 'light');
    await saveScreenshot(desktop, process.env.HISTORY_LIGHT_SCREENSHOT);
    await desktop.getByRole('button', { name: '切换为深色模式' }).click();
    await desktop.getByRole('button', { name: '算法档案' }).click();
    assert.ok(await desktop.locator('.landing-copy').evaluate((element) => parseFloat(getComputedStyle(element).animationDuration)) > .1);
    assert.equal(await desktop.locator('.reader').count(), 0, 'the root URL should open on the archive landing page');
    await desktop.getByRole('button', { name: /浏览文件/ }).click();
    await desktop.getByText(`显示 ${rootFiles.length} / ${manifest.count} 个文件`).waitFor();
    assert.equal(await desktop.locator('.app-shell').getAttribute('data-theme'), 'dark');
    assert.equal(await desktop.locator('.file-row').count(), rootFiles.length);
    assert.equal(await desktop.getByLabel('文件排序').inputValue(), 'recent');
    assert.match(await desktop.locator('.file-row').first().textContent(), new RegExp(rootFiles[0].name.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')));
    assert.ok(await desktop.locator('.folder-row').count() >= 20);
    await saveScreenshot(desktop, process.env.FOLDER_SCREENSHOT);
    await desktop.setViewportSize({ width: 800, height: 750 });
    assert.ok(await desktop.locator('.sidebar').evaluate((element) => element.getBoundingClientRect().width) <= 310);
    await saveScreenshot(desktop, process.env.FOLDER_NARROW_SCREENSHOT);
    await desktop.setViewportSize({ width: 1440, height: 900 });
    await desktop.locator('.folder-row[title="src"]').click();
    assert.match(desktop.url(), /#dir=src$/);
    await desktop.getByLabel('其他语言与文件类型').selectOption('tsx');
    await desktop.getByRole('button', { name: 'TSX src/App.tsx' }).click();
    await desktop.locator('.code .hljs-keyword').first().waitFor();
    await desktop.getByRole('button', { name: '仓库' }).click();
    await desktop.getByRole('button', { name: '全部', exact: true }).click();

    await desktop.getByPlaceholder('搜索文件名或路径').fill('260509练习赛①#A. 三投');
    await desktop.getByRole('button', { name: 'C++ 260509练习赛①#A. 三投.cpp', exact: true }).click();
    await desktop.locator('#viewer code').waitFor();
    assert.match(desktop.url(), /%23A/);

    await desktop.getByPlaceholder('搜索文件名或路径').fill('P9709 [KMOI R1] 军事行动.md');
    await desktop.getByRole('button', { name: /Markdown P9709 \[KMOI R1\] 军事行动\.md/ }).click();
    await desktop.locator('#viewer .markdown-body').waitFor();
    await desktop.locator('#viewer .katex').first().waitFor();
    assert.ok(await desktop.locator('#viewer .katex').count() > 5);
    assert.equal(await desktop.locator('.markdown-callout').count(), 4);
    assert.equal(await desktop.locator('.markdown-callout-success[open]').count(), 1);
    assert.equal(await desktop.locator('.markdown-callout-warning .markdown-callout-error').count(), 1);
    assert.equal(await desktop.locator('.markdown-align[data-align="center"]').count(), 1);
    assert.equal(await desktop.locator('.markdown-epigraph[data-author="——otto"]').count(), 1);
    assert.equal(await desktop.locator('table.cute-table-three').count(), 1);
    assert.equal(await desktop.locator('table.cute-table-three td[rowspan="2"]').count(), 1);
    assert.equal(await desktop.locator('table.cute-table-tuack[data-tuack="3"]').count(), 1);
    assert.equal(await desktop.locator('table.cute-table-tuack td[colspan="2"]').count(), 2);
    assert.equal(await desktop.locator('.markdown-code-block').count(), 1);
    assert.equal(await desktop.locator('.markdown-code-block .line-number').count(), 5);
    assert.equal(await desktop.locator('.markdown-code-block .code-line[data-highlighted="true"]').count(), 3);
    await saveScreenshot(desktop, process.env.MATH_SCREENSHOT);

    await desktop.getByPlaceholder('搜索文件名或路径').fill('P1241 括号序列');
    await desktop.getByRole('button', { name: /C\+\+ P1241 括号序列\.cpp/ }).click();
    await desktop.locator('.code-gutter').waitFor();
    assert.ok(await desktop.locator('.code .hljs-comment').count() > 0);
    assert.ok(await desktop.locator('.code .hljs-string').count() > 0);
    await desktop.getByRole('button', { name: '查看题解' }).click();
    await desktop.locator('#meta-name').getByText('P1241 括号序列.md', { exact: true }).waitFor();
    await desktop.locator('#viewer .markdown-body, #viewer .markdown-fallback').waitFor();
    await saveScreenshot(desktop, process.env.DESKTOP_SCREENSHOT);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(15000);
    mobile.on('pageerror', (error) => pageErrors.push(error.message));
    mobile.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await mockRawSources(mobile, manifest.commit);
    await mobile.goto(new URL('./', siteUrl).href, { waitUntil: 'domcontentloaded' });
    await mobile.getByRole('heading', { name: /代码与题解/ }).waitFor();
    await mobile.getByRole('button', { name: 'Git 历程' }).click();
    await mobile.getByRole('heading', { name: 'Git 历程' }).waitFor();
    assert.equal(await mobile.evaluate(() => document.documentElement.scrollWidth <= innerWidth), true);
    assert.ok(await mobile.locator('.commit-row').count() > 100);
    await mobile.locator('.history-detail').scrollIntoViewIfNeeded();
    assert.equal(await mobile.locator('.history-detail').isVisible(), true);
    await saveScreenshot(mobile, process.env.MOBILE_HISTORY_SCREENSHOT);
    await mobile.getByRole('button', { name: '算法档案' }).click();
    await saveScreenshot(mobile, process.env.MOBILE_LANDING_SCREENSHOT);
    await mobile.getByRole('button', { name: /浏览文件/ }).click();
    await mobile.getByText(`显示 ${rootFiles.length} / ${manifest.count} 个文件`).waitFor();
    assert.equal(await mobile.evaluate(() => document.documentElement.scrollWidth <= innerWidth), true);
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    await mobile.getByPlaceholder('搜索文件名或路径').fill('P1241 括号序列');
    await mobile.getByRole('button', { name: /C\+\+ P1241 括号序列\.cpp/ }).click();
    await mobile.locator('#viewer code').waitFor();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    await saveScreenshot(mobile, process.env.MOBILE_SCREENSHOT);
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');

    const reduced = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    reduced.setDefaultTimeout(15000);
    await reduced.emulateMedia({ reducedMotion: 'reduce' });
    reduced.on('pageerror', (error) => pageErrors.push(error.message));
    reduced.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await mockRawSources(reduced, manifest.commit);
    await reduced.goto(siteUrl, { waitUntil: 'domcontentloaded' });
    await reduced.getByRole('heading', { name: /代码与题解/ }).waitFor();
    assert.ok(await reduced.locator('.landing-copy').evaluate((element) => parseFloat(getComputedStyle(element).animationDuration)) < .001);
    assert.equal(await reduced.locator('[data-scene-root]').count(), 0);
    await saveScreenshot(reduced, process.env.REDUCED_SCREENSHOT);

    assert.deepEqual(pageErrors, []);
    console.log(`site smoke passed with ${manifest.count} indexed files`);
  } finally {
    await browser.close();
    if (server) await new Promise((resolve) => server.close(resolve));
  }
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
