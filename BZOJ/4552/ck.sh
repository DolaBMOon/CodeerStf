while true;do
	./mk.cpp.out > input
	if ./a.cpp.out < input > output;then
		printf "MOE\n"
	else
		break
	fi
done
