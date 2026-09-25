const fs = require("node:fs/promises");
const path = require("node:path");

const POWERED_BY =
  "//  Powered by Visual Studio Code + CPH (Competitive Programming Helper)";

function getProblemId(name, url) {
  let id = "";

  if (url) {
    try {
      const parsed = new URL(url);
      const isHost = (host) =>
        parsed.hostname === host || parsed.hostname.endsWith(`.${host}`);

      if (isHost("codeforces.com")) {
        const patterns = [
          /\/contest\/(\d+)\/problem\/(\w+)/,
          /\/problemset\/problem\/(\d+)\/(\w+)/,
          /\/gym\/(\d+)\/problem\/(\w+)/,
        ];
        for (const pattern of patterns) {
          const match = url.match(pattern);
          if (match) {
            id = `CF${match[1]}${match[2]}`;
            break;
          }
        }
      }

      if (!id && isHost("luogu.com.cn")) {
        id = url.match(/problem\/(\w+)/)?.[1] || "";
      }

      if (!id && isHost("atcoder.jp")) {
        const match = url.match(/tasks\/(\w+)_(\w+)/);
        if (match) id = `${match[1].toUpperCase()}${match[2].toUpperCase()}`;
      }

      if (!id && isHost("poj.org")) {
        const match = url.match(/[?&]id=(\d+)/);
        if (match) id = `POJ${match[1]}`;
      }

      if (
        !id &&
        (isHost("uva.onlinejudge.org") || isHost("onlinejudge.org"))
      ) {
        const match = url.match(/\/problem\/(\d+)/);
        if (match) id = `UVA${match[1]}`;
      }
    } catch {
      // Fall back to the problem title when the URL is not valid.
    }
  }

  if (!id) id = String(name).match(/\d+/)?.[0] || "";
  return id;
}

function getProblemBasename(problem) {
  const name = String(problem.name || "problem");
  const id = getProblemId(name, problem.url);
  let cleanName = name.replace(/[<>:"/\\|?*\x00-\x1f]/g, "_");

  if (id.startsWith("CF") && id.length > 2) {
    const lastChar = id[id.length - 1];
    const prefix = cleanName.match(/^([A-Za-z])\.\s*/);
    if (prefix && prefix[1].toUpperCase() === lastChar.toUpperCase()) {
      cleanName = cleanName.substring(prefix[0].length);
    }
  }

  if (id && cleanName.startsWith(id)) {
    const rest = cleanName.substring(id.length).replace(/^[\s.\-_]+/, "");
    if (rest.length > 0) cleanName = rest;
  }

  const basename = id
    ? cleanName
      ? `${id} ${cleanName}`
      : id
    : cleanName;
  return basename.replace(/[. ]+$/g, "") || "problem";
}

function displayValue(value) {
  if (value === undefined || value === null) return "";
  if (typeof value === "boolean") return String(value).toLowerCase();
  return String(value).replace(/[\r\n]+/g, " ");
}

function formatTimestamp(date) {
  const pad = (value) => String(value).padStart(2, "0");
  return `${date.getFullYear()}-${pad(date.getMonth() + 1)}-${pad(date.getDate())} ${pad(date.getHours())}:${pad(date.getMinutes())}:${pad(date.getSeconds())}`;
}

function formatLimit(label, value, unit) {
  const formatted = displayValue(value);
  return `//  ${label}:${formatted ? ` ${formatted} ${unit}` : ""}`;
}

function buildHeader(problem, now = new Date()) {
  const lines = [
    "//  Author: Tangyixiao",
    `//  Time: ${formatTimestamp(now)}`,
    `//  Problem: ${displayValue(problem.name)}`,
    `//  Contest: ${displayValue(problem.group)}`,
    `//  URL: ${displayValue(problem.url)}`,
    formatLimit("Memory Limit", problem.memoryLimit, "MB"),
    formatLimit("Time Limit", problem.timeLimit, "ms"),
    `//  Interactive: ${displayValue(problem.interactive)}`,
    `//  Test Type: ${displayValue(problem.testType)}`,
    "//",
    "//  Algorithm:",
    "//  Complexity: O()",
    "//  Note:",
    "//",
    POWERED_BY,
    "",
    "",
  ];
  return lines.join("\n");
}

function replaceLegacyHeader(source, header) {
  if (!source.startsWith("//  Author: Tangyixiao")) return null;
  const marker = /^\/\/  Powered by [^\r\n]*(?:\r?\n|$)/m;
  const match = source.match(marker);
  if (!match || match.index === undefined) return null;
  const end = match.index + match[0].length;
  return header + source.substring(end).replace(/^\r?\n/, "");
}

function prependHeader(source, problem, now = new Date()) {
  if (source.includes(POWERED_BY)) return source;
  const newline = source.includes("\r\n") ? "\r\n" : "\n";
  const header = buildHeader(problem, now).replace(/\n/g, newline);
  return replaceLegacyHeader(source, header) || header + source;
}

async function writeProblemSamples(workspaceRoot, problem) {
  const basename = getProblemBasename(problem);
  const cphRoot = path.resolve(workspaceRoot, "cph");
  const sampleDir = path.resolve(cphRoot, basename);
  if (!sampleDir.toLowerCase().startsWith(`${cphRoot}${path.sep}`.toLowerCase())) {
    throw new Error("Problem name resolves outside the cph samples folder");
  }

  await fs.mkdir(sampleDir, { recursive: true });
  const tests = Array.isArray(problem.tests) ? problem.tests : [];
  for (let index = 0; index < tests.length; index += 1) {
    const test = tests[index] || {};
    const number = index + 1;
    const stem = `${basename}_${number}`;
    await fs.writeFile(path.join(sampleDir, `${stem}.in`), String(test.input ?? ""), "utf8");
    await fs.writeFile(path.join(sampleDir, `${stem}.ans`), String(test.output ?? ""), "utf8");
  }

  const first = tests[0] || {};
  await fs.writeFile(path.join(sampleDir, "input.txt"), String(first.input ?? ""), "utf8");
  await fs.writeFile(path.join(sampleDir, "expected.txt"), String(first.output ?? ""), "utf8");
  await fs.writeFile(path.join(sampleDir, "output.txt"), "", "utf8");
  await fs.writeFile(
    path.join(sampleDir, "problem.json"),
    `${JSON.stringify(problem, null, 2)}\n`,
    "utf8",
  );

  return {
    basename,
    sampleDir,
    sourcePath: path.join(workspaceRoot, `${basename}.cpp`),
    testCount: tests.length,
  };
}

async function addHeaderToSource(sourcePath, problem, options = {}) {
  const retries = options.retries ?? 30;
  const delayMs = options.delayMs ?? 100;
  let source;

  for (let attempt = 0; attempt < retries; attempt += 1) {
    try {
      source = await fs.readFile(sourcePath, "utf8");
      break;
    } catch (error) {
      if (error.code !== "ENOENT" || attempt === retries - 1) throw error;
      await new Promise((resolve) => setTimeout(resolve, delayMs));
    }
  }

  const updated = prependHeader(source, problem);
  if (updated !== source) await fs.writeFile(sourcePath, updated, "utf8");
}

module.exports = {
  POWERED_BY,
  addHeaderToSource,
  buildHeader,
  getProblemBasename,
  prependHeader,
  writeProblemSamples,
};
