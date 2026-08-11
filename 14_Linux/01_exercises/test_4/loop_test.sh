#!/bin/bash

echo "=== 阶段 1：使用 for 循环初始化 GPU ==="
# 遍历 4 张卡的 ID
for gpu_id in 0 1 2 3
do
    echo "正在分配算力到 GPU: $gpu_id ..."
    sleep 1  # 暂停 1 秒，假装在做复杂的初始化
done
echo "所有 GPU 初始化完毕！"

echo "-----------------------------------"

echo "=== 阶段 2：使用 while 循环模拟训练倒计时 ==="
TIME_LEFT=3

# 当时间大于 0 时，一直循环 (-gt 是 greater than)
while [ $TIME_LEFT -gt 0 ]
do
    echo "模型训练中... 剩余 $TIME_LEFT 秒结束"
    sleep 1  # 必须加 sleep，防止 CPU 卡死！
    
    # 关键点：每循环一次，时间减 1。注意 $(( )) 的数学计算外壳！
    TIME_LEFT=$((TIME_LEFT - 1)) 
done

echo "训练任务圆满完成，显存已释放！"
