#!/bin/bash
#g++ my.cpp -o my -std=c++11

file='*.in'
i=1
for item in $file
do
    filename=${item%.*}
    echo $filename
    echo -e "\033[33m running on test $i... \033[0m"
    ./spj  $item  $filename.ans $filename.ans
    i=$(($i+1))
    echo -e
done
