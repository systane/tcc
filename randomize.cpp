#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h> 
#include <vector>
#include <algorithm>
#include <time.h> 
#include <cstdlib>      // std::rand, std::srand
#include <random>
using std::cout; using std::endl; using std::string; using std::ofstream; 
using std::ifstream;






// VERIFICA SE UM NÚMERO JÁ EXISTE NO VETOR
bool inList(std::vector<int> &list, int number) {
	for(int i = 0; i < list.size(); ++i){
		if(list[i] == number)
			return true;
	}

	return false;
}



// PREENCHE O VETOR COM NÚMEROS ALEATÓRIOS
void fillVector(std::vector<int> & rand_vector){
	
	
	std::random_device rd;   // utiliza random_device para criar uma semente para o mt19937 (RNG - pseudo-random number generate) 
    std::mt19937 gen(rd());  // instancia um objeto que recebe a semente rd para gerar número aleatórios.
 	std::uniform_int_distribution <> dist(1,10); // filtra um inteiro para q ele fique no intervalo entre [1, 10] com probabilidade uniformente distribuida
 	
    

    while(rand_vector.size() < 10){
    	int number = dist(gen); // chamada do 'filtro' para distribuir um número entre 1 e 10

    	if(!inList(rand_vector, number)){
    		rand_vector.push_back(number);
    	}
    }
}



// VERIFICA SE O VETOR JÁ EXISTE NO ARQUIVO
bool inFile(string newRegistry){
	string sequence;
	string file = "classificacoes/distancia_euclidiana/random2";
	
	ifstream randomFile (file.c_str());
		if(randomFile.is_open()){
			while(randomFile >> sequence){
				if(sequence == newRegistry){
					return true;
				}
				randomFile.get();
			}
			randomFile.close();
		}
		
		else
			cout << "Impossivel abrir arquivo:" << file <<endl;


	return false;
}



 // PREENCHE O ARQUIVO COM UM NOVO VETOR
void fillFile(string sequence){
	
	string outputFile = "classificacoes/distancia_euclidiana/random2";
	long int number = 0;



	//number = std::stol(sequence);
	if(!inFile(sequence)){

		ofstream outFile(outputFile.c_str(), std::ofstream::app); //modo apendice, não substitui o conteúdo já existe no txt
		if(outFile.is_open()){
			outFile<<sequence<<endl;
			outFile.close();
		}
		else
			cout << "Arquivo de gravacao nao pode ser aberto";
	}
}



//====================================================================================


int main (int argc, char* arg[]){

	std::vector<double> test_vector;
	std::vector<double> reference_vector;
	std::vector<int> rand_vector;
	std::vector<string> rand_vector2;
	string sequence = "";

	
	
	
	
  	
	//string sequence = "";
	
	fillVector(rand_vector); // PREENCHE UM VETOR COM NÚMERO ALEATÓRIOS

  		
	for(int j = 0; j < rand_vector.size(); ++j){    
		sequence = sequence + std::to_string(rand_vector[j])+",";
	}
		
	fillFile(sequence);

	return 0;


	
}

// ======================================================================================

