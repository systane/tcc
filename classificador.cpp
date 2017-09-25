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



// Realiza o cálculo da distancia
double EuclideanDistance (double * test, double * ref){
	double result = 0;
	
	// primeira versão: i < 9
	for(int i = 0; i < 9; i++){
		//cout<<"test["<<i<<"]:"<<test[i]<<endl;
		//cout<<"ref["<<i<<"]:"<<ref[i]<<endl;
	 	result = result + (test[i] - ref[i]) * (test[i] - ref[i]);
	}

	return sqrt(result);
}



// CRIA OS VETORES DOS VALORES LIDOS NOS ARQUIVOS DE TEXTO 
void readFile (std::vector<double> & vector, string file){
	double value;

	ifstream referenceFile (file.c_str());
		if(referenceFile.is_open()){
			while(referenceFile >> value){
				vector.push_back(value);
				referenceFile.get();
			}
			referenceFile.close();
		}
		
		else
			cout << "Impossivel abrir arquivo:" << file <<endl;
}



// SALVA OS RESULTADO DA CLASSIFICAÇÃO EM UM ARQUIVO DE TEXTO
void printFile (string folder, string reference_file, string test_file, double distance){
	string outputFile = "classificacoes/distancia_euclidiana/"+folder+"/class:" + reference_file;

	ofstream outFile(outputFile.c_str(), std::ofstream::app); //modo apendice, não substitui o conteúdo já existe no txt
	if(outFile.is_open()){
		 outFile <<"nomeTeste: " << test_file << endl;
		 outFile <<"valor:" << exp(-distance) <<'\n' << endl;
		 outFile.close();
	}
	else
		cout << "Arquivo de gravacao nao pode ser aberto"<<endl;
}



// RECEBE O INPUT E PEGA O CAMINHO DOS ARQUIVOS DE TESTE E REFERENCIA
void getInput (string & folder, string & reference_file, string & reference_file_path, string & test_file, string & test_file_path, string parameter){
	
  	int position_reference_file_path;
  	int size_parameter;
  	int position_folder;


  	size_parameter = parameter.size();
  	position_reference_file_path = parameter.find("-",0);
  	test_file = parameter.substr(position_reference_file_path+1, size_parameter);
  	reference_file = parameter.substr(0, position_reference_file_path);
  	position_folder = reference_file.find("/", 0);
  	folder = reference_file.substr(0, position_folder);
  	reference_file = reference_file.substr(position_folder+1, reference_file.size());


  	test_file_path = "Banco_de_amostras/Caracteristicas_teager_editada/" + test_file;
  	reference_file_path = "Banco_de_amostras/curva_media/"+folder+"/curva/"+ reference_file;

  	//cout<<"test_path: "<<test_file_path<<endl;
  	//cout<<"ref_path: "<<reference_file_path<<endl;
  	//cout<<"folder: "<<folder<<endl;
}


//====================================================================================


int main (int argc, char* arg[]){

	std::vector<double> test_vector;
	std::vector<double> reference_vector;
	std::vector<int> rand_vector;
	std::vector<string> rand_vector2;
	string sequence = "";
	string reference_file = "", reference_file_path = "";
	string test_file = "", test_file_path = "";
	string folder = "";







  	getInput(folder, reference_file, reference_file_path, test_file, test_file_path, arg[1]);


  	readFile(reference_vector, reference_file_path);// PEGA O VETOR DE REFERENCIA
  	readFile(test_vector, test_file_path);// PEGA O VETOR DE TESTE  	


	double distance = EuclideanDistance(&test_vector[0], &reference_vector[0]);
	

	printFile(folder, reference_file, test_file, distance);

	

	



  /*	double value;

	ifstream referenceFile (file.c_str());
	if(referenceFile.is_open()){
		while(referenceFile >> value){
			vector.push_back(value);
			referenceFile.get();
		}
		referenceFile.close();
	}
	
	else
		cout << "Impossivel abrir arquivo:" << file <<endl;



  	string outputFile =  "classificacoes/combinacoes";
  	ofstream outFile(outputFile.c_str(), std::ofstream::app); //modo apendice, não substitui o conteúdo já existe no txt
	if(outFile.is_open()){
		for(int i = 1; i < 10; i++){
			outFile << "Sequencia: " << pool[i];
	 	}
		outFile.close();

	}
	else
		cout << "Arquivo de gravacao nao pode ser aberto";
  	

	//cout << "arquivo ref: " << reference_file <<endl;
  	//cout << "arquivo teste: " << test_file << endl;
	//cout << exp(-distance)<<endl;
	*/

	return 0;
	
}

// ======================================================================================

