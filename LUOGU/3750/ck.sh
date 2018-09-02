while true;do
	./mk.cpp.out > input
	./t.cpp.out < input > output
	./ac.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
