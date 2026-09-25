# CPH Sample Bridge

This workspace extension accepts Competitive Companion imports on port `27121`, writes the samples to `cph/<source basename>/`, then forwards the original request to CPH-NG at `[::1]:27122`.

Each import creates numbered `.in`/`.ans` files plus `input.txt`, `expected.txt`, `output.txt`, and `problem.json`. It also adds the CP Editor style problem header to the generated C++ source while leaving the template body intact.

Run its focused integration test with:

```powershell
node --test .vscode/cph-sample-bridge/test/bridge.test.js
```
