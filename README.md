# algorithm
算法集

# 遇到 fatal: unable to access 并提示 Encountered end of file 错误，通常与网络连接、Git 配置或认证问题有关。以下是分步解决方案：

## 1. 切换到 SSH 协议
git remote set-url origin git@github.com:looken1024/algorithm.git

## 2. 检查网络连通性
ping github.com

## 3. 推送代码（使用 SSH）
git push

## 如果仍失败，尝试：
git config --global http.postBuffer 524288000
git push -u origin main

