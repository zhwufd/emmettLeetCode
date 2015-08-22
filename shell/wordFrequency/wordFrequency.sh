cat words.txt | tr -s  ' ' '\n' | sort | uniq -c | sed 's/^ *//' | sort -nr | awk  -F ' ' '{print $2,$1;}' 
