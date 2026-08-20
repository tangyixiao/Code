const assert = require('node:assert/strict');
const http = require('node:http');
const path = require('node:path');
const fs = require('node:fs');

const modules = process.env.CODEX_NODE_MODULES;
if (!modules) throw new Error('CODEX_NODE_MODULES is required');
const { chromium } = require(path.join(modules, 'playwright'));

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
  return new Promise((resolve) => server.listen(18765, '127.0.0.1', () => resolve(server.address().port)));
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
    if (pathname.startsWith('/Code/assets/')) {
      const asset = path.join(dist, pathname.slice('/Code/'.length));
      if (fs.existsSync(asset)) {
        if (asset.endsWith('.js')) response.setHeader('content-type', 'text/javascript; charset=utf-8');
        if (asset.endsWith('.css')) response.setHeader('content-type', 'text/css; charset=utf-8');
        if (asset.endsWith('.woff') || asset.endsWith('.woff2')) response.setHeader('content-type', 'font/woff2');
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
  });

  try {
    const page = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    page.setDefaultTimeout(5000);
    await page.route('https://cdn.jsdelivr.net/**', (route) => route.abort());
    await page.route('https://raw.githubusercontent.com/**', async (route) => {
      const decoded = decodeURIComponent(route.request().url());
      const body = decoded.endsWith('.md')
        ? '# 题目\n<img src=x onerror="document.body.dataset.xss=1">\n'
        : 'int main(){}\n';
      await route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body });
    });

    await page.goto(`http://127.0.0.1:${port}/Code/#file=${encodeURIComponent('题目 #1.md')}`);
    await page.locator('.count').waitFor({ state: 'attached' });
    assert.equal(await page.locator('#meta-name').textContent(), '题目 #1.md');
    assert.equal(await page.locator('body').getAttribute('data-xss'), null);
    assert.match(await page.locator('#viewer').textContent(), /题目/);
    assert.equal(await page.locator('.file-row').count(), 3);
    assert.equal(await page.locator('.file-row').first().evaluate((element) => element.tagName), 'BUTTON');

    await page.getByRole('button', { name: 'Markdown', exact: true }).click();
    await page.getByText('显示 2 / 3 个文件').waitFor();
    await page.getByPlaceholder('搜索题目编号或文件名').fill('P10');
    await page.getByText('显示 1 / 3 个文件').waitFor();
    await page.getByRole('button', { name: /P10 题解\.md/ }).click();
    assert.match(page.url(), /#file=P10%20%E9%A2%98%E8%A7%A3\.md$/);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(5000);
    await mobile.route('https://cdn.jsdelivr.net/**', (route) => route.abort());
    await mobile.route('https://raw.githubusercontent.com/**', (route) =>
      route.fulfill({ status: 200, contentType: 'text/plain; charset=utf-8', body: 'int main(){}\n' })
    );
    await mobile.goto(`http://127.0.0.1:${port}/Code/`);
    await mobile.getByText('显示 3 / 3 个文件').waitFor();
    await mobile.getByRole('button', { name: /A\.cpp/ }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');

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
