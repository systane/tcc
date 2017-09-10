while read LINHA
do	

	file="Banco_de_amostras/curva_media/"$LINHA"-ponto[10]"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/10 }' privalor=NR | tr "." "," > "Banco_de_amostras/curva_media/curva/"$LINHA" ponto_medio[10]"
		
done < Banco_de_comandos.txt




