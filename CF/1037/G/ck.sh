while true;do
	./mk.cpp.out > input
	./b.cpp.out < input > output
	./tou.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
