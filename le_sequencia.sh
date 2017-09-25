while read COMANDO
do
	file="classificacoes/distancia_euclidiana/random2"

	while read LINHA
	do
		IFS=',' read -r -a array <<< "$LINHA"
		length="${#array[@]}"
		#echo "${array[0]}"
		nome=$(echo "$LINHA" | sed 's/,//g')
		#echo $nome

		#for (( i=0 ; i < "$length" ; i++))
		#do
		#	nome=$nome${array[$i]}
		#done



		mkdir -p "Banco_de_amostras/curva_media"
		mkdir -p "Banco_de_amostras/curva_media/"$nome
		mkdir -p "Banco_de_amostras/curva_media/"$nome"/curva"
		mkdir -p "Banco_de_amostras/curva_media/"$nome"/pontos_medios"




		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==1'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto1"
		done 


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==2'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto2"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==3'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto3"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==4'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto4"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==5'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto5"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==6'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto6"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==7'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto7"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==8'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto8"
		done


		for index in {0..4}
		do
			aux=${array[$index]}
			file="Banco_de_amostras/Caracteristicas_teager_editada/"$COMANDO"["$aux"]"
			tr "," "." < $file | awk -F":" 'NR==9'  >> "Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto9"
		done

#================================================================================================================================================


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto1"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  > "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto2"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto3"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >>"Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto4"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto5"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto6"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto7"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto8"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO


		file="Banco_de_amostras/curva_media/"$nome"/pontos_medios/"$COMANDO"-ponto9"
		tr "," "." < $file | awk -F":" '{ sum += $1 } END { print sum/5 }' privalor=NR  >> "Banco_de_amostras/curva_media/"$nome"/curva/"$COMANDO

	done < "$file"
done < Banco_de_comandos.txt
