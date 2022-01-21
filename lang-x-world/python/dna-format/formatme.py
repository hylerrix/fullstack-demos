#!/usr/bin/python
# coding=utf-8

# 使用须知：本程序目前只针对以 LF 为换行符的 UNIX/Linux 文件适用 

import argparse
import sys
import os

# 定义没有去冗余化的纯 DNA 序列临时文件名
RedunTempFile = '.redun.temp'
# 定义去冗余化并统计了序列数目的临时文件名
DisRedunTempFile = '.disredun.temp'

# parse arguments
parser = argparse.ArgumentParser(description = "Process fastq and fasta files.")
group = parser.add_mutually_exclusive_group()
parser.add_argument("-i", "--input", dest = "infile", required = True, help = "Input file path" )
parser.add_argument("-o", "--output", dest = "outfile", required = True, help = "Output file path")
group.add_argument("--a", dest = "qtoa", action = "store_true", help = "convert fastq to fasta")
group.add_argument("--b", dest = "mvredun", action = "store_true", help = "remove redundancy of seq")
group.add_argument("--c", dest = "toseq", action = "store_true", help = "lines")
group.add_argument("--d", dest = "addredun", action = "store_true", help = "to pure seq")

def main():
    args = parser.parse_args()
    # 生成 RedunTempFile 临时文件
    __filterDNA(args.infile, RedunTempFile)
    # 生成 DisRedunTempFile 临时文件
    __disRedunDNA(RedunTempFile, DisRedunTempFile)
    if args.qtoa:
        qtoa(DisRedunTempFile, args.outfile)
    elif args.mvredun:
        mvredun(DisRedunTempFile, args.outfile)
    elif args.toseq:
        toseq(DisRedunTempFile, args.outfile)
    elif args.addredun:
        addredun(args.infile, args.outfile)
    # 销毁临时文件
    __deleteTempFile()
    print("Done.")

# 判断该行是否是 DNA 序列，判断原则为是否包含 ACGT
def __isDNA (line):
    for l in line:
        if (l not in 'ACGT'):
            return 0
    return 1

# 生成 RedunTempFile 临时文件
def __filterDNA (infile, outfile):
    redunDNAArr = []
    # 逐行打开源文件
    for line in open(infile, 'r'):
        # 去掉每行行尾换行符
        line = line.strip('\n')
        flag = __isDNA(line)
        # 是 DNA 序列
        if (flag == 1):
            redunDNAArr.append(line + '\n')
    # 打开目标文件并输出至目标文件
    w = open(outfile, 'w')
    w.writelines(redunDNAArr)

# 生成 DisRedunTempFile 临时文件
def __disRedunDNA (infile, outfile):
    # 去冗余化并包含冗余个数的字典 disRedunDNA
    # eg: {'aaaa': 1, 'bbbb': 1}
    disRedunDNA = {}
    for line in open(infile, 'r'):
        line = line.strip('\n')
        if (not disRedunDNA.has_key(line)):
            # 没有该 DNA 序列时，将该序列以新键形式加入字典
            disRedunDNA[line] = 1
        else:
            # 打开目标文件并输出至目标文件
            disRedunDNA[line] += 1
    # 将去冗余化的字典转为可直接打印的换行字符串
    disRedunDNAArr = []
    for key in disRedunDNA:
        disRedunDNAArr.append(key + '\t' + str(disRedunDNA[key]) + '\n')
    w = open(outfile, 'w')
    w.writelines(disRedunDNAArr)

# 删除临时文件
def __deleteTempFile ():
    os.remove(RedunTempFile)
    os.remove(DisRedunTempFile)

# fastq转化fasta
def qtoa (infile, outfile):
    print("convert fastq to fasta")
    # 初始化行数游标，以此为 ID 号
    seqID = 0
    # 初始化 fasta 格式的数组
    fastaArr = []
    for line in open(infile, 'r'):
        seqID += 1
        seq = line.split('\t')
        sequence = seq[0]
        seqNumber = str(seq[1])
        fastaArr.append('>seq' + str(seqID) + '_' + seqNumber)
        fastaArr.append(sequence + '\n')
    # fasta 格式的数组写入 fasta 文件中
    w = open(outfile, 'w')
    w.writelines(fastaArr)

# 去冗余化，只需选取 DisRedunTempFile 临时文件片段
def mvredun (infile, outfile):
    fastaArr = []
    for line in open(infile, 'r'):
        sequence = line.split('\t')[0]
        fastaArr.append(sequence + '\n')
    w = open(outfile, 'w')
    w.writelines(fastaArr)

# 统计序列的数目，只需选取 DisRedunTempFile 临时文件片段
def toseq (infile, outfile):
    seqID = 0
    fastaArr = []
    for line in open(infile, 'r'):
        seqID += 1
        seq = line.split('\t')
        seqNumber = str(seq[1])
        fastaArr.append('>Read_' + str(seqID) + '@' + seqNumber)
    w = open(outfile, 'w')
    w.writelines(fastaArr)

# 将fasta文件改为纯序列文件
def addredun (infile, outfile):
    seqArr = []
    for line in open(infile, 'r'):
        # 去掉每行行尾换行符
        line = line.strip('\n')
        flag = __isDNA(line)
        # 是 DNA 序列
        if (flag == 1):
            seqArr.append(line + '\n')
    w = open(outfile, 'w')
    w.writelines(seqArr)

if __name__ == "__main__":
    main()
else:
    print("Run this script directly.", sys.stderr)
