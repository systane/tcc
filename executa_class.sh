#!/bin/bash
g++ -std=c++17 classificador.cpp -o classificador
while read COMANDO
do
	while read LINHA #enquanto a variavel read ler uma linha do arquivo ele faz
	do
		file="classificacoes/distancia_euclidiana/random2"
		while read SEQUENCE
		do
			IFS=',' read -r -a array <<< "$SEQUENCE"
			length="${#array[@]}"
			#echo "${array[0]}"
			touch "classificacoes/distancia_euclidiana/"$nome"/class:"$LINHA #cria um arquivo com o nome lido em cada linha do arquivo
			nome=$(echo "$SEQUENCE" | sed 's/,//g')
		    
		    for index in {5..9} #laço que vai de 1 até 10
		    do
		    	aux=${array[$index]}
		    	mkdir -p "classificacoes/distancia_euclidiana/"$nome
		       ./classificador $nome"/"$COMANDO-$LINHA"["$aux"]" #executa o programa passando como parametro cada .wav no banco de dados
		    done
	    done < "$file"
	done < Banco_de_comandos.txt
done < Banco_de_classificadores.txt