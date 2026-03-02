// ==UserScript==
// @name         洛谷一键跳转VJudge（增强版）
// @namespace    http://tampermonkey.net/
// @version      1.1.0
// @description  洛谷题目页自动添加“跳转VJudge”按钮，修复CF带数字后缀匹配，增强SPOJ识别及按钮等待机制
// @author       Tangyixao
// @match        https://www.luogu.com.cn/problem/CF*
// @match        https://www.luogu.com.cn/problem/SP*
// @match        https://www.luogu.com.cn/problem/AT*
// @match        https://www.luogu.com.cn/problem/UVA*
// @match        https://www.luogu.com.cn/problem/P*
// @match        https://www.luogu.com.cn/problem/B*
// @grant        none
// ==/UserScript==

(function () {
  "use strict";

  // 最大尝试次数（避免无限循环）
  const MAX_RETRIES = 10;
  const RETRY_INTERVAL = 500; // 毫秒

  /**
   * 获取 VJudge 跳转链接
   * @returns {string|null}
   */
  function getVjudgeUrl() {
    const luoguPath = window.location.pathname;
    const consolePrefix = "[洛谷跳转VJudge]";

    // 洛谷 P 开头题目
    if (luoguPath.startsWith("/problem/P")) {
      const pMatch = luoguPath.match(/P(\d+)/);
      if (pMatch) {
        console.log(consolePrefix, "识别到洛谷P题，ID:", pMatch[1]);
        return `https://vjudge.net/problem/洛谷-P${pMatch[1]}`;
      }
    }
    // 洛谷 B 开头题目
    else if (luoguPath.startsWith("/problem/B")) {
      const bMatch = luoguPath.match(/B(\d+)/);
      if (bMatch) {
        console.log(consolePrefix, "识别到洛谷B题，ID:", bMatch[1]);
        return `https://vjudge.net/problem/洛谷-B${bMatch[1]}`;
      }
    }
    // AtCoder 题目 (AT_xxxx)
    else if (luoguPath.startsWith("/problem/AT_")) {
      const atMatch = luoguPath.match(/AT_(\w+)/);
      if (atMatch) {
        console.log(consolePrefix, "识别到AtCoder题，ID:", atMatch[1]);
        return `https://vjudge.net/problem/AtCoder-${atMatch[1]}`;
      }
    }
    // UVA 题目
    else if (luoguPath.startsWith("/problem/UVA")) {
      const uvaMatch = luoguPath.match(/UVA(\d+)/);
      if (uvaMatch) {
        console.log(consolePrefix, "识别到UVA题，ID:", uvaMatch[1]);
        return `https://vjudge.net/problem/UVA-${uvaMatch[1]}`;
      }
    }
    // Codeforces 题目 (CFxxxx)
    else if (luoguPath.startsWith("/problem/CF")) {
      const cfMatch = luoguPath.match(/CF(\d+[A-Za-z\d]*)/);
      if (cfMatch) {
        console.log(consolePrefix, "识别到CF题，ID:", cfMatch[1]);
        return `https://vjudge.net/problem/CodeForces-${cfMatch[1]}`;
      }
    }
    // SPOJ 题目 (SPxxxx)
    else if (luoguPath.startsWith("/problem/SP")) {
      let spojId = null;
      // 方法1：从页面中寻找指向 spoj.com 的原始链接
      const originalLink = document.querySelector(
        'a[href*="spoj.com/problems/"]',
      );
      if (originalLink) {
        const parts = originalLink.href.split("/problems/");
        if (parts.length > 1) {
          spojId = parts[1].replace("/", "");
        }
      }
      // 方法2：从页面文本中匹配 SPOJ 题号（正则放宽）
      if (!spojId) {
        const pageText = document.body.innerText;
        const spojTextMatch = pageText.match(
          /SPOJ\s*[:\-]?\s*([A-Za-z0-9_\-]+)/i,
        );
        if (spojTextMatch) {
          spojId = spojTextMatch[1].trim();
        }
      }
      // 方法3：直接从 URL 中提取 SP 后面的部分作为备选（可能不准确，但作为 fallback）
      if (!spojId) {
        const spFallback = luoguPath.match(/\/problem\/(SP.+)/);
        if (spFallback) {
          // 去掉开头的 "SP"，保留后续字符
          const raw = spFallback[1].substring(2); // 移除 "SP"
          if (raw) {
            spojId = raw;
            console.warn(consolePrefix, "使用URL备选ID，请验证准确性:", spojId);
          }
        }
      }

      if (spojId) {
        console.log(consolePrefix, "识别到SPOJ题，ID:", spojId);
        return `https://vjudge.net/problem/SPOJ-${spojId}`;
      } else {
        console.warn(consolePrefix, "未能提取到SPOJ题目标识符");
      }
    }

    return null;
  }

  /**
   * 查找“复制题目”按钮（容错匹配）
   * @returns {HTMLElement|null}
   */
  function findCopyButton() {
    // 洛谷的复制题目按钮通常文本包含“复制”，且不是“复制代码”
    const buttons = document.querySelectorAll("button");
    for (let btn of buttons) {
      const text = btn.innerText.trim();
      if (text.includes("复制") && !text.includes("代码")) {
        return btn;
      }
    }
    return null;
  }

  /**
   * 插入跳转按钮
   * @param {HTMLElement} copyBtn
   */
  function insertJumpButton(copyBtn) {
    const vjudgeUrl = getVjudgeUrl();
    if (!vjudgeUrl) {
      console.warn("[洛谷跳转VJudge] 未生成有效跳转链接，请检查页面格式");
      return;
    }

    // 创建跳转按钮
    const jumpBtn = document.createElement("button");
    jumpBtn.innerText = "跳转VJudge";

    // 复制原始按钮样式
    const copyStyles = window.getComputedStyle(copyBtn);
    const styleProps = [
      "backgroundColor",
      "color",
      "border",
      "borderRadius",
      "padding",
      "fontSize",
      "fontFamily",
      "cursor",
      "height",
      "lineHeight",
      "textAlign",
      "whiteSpace",
      "verticalAlign",
      "display",
      "marginTop",
      "marginBottom",
    ];
    styleProps.forEach((prop) => {
      jumpBtn.style[prop] = copyStyles[prop];
    });

    // 微调
    jumpBtn.style.marginLeft = "5px";
    jumpBtn.style.minWidth = copyStyles.minWidth || "80px";

    jumpBtn.addEventListener("click", () => {
      window.open(vjudgeUrl, "_blank");
    });

    // 插入到复制按钮后面
    copyBtn.parentNode.insertBefore(jumpBtn, copyBtn.nextSibling);
    console.log("[洛谷跳转VJudge] 跳转按钮已添加，目标:", vjudgeUrl);
  }

  /**
   * 等待复制按钮出现（轮询）
   * @param {number} retries
   */
  function waitForCopyButton(retries = 0) {
    if (retries > MAX_RETRIES) {
      console.warn("[洛谷跳转VJudge] 超过最大重试次数，未找到复制按钮");
      return;
    }

    const copyBtn = findCopyButton();
    if (copyBtn) {
      insertJumpButton(copyBtn);
    } else {
      setTimeout(() => waitForCopyButton(retries + 1), RETRY_INTERVAL);
    }
  }

  // 启动等待
  waitForCopyButton();
})();
