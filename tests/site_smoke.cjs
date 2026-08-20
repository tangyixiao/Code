const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const modules = process.env.CODEX_NODE_MODULES;
if (!modules) throw new Error('CODEX_NODE_MODULES is required');
const { chromium } = require(path.join(modules, 'playwright'));

async function saveScreenshot(page, target) {
  if (!target) return;
  fs.mkdirSync(path.dirname(target), { recursive: true });
  await page.screenshot({ path: target, fullPage: true });
}

async function main() {
  const siteUrl = process.env.SITE_URL;
  if (!siteUrl) throw new Error('SITE_URL is required');
  const browser = await chromium.launch({ headless: true, executablePath: process.env.CHROME_PATH });
  const pageErrors = [];

  try {
    const manifest = await (await fetch(new URL('files.json', siteUrl))).json();
    assert.equal(manifest.schemaVersion, 1);
    assert.ok(manifest.count > 2000, `expected a full archive, received ${manifest.count}`);

    const desktop = await browser.newPage({ viewport: { width: 1440, height: 900 } });
    desktop.setDefaultTimeout(15000);
    desktop.on('pageerror', (error) => pageErrors.push(error.message));
    await desktop.goto(siteUrl, { waitUntil: 'domcontentloaded' });
    await desktop.getByText(`显示 ${manifest.count} / ${manifest.count} 个文件`).waitFor();
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
    await desktop.getByRole('button', { name: '查看配对文件' }).click();
    await desktop.locator('#meta-name').getByText('P1241 括号序列.md', { exact: true }).waitFor();
    await desktop.locator('#viewer .markdown-body, #viewer .markdown-fallback').waitFor();
    await saveScreenshot(desktop, process.env.DESKTOP_SCREENSHOT);

    const mobile = await browser.newPage({ viewport: { width: 390, height: 844 } });
    mobile.setDefaultTimeout(15000);
    mobile.on('pageerror', (error) => pageErrors.push(error.message));
    await mobile.goto(new URL('./', siteUrl).href, { waitUntil: 'domcontentloaded' });
    await mobile.getByText(`显示 ${manifest.count} / ${manifest.count} 个文件`).waitFor();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');
    await mobile.getByPlaceholder('搜索题目编号或文件名').fill('P1241 括号序列');
    await mobile.getByRole('button', { name: /C\+\+ P1241 括号序列\.cpp/ }).click();
    await mobile.locator('#viewer code').waitFor();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'viewer');
    await saveScreenshot(mobile, process.env.MOBILE_SCREENSHOT);
    await mobile.getByRole('button', { name: '返回文件列表' }).click();
    assert.equal(await mobile.locator('body').getAttribute('data-mobile-view'), 'list');

    assert.deepEqual(pageErrors, []);
    console.log(`site smoke passed with ${manifest.count} indexed files`);
  } finally {
    await browser.close();
  }
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
