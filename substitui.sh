#!/bin/bash
while read LINHA
do
	for index in {1..10}
	do
		file="Banco_de_amostras/teste/"$LINHA"["$index"]"
		while read FILELINE
		do
			sed -i 's/valor:0./valor:0,/' $file
		done < "$file"
	done
done < Banco_de_comandos.txt