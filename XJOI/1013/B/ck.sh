while true;do
	./mk.cpp.out > input
	./a.cpp.out < input > output
	./ac.cpp.out < input > ans
	if diff output ans -b;then
		printf "MOE\n"
	else
		break
	fi
done
