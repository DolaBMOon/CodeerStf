while true;do
	./mk.cpp.out > input
	./ac.cpp.out < input > ans
	./b.cpp.out < input > output
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
