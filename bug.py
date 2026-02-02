import requests
from bs4 import BeautifulSoup
import time

def fetch_website_source(url):
    """
    爬取网站源代码
    """
    # 设置请求头，模拟浏览器访问
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
        'Connection': 'keep-alive',
    }
    
    try:
        # 发送GET请求
        response = requests.get(url, headers=headers, timeout=10)
        
        # 检查响应状态
        response.raise_for_status()
        
        # 设置编码（根据实际情况调整）
        response.encoding = response.apparent_encoding or 'utf-8'
        
        return response.text
        
    except requests.exceptions.RequestException as e:
        print(f"请求失败: {e}")
        return None

def main():
    # 目标网址
    url = "http://www.sxyz.net"
    
    print(f"正在爬取 {url} ...")
    
    # 获取源代码
    source_code = fetch_website_source(url)
    
    if source_code:
        # 保存到文件
        with open('sxyz_source.html', 'w', encoding='utf-8') as f:
            f.write(source_code)
        print("源代码已保存到 sxyz_source.html")
        
        # 可选：使用BeautifulSoup解析
        soup = BeautifulSoup(source_code, 'html.parser')
        print(f"页面标题: {soup.title.string if soup.title else '无标题'}")
        
        # 显示部分内容（前500字符）
        print("\n前500字符预览:")
        print(source_code[:500])
        
    else:
        print("未能获取源代码")

if __name__ == "__main__":
    main()