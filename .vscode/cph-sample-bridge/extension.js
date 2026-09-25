const vscode = require("vscode");
const { createBridgeServer } = require("./bridge");

let outputChannel;
let server;

function activate(context) {
  outputChannel = vscode.window.createOutputChannel("CPH Sample Bridge");
  context.subscriptions.push(outputChannel);

  const workspaceFolder = vscode.workspace.workspaceFolders?.[0];
  if (!workspaceFolder) {
    outputChannel.appendLine("No workspace is open; the import bridge was not started.");
    return;
  }

  if ((vscode.workspace.workspaceFolders || []).length > 1) {
    outputChannel.appendLine(
      "Multiple workspace folders are open; samples will use the first folder, matching the current CPH path script.",
    );
  }

  const configuration = vscode.workspace.getConfiguration("cphSampleBridge");
  const listenPort = configuration.get("listenPort", 27121);
  const cphNgHost = configuration.get("cphNgHost", "::1");
  const cphNgPort = configuration.get("cphNgPort", 27122);

  server = createBridgeServer({
    workspaceRoot: workspaceFolder.uri.fsPath,
    cphNgHost,
    cphNgPort,
    logger: {
      info: (message) => outputChannel.appendLine(message),
      warn: (message, error) =>
        outputChannel.appendLine(`${message}${error ? `: ${error.message}` : ""}`),
      error: (message, error) =>
        outputChannel.appendLine(`${message}${error ? `: ${error.message}` : ""}`),
    },
  });

  server.on("listening", () =>
    outputChannel.appendLine(
      `Listening on loopback port ${listenPort}; forwarding imports to CPH-NG at [${cphNgHost}]:${cphNgPort}.`,
    ),
  );
  server.on("error", (error) =>
    outputChannel.appendLine(`Could not start the import bridge: ${error.message}`),
  );
  server.listen(listenPort);

  context.subscriptions.push({
    dispose: () => {
      if (server?.listening) server.close();
    },
  });
}

function deactivate() {
  if (server?.listening) server.close();
}

module.exports = { activate, deactivate };
