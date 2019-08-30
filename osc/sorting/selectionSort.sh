swap() {
  local tmp=${arr[$1]}
  arr[$1]=${arr[$2]}
  arr[$2]=$tmp
}
echo "enter size of arr"
read n
i=$n
echo "Enter array"
while [ $i -ne 0 ] 
do
	read line
    arr=("${arr[@]}" $line)
    i=$((i-1))
done
for (( i=0; i < n; i++ )); do
	temp=${arr[$i]}
	ind=$i
	for (( j=i+1 ; j<n ; j++ )); do
		if(( ${arr[$j]} < $temp ))
		then
			temp=${arr[$j]}
			ind=$j
		fi
	done
	swap $i $ind
done
echo "Sorted array is :"
echo ${arr[@]}

