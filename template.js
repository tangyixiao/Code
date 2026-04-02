const process = async () => {
  if (!workspaceFolders || workspaceFolders.length === 0) {
    return "No workspace folder found";
  }
  const folder = workspaceFolders[0].path;
  const ext = "cpp";
  const results = [];

  for (const problem of problems) {
    try {
      const { name, url } = problem;
      let fullId = ""; // 最终用于文件名的编号部分

      if (url) {
        try {
          const u = new URL(url);
          const isHost = (host) =>
            u.hostname === host || u.hostname.endsWith(`.${host}`);

          // ----- Codeforces -----
          if (isHost("codeforces.com")) {
            const regexPatterns = [
              /\/contest\/(\d+)\/problem\/(\w+)/,
              /\/problemset\/problem\/(\d+)\/(\w+)/,
              /\/gym\/(\d+)\/problem\/(\w+)/,
            ];
            for (const regex of regexPatterns) {
              const match = url.match(regex);
              if (match) {
                fullId = `CF${match[1]}${match[2]}`;
                break;
              }
            }
          }

          // ----- Luogu -----
          if (!fullId && isHost("luogu.com.cn")) {
            const match = url.match(/problem\/(\w+)/);
            if (match) {
              fullId = match[1]; // 如 P1301, B4273, U275307
            }
          }

          // ----- AtCoder -----
          if (!fullId && isHost("atcoder.jp")) {
            const match = url.match(/tasks\/(\w+)_(\w+)/);
            if (match) {
              const contest = match[1].toUpperCase();
              const problemLetter = match[2].toUpperCase();
              fullId = `${contest}${problemLetter}`; // ABC123A
            }
          }

          // ----- POJ -----
          if (!fullId && isHost("poj.org")) {
            const match = url.match(/[?&]id=(\d+)/);
            if (match) {
              fullId = `POJ${match[1]}`;
            }
          }

          // ----- UVA -----
          if (
            !fullId &&
            (isHost("uva.onlinejudge.org") || isHost("onlinejudge.org"))
          ) {
            const match = url.match(/\/problem\/(\d+)/);
            if (match) {
              fullId = `UVA${match[1]}`;
            }
          }

          // 可继续扩展其他平台...
        } catch (e) {
          logger.error("URL Parsing error:", e.message);
        }
      }

      // 如果未能从 URL 提取到编号，则尝试从题目名称中提取数字作为后备
      if (!fullId) {
        const numMatch = name.match(/\d+/);
        if (numMatch) {
          fullId = numMatch[0];
        }
      }

      // 清理题目名称中的非法文件名字符
      let cleanName = name.replace(/[<>:"/\\|?*]/g, "_");

      // ---- 针对 Codeforces 去除开头的 "A." 等前缀 ----
      if (fullId.startsWith("CF") && fullId.length > 2) {
        const lastChar = fullId[fullId.length - 1];
        const prefixMatch = cleanName.match(/^([A-Za-z])\.\s*/);
        if (
          prefixMatch &&
          prefixMatch[1].toUpperCase() === lastChar.toUpperCase()
        ) {
          cleanName = cleanName.substring(prefixMatch[0].length);
        }
      }

      // 如果 cleanName 以 fullId 开头（可能后面有空格、点、短横等），则去掉这部分前缀
      if (fullId && cleanName.startsWith(fullId)) {
        let rest = cleanName.substring(fullId.length);
        rest = rest.replace(/^[\s\.\-_]+/, "");
        if (rest.length > 0) {
          cleanName = rest;
        }
      }

      // 构建最终文件名
      let filename;
      if (fullId) {
        filename = cleanName
          ? `${fullId} ${cleanName}.${ext}`
          : `${fullId}.${ext}`;
      } else {
        filename = `${cleanName}.${ext}`;
      }

      results.push(path.join(folder, filename));
    } catch (e) {
      logger.error("Error generating filename for problem", e.message || e);
      results.push(null);
    }
  }

  return results;
};
