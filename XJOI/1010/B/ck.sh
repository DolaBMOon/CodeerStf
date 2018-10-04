while true;do
	./mk.cpp.out > input
	./nw.cpp.out < input > output
	./cxt.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
