const assert = require('node:assert/strict');
const http = require('node:http');
const path = require('node:path');
const fs = require('node:fs');

const modules = process.env.CODEX_NODE_MODULES;
const { chromium } = require(modules ? path.join(modules, 'playwright') : 'playwright');

const root = path.resolve(__dirname, '..');
const dist = path.join(root, 'dist');
const commit = 'a'.repeat(40);
const manifest = JSON.stringify({
  schemaVersion: 2,
  commit,
  generatedAt: '2026-08-20T00:00:00Z',
  count: 6,
  files: [
    { name: 'A.cpp', path: 'A.cpp', type: 'cpp', size: 13, updatedAt: '2026-09-29T09:00:00+08:00', lastCommit: commit },
    { name: 'P10 题解.md', path: 'P10 题解.md', type: 'md', size: 8, updatedAt: '2026-09-28T09:00:00+08:00', lastCommit: commit },
    { name: '题目 #1.md', path: '题目 #1.md', type: 'md', size: 30, updatedAt: '2026-09-27T09:00:00+08:00', lastCommit: commit },
    { name: 'helper.py', path: 'tools/helper.py', type: 'py', size: 26, updatedAt: '2026-09-26T09:00:00+08:00', lastCommit: commit },
    { name: 'index.php', path: 'tools/index.php', type: 'php', size: 28, updatedAt: '2026-09-25T09:00:00+08:00', lastCommit: commit },
    { name: 'sample.bin', path: 'assets/sample.bin', type: 'bin', size: 1024, updatedAt: '2026-09-24T09:00:00+08:00', lastCommit: commit },
  ],
});
const historyData = JSON.stringify({
  schemaVersion: 1,
  generatedAt: '2026-09-29T02:00:00Z',
  buildCommit: commit,
  pushEvent: true,
  remoteMain: commit,
  branches: [{ name: 'origin/main', sha: commit, remote: true }, { name: 'main', sha: commit, remote: false }],
  rows: [
    { graph: '* ', sha: commit, parents: ['b'.repeat(40)], committedAt: '2026-09-29T02:00:00Z', author: 'Test', subject: 'update archive' },
    { graph: '|\\' },
    { graph: '* ', sha: 'b'.repeat(40), parents: [], committedAt: '2026-09-28T02:00:00Z', author: 'Test', subject: 'initial commit' },
  ],
});

function listen(server) {
  return new Promise((resolve) => server.listen(Number(process.env.SITE_PORT || 18765), '127.0.0.1', () => resolve(server.address().port)));
}

