clear

printf '\033[31m
░█░█░▀█▀░█▀▄░█░█░█▀▀░░░█▀▀░█░█░█▀▄░█▀▀░█▀▄░░░▀█▀░█▀▀░█▀█░█▄█
░▀▄▀░░█░░█▀▄░█░█░▀▀█░░░█░░░░█░░█▀▄░█▀▀░█▀▄░░░░█░░█▀▀░█▀█░█░█
░░▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀░░░▀▀▀░░▀░░▀▀░░▀▀▀░▀░▀░░░░▀░░▀▀▀░▀░▀░▀░▀

our channel :
	<< \033[36m@virus_cyberteam\033[31m >>
'

sleep 2

printf 'create your Virus : \n'

printf '\t[\033[9;112f]'

printf '\033[9;10f\033[39m'

i=0
while [ $i -le 100 ]
do
	printf '\033[9;113f%%%d' $(($i))
	sleep 0.01
	printf '\033[9;%df██' $(($i+10))
	i=$(($i + 2))
done

printf '\n\n'

