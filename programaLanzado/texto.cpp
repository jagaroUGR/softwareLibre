//generates the text for training tesseract
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale>
#include <list>
#include <wchar.h>
#include <list>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc,char* argv[]){
  char* locale;  
  locale = setlocale(LC_ALL,"");//we should set the Unix environment variable local
				//LC_ALL=en_US.utf8

  FILE *of;
  of = fopen("entrenamiento.txt","w");
  //wprintf ("%ls\n",locale);

  //convert decimal in hexadecimal
  int car;
  char buffer[20];
  list<int> lista;

  for(int i=0;i<0xFF;i++){
    int val= 0x1200;
    val+=i;
    if(val!=0x1249 && val!=0x124E && val!=0x124F && val!=0x1257 && val!=0x1259 && val!=0x125E && val!=0x125F && val!=0x1289 && val!=0x128E && val!=0x128F && val!=0x12B1 && val!=0x12B6 && val!=0x12B7 && val!=0x12BF && val!=0x12C1 && val!=0x12C6 && val!=0x12C7 && val!=0x12D7){
      wprintf(L"numero:%d\thex:%x\tcaracter de prueba %lc\n",val,val,val);
      for(int j=0;j<10;j++){
        lista.push_back(val);
      }
      //

    }
  }

   for(int i=0;i<0x7C;i++){
    int val= 0x1300;
    val+=i;
    if(val!=0x1311 && val!=0x1316 && val!=0x1317 && val!=0x1311 && val!=0x135B && val!=0x135C && val!=0x137D && val!=0x137E && val!=0x137F){
      wprintf(L"numero:%d\thex:%x\tcaracter de prueba %lc\n",val,val,val);
      for(int j=0;j<20;j++){
        lista.push_back(val);
      }
      //

    }
  }

  //Mostramos y eliminamos elementos de la lista de forma aleatoria.
  list<int>::iterator lit(lista.begin()), 
			    lend(lista.end());
  int pos;
  wprintf(L"\n\n\n");

  srand(time(NULL));
  while(lista.size()!=0){
    pos = rand() % lista.size();
    advance(lit,pos);
    fwprintf(of,L"%lc ",*lit);
    lit=lista.erase(lit);
    lit=lista.begin();
  }
  
  fclose(of);
  
  
  return 0;
}
