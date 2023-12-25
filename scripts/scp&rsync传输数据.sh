#!/bin/bash

# 已有文件列表数组
existing_files=()
 
# 目标远程主机
remote_host="user@host:/path/to/remote/target/"

# 本地文件目录
local_files_dir="/path/to/local/target/"

# 遍历本地文件列表
for local_file in "$local_files_dir"*
do
    # 提取文件名
    file_name=$(basename "$local_file")

    # 检查文件是否在已有文件列表中
    if [[ " ${existing_files[@]} " =~ " $file_name " ]]; then
        echo "File $file_name already exists. Skipping..."
    else
        # 文件不在列表中，使用scp传输
        scp "$local_file" "$remote_host"
        echo "Transferred $file_name to $remote_host"
    fi
done


# rsync
# (rsync -avr --no-times /path/to/local/target user@host:/path/to/remote/target && rsync -avr  --no-times /path/to/local/target user@host:/path/to/remote/target) &