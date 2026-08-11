#!/bin/bash

TASK_TYPE=$1

case $TASK_TYPE in
    "train")
        echo "初始化 GPU 集群，准备开始【训练】任务..."
        ;;
    "infer")
        echo "加载轻量化模型，准备开始【推理】任务..."
        ;;
    *)
        echo "错误：未知的任务类型！请传入 train 或 infer"
        ;;
esac


