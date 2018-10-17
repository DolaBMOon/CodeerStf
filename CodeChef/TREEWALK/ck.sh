while true;do
	./mk.cpp.out > ainput
	./a.cpp.out < ainput > output
	./b.cpp.out < ainput > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
