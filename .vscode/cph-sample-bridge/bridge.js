const http = require("node:http");
const {
  addHeaderToSource,
  writeProblemSamples,
} = require("./sample-writer");

const MAX_BODY_BYTES = 16 * 1024 * 1024;
const HOP_BY_HOP_HEADERS = new Set([
  "connection",
  "keep-alive",
  "proxy-authenticate",
  "proxy-authorization",
  "te",
  "trailers",
  "transfer-encoding",
  "upgrade",
]);

function readBody(request) {
  return new Promise((resolve, reject) => {
    const chunks = [];
    let size = 0;
    request.on("data", (chunk) => {
      size += chunk.length;
      if (size > MAX_BODY_BYTES) {
        reject(Object.assign(new Error("Request body is too large"), { statusCode: 413 }));
        request.destroy();
        return;
      }
      chunks.push(chunk);
    });
    request.on("end", () => resolve(Buffer.concat(chunks)));
    request.on("error", reject);
  });
}

function asProblems(payload) {
  if (Array.isArray(payload)) return payload;
  if (payload && Array.isArray(payload.problems)) return payload.problems;
  if (payload && payload.problem && typeof payload.problem === "object") {
    return [payload.problem];
  }
  return payload && typeof payload === "object" ? [payload] : [];
}

function forwardRequest(request, body, cphNgHost, cphNgPort) {
  return new Promise((resolve, reject) => {
    const headers = { ...request.headers };
    headers.host = cphNgHost.includes(":")
      ? `[${cphNgHost}]:${cphNgPort}`
      : `${cphNgHost}:${cphNgPort}`;
    headers["content-length"] = Buffer.byteLength(body);

    const upstream = http.request(
      {
        hostname: cphNgHost,
        port: cphNgPort,
        method: request.method,
        path: request.url || "/",
        headers,
      },
      (response) => {
        const chunks = [];
        response.on("data", (chunk) => chunks.push(chunk));
        response.on("end", () =>
          resolve({
            statusCode: response.statusCode || 502,
            headers: response.headers,
            body: Buffer.concat(chunks),
          }),
        );
        response.on("error", reject);
      },
    );
    upstream.on("error", reject);
    upstream.end(body);
  });
}

function writeResponse(response, result) {
  const headers = {};
  for (const [name, value] of Object.entries(result.headers || {})) {
    if (!HOP_BY_HOP_HEADERS.has(name.toLowerCase()) && value !== undefined) {
      headers[name] = value;
    }
  }
  headers["content-length"] = result.body.length;
  response.writeHead(result.statusCode, headers);
  response.end(result.body);
}

function createBridgeServer(options) {
  const {
    workspaceRoot,
    cphNgHost = "::1",
    cphNgPort,
    logger = console,
  } = options;

  return http.createServer(async (request, response) => {
    if (request.method === "OPTIONS") {
      response.writeHead(204, {
        "access-control-allow-methods": "POST, OPTIONS",
        "access-control-allow-origin": "*",
      });
      response.end();
      return;
    }

    if (request.method === "GET") {
      response.writeHead(200, { "content-type": "text/plain; charset=utf-8" });
      response.end("CPH sample bridge is ready");
      return;
    }

    if (request.method !== "POST") {
      response.writeHead(405, { allow: "GET, POST, OPTIONS" });
      response.end();
      return;
    }

    let payload;
    let body;
    let problems;
    let sampleResults;
    try {
      body = await readBody(request);
      payload = JSON.parse(body.toString("utf8"));
      problems = asProblems(payload);
      sampleResults = [];
      for (const problem of problems) {
        if (!problem || typeof problem !== "object") continue;
        sampleResults.push({
          problem,
          result: await writeProblemSamples(workspaceRoot, problem),
        });
      }
    } catch (error) {
      const statusCode = error.statusCode || 400;
      logger.error("CPH sample import failed before forwarding", error);
      response.writeHead(statusCode, { "content-type": "text/plain; charset=utf-8" });
      response.end(error.message || "Invalid Competitive Companion payload");
      return;
    }

    let upstream;
    try {
      upstream = await forwardRequest(request, body, cphNgHost, cphNgPort);
    } catch (error) {
      logger.error(`Could not forward Competitive Companion import to CPH-NG on ${cphNgPort}`, error);
      response.writeHead(502, { "content-type": "text/plain; charset=utf-8" });
      response.end(`Could not connect to CPH-NG at ${cphNgHost}:${cphNgPort}`);
      return;
    }

    if (upstream.statusCode >= 200 && upstream.statusCode < 300) {
      for (const { problem, result } of sampleResults) {
        try {
          await addHeaderToSource(result.sourcePath, problem);
        } catch (error) {
          logger.warn("Could not add the problem header to the generated source", error);
        }
      }
    }

    writeResponse(response, upstream);
  });
}

module.exports = { createBridgeServer };
