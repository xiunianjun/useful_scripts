#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <variable_value>"
    exit 1
fi

dataset="$1"
strategies=("A" "B" "C" "D")
conditions=("1" "2")

mkdir -p "${dataset}/"
mkdir -p "${dataset}/grep/"
mkdir -p "${dataset}/merged/"

for con in "${conditions[@]}"; do
    input_files=""

    for ds in "${strategies[@]}"; do
        mkdir -p "${dataset}/grep/${ds}_${con}"
        # 数据格式： Pn: 浮点数/整数
        # P1s
        cat "${dataset}/raw/${dataset}_${ds}_${con}.log" | grep -P "^P1: (-nan|\d+(\.\d+)?)?" | awk '{match($0, /[0-9]+(\.[0-9]+)?/); print substr($0, RSTART, RLENGTH)}' > "${dataset}/grep/${ds}_${con}/M.txt"
        # P2
        cat "${dataset}/raw/${dataset}_${ds}_${con}.log" | grep -P "^P2: (-nan|\d+(\.\d+)?)?" | awk '{match($0, /[0-9]+(\.[0-9]+)?/); print substr($0, RSTART, RLENGTH)}' > "${dataset}/grep/${ds}_${con}/N.txt"
        # P3
        cat "${dataset}/raw/${dataset}_${ds}_${con}.log" | grep -P "^P3: (-nan|\d+(\.\d+)?)?" | awk '{match($0, /([0-9]+(\.[0-9]+)?)/); print substr($0, RSTART, RLENGTH)}' > "${dataset}/grep/${ds}_${con}/K.txt"
    done

    for ds in "${strategies[@]}"; do
        for file_type in "M" "N" "K"; do
            input_files+=" ${dataset}/grep/${ds}_${con}/${file_type}.txt"
        done
        input_files+=" tab.txt"
    done
    paste -d$'\t' ${input_files} > "${dataset}/merged/table_${con}.txt"
done