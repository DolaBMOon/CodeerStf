while true;do
	./mk.cpp.out > input
	./gay.cpp.out < input > output
	./bf.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
