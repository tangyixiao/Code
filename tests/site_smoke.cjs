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

async function mockRawSources(page) {
  await page.route('https://raw.githubusercontent.com/**', (route) => {
    const url = decodeURIComponent(route.request().url());
    const body = url.endsWith('P9709 [KMOI R1] 军事行动.md')
      ? `# 军事行动\n\n$ x_1 + x_2 = 10 $\n\n$ y = ax^2 + bx + c $\n\n$ \\sum_{i=1}^{n} i $\n\n$ \\frac{a}{b} $\n\n$ \\alpha + \\beta = \\gamma $\n\n$ \\int_0^1 x^2 dx $\n`
      : url.endsWith('P1241 括号序列.md')
        ? '# 括号序列\n\n配对题解内容保留。\n'
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
    assert.equal(manifest.schemaVersion, 1);
    assert.ok(manifest.count > 2000, `expected a full archive, received ${manifest.count}`);

    const desktop = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    desktop.setDefaultTimeout(15000);
    desktop.on('pageerror', (error) => pageErrors.push(error.message));
    desktop.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await mockRawSources(desktop);
    await desktop.goto(siteUrl, { waitUntil: 'domcontentloaded' });
    await desktop.getByText(`显示 ${manifest.count} / ${manifest.count} 个文件`).waitFor();
    await desktop.locator('[data-scene-root]').waitFor({ state: 'attached' });
    assert.equal(await desktop.locator('[data-scene-canvas]').count(), 1);
    assert.equal(await desktop.locator('[data-scene-root]').getAttribute('data-scene-variant'), 'workbench');
    assert.equal(await desktop.locator('[data-scene-root]').getAttribute('data-scene-motion'), 'full');
    assert.equal(await desktop.locator('[data-scene-root]').getAttribute('data-scene-fallback'), 'inactive');
    assert.equal(await desktop.locator('[data-scene-root]').getAttribute('data-scene-particles'), '360');
    await desktop.waitForFunction(() => Number(document.querySelector('[data-scene-root]')?.getAttribute('data-scene-render-count')) > 0);
    assert.ok(Number(await desktop.locator('[data-scene-root]').getAttribute('data-scene-render-count')) > 0);
    assert.equal(await desktop.locator('.file-row').count(), manifest.count);

    await desktop.getByPlaceholder('搜索题目编号或文件名').fill('260509练习赛①#A. 三投');
    await desktop.getByRole('button', { name: /260509练习赛①#A\. 三投\.cpp/ }).click();
    await desktop.locator('#viewer code').waitFor();
    assert.match(desktop.url(), /%23A/);

    await desktop.getByPlaceholder('搜索题目编号或文件名').fill('P9709 [KMOI R1] 军事行动.md');
    await desktop.getByRole('button', { name: /Markdown P9709 \[KMOI R1\] 军事行动\.md/ }).click();
    await desktop.locator('#viewer .markdown-body').waitFor();
    await desktop.locator('#viewer .katex').first().waitFor();
    assert.ok(await desktop.locator('#viewer .katex').count() > 5);
    await saveScreenshot(desktop, process.env.MATH_SCREENSHOT);

    await desktop.getByPlaceholder('搜索题目编号或文件名').fill('P1241 括号序列');
    await desktop.getByRole('button', { name: /C\+\+ P1241 括号序列\.cpp/ }).click();
    await desktop.getByRole('button', { name: '查看题解' }).click();
    await desktop.locator('#meta-name').getByText('P1241 括号序列.md', { exact: true }).waitFor();
    await desktop.locator('#viewer .markdown-body, #viewer .markdown-fallback').waitFor();
    await saveScreenshot(desktop, process.env.DESKTOP_SCREENSHOT);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(15000);
    mobile.on('pageerror', (error) => pageErrors.push(error.message));
    mobile.on('console', (message) => { if (message.type() === 'error') pageErrors.push(message.text()); });
    await mockRawSources(mobile);
    await mobile.goto(new URL('./', siteUrl).href, { waitUntil: 'domcontentloaded' });
    await mobile.getByText(`显示 ${manifest.count} / ${manifest.count} 个文件`).waitFor();
    await mobile.locator('[data-scene-root]').waitFor({ state: 'attached' });
    assert.equal(await mobile.locator('[data-scene-canvas]').count(), 1);
    assert.equal(await mobile.locator('[data-scene-root]').getAttribute('data-scene-motion'), 'full');
    assert.equal(await mobile.locator('[data-scene-root]').getAttribute('data-scene-particles'), '360');
    await mobile.waitForFunction(() => Number(document.querySelector('[data-scene-root]')?.getAttribute('data-scene-render-count')) > 0);
    assert.ok(Number(await mobile.locator('[data-scene-root]').getAttribute('data-scene-render-count')) > 0);
    assert.equal(await mobile.evaluate(() => document.documentElement.scrollWidth <= innerWidth), true);
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    await mobile.getByPlaceholder('搜索题目编号或文件名').fill('P1241 括号序列');
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
    await mockRawSources(reduced);
    await reduced.goto(siteUrl, { waitUntil: 'domcontentloaded' });
    await reduced.locator('[data-scene-root]').waitFor({ state: 'attached' });
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-animation'), 'static');
    await reduced.waitForFunction(() => Number(document.querySelector('[data-scene-root]')?.getAttribute('data-scene-render-count')) === 1);
    const reducedRenderCount = await reduced.locator('[data-scene-root]').getAttribute('data-scene-render-count');
    await reduced.waitForTimeout(250);
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-render-count'), reducedRenderCount);
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
