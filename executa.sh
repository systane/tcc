#!/bin/bash
g++ decoder_wave_linux_windows.cpp -o decoder
while read LINHA #enquanto a variavel read ler uma linha do arquivo ele faz
do
    for index in {1..10} #laço que vai de 1 até 10
    do
        touch "Banco_de_amostras/"$LINHA"["$index"]" #cria um arquivo com o nome lido em cada linha do arquivo
        #echo -e $LINHA"["$index"]"
        #chmod+rw % muda a permissão do arquivo atual para read and write
       ./decoder Banco_de_audio/$LINHA"["$index"].wav" #executa o programa passando como parametro cada .wav no banco de dados
    done
done < Banco_de_comandos.txt
