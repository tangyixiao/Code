import fs from 'node:fs';
import path from 'node:path';
import { createRequire } from 'node:module';

const require = createRequire(import.meta.url);
const { renderMarkdown } = await import('../src/markdown.ts');

const root = path.resolve(import.meta.dirname, '..');
const plain = (code) => code.split('\n').map((line) => line.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;'));

const decode = (s) => s
  .replaceAll('&amp;', '&')
  .replaceAll('&lt;', '<')
  .replaceAll('&gt;', '>')
  .replaceAll('&quot;', '"')
  .replaceAll('&#39;', "'");

// scan text segments the way auto-render does: per text node, math must be balanced within one node
function findUnbalanced(html) {
  const withoutPre = html.replace(/<pre[\s\S]*?<\/pre>/g, ' ');
  const segments = withoutPre.split(/<[^>]+>/).map(decode);
  const issues = [];
  for (const segment of segments) {
    // skip code spans leftovers are inline <code> - still text nodes, auto-render skips them via ignoredTags,
    // so ignore segments that would live inside <code>; approximate: track tags below.
  }
  // better walk: track open code tags
  let insideCode = false;
  const parts = withoutPre.split(/(<[^>]+>)/);
  for (const part of parts) {
    if (part.startsWith('<')) {
      if (/^<code[\s>]/.test(part)) insideCode = true;
      else if (/^<\/code[\s>]/.test(part)) insideCode = false;
      continue;
    }
    if (insideCode) continue;
    const text = decode(part);
    let count = 0;
    for (let i = 0; i < text.length; i += 1) {
      if (text[i] === '$' && text[i - 1] !== '\\' && text[i - 1] !== '`') count += 1;
      if (text[i] === '$' && text[i + 1] === '$') i += 1;
    }
    if (count % 2 === 1) issues.push(text.trim().slice(0, 80));
  }
  return issues;
}

const files = fs.readdirSync(root).filter((f) => f.endsWith('.md'));
let bad = 0;
const report = [];
for (const name of files) {
  const md = fs.readFileSync(path.join(root, name), 'utf8');
  if (!md.includes('$')) continue;
  let html;
  try {
    html = renderMarkdown(md, plain);
  } catch (error) {
    report.push({ name, error: String(error) });
    bad += 1;
    continue;
  }
  const issues = findUnbalanced(html);
  if (issues.length) {
    bad += 1;
    report.push({ name, issues: issues.slice(0, 3) });
  }
}
console.log(`scanned ${files.length} md files, ${bad} with unbalanced math text nodes`);
for (const item of report.slice(0, 40)) {
  console.log('\n=== ' + item.name);
  if (item.error) console.log('  ERROR', item.error);
  else for (const issue of item.issues) console.log('  · ' + issue);
}
fs.writeFileSync(path.join(root, 'math-sweep-report.json'), JSON.stringify(report, null, 2));
