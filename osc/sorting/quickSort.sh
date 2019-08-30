swap() {
  local tmp=${arr[$1]}
  arr[$1]=${arr[$2]}
  arr[$2]=$tmp
}

function quicksort(){
	local st=$1
	local end=$2
	if [[ $st < $end ]]; then
		local sep=$st
		for (( i=st+1; i<end; i++ )); do
			if (( arr[i] < arr[st] )); then
				swap $((++sep)) $i
			fi
		done
		swap $st $sep
		quicksort $st $sep
		quicksort $st $sep
		quicksort $((++sep)) $i
	fi
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
quicksort 0 $n 
echo "Sorted array is :"
echo ${arr[@]}