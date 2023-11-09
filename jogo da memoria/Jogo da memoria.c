
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	int matriz[4][4]={1,4,5,7,2,5,8,2,6,3,4,3,7,1,8,6};
	int i, j, c1,c2,c3,c4, tempo=0, acertos=0, erros=0, salvar, jogarnovamente, num=0, respostas[4];
	char inicio,simbolo=4, beep=7, matriz2[4][4]; //para iniciar o programa, faz com que o programa aguarde pelo usuario pressionar ENTER
	srand(time(NULL));
	FILE *arq;
	arq = fopen("jogomemoria2021.txt", "w");

	if (arq == NULL)
{
   printf("Problemas na CRIACAO do arquivo\n");

}
else
{

	
	
	comeco:
	printf("\n\n\n ========================================================================\n");
    printf("                            ***************\n");
    printf("                            JOGO DA MEMÓRIA\n");
    printf("                            ***************\n");
    printf("                      Seja bem vindo ao nosso jogo!\n");
    printf(" ========================================================================\n");
    printf("                         Jogo desenvolvido por:\n");
    printf("\n                          Vinicius Gabriel\n");
    printf("                            Diego Marcon\n");
    printf("                           Rafael Moreira\n");
    printf("                          Evandeilson Silva\n");
    printf(" ========================================================================\n");
    printf("\n                   Precione Enter para começar...");
    fflush(stdin);
    getchar();
    system("cls");
}
	

    
	
	


	
for(i=0;i<4;i++){
		for(j=0;j<4;j++){
		matriz2[i][j]=simbolo;
		}
	}

	
	tempo=5;
	
	do{
		system("cls");
		printf("MEMORIZE OS PARES ABAIXO!! VOCE TEM %i SEGUNDOS\n\n",tempo);
		tempo--;
		for(i=0;i<4;i++){ //linhas da matriz
			for(j=0;j<4;j++){ //colunas da matriz
			printf("%i\t",matriz[i][j]); //imprime a matriz tabulada
			}
			printf("\n\n"); //pula linha na impressao da matriz
		}
		Sleep(1000);		
	}

	while(tempo>0);
	system("cls");
	printf("MUITO BEM, AGORA ENCONTRE OS PARES\n\n");
	

	for(i=0;i<4;i++){ //linhas da matriz
			for(j=0;j<4;j++){ //colunas da matriz
			printf("%c\t",matriz2[i][j]); //imprime a matriz com simbolo ascii
			}
			printf("\n\n"); //pula linha na impressao da matriz
		}
	
 
jgd1:
while(acertos<8 && erros<10){
printf("\nEntre com uma cordenada(max = 4 4): ");
scanf("%d %d", &c1, &c2);
if(c1>4 || c1<1 || c2>4 || c2<1){
printf("coordenada invalida!! Digite de 1 a 4 para linha\ne de 1 a 4 para a coluna.\n");
system("pause");
goto jgd1;
}
printf("O número da posicao eh %d\n", matriz[c1 - 1][c2 -1]);
jgd2:
printf("Entre com outra coordenada: ");
scanf("%d %d", &c3, &c4);
if(c3>4 || c3<1 || c4>4 || c4<1){
printf("coordenada invalida!! Digite de 1 a 4 para linha\ne de 1 a 4 para a coluna.\n");
system("pause");
    goto jgd2;
}
printf("O número da posicao eh %d\n", matriz[c3 - 1][c4 -1]);

c1 = c1 - 1;
c2 = c2 - 1;
c3 = c3 - 1;
c4 = c4 - 1;

if (matriz2[c1][c2]==0 || matriz2[c3][c4]==0){
printf("\nops...Esse par ja foi encontrado\n");
system("pause");
goto jgd1;
}



if (matriz[c1][c2] == matriz[c3][c4]){
	matriz2[c1][c2]=0;
	matriz2[c3][c4]=0;
	

	printf("\ncartas restantes:\n\n");
	for(i=0;i<4;i++){ //linhas da matriz
			for(j=0;j<4;j++){ //colunas da matriz
			printf("%c\t",matriz2[i][j]); //imprime a matriz com simbolo ascii
			}
			printf("\n\n"); //pula linha na impressao da matriz
		}
	
	
acertos++;
printf("%c", beep);
printf("encontrou um par!");


}
else{
	printf("erou!");
	erros++;
}
printf(" acertos:%d",acertos);
printf(" erros:%d\n",erros);

}
if(acertos == 8){

printf("------VOCE ENCONTROU TODOS OS PARES!PARABENS!-----");
} else if (erros == 10){
	printf("------GAME OVER!-----");
}
printf("\n\ndeseja salvar os pontos?\ndigite 1 para SIM e 2 para NAO");
scanf("%d",salvar);
if (salvar == '1'){

	fprintf(arq, "total de acertos:%d\n", acertos);
	fprintf(arq, "total de erros:%d\n", erros);
	fclose(arq);
	printf("dados gravados com sucesso!\n");
	
} else {
	
}
system("cls");
printf("deseja jogar novamente?\ndigite 1 para SIM e 2 para NAO\n");
scanf("%d",jogarnovamente);
if(jogarnovamente == '1'){
	goto comeco;
} else if (jogarnovamente =='2'){
	system("exit");
}
}
