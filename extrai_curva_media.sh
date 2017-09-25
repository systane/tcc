while read LINHA
do
	touch "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto1"
	touch "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto2"
	touch "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto3"
	touch "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto4"
	touch "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto5"
	touch "Banco_de_amostras/curva_media2/curva/"$LINHA


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==1' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto1"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==2' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto2"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==3' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto3"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==4' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto4"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==5' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto5"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==6' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto6"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==7' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto7"
	done 


	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==8' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto8"
	done 

	for index in {1..5}
	do
		file="Banco_de_amostras/Caracteristicas_teager_editada/"$LINHA"["$index"]"
		tr "," "." < $file | awk -F":" 'NR==9' | tr "." "," >> "Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto9"
	done 
	
	#=========================================================================================================================================================

	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto1"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," > "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto2"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto3"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto4"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto5"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto6"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto7"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto8"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA


	file="Banco_de_amostras/curva_media2/pontos_medios/"$LINHA"-ponto9"
	tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR | tr "." "," >> "Banco_de_amostras/curva_media2/curva/"$LINHA

done < Banco_de_comandos.txt


