#!/bin/sh
cat /etc/passwd | grep -v "#" | awk "NR%2==0" | cut -f1 -d : | rev | sort -r | awk 'NR>= ENVIRON["FT_LINE1"] && NR<= ENVIRON["FT_LINE2"]' | xargs | sed 's/ /, /g' | tr '\n' '.'
