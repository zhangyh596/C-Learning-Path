#!/bin/bash

# 【🔥 AI Infra 必须深入理解】：定义函数
prepare_model() {
    # 使用 local 定义局部变量，接收传给函数的 $1 和 $2
    local model_name=$1
    local target_dir=$2
    
    # 拼接出完整的文件路径
    local full_path="$target_dir/${model_name}.pth"

    echo "▶ 正在配置模型: $model_name"
    echo "  - 目标目录: $target_dir"
    
    # 执行具体的创建指令
    mkdir -p "$target_dir"
    touch "$full_path"
    
    echo "  ✅ 配置成功！文件已生成在: $full_path"
    echo "-----------------------------------"
}

echo "=== 开始自动化部署模型流水线 ==="

# 【🔥 AI Infra 必须深入理解】：调用函数并传参（空格隔开参数）
# 第一次调用
prepare_model "llama-3-8b" "/tmp/ai_models/llama"

# 第二次调用，换不同的参数
prepare_model "qwen-72b" "/tmp/ai_models/qwen"

echo "=== 流水线执行完毕 ==="
