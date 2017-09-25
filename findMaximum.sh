#!/bin/bash
while read CLASSIFICADOR
do
    file="classificacoes/distancia_euclidiana/class:"$CLASSIFICADOR
	touch 'classificacoes/distancia_euclidiana/resultados'    	
	echo 'classificador:'$CLASSIFICADOR >> 'classificacoes/distancia_euclidiana/resultados'
	tr "," "." < $file | awk -F"valor: " 'NR==2{a[NR]=min=$2} {a[NR]=$2; a[NR]>min?min=a[NR]:min; } END{for(i=1;i<=NR;i++){print "valor:"min}}' >> 'classificacoes/distancia_euclidiana/resultados' 
done < Banco_de_classificadores.txt