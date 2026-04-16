# receiver.py
from http.server import BaseHTTPRequestHandler, HTTPServer
import json

class Handler(BaseHTTPRequestHandler):
    def do_POST(self):
        length = int(self.headers['Content-Length'])
        data = json.loads(self.rfile.read(length).decode())
        print(f"\n收到题目: {data.get('name', '未知')}")
        print(f"时间限制: {data.get('timeLimit', 'N/A')} sec")
        print(f"内存限制: {data.get('memoryLimit', 'N/A')} MB")
        print(f"测试用例数: {len(data.get('tests', []))}")
        for i, test in enumerate(data.get('tests', [])):
            print(f"\n测试用例 {i+1}:")
            print(f"输入:\n{test.get('input', '')[:200]}...")
            print(f"输出:\n{test.get('output', '')[:200]}...")
        self.send_response(200)
        self.end_headers()

if __name__ == '__main__':
    server = HTTPServer(('localhost', 12345), Handler)
    print("本地接收服务器已启动，监听端口 12345")
    server.serve_forever()