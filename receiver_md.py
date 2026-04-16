import json
import os
from http.server import BaseHTTPRequestHandler, HTTPServer
from datetime import datetime

# --- 配置信息，请根据你的需要修改 ---
# 你的VSCode工作区路径，题目文件会保存在这个目录下
WORKSPACE_PATH = r"D:\\Code\\"  # 例如: r"C:\Users\你的用户名\Documents\OJ"
# -----------------------------------

def save_problem_as_md(problem_data):
    """将题目数据保存为Markdown文件"""
    name = problem_data.get('name', 'Untitled')
    # 清理文件名中不合法的字符
    safe_name = "".join(c for c in name if c.isalnum() or c in (' ', '.', '-', '_')).rstrip()
    filename = os.path.join(WORKSPACE_PATH, f"{safe_name}.md")
    
    # 确保工作区目录存在
    os.makedirs(WORKSPACE_PATH, exist_ok=True)
    
    # 构建Markdown内容
    md_content = f"""# {name}

## 基本信息
- **URL**: {problem_data.get('url', '')}
- **时间限制**: {problem_data.get('timeLimit', 0)} sec
- **内存限制**: {problem_data.get('memoryLimit', 0)} MB

## 题目描述
{problem_data.get('description', '')}

## 输入格式
{problem_data.get('input', '')}

## 输出格式
{problem_data.get('output', '')}

## 示例测试用例
"""
    # 添加测试用例
    tests = problem_data.get('tests', [])
    if tests:
        for i, test in enumerate(tests, 1):
            md_content += f"""
### 示例 {i}
**输入**:
```text
{test.get('input', '')}
```
**输出**:
```text
{test.get('output', '')}
```
"""
    else:
        md_content += "\n*无测试用例*\n"
    
    # 写入文件
    try:
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(md_content)
        print(f"[INFO] 题目已保存为: {filename}")
    except Exception as e:
        print(f"[ERROR] 保存文件失败: {e}")

class ProblemHandler(BaseHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        try:
            problem = json.loads(post_data.decode('utf-8'))
            print(f"\n[RECV] 收到题目: {problem.get('name', 'N/A')}")
            save_problem_as_md(problem)
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b'OK')
        except Exception as e:
            print(f"[ERROR] 处理失败: {e}")
            self.send_response(500)
            self.end_headers()

if __name__ == '__main__':
    if not os.path.exists(WORKSPACE_PATH):
        os.makedirs(WORKSPACE_PATH)
        print(f"[INFO] 已创建目录: {WORKSPACE_PATH}")
    server = HTTPServer(('localhost', 12345), ProblemHandler)
    print(f"服务器已启动，监听端口 12345...\n题目Markdown文件将保存到: {WORKSPACE_PATH}")
    server.serve_forever()
