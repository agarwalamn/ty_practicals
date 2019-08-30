echo "Enter size of arr"
read n
i=$n
echo "Enter array"
while [ $i -ne 0 ]
do
	read line
    arr=("${arr[@]}" $line)
    i=$((i-1))
done
for (( i=1; i < n; i++ )); do
	j=$((i-1))
	key=${arr[$i]}
	while (( j>=0 && arr[j]>key )); do
		arr[$((j+1))]=${arr[$j]}
		j=$((j-1))
	done
	arr[$((j+1))]=$key
done
echo "Sorted array is :"
echo ${arr[@]}