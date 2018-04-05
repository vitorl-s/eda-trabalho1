#include <stdio.h>

void fneuronio(double *, double *, double, int, int *);

int main(){

  double limiar,entradas[10],pesos[10];
  int ativavel;

  for(int i=0;i<10;i++){
    printf("Digite o valor da entrada %d: ", i+1 );
    scanf("%lf", &entradas[i]);
  }

  for(int i=0;i<10;i++){
    printf("Digite o valor do peso %d: ", i+1 );
    scanf("%lf", &pesos[i]);
  }
  printf("Digite o valor do limiar: ");
  scanf("%lf", &limiar);

  fneuronio(entradas,pesos,limiar,10,&ativavel);

  if(ativavel == 1)
    printf("Neuronio ativado!\n");
  else
    printf("Neuronio desativado!\n");

  return 0;
}

void fneuronio(double *entradas, double *pesos, double limiar, int tamanho, int *ativavel){

  double somap=0;
  int i=0;

  while(tamanho>0){
    somap += (*(entradas+i))*(*(pesos+i));
    tamanho--;
    i++;
  }

  if(somap>limiar)
  *ativavel=1;
  else
  *ativavel=0;
}
