echo "Welcome $(whoami)!"
echo "This script is used to download git repositories"
git --version &> /dev/null
if [ $? -eq 0 ]
then 
	echo "Enter the git repository's link"
	read link
	echo "Enter th location to clone (Press . for current directory)"
	read dir
	git clone $link $dir
else
	echo "Seems like git not installed"
	echo "Would like to install?(Yes/no)"
	read res
	if [ $res == "Y" ] || [ $res == "y" ] || [ $res == "yes" ] || [ $res == "YES" ] || [ $res == "Yes" ] ]
		then
			sudo apt-get install git
			echo would you like to coninue?
			read rep
			if [ $rep == "Y" ] || [ $rep == "y" ] || [ $rep == "yes" ] || [ $rep == "YES" ] || [ $rep == "Yes" ]
			then 
				./input.sh
			else
				break
			fi
	else 
		echo "OK"
	fi
fi