const assert = require("node:assert/strict");
const http = require("node:http");
const fs = require("node:fs/promises");
const os = require("node:os");
const path = require("node:path");
const test = require("node:test");
const { buildHeader } = require("../sample-writer");

let createBridgeServer;
try {
  ({ createBridgeServer } = require("../bridge"));
} catch {
  // Keep the test runnable before the bridge is implemented.
}

const problem = {
  name: "B4463 [海淀区入门组 2025] 素数和回文数",
  group: "海淀区入门组 2025",
  url: "https://www.luogu.com.cn/problem/B4463",
  memoryLimit: 256,
  timeLimit: 1000,
  interactive: false,
  testType: "single",
  tests: [
    { input: "1 2\n", output: "3\n" },
    { input: "5 6\n", output: "11\n" },
  ],
};

function listen(server, host = "127.0.0.1") {
  return new Promise((resolve, reject) => {
    server.once("error", reject);
    server.listen(0, host, () => {
      server.removeListener("error", reject);
      resolve(server.address().port);
    });
  });
}

function post(port, body) {
  return new Promise((resolve, reject) => {
    const request = http.request(
      {
        host: "127.0.0.1",
        port,
        method: "POST",
        path: "/",
        headers: { "content-type": "application/json" },
      },
      (response) => {
        const chunks = [];
        response.on("data", (chunk) => chunks.push(chunk));
        response.on("end", () =>
          resolve({
            statusCode: response.statusCode,
            body: Buffer.concat(chunks).toString("utf8"),
          }),
        );
      },
    );
    request.on("error", reject);
    request.end(JSON.stringify(problem));
  });
}

test("Competitive Companion import writes numbered samples and forwards to CPH-NG", async (t) => {
  assert.equal(typeof createBridgeServer, "function");

  const workspace = await fs.mkdtemp(path.join(os.tmpdir(), "cph-bridge-"));
  const sourceName = "B4463 [海淀区入门组 2025] 素数和回文数.cpp";
  const sourceBody = "#include <bits/stdc++.h>\r\nint main() {}\r\n";
  let receivedPayload;
  const cphNg = http.createServer(async (request, response) => {
    const chunks = [];
    for await (const chunk of request) chunks.push(chunk);
    receivedPayload = JSON.parse(Buffer.concat(chunks).toString("utf8"));
    await fs.writeFile(path.join(workspace, sourceName), sourceBody, "utf8");
    response.writeHead(200, { "content-type": "text/plain" });
    response.end("imported");
  });
  const cphNgPort = await listen(cphNg, "::1");
  const bridge = createBridgeServer({
    workspaceRoot: workspace,
    cphNgHost: "::1",
    listenPort: 0,
    cphNgPort,
    logger: { info() {}, warn() {}, error() {} },
  });
  t.after(async () => {
    await new Promise((resolve) => bridge.close(resolve));
    await new Promise((resolve) => cphNg.close(resolve));
    await fs.rm(workspace, { recursive: true, force: true });
  });
  const bridgePort = await listen(bridge);

  const result = await post(bridgePort, problem);
  const sampleDir = path.join(workspace, "cph", path.basename(sourceName, ".cpp"));

  assert.equal(result.statusCode, 200);
  assert.equal(result.body, "imported");
  assert.deepEqual(receivedPayload, problem);
  assert.equal(
    await fs.readFile(path.join(sampleDir, path.basename(sourceName, ".cpp") + "_1.in"), "utf8"),
    "1 2\n",
  );
  assert.equal(
    await fs.readFile(path.join(sampleDir, path.basename(sourceName, ".cpp") + "_1.ans"), "utf8"),
    "3\n",
  );
  assert.equal(await fs.readFile(path.join(sampleDir, "input.txt"), "utf8"), "1 2\n");
  assert.equal(await fs.readFile(path.join(sampleDir, "expected.txt"), "utf8"), "3\n");
  assert.equal(await fs.readFile(path.join(sampleDir, "output.txt"), "utf8"), "");
  assert.deepEqual(JSON.parse(await fs.readFile(path.join(sampleDir, "problem.json"), "utf8")), problem);

  const generatedSource = await fs.readFile(path.join(workspace, sourceName), "utf8");
  assert.ok(generatedSource.startsWith("//  Author: Tangyixiao\r\n"));
  assert.ok(generatedSource.includes("//  Problem: B4463 [海淀区入门组 2025] 素数和回文数\r\n"));
  assert.ok(generatedSource.includes("//  Contest: 海淀区入门组 2025\r\n"));
  assert.ok(generatedSource.includes("//  Memory Limit: 256 MB\r\n"));
  assert.ok(generatedSource.includes("//  Time Limit: 1000 ms\r\n"));
  assert.ok(generatedSource.includes("//  Interactive: false\r\n"));
  assert.ok(generatedSource.includes("//  Powered by Visual Studio Code + CPH (Competitive Programming Helper)\r\n"));
  assert.ok(generatedSource.endsWith(sourceBody));
});

test("header leaves unavailable resource limits blank without dangling units", () => {
  const header = buildHeader(
    {
      name: "Legacy problem",
      group: "",
      url: "",
      memoryLimit: null,
      timeLimit: null,
      interactive: null,
      testType: "",
    },
    new Date(2026, 8, 24, 12, 0, 0),
  );
  const memoryLine = header.split("\n").find((line) => line.startsWith("//  Memory Limit:"));
  const timeLine = header.split("\n").find((line) => line.startsWith("//  Time Limit:"));

  assert.equal(memoryLine, "//  Memory Limit:");
  assert.equal(timeLine, "//  Time Limit:");
});
