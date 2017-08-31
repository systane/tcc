while read LINHA
do
	for index in {1..10}
	do
		#file="Banco_de_amostras/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==1{a[NR]=min=$2} {a[NR]=$2; a[NR]>min?min=a[NR]:min; } END{for(i=1;i<=NR;i++){print "value:"a[i]/min}}' | tr "." "," > "temp"
		mv temp $file
		
	done
done < Banco_de_comandos.txt




