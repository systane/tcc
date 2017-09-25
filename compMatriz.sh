#Vai ler e formatar os números de sequencias
#executar o comparaMatriz.cpp passando como parametro a sequencia lida 

g++ -std=c++17 comparaMatriz.cpp -o matriz

file="classificacoes/distancia_euclidiana/random2"

	while read LINHA
	do
		IFS=',' read -r -a array <<< "$LINHA"
		length="${#array[@]}"
		#echo "${array[0]}"
		sequencia=$(echo "$LINHA" | sed 's/,//g')
		./matriz $sequencia

done < "$file"