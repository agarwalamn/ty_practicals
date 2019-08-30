swap() {
  local tmp=${arr[$1]}
  arr[$1]=${arr[$2]}
  arr[$2]=$tmp
}

echo "enter size of array!"
read n
i=$n
echo "Enter array value"
while [ $i -ne 0 ]
do
	read line
    arr=("${arr[@]}" $line)
    i=$((i-1))
done
for (( i = 0; i < n; i++ )); do
	for (( j = 0; j <n-i-1 ; j++ )); do
		if ((${arr[j]} > ${arr[$((j+1))]}))
		then
			swap $j $((j+1))
        fi
	done
done
echo "Sorted array is :"
echo ${arr[@]}