#!/bin/bash
g++ classificadorAbrirCalc.cpp -o classificadorAbrirCalc
while read LINHA #enquanto a variavel read ler uma linha do arquivo ele faz
do
    for index in {1..10} #laço que vai de 1 até 10
    do
        touch "classificacoes/distancia_euclidiana/class:_"$COMANDO" test:_"$LINHA"["$index"]" #cria um arquivo com o nome lido em cada linha do arquivo
        #echo -e $LINHA"["$index"]"
        #chmod+rw % muda a permissão do arquivo atual para read and write
       ./classificador Banco_de_amostras/curva_media/$Abrir_calculadora-Banco_de_amostras/Caracteristicas_teager_editada/$LINHA"["$index"]" #executa o programa passando como parametro cada .wav no banco de dados
    done
done < Banco_de_comandos.txt



