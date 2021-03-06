//ler a o argumento e buscar na pasta os 11 classificadores.
//salvar todos os resultados númericos em vetores
//encontrar para indice do vetor o maior valor
//salvar o maior valor de cada indice em uma matriz quadrada
//Por fim calcular a diagonal da matriz e salvar o resultado em um arquivo de texto junto com a sequencia númerica que originou tal matriz

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


// CRIA OS VETORES DOS VALORES LIDOS NOS ARQUIVOS DE TEXTO 
void readFile (std::vector<double> & vector, string file, string className){
	string line;
	string trash = "valor:";
	double value;
	file = file + "/class:" +className;


	ifstream referenceFile (file.c_str());
		if(referenceFile.is_open()){
			while(referenceFile >> line){
				if(line.find(trash) != string::npos){
					int sizeLine = line.size();
					int sizeTrash = trash.size();
					line = line.substr(sizeTrash, sizeLine);
					value = stod(line);
					vector.push_back(value);
				}
				referenceFile.get();
			}
			referenceFile.close();
		}
		
		else
			cout << "Impossivel abrir arquivo:" << file <<endl;
}


void initArray(int (&array)[55]){
	for(int i = 0; i < 55; i++){
		array[i] = 0;
	}
}


void printFile (string sequence, int score){
	string outputFile = "classificacoes/distancia_euclidiana/Resultados";

	ofstream outFile(outputFile.c_str(), std::ofstream::app); //modo apendice, não substitui o conteúdo já existe no txt
	if(outFile.is_open()){
		 outFile<< sequence << " - " << score << endl;
		 outFile.close();
	}
	else
		cout << "Arquivo Resultados nao pode ser aberto"<<endl;
}