async function main() {
  const server = http.createServer((request, response) => {
    const pathname = new URL(request.url, 'http://127.0.0.1').pathname;
    if (pathname === '/Code/' || pathname === '/Code/index.html') {
      response.setHeader('content-type', 'text/html; charset=utf-8');
      response.end(fs.readFileSync(path.join(dist, 'index.html')));
      return;
    }
    if (pathname === '/Code/files.json') {
      response.setHeader('content-type', 'application/json; charset=utf-8');
      response.end(manifest);
      return;
    }
    if (pathname === '/Code/history.json') {
      response.setHeader('content-type', 'application/json; charset=utf-8');
      response.end(historyData);
      return;
    }
    if (pathname === '/Code/favicon.ico') {
      response.statusCode = 204;
      response.end();
      return;
    }
    if (pathname.startsWith('/Code/assets/')) {
      const asset = path.join(dist, pathname.slice('/Code/'.length));
      if (fs.existsSync(asset)) {
        const contentTypes = {
          '.css': 'text/css; charset=utf-8',
          '.js': 'text/javascript; charset=utf-8',
          '.ttf': 'font/ttf',
          '.woff': 'font/woff',
          '.woff2': 'font/woff2',
        };
        response.setHeader('content-type', contentTypes[path.extname(asset)] || 'application/octet-stream');
        response.end(fs.readFileSync(asset));
        return;
      }
    }
    response.statusCode = 404;
    response.end('not found');
  });
  const port = await listen(server);
  const browser = await chromium.launch({
    headless: true,
    executablePath: process.env.CHROME_PATH,
    args: ['--enable-webgl', '--use-angle=swiftshader'],
  });

  try {
    const pageErrors = [];
    const page = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    page.setDefaultTimeout(15000);
    page.on('pageerror', (error) => pageErrors.push(error.message));
    page.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await page.route('https://cdn.jsdelivr.net/**', (route) => route.abort());
    await page.route('https://api.github.com/repos/tangyixiao/Code/actions/workflows/pages.yml/runs**', (route) => route.fulfill({
      status: 200, contentType: 'application/json; charset=utf-8',
      body: JSON.stringify({ workflow_runs: [{ id: 1, head_sha: commit, created_at: '2026-09-29T02:00:00Z', status: 'completed', conclusion: 'success', html_url: 'https://github.com/tangyixiao/Code/actions/runs/1' }] }),
    }));
    await page.route('https://raw.githubusercontent.com/**', async (route) => {
      const decoded = decodeURIComponent(route.request().url());
      const body = decoded.endsWith('.py') ? 'def answer():\n    return 42\n' : decoded.endsWith('.md')
        ? `# 题目\n\n\`\`\`cpp\n/* first line\nstill a comment */\nint answer = 42;\n\`\`\`\n\n${'内容保留滚动位置。\n\n'.repeat(80)}<img src="data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==" onerror="document.body.dataset.xss=1">\n`
        : `${'int main(){}\n'.repeat(120)}`;
      await route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body });
    });

    await page.emulateMedia({ colorScheme: 'light' });
    await page.goto(`http://127.0.0.1:${port}/Code/#file=${encodeURIComponent('题目 #1.md')}`);
    await page.locator('.count').waitFor({ state: 'attached' });
    assert.equal(await page.title(), '算法档案 · tangyixiao');
    assert.equal(await page.getByRole('heading', { name: '算法档案' }).count(), 1);
    assert.equal(await page.locator('.app-shell').getAttribute('data-theme'), 'dark');
    assert.equal(await page.locator('[data-scene-root]').count(), 0);
    assert.equal(await page.locator('#meta-name').textContent(), '题目 #1.md');
    assert.equal(await page.locator('body').getAttribute('data-xss'), null);
    assert.match(await page.locator('#viewer').textContent(), /题目/);
    await page.locator('#viewer .markdown-code-block .code-line[data-line="2"] .line-content span[style]').waitFor();
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'dark');
    assert.equal(await page.locator('#viewer .markdown-code-block').evaluate((element) => getComputedStyle(element).backgroundColor), 'rgb(30, 30, 30)');
    assert.equal(await page.locator('#viewer .markdown-code-block .line-content').first().evaluate((element) => getComputedStyle(element).color), 'rgb(212, 212, 212)');
    assert.equal(await page.locator('#viewer .markdown-code-block .code-line[data-line="2"] .line-content span[style]').evaluate((element) => getComputedStyle(element).color), 'rgb(106, 153, 85)', 'a multiline comment must retain its grammar state');
    assert.equal(await page.locator('.markdown-body').evaluate((element) => getComputedStyle(element).fontSize), '15px');
    await page.locator('.reader-body').hover();
    await page.keyboard.down('Control');
    await page.mouse.wheel(0, -100);
    await page.keyboard.up('Control');
    assert.equal(await page.locator('.markdown-body').evaluate((element) => getComputedStyle(element).fontSize), '16px');
    assert.equal(await page.getByRole('button', { name: '重置阅读字体' }).textContent(), '14px');
    await page.reload();
    await page.locator('.markdown-body').waitFor();
    assert.equal(await page.locator('.markdown-body').evaluate((element) => getComputedStyle(element).fontSize), '16px', 'reader font size should survive reload');
    await page.getByRole('button', { name: '重置阅读字体' }).click();
    assert.equal(await page.locator('.markdown-body').evaluate((element) => getComputedStyle(element).fontSize), '15px');
    await page.emulateMedia({ colorScheme: 'dark' });
    await page.emulateMedia({ colorScheme: 'light' });
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'dark');
    const sidebarBackground = await page.locator('.sidebar').evaluate((element) => getComputedStyle(element).backgroundColor);
    await page.getByRole('button', { name: '切换为浅色模式' }).click();
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'light');
    assert.equal(await page.locator('#viewer .markdown-code-block').evaluate((element) => getComputedStyle(element).backgroundColor), 'rgb(255, 255, 255)');
    assert.equal(await page.locator('#viewer .markdown-code-block .line-content').first().evaluate((element) => getComputedStyle(element).color), 'rgb(0, 0, 0)');
    assert.equal(await page.locator('#viewer .markdown-code-block .code-line[data-line="2"] .line-content span[style]').evaluate((element) => getComputedStyle(element).color), 'rgb(0, 128, 0)');
    assert.notEqual(await page.locator('.sidebar').evaluate((element) => getComputedStyle(element).backgroundColor), sidebarBackground);
    await page.emulateMedia({ colorScheme: 'dark' });
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'light', 'manual selection should override system changes');
    await page.reload();
    await page.locator('#viewer .markdown-code-block code').waitFor();
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'light', 'manual selection should survive reload');
    assert.equal(await page.locator('.file-row').count(), 3);
    assert.equal(await page.locator('.file-row').first().evaluate((element) => element.tagName), 'BUTTON');
    assert.equal(await page.getByLabel('文件排序').inputValue(), 'recent');
    const resizer = page.getByRole('separator', { name: '调整文件列表宽度' });
    assert.equal(await resizer.getAttribute('aria-valuenow'), '296');
    const beforeResize = await page.locator('.sidebar').evaluate((element) => element.getBoundingClientRect().width);
    const box = await resizer.boundingBox();
    await page.mouse.move(box.x + box.width / 2, box.y + 100);
    await page.mouse.down();
    await page.mouse.move(box.x + 100, box.y + 100, { steps: 4 });
    await page.mouse.up();
    const afterResize = await page.locator('.sidebar').evaluate((element) => element.getBoundingClientRect().width);
    assert.ok(afterResize > beforeResize + 70, 'dragging should widen the file list');
    await page.reload();
    await page.locator('.sidebar').waitFor();
    assert.ok(await page.locator('.sidebar').evaluate((element) => element.getBoundingClientRect().width) > beforeResize + 70, 'sidebar width should survive reload');
    await page.getByRole('separator', { name: '调整文件列表宽度' }).focus();
    await page.keyboard.press('ArrowLeft');
    assert.ok(await page.locator('.sidebar').evaluate((element) => element.getBoundingClientRect().width) < afterResize, 'keyboard should resize the file list');
    const stackResizer = page.getByRole('separator', { name: '调整文件夹区域高度' });
    const folderHeightBefore = await page.locator('.folder-area').evaluate((element) => element.getBoundingClientRect().height);
    const stackBox = await stackResizer.boundingBox();
    await page.mouse.move(stackBox.x + 100, stackBox.y + stackBox.height / 2);
    await page.mouse.down();
    await page.mouse.move(stackBox.x + 100, stackBox.y + 70, { steps: 4 });
    await page.mouse.up();
    assert.ok(await page.locator('.folder-area').evaluate((element) => element.getBoundingClientRect().height) > folderHeightBefore + 50);
    await page.getByRole('button', { name: '折叠文件夹' }).click();
    assert.equal(await page.locator('.folder-list').isVisible(), false);
    await page.reload();
    assert.equal(await page.locator('.folder-list').isVisible(), false, 'folder collapse should survive reload');
    await page.getByRole('button', { name: '展开文件夹' }).click();
    assert.equal(await page.locator('.folder-list').isVisible(), true);
    await page.getByLabel('文件排序').selectOption('oldest');
    await page.locator('.file-row').first().getByText('题目 #1.md').waitFor();
    await page.getByLabel('文件排序').selectOption('name');
    await page.locator('.file-row').first().getByText('A.cpp').waitFor();
    await page.getByLabel('文件排序').selectOption('recent');
    await page.locator('.file-row').first().getByText('A.cpp').waitFor();
    const desktopLayout = await page.evaluate(() => ({
      viewportHeight: innerHeight,
      documentHeight: document.documentElement.scrollHeight,
      shellHeight: document.querySelector('.app-shell').getBoundingClientRect().height,
      listOverflow: getComputedStyle(document.querySelector('.file-list')).overflowY,
      readerOverflow: getComputedStyle(document.querySelector('.reader-body')).overflowY,
      markdownHeadingSize: parseFloat(getComputedStyle(document.querySelector('.markdown-body h1')).fontSize),
    }));
    assert.ok(desktopLayout.documentHeight <= desktopLayout.viewportHeight + 1, 'desktop page must not scroll as one long document');
    assert.ok(Math.abs(desktopLayout.shellHeight - desktopLayout.viewportHeight) <= 1, 'workbench must fill the viewport');
    assert.equal(desktopLayout.listOverflow, 'auto');
    assert.equal(desktopLayout.readerOverflow, 'auto');
    assert.ok(desktopLayout.markdownHeadingSize >= 36 && desktopLayout.markdownHeadingSize <= 40, 'markdown h1 should be about 2.4rem');

    await page.getByRole('button', { name: 'Markdown', exact: true }).click();
    await page.getByText('显示 2 / 6 个文件').waitFor();
    await page.getByPlaceholder('搜索文件名或路径').fill('P10');
    await page.getByText('显示 1 / 6 个文件').waitFor();
    await page.getByRole('button', { name: /P10 题解\.md/ }).click();
    assert.match(page.url(), /#file=P10%20%E9%A2%98%E8%A7%A3\.md$/);

    await page.getByRole('button', { name: '全部', exact: true }).click();
    await page.getByPlaceholder('搜索文件名或路径').fill('');
    await page.getByRole('button', { name: /C\+\+ A\.cpp/ }).click();
    await page.locator('#viewer code').waitFor();
    assert.equal((await page.locator('.code-gutter').textContent()).split('\n').length, 121);
    assert.equal(await page.locator('.reader').getAttribute('data-code-theme'), 'light');
    assert.equal(await page.locator('#viewer .code').evaluate((element) => getComputedStyle(element).backgroundColor), 'rgb(255, 255, 255)');
    await page.getByRole('button', { name: '切换为深色模式' }).click();
    assert.equal(await page.locator('#viewer .code').evaluate((element) => getComputedStyle(element).backgroundColor), 'rgb(30, 30, 30)');
    const search = page.getByPlaceholder('搜索文件名或路径');
    await search.focus();
    const readerScroll = await page.locator('.reader-body').evaluate((element) => {
      element.scrollTop = Math.min(24, element.scrollHeight - element.clientHeight);
      return { top: element.scrollTop, height: element.scrollHeight, client: element.clientHeight };
    });
    await page.getByRole('button', { name: /Markdown P10 题解\.md/ }).dispatchEvent('mousedown', { button: 0 });
    await page.locator('#meta-name').getByText('P10 题解.md', { exact: true }).waitFor();
    await page.locator('#viewer .markdown-body').waitFor();
    assert.equal(await page.evaluate((input) => document.activeElement === input, await search.elementHandle()), true);
    const expectedReaderScroll = await page.locator('.reader-body').evaluate((element, top) => Math.min(top, element.scrollHeight - element.clientHeight), readerScroll.top);
    await page.waitForTimeout(1000);
    assert.equal(await page.locator('.reader-body').evaluate((element) => element.scrollTop), expectedReaderScroll);
    assert.equal(await page.locator('.reader-body').evaluate((element) => element.scrollTop), expectedReaderScroll);
    assert.match(await page.locator('#viewer').textContent(), /题目/);
    await page.getByRole('button', { name: 'Git 历程' }).click();
    await page.getByRole('heading', { name: 'Git 历程' }).waitFor();
    assert.equal(await page.locator('.commit-row').count(), 2);
    assert.equal(await page.locator('.commit-row .git-node').count(), 2);
    assert.ok(await page.locator('.commit-connector .git-rail').count() >= 2);
    assert.equal(await page.locator('.git-graph').first().evaluate((element) => element.tagName.toLowerCase()), 'svg');
    assert.match(await page.locator('.history-push').textContent(), /本次由 main 推送触发/);
    await page.getByText('部署成功').first().waitFor();
    assert.equal(await page.locator('.commit-ref-list .push-ref').count(), 1);
    await page.locator('.commit-row').last().click();
    assert.match(await page.locator('.history-detail').textContent(), /initial commit/);
    await page.getByRole('button', { name: /origin\/main/ }).click();
    assert.match(await page.locator('.history-detail').textContent(), /update archive/);
    await page.getByRole('button', { name: '文件', exact: true }).click();
    await page.getByLabel('文件排序').waitFor();
    await page.locator('.folder-row').filter({ hasText: 'tools' }).click();
    assert.match(page.url(), /#dir=tools$/);
    assert.equal(await page.locator('.file-row').count(), 2);
    await page.getByLabel('其他语言与文件类型').selectOption('py');
    assert.equal(await page.locator('.file-row').count(), 1);
    await page.getByRole('button', { name: 'Python tools/helper.py' }).click();
    await page.locator('.code .shiki span[style]').first().waitFor();
    await page.getByRole('button', { name: '仓库' }).click();
    await page.locator('.folder-row').filter({ hasText: 'assets' }).click();
    await page.getByRole('button', { name: '全部', exact: true }).click();
    await page.getByRole('button', { name: 'BIN assets/sample.bin' }).click();
    assert.match(await page.locator('.binary-preview').textContent(), /无法在网页中预览/);
    assert.deepEqual(pageErrors, []);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(15000);
    const mobileErrors = [];
    mobile.on('pageerror', (error) => mobileErrors.push(error.message));
    mobile.on('console', (message) => { if (message.type() === 'error') mobileErrors.push(message.text()); });
    await mobile.emulateMedia({ colorScheme: 'dark' });
    await mobile.route('https://cdn.jsdelivr.net/**', (route) => route.abort());
    await mobile.route('https://raw.githubusercontent.com/**', (route) =>
      route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body: route.request().url().endsWith('.md') ? '# 移动端\n\n```cpp\nint answer = 1;\n```\n' : 'int main(){}\n' })
    );
    await mobile.goto(`http://127.0.0.1:${port}/Code/#file=${encodeURIComponent('题目 #1.md')}`);
    await mobile.locator('.count').waitFor({ state: 'attached' });
    assert.equal(await mobile.locator('.app-shell').getAttribute('data-theme'), 'dark');
    assert.equal(await mobile.evaluate(() => document.documentElement.scrollWidth <= innerWidth), true);
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    assert.equal(await mobile.locator('#meta-name').textContent(), '题目 #1.md');
    await mobile.locator('.markdown-code-block code').waitFor();
    assert.equal(await mobile.getByRole('button', { name: '切换为浅色模式' }).isVisible(), true);
    await mobile.getByRole('button', { name: '切换为浅色模式' }).click();
    assert.equal(await mobile.locator('.reader').getAttribute('data-code-theme'), 'light');
    assert.equal(await mobile.locator('.app-shell').getAttribute('data-theme'), 'light');
    assert.equal(await mobile.locator('.markdown-code-block').evaluate((element) => getComputedStyle(element).backgroundColor), 'rgb(255, 255, 255)');
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    await mobile.getByRole('button', { name: /A\.cpp/ }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    assert.deepEqual(mobileErrors, []);

    console.log('site browser tests passed');
  } finally {
    await browser.close();
    await new Promise((resolve) => server.close(resolve));
  }
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
