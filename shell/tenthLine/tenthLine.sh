#linenum=$(cat file.txt | wc -l)
#if [ $linenum -gt 9 ]
#then
	awk '{if(NR == 10) print $0;}' file.txt
#fi
