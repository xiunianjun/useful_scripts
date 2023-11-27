import argparse
import fileinput

text_map = {
    "⽬": "目",
    "⽂": "文",
    "⽅": "方",
    "⽀": "支",
    "⼼": "心",
    "⽚": "片",
    "⼀": "一",
    "⼩": "小",
    "⽤": "用",
    "⼾": "户",
    "⽐": "比",
    "⾥": "里",
    "⽹": "网",
    "⾯": "面",
    "⾏": "行",
    "⻆": "角",
    "⽣": "生",
    "⼯": "工",
    "⽔": "水",
    "⻚": "页",
    "⽽": "而",
    "⻉": "贝",
    "⾃": "自",
    "⼒": "力",
    "⻓": "长",
    "⼦": "子",
    "⽴": "立",
    "⼝": "口",
    "⼜": "又",
    "⼤": "大"
}

def replace_chars_inplace(input_file):
    with fileinput.FileInput(input_file, inplace=True, encoding='utf-8') as file:
        for line in file:
            for char in line:
                if char in text_map:
                    line = line.replace(char, text_map[char])
            print(line, end='')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Replace characters in a file using a predefined map.')
    parser.add_argument('input_file', type=str, help='Input file name')

    args = parser.parse_args()

    replace_chars_inplace(args.input_file)