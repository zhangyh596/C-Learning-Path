#!/bin/bash

echo "=== 🧹 GPU 显存强制清空向导 ==="

# 第一步：正常读取用户输入
read -p "请输入你要清空的 GPU 卡号 (例如 0, 1, 2): " GPU_ID

echo "正在锁定 GPU $GPU_ID..."
sleep 1

# 第二步：带有 5 秒倒计时的危险操作确认（注意这里的 -t 5）
read -t 5 -p "⚠️ 警告：确定要清空 GPU $GPU_ID 上的所有训练进程吗？(输入 yes 确认，5秒不操作将自动取消): " CONFIRM

# 因为用 read -t 倒计时结束时不会自动换行，我们手动加个换行让输出变好看
echo "" 

# 第三步：结合 if 进行判断
if [[ $CONFIRM == "yes" ]]; then
    echo "🔥 轰！GPU $GPU_ID 的显存已全部强制清空！"
else
    echo "🛡️ 操作已取消（或您已超时未确认），GPU 进程安全保留。"
fi
