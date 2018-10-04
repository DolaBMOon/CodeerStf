while true;do
	./mk.cpp.out > input
	./b.cpp.out < input > output
	./bk2.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
