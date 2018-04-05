#include <stdio.h>

void recebe_notas(double *, int, double *);
void conta_notas(double*, int ,double *, double*);
int percent_aprov(double *, double *, double *, double *);

int main(){

  double notas[10],apr[10],aprovados,reprovados,porcentagemAprov,porcentagemReprov;
  int tamanho;

  for(int i=0;i<10;i++){
    printf("Digite a nota %d: ",i+1 );
    scanf("%lf", notas+i);
  }
  recebe_notas(notas,10,apr);
  conta_notas(apr,10,&aprovados,&reprovados);
  percent_aprov(&aprovados,&reprovados,&porcentagemAprov,&porcentagemReprov);

  printf("Quantidade de aprovados: %.1lf\n", aprovados );
  printf("Quantidade de reprovados: %.1lf\n", reprovados );
  printf("Percentagem de aprovados: %.2lf\n", porcentagemAprov );
  printf("Percentagem de reprovados: %.2lf\n", porcentagemReprov );
    if(percent_aprov(&aprovados,&reprovados,&porcentagemAprov,&porcentagemReprov) == 1)
      printf("Mais da metade da turma foi aprovada!\n");
    else if(porcentagemAprov == 50)
      printf("Metade da turma foi aprovada!\n");
    else
      printf("Mais da metade da turma foi reprovada!\n");

  return 0;
}

void recebe_notas(double *notas,int tamanho,double *apr){
  int i=0;

  while(tamanho>0){
    if(*(notas+i) >= 6)
    *(apr+i) = 1;
    else
    *(apr+i) = 0;
    tamanho--;
    i++;
  }
}

void conta_notas(double *apr,int tamanho,double *aprovados, double *reprovados){
  int i;
  int contadorAprovados=0;
  int contadorReprovados=0;

  while (tamanho>0) {
    if(*(apr+i) == 1){
      contadorAprovados++;
    }
    else
    contadorReprovados++;
    tamanho--;
    i++;
  }
  *aprovados =  contadorAprovados;
  *reprovados = contadorReprovados;
}

int percent_aprov(double *aprovados, double *reprovados, double *porcentagemAprov, double *porcentagemReprov){

  *porcentagemAprov = (*aprovados/(*aprovados + *reprovados))*100;
  *porcentagemReprov = (*reprovados/(*aprovados + *reprovados))*100;

  if(*porcentagemAprov > 50)
  return 1;
  else
  return 0;
}
