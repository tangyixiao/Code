import tkinter as tk
from tkinter import messagebox, filedialog, ttk
import requests
import json
import re
import os
import subprocess
import sys
import threading
import random
import time
from urllib.parse import urlparse
 
class BilibiliDownloader:
    def __init__(self, master):
        self.master = master
        master.title("Bilibili视频下载器")
        master.geometry("750x560")
        master.resizable(False, False)
 
        # 常量定义
        self.FFMPEG_PATH = r'.\ffmpeg.exe'
        self.ILLEGAL_CHARS = r'[<>:"/\\|?*\x00-\x1F]'
        
        # 请求头
##        self.headers = {
##            'referer': 'https://www.bilibili.com/',
##            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36'
##        }
 
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
            'Referer': 'https://www.bilibili.com/',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
            'Accept-Language': 'zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3',
        }
 
        # 创建UI组件
        self.create_widgets()
 
    def create_widgets(self):
        # 顶部Frame
        top_frame = tk.Frame(self.master)
        top_frame.pack(fill=tk.X, padx=10, pady=(20,5))
 
        # URL输入区域
        tk.Label(top_frame, text="请输入B站视频URL:").pack()
        # 创建一个子Frame来容纳输入框和按钮
        url_frame = tk.Frame(top_frame)
        url_frame.pack(fill=tk.X, pady=5)
 
        # URL输入框（宽度调整为70，给按钮留空间）
        self.url_entry = tk.Entry(url_frame, width=70)
        self.url_entry.pack(side=tk.LEFT, expand=True, fill=tk.X, padx=(0, 5))
 
        # 清除按钮
        clear_btn = tk.Button(url_frame, text="清除", command=self.clear_url)
        clear_btn.pack(side=tk.RIGHT)
 
        # 添加合并音视频编码模式选择
        encode_frame = tk.LabelFrame(self.master, text="合并音视频编码模式选择", padx=10, pady=5)
        encode_frame.pack(pady=10, fill='x', padx=10)
 
        # 创建一个Frame来容纳单选按钮
        radio_frame = tk.Frame(encode_frame)
        radio_frame.pack(pady=5)
 
        self.encode_mode = tk.StringVar(value="fast")
        tk.Radiobutton(radio_frame, text="较快（不支持HEVC）", variable=self.encode_mode, 
                       value="fast").pack(side='left', padx=30)
        tk.Radiobutton(radio_frame, text="兼容模式（较慢，支持HEVC）", variable=self.encode_mode, 
                       value="compatible").pack(side='left', padx=30)
 
        # 中部Frame
        mid_frame = tk.Frame(self.master)
        mid_frame.pack(fill=tk.X, padx=10, pady=5)
 
        # 选择保存路径按钮
        path_frame = tk.Frame(mid_frame)
        path_frame.pack(fill=tk.X, pady=5)
        tk.Button(path_frame, text="选择保存路径", command=self.choose_save_directory).pack(side=tk.LEFT)
        self.save_path_var = tk.StringVar(value=os.path.join(os.path.expanduser("~"), "Downloads"))
        tk.Label(path_frame, textvariable=self.save_path_var).pack(side=tk.LEFT, padx=5)
 
        # 下载按钮
        self.download_btn = tk.Button(mid_frame, text="开始下载", command=self.start_download)
        self.download_btn.pack(pady=10)
 
        # 进度条
        self.progress_var = tk.DoubleVar()
        self.progress_bar = ttk.Progressbar(
            self.master,
            variable=self.progress_var,
            maximum=100,
            mode='determinate'
        )
        self.progress_bar.pack(fill=tk.X, padx=10, pady=5)
 
        # 创建一个Frame来容纳文本框和滚动条
        text_frame = tk.Frame(self.master)
        text_frame.pack(pady=10, fill=tk.BOTH, expand=True)
 
        # 先创建滚动条
        scrollbar = tk.Scrollbar(text_frame)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
 
        # 创建文本框并设置滚动条
        self.status_text = tk.Text(text_frame, height=12, width=60)
        self.status_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
 
        # 将文本框和滚动条关联
        self.status_text.config(yscrollcommand=scrollbar.set)
        scrollbar.config(command=self.status_text.yview)
 
    def clear_url(self):
        """清空URL输入框"""
        self.url_entry.delete(0, tk.END)
    
    def choose_save_directory(self):
        directory = filedialog.askdirectory()
        if directory:
            self.save_path_var.set(directory)
 
    def log_message(self, message):
        self.status_text.insert(tk.END, message + "\n")
        self.status_text.see(tk.END)
        self.master.update_idletasks()
 
    def clean_filename(self, filename):
        """清理文件名中的非法字符"""
        return re.sub(self.ILLEGAL_CHARS, '_', filename).strip()
 
    def random_delay(self):
        """随机延时，避免反爬"""
        time.sleep(random.uniform(0.5, 2))
 
    def getResponse(self, url):
        """获取url响应体（带重试机制）"""
        max_retries = 3
        for i in range(max_retries):
            try:
                self.random_delay()  # 随机延时
                response = requests.get(url=url, headers=self.headers, timeout=20)
                if response.status_code == 403:
                    raise RuntimeError("访问被拒绝，请稍后重试")
                response.raise_for_status()
                return response
            except requests.Timeout:
                if i == max_retries - 1:
                    raise RuntimeError("请求超时，请检查网络连接")
            except requests.RequestException as e:
                if i == max_retries - 1:
                    raise RuntimeError(f"网络请求失败: {str(e)}")
            self.log_message(f"[!] 第{i+1}次重试...")
        raise RuntimeError("连接失败")
 
    def download_with_progress(self, url, desc="下载中"):
        """带进度条的下载"""
        response = requests.get(url, headers=self.headers, stream=True)
        total = int(response.headers.get('content-length', 0))
        block_size = 1024  # 1 KB
        downloaded = 0
        
        content = bytearray()
        for data in response.iter_content(block_size):
            downloaded += len(data)
            content.extend(data)
            if total:
                progress = (downloaded / total) * 100
                self.progress_var.set(progress)
                self.master.update_idletasks()
                
        return bytes(content)
 
    def parseResponse(self, url):
        """解析响应体"""
        try:
            if 'bilibili.com' not in urlparse(url).netloc:
                raise ValueError("非B站视频链接")
 
            response = self.getResponse(url)
            html_text = response.text
 
            # 1. 提取视频信息 __playinfo__（支持多行、非贪婪）
            html_data_match = re.search(
                r'<script>window\.__playinfo__=(.*?)</script>',
                html_text,
                re.DOTALL  # 使 . 匹配换行
            )
            if not html_data_match:
                raise ValueError("未找到视频数据")
            
            try:
                jsonData = json.loads(html_data_match.group(1))
            except json.JSONDecodeError:
                raise ValueError("视频数据解析失败")
 
            # 2. 提取标题（更宽松的匹配）
            # 方法一：直接匹配 <title> 标签
            title_match = re.search(r'<title>([^<]+)</title>', html_text)
            if not title_match:
                # 方法二：尝试匹配带属性的 title 标签（兼容旧版）
                title_match = re.search(r'<title[^>]*>([^<]+)</title>', html_text)
            
            if not title_match:
                raise ValueError("未找到视频标题")
            
            raw_title = title_match.group(1)
            # 清理标题，移除常见的后缀 " - 哔哩哔哩" 等
            videoTitle = self.clean_filename(re.sub(r'\s*[-|–]\s*哔哩哔哩.*$', '', raw_title).strip())
            if not videoTitle:
                videoTitle = "bilibili_video"  # 后备默认标题
 
            # 3. 提取音视频流地址
            try:
                audioUrl = jsonData['data']['dash']['audio'][0]['baseUrl']
                videoUrl = jsonData['data']['dash']['video'][0]['baseUrl']
            except (KeyError, IndexError):
                raise ValueError("视频流信息不完整")
 
            return {
                'videoTitle': videoTitle,
                'audioUrl': audioUrl,
                'videoUrl': videoUrl,
            }
        except Exception as e:
            raise RuntimeError(f"解析响应失败: {str(e)}")
 
 
    def saveMedia(self, fileName, url, mediaType):
        """保存媒体文件"""
        try:
            save_dir = self.save_path_var.get()
            os.makedirs(save_dir, exist_ok=True)
            safe_name = f"{self.clean_filename(fileName)}.{mediaType}"
            full_path = os.path.join(save_dir, safe_name)
            
            # 确保路径唯一
            actual_path = self.get_unique_filename(full_path)
            if actual_path != full_path:
                self.log_message(f"[!] 文件已存在，将保存为: {os.path.basename(actual_path)}")
            
            self.log_message(f"[!] 开始下载{mediaType.upper()}...")
            content = self.download_with_progress(url, f"下载{mediaType}")
            
            with open(actual_path, 'wb') as f:
                f.write(content)
            self.log_message(f"[√] {mediaType.upper()}下载完成: {os.path.basename(actual_path)}")
            return actual_path
        except Exception as e:
            raise RuntimeError(f"文件保存失败: {str(e)}")
 
    def AvMerge(self, Mp3Path, Mp4Path, savePath):
        """合并音视频"""
        try:
            if not os.path.isfile(self.FFMPEG_PATH):
                raise FileNotFoundError("FFmpeg路径不存在")
 
            self.log_message("[!] 开始合并音视频...")
            self.progress_var.set(10)
            self.master.update_idletasks()
            
            output_dir = os.path.dirname(savePath)
            filename = os.path.basename(savePath)
            name, ext = os.path.splitext(filename)
            # 生成基础合并路径（带 _merged 后缀）
            base_merged = os.path.join(output_dir, f"{name}_merged{ext}")
            # 确保路径唯一
            actual_merged = self.get_unique_filename(base_merged)
            if actual_merged != base_merged:
                self.log_message(f"[!] 合并文件已存在，将保存为: {os.path.basename(actual_merged)}")
            
            # 设置startupinfo以隐藏控制台窗口
            startupinfo = None
            if sys.platform == 'win32':
                startupinfo = subprocess.STARTUPINFO()
                startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
                startupinfo.wShowWindow = subprocess.SW_HIDE
            
            if self.encode_mode.get() == "fast":
                cmd = [
                    self.FFMPEG_PATH, '-y',
                    '-i', Mp4Path, '-i', Mp3Path,
                    '-c:v', 'copy', '-c:a', 'aac', # copy模式，加快处理速度，但不支持HEVC视频扩展
                    '-strict', 'experimental',
                    actual_merged
                ]
            else:
                cmd = [
                    self.FFMPEG_PATH, '-y',
                    '-i', Mp4Path, '-i', Mp3Path,
                    '-c:v', 'libx264', '-preset', 'medium', # 使用libx264编码器，支持编码器——HEVC视频扩展，但速度慢
                    '-crf', '28', # 控制视频质量，范围0-51，数值越小质量越好
                    '-c:a', 'aac', '-strict', 'experimental',
                    actual_merged
                ]
            
            subprocess.run(cmd, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, startupinfo=startupinfo)
 
            self.progress_var.set(100)
            self.master.update_idletasks()
            self.log_message(f"[√] 合并完成: {os.path.basename(actual_merged)}")
            
            # 清理临时文件
            for path in [Mp3Path, Mp4Path]:
                try:
                    if os.path.exists(path):
                        os.remove(path)
                        self.log_message(f"[!] 已清理临时文件: {os.path.basename(path)}")
                except Exception as e:
                    self.log_message(f"[!] 清理文件失败: {str(e)}")
                    
            return actual_merged
                        
        except Exception as e:
            self.progress_var.set(0)
            self.master.update_idletasks()
            raise RuntimeError(f"合并过程出错: {str(e)}")
 
    # 处理保存路径中同名文件直接被替换问题
    def get_unique_filename(self, filepath):
        """如果文件已存在，自动生成带数字后缀的新路径"""
        if not os.path.exists(filepath):
            return filepath
        directory = os.path.dirname(filepath)
        filename, ext = os.path.splitext(os.path.basename(filepath))
        counter = 1
        while True:
            new_name = f"{filename} ({counter}){ext}"
            new_path = os.path.join(directory, new_name)
            if not os.path.exists(new_path):
                return new_path
            counter += 1
 
 
    def _download_task(self):
        """下载任务的具体实现"""
        try:
            url = self.url_entry.get().strip()
            if not url:
                raise ValueError("请输入视频URL")
            if not url.startswith(('http://', 'https://')):
                raise ValueError("请输入有效的URL地址")
 
            # 禁用下载按钮
            self.download_btn.config(state='disabled')
            
            # 解析视频信息
            videoInfo = self.parseResponse(url)
            base_name = videoInfo['videoTitle']
 
            # 下载音频和视频（每次下载前重置进度条）
            self.progress_var.set(0)
            mp3_path = self.saveMedia(base_name, videoInfo['audioUrl'], 'mp3')
            
            self.progress_var.set(0)
            mp4_path = self.saveMedia(base_name, videoInfo['videoUrl'], 'mp4')
 
            # 合并文件
            output_path = os.path.join(self.save_path_var.get(), f'{base_name}.mp4')
            final_path = self.AvMerge(mp3_path, mp4_path, output_path)
 
            self.log_message(f"[√] 全部操作已完成！\n[√] 保存路径: {final_path}")
            messagebox.showinfo("成功", "视频下载并合并完成！")
 
        except Exception as e:
            self.log_message(f"[X] 错误: {str(e)}")
            messagebox.showerror("错误", str(e))
        finally:
            # 重置进度条
            self.progress_var.set(0)
            # 重新启用下载按钮
            self.download_btn.config(state='normal')
 
    def start_download(self):
        """在新线程中启动下载任务"""
        download_thread = threading.Thread(target=self._download_task)
        download_thread.daemon = True
        download_thread.start()
 
def main():
    root = tk.Tk()
    app = BilibiliDownloader(root)
    root.mainloop()
 
if __name__ == '__main__':
    main()