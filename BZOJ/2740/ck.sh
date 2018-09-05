#!/bin/bash
while true;do
	./mk.cpp.out > input
	./a.cpp.out < input > output
	./t.cpp.out < input > ans
	if diff output ans;then
		printf "MOE"
	else
		break
	fi
done
