while true;do
	./mk.cpp.out > input
	./a.cpp.out < input > output
	./j.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
