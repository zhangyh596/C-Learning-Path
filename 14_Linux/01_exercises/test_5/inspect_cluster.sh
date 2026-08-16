#!/bin/bash

# ==========================================
# AI 算力节点自动化巡检脚本 v1.0
# ==========================================

# 【知识点 1：自定义函数与局部变量】
print_header() {
    local title=$1
    echo ""
    echo "======================================"
    echo " 🔍 $title"
    echo "======================================"
}

# 【知识点 2：三剑客处理系统真实数据 + if 控制流】
check_disk() {
    print_header "系统根目录磁盘空间巡检"
    
    # 用 df 拿数据，awk 提取第二行第五列的百分比，sed 去掉 '%' 符号方便进行数学比对
    local usage=$(df -h / | awk 'NR==2 {print $5}' | sed 's/%//')

    if [ "$usage" -ge 80 ]; then
        echo "❌ [告警] 磁盘占用已达 $usage%！(超过 80% 阈值，请清理环境)"
    else
        echo "✅ [正常] 磁盘空间充裕，当前占用: $usage%"
    fi
}

# 【知识点 3：HereDoc 造数据 + for 循环 + 正则匹配】
check_gpu_nodes() {
    print_header "GPU 节点健康状态巡检"

    # 临时生成一份模拟的 GPU 监控日志
    cat << 'EOF' > /tmp/mock_gpu.log
node-01: GPU0_TEMP=75C MEM=40% STATUS=Running
node-02: GPU0_TEMP=88C MEM=95% STATUS=OOM_ERROR
node-03: GPU0_TEMP=60C MEM=10% STATUS=Running
node-04: GPU0_TEMP=N/A MEM=N/A STATUS=Offline
EOF

    # 提取所有节点名：用正则抓取以 node 开头的行，用 awk 提取第一列，sed 去掉冒号
    local nodes=$(grep '^node' /tmp/mock_gpu.log | awk '{print $1}' | sed 's/://')

    # 遍历每一个节点
    for node in $nodes; do
        # 抓取当前节点的完整日志行
        local log_line=$(grep "^$node" /tmp/mock_gpu.log)

        # 使用扩展正则 (-E) 判断是否包含致命错误标识 (-q 表示静默执行，只拿状态码)
        if echo "$log_line" | grep -E -q "ERROR|Offline|Timeout"; then
            echo "🚨 [异常节点] $node -> $log_line"
        else
            echo "✅ [健康节点] $node 运行良好"
        fi
    done

    # 巡检完毕，清理临时文件
    rm -f /tmp/mock_gpu.log
}

# --- 主程序入口 ---
echo "🚀 开始执行 AI 集群全量巡检，当前时间: $(date '+%Y-%m-%d %H:%M:%S')"
check_disk
check_gpu_nodes
echo ""
echo "🎉 巡检任务全部执行完毕！"
