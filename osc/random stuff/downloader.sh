
echo "Please enter your name to continue"
read name
echo "Hello $name! Welcome to process management program"
echo "Press 1 to get all process"
read i
	if [[ i -eq 1 ]]; then
		ps -A
	fi

echo "Press 2 to kill process"
read i
	if [[ i -eq 2 ]]; then
		echo "Enter PID of process"
		read k
		kill $k
	fi
echo "Thank you for using our program!"
	