int main (int argc, char* arg[]){

	string sequence = arg[1];
	string referece_file_path = "classificacoes/distancia_euclidiana/"+sequence;

	cout<<"Numero de sequencia: "<<sequence<<endl;

	std::vector<double> classCalen;
	std::vector<double> classAbrirCalc;
	std::vector<double> classAlarme;
	std::vector<double> classBoaNoite;
	std::vector<double> classBomDia;
	std::vector<double> classComoTempo;
	std::vector<double> classOi;
	std::vector<double> classPesq;
	std::vector<double> classSair;
	std::vector<double> classVaiCho;
	std::vector<double> classVerNot;
	std::vector<double> bestResults;
	
	double matrix[11][11];
	

	int positionCalen[55];
	int positionAbrirCalc[55];
	int positionAlarme[55];
	int positionBoaNoite[55];
	int positionBomDia[55];
	int positionComoTempo[55];
	int positionOi[55];
	int positionPesq[55];
	int positionSair[55];
	int positionVaiCho[55];
	int positionVerNot[55];
	

	int qntCalen = 0;
	int qntAbrirCalc = 0;
	int qntAlarme = 0;
	int qntBoaNoite = 0;
	int qntBomDia = 0;
	int qntComoTempo = 0;
	int qntOi = 0;
	int qntPesq = 0;
	int qntSair = 0;
	int qntVaiCho = 0;
	int qntVerNot = 0;

	readFile(classCalen,		referece_file_path, "Calendаrio");
	readFile(classAbrirCalc, 	referece_file_path, "Abrir_calculadora");
	readFile(classAlarme, 		referece_file_path, "Alarme");
	readFile(classBoaNoite, 	referece_file_path, "Boa_noite_Logan");
	readFile(classBomDia, 		referece_file_path, "Bom_dia_Logan");
	readFile(classComoTempo, 	referece_file_path, "Como_esta_o_tempo_hoje");
	readFile(classOi, 			referece_file_path, "Oi_Logan");
	readFile(classPesq, 		referece_file_path, "Pesquisar");
	readFile(classSair, 		referece_file_path, "Sair");
	readFile(classVaiCho, 		referece_file_path, "Vai_chover");
	readFile(classVerNot, 		referece_file_path, "Ver_noticias");


	//limpa os arrays
	initArray(positionCalen);
	initArray(positionAbrirCalc);
	initArray(positionAlarme);
	initArray(positionBoaNoite);
	initArray(positionBomDia);
	initArray(positionComoTempo);
	initArray(positionOi);
	initArray(positionPesq);
	initArray(positionSair);
	initArray(positionVaiCho);
	initArray(positionVerNot);


	// inicializa matriz com zeros
	for(int i = 0; i < 11; ++i){
		for(int j = 0; j < 11; ++j){
			matrix[i][j] = 0;
		}
	}

	
	// pega os melhores resultados
	for(int i = 0; i < 55; ++i){
		double maxValue;
		double max[11];
		max[0]  = classAbrirCalc[i];
		max[1]  = classCalen[i];
		max[2]  = classAlarme[i];
		max[3]  = classBoaNoite[i];
		max[4]  = classBomDia[i];
		max[5]  = classComoTempo[i];
		max[6]  = classOi[i];
		max[7]  = classPesq[i];
		max[8]  = classSair[i];
		max[9]  = classVaiCho[i];
		max[10] = classVerNot[i];


		maxValue = *std::max_element(max, max+11);
		bestResults.push_back(maxValue);

		if(maxValue == classCalen[i]){
			positionCalen[i] = positionCalen[i] + 1;
			++qntCalen;

		}

		if(maxValue == classAbrirCalc[i]){
			positionAbrirCalc[i] = positionAbrirCalc[i] + 1;
			++qntAbrirCalc;

		}

		if(maxValue == classAlarme[i]){
			positionAlarme[i] = positionAlarme[i] + 1;
			++qntAlarme;
		}

		if(maxValue == classBoaNoite[i]){
			positionBoaNoite[i] = positionBoaNoite[i] + 1;
			++qntBoaNoite;
		}

		if(maxValue == classBomDia[i]){
			positionBomDia[i] = positionBomDia[i] + 1;
			++qntBomDia;
		}

		if(maxValue == classComoTempo[i]){
			positionComoTempo[i] = positionComoTempo[i] + 1;
			++qntComoTempo;
		}

		if(maxValue == classOi[i]){
			positionOi[i] = positionOi[i] + 1;
			++qntOi;
		}

		if(maxValue == classPesq[i]){
			positionPesq[i] = positionPesq[i] + 1;
			++qntPesq;
		}

		if(maxValue == classSair[i]){
			positionSair[i] = positionSair[i] + 1;
			++qntSair;
		}

		if(maxValue == classVaiCho[i]){
			positionVaiCho[i] = positionVaiCho[i] + 1;
			++qntVaiCho;
		}

		if(maxValue == classVerNot[i]){
			positionVerNot[i] = positionVerNot[i] + 1;
			++qntVerNot;
		}
	}

	// preenche a matriz
	for(int k = 0; k < 55; ++k){

		if(qntCalen > 0){
			int j = 0;
			while(qntCalen > 0){
				if(positionCalen[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][0] += 1;
					--qntCalen;
				}
			++j;
			}
		}

		if(qntAbrirCalc > 0){
			int j = 0;
			while(qntAbrirCalc > 0){
				if(positionAbrirCalc[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][1] += 1;
					--qntAbrirCalc;
				}
			++j;
			}
		}


		if(qntAlarme > 0){
			int j = 0;
			while(qntAlarme > 0){
				if(positionAlarme[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][2] += 1;
					--qntAlarme;
				}
			++j;
			}
		}


		if(qntBoaNoite > 0){
			int j = 0;
			while(qntBoaNoite > 0){
				if(positionBoaNoite[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][3] += 1;
					--qntBoaNoite;
				}
			++j;
			}
		}


		if(qntBomDia > 0 ){
			int j = 0;
			while(qntBomDia > 0){
				if(positionBomDia[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][4] += 1;
					--qntBomDia;
				}
			++j;
			}
		}

		if(qntComoTempo > 0){
			int j = 0;
			while(qntComoTempo > 0){
				if(positionComoTempo[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][5] += 1;
					--qntComoTempo;
				}
			++j;
			}
		}

		if(qntOi > 0){
			int j = 0;
			while(qntOi > 0){
				if(positionOi[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][6] += 1;
					--qntOi;
				}
			++j;
			}


		if(qntPesq > 0){
			int j = 0;
			while(qntPesq > 0){
				if(positionPesq[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][7] += 1;
					--qntPesq;
				}
			++j;
			}
		}


		if(qntSair > 0){
			int j = 0;
			while(qntSair > 0){
				if(positionSair[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][8] += 1;
					--qntSair;
				}
			++j;
			}
		}

	
		}


		if(qntVaiCho > 0){
			int j = 0;
			while(qntVaiCho > 0){
				if(positionVaiCho[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][9] += 1;
					--qntVaiCho;
				}
			++j;
			}
		}


		if(qntVerNot > 0){
			int j = 0;
			while(qntVerNot > 0){
				if(positionVerNot[j] == 1){
					int linha = (int)j / 5;
					matrix[linha][10] += 1;;
					--qntVerNot;
				}
			++j;
			}
		}
	}
		


	//armazena em uma matriz
	int diagonal = 0;
	for(int i = 0; i < 11; ++i){
		diagonal = diagonal + matrix[i][i];
	}
	cout<<"Score: "<<diagonal<<endl;


	printFile(sequence, diagonal);



	//imprimir em um txt
	// for(int i = 0; i < 11; ++i){
	// 	for(int j = 0; j < 11; ++j){
	// 		cout<<matrix[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }
	


	return 0;
}