#include <stdio.h>

void fneuronio(double *entradas, double *pesos, double limiar, int tamanho, int *ativavel){

  double somap=0;
  int i=0;

  while(tamanho>0){
    somap= (*(entradas+i))*(*(pesos+i));
    tamanho--;
    i++;
  }

  if(somap>limiar)
  *ativavel=1;
  else
  *ativavel=0;
}

int main(){


  double limiar,entradas[9],pesos[9];
  int ativavel;

  for(int i=0;i<3;i++)
    scanf("%lf", &entradas[i]);

  for(int i=0;i<3;i++)
    scanf("%lf", &pesos[i]);

  scanf("%lf", &limiar);


  fneuronio(entradas,pesos,limiar,10,&ativavel);

  if(ativavel == 1)
    printf("Neuronio ativado!");
  else
    printf("Neuronio desativado!\n");

  return 0;
}
