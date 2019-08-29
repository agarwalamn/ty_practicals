echo "enter sizearr"
read n
i=$n
echo "Entarr"
while [ $i -ne 0 ]
do
	read line
    arr=("${arr[@]}" $line)
    i=$((i-1))
done
for (( i = 0; i < n; i++ )); do
	for (( j = 0; j <n-i-1 ; j++ )); do
		if ((${arr[j]} < ${arr[$((j+1))]}))
		then
			temp = ${arr[$j]} 
            arr[$j] = ${arr[$((j+1))]}   
            arr[$((j+1))] = $temp 
        fi
	done
done
echo ${arr[@]}