#!/usr/bin/bash

stop=0;

if [ ! -d "$1" ];
then
	echo "First argument: Not a valid directory.";
	stop=1;
fi

if [ "$2" != "week" ] && [ "$2" != "maand" ];
then
	echo "Second argument: not valid, must be week or maand.";
	stop=1;
fi

if [ $stop == 1 ];
then
	echo "Not all requirements have been met, stopping program.";
	exit
fi

#Input is valid
#Verplaats naar /home/shared_dir/{{jaar}}/{{weeknr}}

dagen=0;

if [ "$2" == "week" ];
then
	dagen=7
else
	dagen=30
fi

files=$1
files+=/*

for file in $files
do
	if [[ $(find "$file" -mtime +$dagen -print) ]];
	then
		echo "File "$(basename $file)" is older and will be moved";
		year=$(date -r $file "+%Y");
		week=$(date -r $file "+%U");
		if [[ ! -d "/home/shared_dir/$year/" ]]
		then
			mkdir "/home/shared_dir/$year"
			if [[ ! -d "/home/shared_dir/$year/$week" ]]
			then
				mkdir "/home/shared_dir/$year/$week";
				echo "creating /home/shared_dir/$year/$week";
			fi
		fi
		mv $file "/home/shared_dir/$year/$week"
	else
		echo "File "$(basename $file)" is newer then $dagen days";
	fi
done
