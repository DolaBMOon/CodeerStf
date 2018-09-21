while true;do
	./mk.cpp.out > input
	./zzf.cpp.out < input > output
	./a.cpp.out < input > ans
	if diff output ans;then
		printf "MOE\n"
	else
		break
	fi
done
