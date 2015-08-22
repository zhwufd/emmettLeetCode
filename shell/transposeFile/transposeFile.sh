numofcol=$(cat file.txt | awk 'BEGIN{FS = " "} END{print NF;}')
for ((i = 1; i<=$numofcol; i++)) 
do
	cat file.txt | awk -v col="$i" 'BEGIN{FS = " "} {print $col;}' | tr '\n' ' '
	printf '\n'
done
