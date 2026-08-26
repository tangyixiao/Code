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
  schemaVersion: 1,
  commit,
  generatedAt: '2026-08-20T00:00:00Z',
  count: 3,
  files: [
    { name: 'A.cpp', path: 'A.cpp', type: 'cpp', size: 13 },
    { name: 'P10 题解.md', path: 'P10 题解.md', type: 'md', size: 8 },
    { name: '题目 #1.md', path: '题目 #1.md', type: 'md', size: 30 },
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
    await page.route('https://raw.githubusercontent.com/**', async (route) => {
      const decoded = decodeURIComponent(route.request().url());
      const body = decoded.endsWith('.md')
        ? `# 题目\n${'内容保留滚动位置。\n\n'.repeat(80)}<img src="data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==" onerror="document.body.dataset.xss=1">\n`
        : `${'int main(){}\n'.repeat(120)}`;
      await route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body });
    });

    await page.goto(`http://127.0.0.1:${port}/Code/#file=${encodeURIComponent('题目 #1.md')}`);
    await page.locator('.count').waitFor({ state: 'attached' });
    await page.locator('[data-scene-root]').waitFor({ state: 'attached', timeout: 15000 });
    assert.equal(await page.title(), 'Paradox Praxis Clinamen — 深海算法档案');
    assert.equal(await page.getByText('Paradox Praxis Clinamen', { exact: true }).count(), 1);
    assert.equal(await page.getByText('佯谬·践履·偏斜', { exact: true }).count(), 1);
    assert.equal(await page.locator('[data-scene-canvas]').count(), 1);
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-variant'), 'workbench');
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-phase'), 'workbench');
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-motion'), 'full');
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-animation'), 'running');
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-fallback'), 'inactive');
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-particles'), '360');
    assert.ok(Number(await page.locator('[data-scene-root]').getAttribute('data-scene-render-count')) > 0);
    assert.equal(await page.locator('[data-scene-canvas]').evaluate((element) => getComputedStyle(element).pointerEvents), 'none');
    assert.equal(await page.locator('#meta-name').textContent(), '题目 #1.md');
    assert.equal(await page.locator('body').getAttribute('data-xss'), null);
    assert.match(await page.locator('#viewer').textContent(), /题目/);
    assert.equal(await page.locator('.file-row').count(), 3);
    assert.equal(await page.locator('.file-row').first().evaluate((element) => element.tagName), 'BUTTON');
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
    await page.getByText('显示 2 / 3 个文件').waitFor();
    await page.getByPlaceholder('搜索题目编号或文件名').fill('P10');
    await page.getByText('显示 1 / 3 个文件').waitFor();
    await page.getByRole('button', { name: /P10 题解\.md/ }).click();
    assert.match(page.url(), /#file=P10%20%E9%A2%98%E8%A7%A3\.md$/);

    await page.getByRole('button', { name: '全部', exact: true }).click();
    await page.getByPlaceholder('搜索题目编号或文件名').fill('');
    await page.getByRole('button', { name: /C\+\+ A\.cpp/ }).click();
    await page.locator('#viewer code').waitFor();
    const firstPulse = await page.locator('[data-scene-root]').getAttribute('data-scene-pulse');
    assert.equal(firstPulse, '2.000');
    const search = page.getByPlaceholder('搜索题目编号或文件名');
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
    assert.equal(await page.locator('[data-scene-root]').getAttribute('data-scene-pulse'), '3.000');
    assert.match(await page.locator('#viewer').textContent(), /题目/);

    await page.evaluate(() => document.querySelector('[data-scene-canvas]').dispatchEvent(new Event('webglcontextlost', { cancelable: true })));
    await page.waitForFunction(() => document.querySelector('[data-scene-root]')?.getAttribute('data-scene-fallback') === 'active');
    await page.locator('.deep-sea-fallback').waitFor({ state: 'visible' });
    assert.equal(await page.locator('.deep-sea-fallback').isVisible(), true);
    assert.deepEqual(pageErrors, []);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(15000);
    const mobileErrors = [];
    mobile.on('pageerror', (error) => mobileErrors.push(error.message));
    mobile.on('console', (message) => { if (message.type() === 'error') mobileErrors.push(message.text()); });
    await mobile.route('https://cdn.jsdelivr.net/**', (route) => route.abort());
    await mobile.route('https://raw.githubusercontent.com/**', (route) =>
      route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body: 'int main(){}\n' })
    );
    await mobile.goto(`http://127.0.0.1:${port}/Code/#file=${encodeURIComponent('题目 #1.md')}`);
    await mobile.locator('.count').waitFor({ state: 'attached' });
    await mobile.locator('[data-scene-root]').waitFor();
    assert.equal(await mobile.locator('[data-scene-canvas]').count(), 1);
    assert.equal(await mobile.locator('[data-scene-root]').getAttribute('data-scene-motion'), 'full');
    assert.equal(await mobile.locator('[data-scene-root]').getAttribute('data-scene-particles'), '360');
    await mobile.waitForFunction(() => Number(document.querySelector('[data-scene-root]')?.getAttribute('data-scene-render-count')) > 0);
    assert.ok(Number(await mobile.locator('[data-scene-root]').getAttribute('data-scene-render-count')) > 0);
    assert.equal(await mobile.evaluate(() => document.documentElement.scrollWidth <= innerWidth), true);
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    assert.equal(await mobile.locator('#meta-name').textContent(), '题目 #1.md');
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    await mobile.getByRole('button', { name: /A\.cpp/ }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    assert.deepEqual(mobileErrors, []);

    const reduced = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    reduced.setDefaultTimeout(15000);
    await reduced.emulateMedia({ reducedMotion: 'reduce' });
    const reducedErrors = [];
    reduced.on('pageerror', (error) => reducedErrors.push(error.message));
    reduced.on('console', (message) => { if (message.type() === 'error') reducedErrors.push(message.text()); });
    await reduced.addInitScript(() => {
      window.__sceneRafCalls = 0;
      const requestAnimationFrame = window.requestAnimationFrame.bind(window);
      window.requestAnimationFrame = (callback) => {
        window.__sceneRafCalls += 1;
        return requestAnimationFrame(callback);
      };
    });
    await reduced.route('https://raw.githubusercontent.com/**', (route) =>
      route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body: 'int main(){}\n' })
    );
    await reduced.goto(`http://127.0.0.1:${port}/Code/`, { waitUntil: 'domcontentloaded' });
    await reduced.locator('[data-scene-root]').waitFor();
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-motion'), 'reduced');
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-animation'), 'static');
    await reduced.waitForFunction(() => Number(document.querySelector('[data-scene-root]')?.getAttribute('data-scene-render-count')) === 1);
    const reducedRenderCount = await reduced.locator('[data-scene-root]').getAttribute('data-scene-render-count');
    const reducedRafCalls = await reduced.evaluate(() => window.__sceneRafCalls);
    await reduced.waitForTimeout(250);
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-render-count'), reducedRenderCount);
    assert.equal(await reduced.evaluate(() => window.__sceneRafCalls), reducedRafCalls);
    await reduced.evaluate(() => { Object.defineProperty(document, 'hidden', { configurable: true, value: true }); document.dispatchEvent(new Event('visibilitychange')); });
    await reduced.evaluate(() => { Object.defineProperty(document, 'hidden', { configurable: true, value: false }); document.dispatchEvent(new Event('visibilitychange')); });
    await reduced.waitForTimeout(250);
    assert.equal(await reduced.locator('[data-scene-root]').getAttribute('data-scene-render-count'), reducedRenderCount);
    assert.equal(await reduced.evaluate(() => window.__sceneRafCalls), reducedRafCalls);
    assert.deepEqual(reducedErrors, []);

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
