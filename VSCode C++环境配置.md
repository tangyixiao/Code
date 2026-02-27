# Windows

这里的 Windows 版本默认你是 Windows 8.1 64 位及以上，若是 Windows 7 请自行安装兼容器或兼容版本。

## VSCode 安装
[官网](https://code.visualstudio.com/)

![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241413387.png)

都选下一步，安装路径可以选择到其他的文件夹（尽量不要有中文），勾选"添加到PATH"选项

## 插件安装

### 1. C/C++、中文等
![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241357820.png)

注：中文安装后需重启VSCode窗口才能展示中文。
### 2. CMake、Code Runner等
![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241357678.png)
## 3. CPH（非必须）
![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241355373.png)

## MinGW 安装

不要用sourceforge上的，那个太老了！

[官网的地址](https://www.mingw-w64.org/)

[github 链接 下载 x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0](https://github.com/niXman/mingw-builds-binaries/releases)

[百度网盘](https://pan.baidu.com/s/1gA1D1NhC90VBAPVGFTHhxA?pwd=ccr1)

设置环境变量，在path中添加bin的路径

![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241403189.png)

![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241405223.png)

记下这个路径，不一定要像我一样装在D盘。

---

这里 msys2 Windows 7 也可以装。


或者还有一种方法，去 [msys2](https://www.msys2.org/) 官网下载[安装包](https://github.com/msys2/msys2-installer/releases/download/2025-12-13/msys2-x86_64-20251213.exe)，注意官网的安装包地址也是在 github 上的，如果下不了检查网络原因。

下载完成后，打开运行程序，有个是添加路径，建议添加到非系统盘，如果你想要断网安装的话请在开始安装前就断网，这样子比较快；如果你想联网安装的话你就可以在后台运行这个程序半个小时到一个小时不等，直到安装完成。

安装完成要勾选 Run MSYS2 或运行 MSYS2，或者再开始菜单运行 MSYS2，然后在终端中输入以下命令安装所有工具包：

```bash
pacman -Syu
pacman -Su
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```

按回车，输入 `y` 确认安装。

按照以上步骤，添加用户和系统环境变量，如：`D:\msys64\ucrt64\bin` 和 `D:\msys64\mingw64\bin` 。

## 验证


在cmd命令提示符窗口中输入`gcc -v`，`g++ -v` 和 `gdb -v` 查看版本。

出现类似于一下界面说明成功：
![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241411038.png)

下载后非中文的文件已经可以运行了，注意要在终端中的 gdb 进行调试。

## C++ 环境配置（非必须）

这一步主要用于含有中文的文件的调试与运行。

打开VSCode，在你所打开的文件夹下打开或新建 `.vscode` 文件夹，在里面创建 `c_cpp_properties.json` , `tasks.json` 和 `launch.json`。

将下面 `D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\···` 改成你自己的 MinGW 或 MSYS2 的路径，注意要使用双反斜杠，尽量不要用中文。

### c_cpp_properties.json
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\include",
                "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\x86_64-w64-mingw32\\include",
                "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\12.2.0\\include",
                "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\12.2.0\\include\\c++",
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\bin\\g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++23",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

### launch.json
```json

{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "task g++",
            "command": "D:\\x86_64-8.1.0-release-win32-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "D:\\x86_64-8.1.0-release-win32-seh-rt_v6-rev0\\mingw64\\bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        },
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "D:\\x86_64-8.1.0-release-win32-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ]
}
```
### tasks.json


```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "D:\\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
    "${file}",
                "-std=c++2a",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

这时候打开你的cpp按下F5，就会编译运行。

打开终端就可以看到结果了。

## Code Runner & CPH 配置
![](https://gitee.com/tangyixiaoqaq/images/raw/master/imgs/202507241420965.png)

把以下内容复制到 `settings.json` 文件中。

```json
  "code-runner.saveAllFilesBeforeRun": true,
  "code-runner.saveFileBeforeRun": true,
  "cph.general.defaultLanguage": "cpp",
  "cph.general.defaultLanguageTemplateFileLocation": "D:\\Study\\Code\\template.cpp", // 这是你的模板文件路径
  "cph.general.firstTime": false,
  "cph.language.cpp.SubmissionCompiler": "GNU G++20 13.2 (64 bit, winlibs)", // 使用 C++20 标准
  "cph.language.cpp.Args": "-std=c++2a -O2",

  "code-runner.executorMap": {
    "javascript": "node",
    "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
    "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "zig": "zig run",
    "cpp": "cd $dir && g++ -std=c++2a $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "objective-c": "cd $dir && gcc -framework Cocoa $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "php": "php",
    "python": "python -u",
    "perl": "perl",
    "perl6": "perl6",
    "ruby": "ruby",
    "go": "go run",
    "lua": "lua",
    "groovy": "groovy",
    "powershell": "powershell -ExecutionPolicy ByPass -File",
    "bat": "cmd /c",
    "shellscript": "bash",
    "fsharp": "fsi",
    "csharp": "scriptcs",
    "vbscript": "cscript //Nologo",
    "typescript": "ts-node",
    "coffeescript": "coffee",
    "scala": "scala",
    "swift": "swift",
    "julia": "julia",
    "crystal": "crystal",
    "ocaml": "ocaml",
    "r": "Rscript",
    "applescript": "osascript",
    "clojure": "lein exec",
    "haxe": "haxe --cwd $dirWithoutTrailingSlash --run $fileNameWithoutExt",
    "rust": "cd $dir && rustc $fileName && $dir$fileNameWithoutExt",
    "racket": "racket",
    "scheme": "csi -script",
    "ahk": "autohotkey",
    "autoit": "autoit3",
    "dart": "dart",
    "pascal": "cd $dir && fpc $fileName && $dir$fileNameWithoutExt",
    "d": "cd $dir && dmd $fileName && $dir$fileNameWithoutExt",
    "haskell": "runghc",
    "nim": "nim compile --verbosity:0 --hints:off --run",
    "lisp": "sbcl --script",
    "kit": "kitc --run",
    "v": "v run",
    "sass": "sass --style expanded",
    "scss": "scss --style expanded",
    "less": "cd $dir && lessc $fileName $fileNameWithoutExt.css",
    "FortranFreeForm": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "fortran-modern": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "fortran_fixed-form": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "fortran": "cd $dir && gfortran $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "sml": "cd $dir && sml $fileName",
    "mojo": "mojo run"
  },
  "code-runner.runInTerminal": true,
  "code-runner.defaultLanguage": "c++",
```

关于浏览器上的CPH插件：

1. 可以从 chrome 应用商店搜索：Competitive Programming Helper (cph) 下载，但要注意需要有梯子。

2. 也可以从网上自行寻找

# NOI Linux 2.0 配置

由于 `NOI Linux 2.0` 已经有VScode和C++14环境配置，所以仅需进行VSCode配置即可。

## tasks.json
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ build active file",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                // "${file}",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${fileDirname}/a.out"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        },
 
    ],
    "version": "2.0.0"
}
```

## launcher.json

```json

{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++ build active file",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```
# 后记
1. 找不到 `task` 没有问题，选择仍旧调试即可。
2. 路径中、文件名尽量不要出现中文、空格等，否则可能会报错。

有问题可以在评论区指出！如果觉得不错，敬请点赞、收藏、关注、分享！