cat /etc/passwd | grep -v '#' | sed -n 'n;p' | cut -d: -f1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | cat -e | tr '$' ',' | tr '\n' ' ' | rev | sed 's/,/./1' | sed 's/ //1' | rev | tr -d '\n'
