#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h> 
#include <vector>
using std::cout; using std::endl; using std::string; using std::ofstream; using std::ifstream;




double EuclideanDistance (double * test, double * ref){
	double result = 0;
	

	for(int i = 0; i < 9; i++){
	 	result = result + (test[i] - ref[i]) * (test[i] - ref[i]);
	}

	return sqrt(result);
}

//====================================================================================


int main (int argc, char* arg[]){
	//double test_vector[9];
	//double reference_vector[9];
	double value;
	std::vector<double> test_vector;
	std::vector<double> reference_vector;


	string parameter = arg[1];
  	string reference_file_path;
  	string teste_file_path;
  	int position_reference_file_path;
  	int size_parameter;


  	size_parameter = parameter.size();
  	position_reference_file_path = parameter.find("-",0);
  	teste_file_path = parameter.substr(position_reference_file_path+1, size_parameter);
  	reference_file_path= parameter.substr(0, position_reference_file_path);


  	//cout << "arquivo ref: " << reference_file_path <<endl;
  	//cout << "arquivo teste: " << teste_file_path << endl;


  	// ================ CRIA OS VETORES DOS VALORES LIDOS DOS ARQUIVOS DE TEXTO ============

  		cout << "ARQUIVO LIDO:" <<endl;
		// PEGA O VETOR DE REFERENCIA
		ifstream referenceFile (reference_file_path.c_str());
		if(referenceFile.is_open()){
			while(referenceFile >> value){
				reference_vector.push_back(value);
				referenceFile.get();
			}
			referenceFile.close();
		}
		
		else
			cout<<"Impossivel abrir arquivo de referencia" <<endl;


		
		// PEGA O VETOR DE TESTE
		ifstream testFile(teste_file_path.c_str());
		if(testFile.is_open()){
			while(testFile >> value){
				test_vector.push_back(value);
				testFile.get();
			}
			testFile.close();

		}

		else
			cout << "Imposssivel abrir arquivo de teste" <<endl;



	double distance = EuclideanDistance(&test_vector[0], &reference_vector[0]);

	cout << exp(-distance)<<endl;

	string outputFile = "classificacoes/distancia_euclidiana/class:_"+

	return 0;
}

// ======================================================================================

