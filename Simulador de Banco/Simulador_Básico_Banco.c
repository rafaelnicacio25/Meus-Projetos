//Simulador Basico de Banco

#include <stdio.h>

int main(){
	float saldo;
	float valor;
	
	int opcao;
	

	printf ("Digite o saldo atual da sua conta: R$ ");
	scanf ("%f", &saldo);
	
	do {
		printf ("---Sistema Bancario---");
		printf ("\n1 - Consultar Saldo");
		printf ("\n2 - Sacar valor");
		printf ("\n3 - Depositar valor");
		printf ("\n4 - Sair");
		printf ("\nEscolha uma opcao: ");
		scanf ("%d", &opcao);		
		
	switch(opcao){
		
		case 1:
			printf ("Seu saldo atual eh: R$ %.2f", saldo);
			break;
			
		case 2:
			printf ("Que valor deseja sacar? R$ ");
			scanf ("%f", &valor);
			
			if (valor > saldo){
				printf ("Saldo insuficiente! \n");
			} else {
				saldo -= valor;
				printf ("Saque efetuado com sucesso! \n");
			}
			break;
				
		case 3:
			printf ("Quanto deseja depositar? R$");
			scanf ("%f", &valor);
			saldo += valor;
			printf ("Saldo depositado com sucesso! \n");
			break;
		
		case 4:
			printf("Saindo... Aguarde um momento.\n");
			break;
		
		default:
			printf ("Opção inexistente! Tente novamente.\n");
	}
	 
	} while(opcao != 4);
	
	return 0;
}

//temos o float e o int para declarar as variáveis
//o do e o while são usados para repetições, nesse caso, eles repetem o menu principal do banco
//o switch é onde escolhemos oque queremos fazer no banco, essas ações estão dentro das cases
//cada case tem um break, para o programa parar de executar aquela ação e volte para o menu principal
//o default, serve para limitar o menu, ou seja, se a pessoa colocar uma opção 5, por exemplo, o programa fala que essa opção não existe