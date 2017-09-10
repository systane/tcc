while read LINHA
do
	for index in {1..10}
	do
		
		file="Banco_de_amostras/Caracteristicas__teager_editada_(funcao_energia)/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==10' | tr "." ","

		
	done > "Banco_de_amostras/curva_media/"$LINHA"-ponto[10]"
done < Banco_de_comandos.txt




