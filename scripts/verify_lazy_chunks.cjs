const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const root = path.resolve(__dirname, '..');
const dist = path.join(root, 'dist');
const assets = path.join(dist, 'assets');
const html = fs.readFileSync(path.join(dist, 'index.html'), 'utf8');
const entryMatch = html.match(/<script[^>]+type="module"[^>]+src="([^"]+\.js)"/);

assert.ok(entryMatch, 'Vite index must reference an ESM entry script');
const entryPath = path.join(dist, entryMatch[1].replace(/^\/Code\//, ''));
const entrySource = fs.readFileSync(entryPath, 'utf8');
const javascript = fs.readdirSync(assets).filter((file) => file.endsWith('.js'));
const lazySources = javascript
  .filter((file) => path.join(assets, file) !== entryPath)
  .map((file) => fs.readFileSync(path.join(assets, file), 'utf8'));

assert.doesNotMatch(entrySource, /WebGLRenderer|IcosahedronGeometry|FogExp2|three\.module/i, 'initial app chunk must not eagerly include Three.js scene code');
assert.ok(lazySources.some((source) => /WebGLRenderer|IcosahedronGeometry|PerspectiveCamera|FogExp2/.test(source)), 'a distinct lazy scene/Three.js chunk must be present');
console.log(`lazy scene chunk verification passed (${lazySources.length} non-entry JavaScript assets)`);
