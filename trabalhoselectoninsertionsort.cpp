#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include <locale.h>

 struct Cliente{
    char nome[100];
    int conta[5];
    float saldo;
    
  };                       //Declaração da struct com os dado do cliente

 typedef Cliente cliente ;  //apelidando a struct "Cliente" para "cliente"


int movimento=0;
int comparacoes=0;  //Declarando as variveis globais para contagem dos movimentos e comparações

void insertionsort(cliente* c, int tam);
void selectionsort (cliente* c, int tam);
void menu(cliente* c, int tam);
void imprime(cliente* c,int tam);      //Protótipos das funções que serão chamadas durante o código

 int main(){
   
   cliente *vetor; //chamando o ponteiro do tipo struct cliente e as variáveis
   int nclientes,op;  
   float t;
   

   printf("Digite a quantidade de Clientes:"); //recebendo a quantidade de clientes
   scanf("%d",&nclientes);
   
   vetor = (cliente*)malloc(nclientes*sizeof(cliente)); //alocação dos clientes na memoria

   for(int i = 0; i<nclientes;i++){
       printf("Digite um nome para o Cliente:\n"); //cadastro dos clientes
       fflush(stdin);
       gets(vetor[i].nome);
       
       printf("Digite o numero da conta do cliente:\n"); 
       scanf("%d",&vetor[i].conta);
       printf("Digite o saldo do cliente:\n");
       scanf("%f",&vetor[i].saldo);
       printf("\n\n");
   }

  
 do{
  
  
  
  printf("0 - Sair\n");
  printf("1 - Ordenar clientes pelo Selection Sort \n");  //menu de interação
  printf("2 - Ordenar clientes pelo Insertion Sort \n");
  printf("3 - imprimir clientes digitados\n");
  printf("Digite uma opcao: \n");
  scanf("%i",&op);
  
  getchar();

  switch (op){
    case 0:
     printf("Programa finalizado!");
    break;
    case 1:
    t=clock(); //t recebe clock()
    selectionsort(vetor,nclientes); //chamando a função selection e imprimindo
    imprime( vetor, nclientes);
    t= clock()- t; //tempo final - tempo inicial
    printf("tempo de execucao:%2.f\n",t);
    printf("comparacoes entre os saldos no selectionsort:%i\n",comparacoes);//imprimindo comparações e movimento e tempo de execução do SelectionSort
    printf("movimentos entre os saldos no selectionsort:%i\n\n",movimento);
    break;
    case 2:
    t=clock();//t recebe clock() 
    insertionsort(vetor,nclientes);//chamando a função insertion e imprimindo
    imprime( vetor, nclientes);
    t= clock()- t;//tempo final - tempo inicial
    printf("tempo de execucao:%2.f\n",t);
    printf("comparacoes entre os saldos no inserctionsort:%i\n",comparacoes);//imprimindo comparações e movimento e tempo de execução do InsertionSort
    printf("movimentos entre os saldos insertionsort:%i\n\n",movimento);
    break;
    case 3:
    imprime(vetor, nclientes);
    break;
  }
  
  
  }while(op!=0);


   return 1;
 }



void insertionsort(cliente* c, int tam){ //insertion: recebe e já ordena os dados
	int i,j;         //Declaração das flags e uma variável auxiliar para struct client
  cliente aux;  
	for (i= 1; i<tam; i++){  //laço for que vai percorrer o vetor até "tam" que é o número de clientes
		aux = c[i];          //"aux" recebe o c de índice i e comparaçao acresce em 1 cada vez que o laço é repetido
		for( j=i; j>0 && aux.saldo <c[j-1].saldo; j--) movimento++; //for para mover os saldos maiores para frente do saldo i
		c[j]= c [j-1];comparacoes ++;      //j recebe i enquanto j maior que 0.j decresce para o aux.saldo percorrer j e ser colocado na posição do número que é menor a ele. e cada vez que o laço se repete acresce movimento

		c[j]=aux;                   
	}
  
}


void selectionsort (cliente* c, int tam){ //SelectionSort: procura o menor valor e bota na primeira posição
     int i, j, menor;  //declaração das flags incluindo flag que recebera o menor valor e a que realizará as trocas
     cliente troca;
     
     for(i=0; i < tam-1; i++){//laço irá percorrer todos os valores do vetor e selecionará o menor valor e "menor" receberá esse valor
          menor = i;
          
          for(j= i + 1; j< tam; j++){      //j receberá um valor que será comparado ao de i, se ele for menor a partir de agora j receberá menor(será o menor valor).E comparacoes acresce 
               if(c[j].saldo< c[menor].saldo)
               menor = j;
               comparacoes++;
          }
          if (i != menor){        //se o "i" nao for o menor valor ele troca de posiçao com "menor" que agora no caso é o menor valorE o movimento acresce
               troca = c[i]; 
               c[i]=c[menor];
               c[menor]= troca;
               movimento++;
          }
     }


}



void imprime(cliente* c, int tam){ //imprime os clientes digitados sem estar na ordem
	
	int i;
	
	printf("\n--------------Ordem dos Clientes:--------------\n\n");
	
	for(i = 0; i < tam; i++)                                            //função imprime enquanto i for menor ou igual que tamanho: printf
	{	
		printf("Nome: %s Numero da Conta: %d\nSaldo:R$%.2f\n\n",c[i].nome,c[i].conta,c[i].saldo);
		
	}
	

}
