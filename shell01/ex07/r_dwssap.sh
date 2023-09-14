cat /etc/passwd | grep -v '^#' | cut -d ':' -f 1 | sed -n "$FT_LINE1 , $FT_LINE2 p" | rev | sort -r | xargs echo | sed 's/ /, /g' | sed 's/$/./g' | tr -d '\n' 
