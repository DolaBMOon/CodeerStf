while true;do
	./mk.cpp.out > cinput
	./a.cpp.out < cinput > output
	./ac.cpp.out < cinput > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
