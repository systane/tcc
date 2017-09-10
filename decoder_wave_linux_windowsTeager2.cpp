#include<stdio.h>
#include<math.h>
#include <string>
#include<iostream>
#include <fstream>
using std::cout; using std::endl; using std::string; using std::ofstream;
//---------------------------------------
int main(int i,char* n[]){

  string file_path_parameter = n[1];
  string name_parameter;
  int position_parameter_name;
  int size_path_parameter;
  int real_size;


  size_path_parameter = file_path_parameter.size();
  position_parameter_name = file_path_parameter.find("/",0);
  real_size = size_path_parameter - 5;
  name_parameter = file_path_parameter.substr(position_parameter_name+1, real_size-position_parameter_name);
  /*
  cout<<"caminho do parametro: "<<file_path_parameter<<endl;
  cout<<"nome do audio: "<<name_parameter<<endl;*/

  void analisa_dados_brutos(double*,int, string name_parameter[]);
  //void cria_arquivos(string name_parameter[]);                                        //criar os arquivos .txt parar guardar as amostragem dos audios
  short converte2de8para1de16(unsigned char, unsigned char);
  FILE* fr;

  if(((fr=fopen(n[1],"rb"))!=NULL))
  {
    struct
          {
            unsigned char riff[4];
            unsigned int len;
          }   

    riff_header;
    fread(&riff_header,sizeof(riff_header),1,fr);
    std::cout<<"\nArquivo do tipo: "<<riff_header.riff[0]<<riff_header.riff[1]<<riff_header.riff[2]<<riff_header.riff[3];
    std::cout<<"\nTamanho excluindo header: "<<riff_header.len;

    ///////////////////////////////////////////////////////////////////////////

    unsigned char wave[4];
    fread(&wave,sizeof(wave),1,fr); //////
    std::cout<<"\nSub-Tipo: "<<wave[0]<<wave[1]<<wave[2]<<wave[3];

    ///////////////////////////////////////////////////////////////////////////
    struct
          { 
            unsigned char id[4];
            unsigned int len;
          }
    riff_chunk;
    fread(&riff_chunk,sizeof(riff_chunk),1,fr);
    std::cout<<"\nIdentificador: "<<riff_chunk.id[0]<<riff_chunk.id[1]<<riff_chunk.id[2]<<riff_chunk.id[3];
    std::cout<<"\nComprimento do chunk apos header: "<<riff_chunk.len;

    //////////////////////////////////////////////////////////////////////////////
    struct
          {
            unsigned short formattag;
            unsigned short numberofchannels;
            unsigned int samplingrate;
            unsigned int avgbytespersecond;
            unsigned short blockalign;
          }
    wave_chunk;
    fread(&wave_chunk,sizeof(wave_chunk),1,fr);

    //tratamento de uma excessao que costuma aparecer em alguns arquivos wav... O correto seriam 16 bytes, as vezes aparecem 18 ou mais...
    if(riff_chunk.len>16)
      {
        unsigned char excesso;
        for(int i=0;i<riff_chunk.len-16;i++)
          fread(&excesso,sizeof(excesso),1,fr);
      }
    //fim do tratamento da excess?
    std::cout<<"\nCategoria do formato: "<<wave_chunk.formattag;
    std::cout<<"\nNumero de canais: "<<wave_chunk.numberofchannels;
    std::cout<<"\nTaxa de amostragem: "<<wave_chunk.samplingrate;
    std::cout<<"\nMedia do num. de bps: "<<wave_chunk.avgbytespersecond;
    std::cout<<"\nAlinhamento do bloco em bytes: "<<wave_chunk.blockalign;

    //////////////////////////////////////////////////////////////////////////////

    if(wave_chunk.formattag==1) //PCM
    {
      int resolucao=(wave_chunk.avgbytespersecond * 8)/(wave_chunk.numberofchannels * wave_chunk.samplingrate);// pq nao bitssample
      std::cout<<"\nResolucao: "<<resolucao;

      struct
            {
              unsigned char data[4];
              unsigned int chunk_size;
            }
      header_data_chunk;

      fread(&header_data_chunk,sizeof(header_data_chunk),1,fr);
      std::cout<<"\nIdentificacao: "<<header_data_chunk.data[0]<<header_data_chunk.data[1]<<header_data_chunk.data[2]<<header_data_chunk.data[3];
      std::cout<<"\nTamanho do chunk de dados: "<<header_data_chunk.chunk_size;
      std::cout<<"\nNumero de frames para amostrar: "<<header_data_chunk.chunk_size/wave_chunk.blockalign;

      int tamanho_da_janela=header_data_chunk.chunk_size/wave_chunk.blockalign;

      std::cout<<"\nTamanho da janela: "<<tamanho_da_janela<<endl;
      if((resolucao==8) && (wave_chunk.numberofchannels==1))
      {
        unsigned char waveformdata;
        double* amostras_no_tempo = new double[tamanho_da_janela];
        for(int i=0;i<tamanho_da_janela;i++)
          {
            fread(&waveformdata,sizeof(waveformdata),1,fr);
            amostras_no_tempo[i]=(double)waveformdata;
          }

        analisa_dados_brutos(&amostras_no_tempo[0],tamanho_da_janela, &name_parameter);
      }
      else if((resolucao==8) && (wave_chunk.numberofchannels==2))
      {
        unsigned char waveformdata_right;
        unsigned char waveformdata_left;
        double* amostras_no_tempo_left = new double[tamanho_da_janela];
        double* amostras_no_tempo_right = new double[tamanho_da_janela];
        for(int i=0;i<tamanho_da_janela;i++)
          {
            fread(&waveformdata_left,sizeof(waveformdata_left),1,fr);
            fread(&waveformdata_right,sizeof(waveformdata_right),1,fr);

            amostras_no_tempo_right[i]=(double)waveformdata_right;
            amostras_no_tempo_left[i]=(double)waveformdata_left;
          }

        analisa_dados_brutos(&amostras_no_tempo_left[0],tamanho_da_janela, &name_parameter);
      //  analisa_dados_brutos(&amostras_no_tempo_right[0],tamanho_da_janela, &name_parameter);
      }
      else if((resolucao==16) && (wave_chunk.numberofchannels==1))
      {
        unsigned char waveformdata_lsb, waveformdata_msb;
        double* amostras_no_tempo = new double[tamanho_da_janela];
        for(int i=0;i<tamanho_da_janela;i++)
          {
            fread(&waveformdata_lsb,sizeof(waveformdata_lsb),1,fr);
            fread(&waveformdata_msb,sizeof(waveformdata_msb),1,fr);
            amostras_no_tempo[i]=(double)converte2de8para1de16(waveformdata_lsb,waveformdata_msb);
          }

        analisa_dados_brutos(&amostras_no_tempo[0],tamanho_da_janela, &name_parameter);
      }
      else if ((resolucao==16) && (wave_chunk.numberofchannels==2))
      {
        unsigned char waveformdata_lsb_left, waveformdata_lsb_right, waveformdata_msb_left, waveformdata_msb_right;
        double* amostras_no_tempo_left = new double[tamanho_da_janela];
        double* amostras_no_tempo_right = new double[tamanho_da_janela];
        for(int i=0;i<tamanho_da_janela;i++)
            {
              fread(&waveformdata_lsb_left,sizeof(waveformdata_lsb_left),1,fr);
              fread(&waveformdata_msb_left,sizeof(waveformdata_msb_left),1,fr);
              fread(&waveformdata_lsb_right,sizeof(waveformdata_lsb_right),1,fr);
              fread(&waveformdata_msb_right,sizeof(waveformdata_msb_right),1,fr);
              amostras_no_tempo_left[i]=(double)converte2de8para1de16(waveformdata_lsb_left,waveformdata_msb_left);
              amostras_no_tempo_right[i]=(double)converte2de8para1de16(waveformdata_lsb_right,waveformdata_msb_right);
            }

        analisa_dados_brutos(&amostras_no_tempo_left[0],tamanho_da_janela, &name_parameter);
       // analisa_dados_brutos(&amostras_no_tempo_right[0],tamanho_da_janela, &name_parameter);
      }
      else
          std::cout<<"Resolucao ou nmero de canais invalido(s)";

    }
    else
        std::cout<<"FORA DO FORMATO PCM...";
        fclose(fr);
  }
  else
      std::cout<<"Arquivo nao existe ou nao pode ser aberto";

  std::cout<<"\n\n\n";
}
//--------------------------------------------------------
short converte2de8para1de16(unsigned char lsb, unsigned char msb){

  return(((msb&0x80)>>7)*(32768) +
         ((msb&0x40)>>6)*(16384) +
         ((msb&0x20)>>5)*(8192) +
         ((msb&0x10)>>4)*(4096) +
         ((msb&0x08)>>3)*(2048) +
         ((msb&0x04)>>2)*(1024) +
         ((msb&0x02)>>1)*(512) +
         ((msb&0x01))*(256) +
         ((lsb&0x80)>>7)*(128) +
         ((lsb&0x40)>>6)*(64) +
         ((lsb&0x20)>>5)*(32) +
         ((lsb&0x10)>>4)*(16) +
         ((lsb&0x08)>>3)*(8) +
         ((lsb&0x04)>>2)*(4) +
         ((lsb&0x02)>>1)*(2) +
         (lsb&0x01));
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

double energy(double * input_vector, int length){// function energy
    double e = 0;
    for(int i = 0; i < length; i++)
        e += pow(input_vector[i],2);
    return(e);
}


//----------------------------------------------------------------------------------------------------------

double energyTeager(double * input_vector, int length){// function energy of Teager
    double *teager = new double[length-2];
    for(int i =   1; i < length-1; i++)
        teager[i-1] += pow(input_vector[i],2) - (input_vector[i-1] * input_vector[i+1]);
    return(teager);
}


//---------------------------------------------------------------------------------------------------------------------------------------------------

void analisa_dados_brutos(double * s, int m, string *name_parameter) {//sinal e seu tamanho


  int L = 0; // partial lengths
  double C = 10; // the desired value, being 0<C<100
  int T = ((100/C) - ((int)(100/C)) == 0) ? (100/C)-1 : (int)(100/C); // the number of elements in T
  double *f = new double[T]; // dynamic vector declaration
  //double z = energy(&s[0], m)*((double)(C)/100); //--> function energy
  double z = energyTeager(&s[0], m)*((double)(C)/100); //--> function energy of Teager
        
  int index;
  string name = "Banco_de_amostras/"+(*name_parameter);
    cout<<"\n\n=====================================================\n\n"<<endl;
    cout<<name<<endl;
    ofstream myfile(name.c_str());//abre o arquivo .txt para gravação da amostragem da música e converte name para string
    if(myfile.is_open()){
      cout<<"abriu o arquivo com sucesso"<<endl;

      // for (index = 0; index < m; index++){     
      //   myfile<<"valor:"<<s[index]<<endl;//plotar os dados nos arquivos

      //método A3
      for(int k = 0; k<T; k++){
        while(energy(&s[0], L) < ((k+1)*z))
          L++;
        f[k] = (double)(L)/(double)(m);
        printf("\n%.5f",f[k]);
        myfile<<"valor:"<<f[k]<<endl;//plotar os dados nos arquivos          
      }

      myfile.close();
    }
    else{
      cout<<"falha ao abrir o arquivo na pasta Banco_de_amostras"<<endl;
    }

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//ALGORITMO 5 - MÉTODO A3 ================================================
/*
// … ensure that s[.], of length M, is available as input
int L = 0; // partial lengths
double C = (10/100); // the desired value, being 0<C<100
int T = ((100/C) - ((int)(100/C)) == 0) ? (100/C)-1 : (int)(100/C); // the number of elements in T
double *f = new double =[T]; // dynamic vector declaration
double z = energy(&s[0], M)*((double)(C)/100);
for(int k = 0; k<T; k++){
  while(energy(&s[0], L) < ((k+1)*z))
  L++;
  f[k] = (double)(L)/(double)(M);
  }
// at this point, the feature vector, f [.], is ready
// function energy
double energy(double * input_vector, int length){
  double e = 0;
  for(int i = 0; i < length; i++)
  e += pow(input_vector[i],2);
  return(e);
}
// FIM ALGORITMO 5 - MÉTODO A3 ==============================================



*/



