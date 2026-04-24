#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import json
import time
import requests
from typing import List, Dict, Optional

class LuoguCrawler:
    """洛谷爬虫类 - 使用官方复制Markdown功能"""
    
    def __init__(self, cookie: Optional[str] = None):
        self.session = requests.Session()
        self.session.headers.update({
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
            'Accept': 'application/json, text/plain, */*',
            'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
            'x-lentille-request': 'content-only',  # 关键：直接获取Markdown原文数据的请求头
            'X-Requested-With': 'XMLHttpRequest',
        })
        if cookie:
            self.session.headers.update({'Cookie': cookie})
    
    def fetch_problem(self, pid: str, save_dir: str = ".") -> Dict:
        """
        爬取题目并保存为Markdown文件（利用官方复制Markdown功能）
        """
        url = f"https://www.luogu.com.cn/problem/{pid}"
        
        # 直接获取JSON格式数据，其中包含了Markdown原文
        resp = self.session.get(url)
        resp.raise_for_status()
        data = resp.json()
        
        # 提取题目核心数据
        problem = data.get('currentData', {}).get('problem')
        if not problem:
            raise ValueError(f"未找到题目 {pid} 的数据")
        
        # 构建Markdown内容，这些字段已经是现成的Markdown格式了
        md_content = self._build_markdown(problem)
        
        os.makedirs(save_dir, exist_ok=True)
        file_path = os.path.join(save_dir, f"{pid}.md")
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(md_content)
        
        print(f"[题目] {pid} 已保存至 {file_path}")
        return problem
    
    def _build_markdown(self, problem: Dict) -> str:
        """将JSON数据转换为格式化的Markdown文档"""
        md_parts = []
        
        # 标题
        md_parts.append(f"# {problem.get('title', '无标题')}\n")
        
        # 背景、描述、输入输出格式等
        for section, title in [
            ('background', '## 题目背景'),
            ('description', '## 题目描述'),
            ('inputFormat', '## 输入格式'),
            ('outputFormat', '## 输出格式')
        ]:
            content = problem.get(section, '')
            if content and content.strip():
                md_parts.append(f"{title}\n\n{content}\n")
        
        # 处理样例
        samples = problem.get('samples', [])
        if samples:
            md_parts.append("## 输入输出样例\n")
            for i, sample in enumerate(samples, 1):
                md_parts.append(f"### 样例 #{i}\n")
                if 'in' in sample and sample['in'].strip():
                    md_parts.append(f"**输入**\n```\n{sample['in'].strip()}\n```\n")
                if 'out' in sample and sample['out'].strip():
                    md_parts.append(f"**输出**\n```\n{sample['out'].strip()}\n```\n")
        
        # 提示信息
        hint = problem.get('hint', '')
        if hint and hint.strip():
            md_parts.append(f"## 提示\n\n{hint}\n")
        
        # 数据范围与限制
        limits = problem.get('limit', {})
        md_parts.append("## 数据范围与限制\n")
        md_parts.append(f"- 时间限制：{limits.get('time', '未知')} ms\n")
        md_parts.append(f"- 内存限制：{limits.get('memory', '未知')} MB\n")
        
        return "\n".join(md_parts)
    
    def fetch_solutions(self, pid: str, save_dir: str = "."):
        """
        爬取题目所有题解并合并为单个Markdown文件
        """
        all_solutions = []
        page = 1
        
        while True:
            api_url = f"https://www.luogu.com.cn/api/problem/solution/{pid}?page={page}"
            headers = {'Referer': f'https://www.luogu.com.cn/problem/solution/{pid}'}
            resp = self.session.get(api_url, headers=headers)
            
            if resp.status_code != 200:
                print(f"[题解] {pid} 第 {page} 页请求失败 (HTTP {resp.status_code})")
                break
                
            data = resp.json()
            if data.get('code') != 200:
                print(f"[题解] {pid} API返回错误: {data.get('message')}")
                break
                
            solutions = data.get('data', [])
            if not solutions:
                break
                
            all_solutions.extend(solutions)
            total = data.get('total', 0)
            if len(all_solutions) >= total:
                break
                
            page += 1
            time.sleep(1)  # 礼貌性的延迟，避免请求过快
            
        if not all_solutions:
            print(f"[题解] {pid} 未找到任何题解")
            return
            
        # 合并所有题解
        merged_md = self._merge_solutions(all_solutions, pid)
        
        os.makedirs(save_dir, exist_ok=True)
        file_path = os.path.join(save_dir, f"{pid}_solution.md")
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(merged_md)
            
        print(f"[题解] {pid} 共 {len(all_solutions)} 篇题解，已合并保存至 {file_path}")
    
    def _merge_solutions(self, solutions: List[Dict], pid: str) -> str:
        """合并多个题解为一个Markdown文档"""
        md_parts = [f"# {pid} 题解汇总\n\n"]
        
        for idx, solution in enumerate(solutions, 1):
            # 提取题解信息
            title = solution.get('title', f'题解 {idx}')
            author = solution.get('author', {}).get('name', '未知')
            time_str = solution.get('time', '')
            content = solution.get('content', '')
            
            # 添加题解内容
            md_parts.append(f"## {title}\n\n")
            md_parts.append(f"**作者**：{author}  \n")
            if time_str:
                md_parts.append(f"**发布时间**：{time_str}  \n")
            md_parts.append("\n")
            
            if content:
                md_parts.append(content + "\n\n")
            else:
                md_parts.append("*该题解无正文内容*\n\n")
                
            md_parts.append("---\n\n")
            
        return "".join(md_parts)

def main():
    import sys
    if len(sys.argv) < 2:
        print("用法: python luogu_crawler.py <题目ID1> [题目ID2] ...")
        print("示例: python luogu_crawler.py P1000 P1001 1002")
        sys.exit(1)
    
    crawler = LuoguCrawler()
    
    for arg in sys.argv[1:]:
        # 自动补全'P'前缀（如果输入为纯数字）
        pid = f"P{arg}" if arg.isdigit() else arg
        print(f"\n正在处理 {pid} ...")
        
        try:
            # 爬取题目详情
            crawler.fetch_problem(pid)
            # 爬取并合并所有题解
            crawler.fetch_solutions(pid)
        except Exception as e:
            print(f"处理 {pid} 时出错: {e}")

if __name__ == "__main__":
    main()