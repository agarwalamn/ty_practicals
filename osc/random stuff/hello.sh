
user=$(whoami)
echo "Hello $user ! Welcome to our program !"
red=`tput setaf 125`
green=`tput setaf 2`
reset=`tput sgr0`

 i=1
 while true
 do
 	echo "$(tput setab 7)${red}Hello Sggs !${green}You are being hacked!${reset}"
 	echo "${red} Dumping Virus no $i"	
 	echo -ne "$(tput setab 2)$(tput setaf 7)$(tput setab 2)#$(tput setab 0)                         (10%)\r"
 	sleep 1
 	echo -ne "$(tput setab 2)$(tput setaf 7)#####                     (33%)\r"
	sleep 1
	echo -ne "$(tput setab 2)$(tput setaf 7)#############             (66%)\r"
	sleep 1
	echo -ne "$(tput setab 2)$(tput setaf 7)#######################   (100%)\ ${reset}"
	echo -ne '\n'
	touch "Virus$i.exe"
 	i=$((i+1))
 done

