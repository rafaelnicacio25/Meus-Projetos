#include <stdio.h>

int main(){
	int inicio;
	int fim;
	int i;
	int contador = 0;
	
	printf ("Digite o primeiro numero: ");
	scanf ("%d", &inicio);
	
	printf ("Digite o ultimo numero: ");
	scanf ("%d", &fim);
	
	printf ("Pares encontrados: ");
	
    for (i = inicio; i <= fim; i++) {
        
        if (i % 2 == 0) {
            printf("%d ", i);
            contador++; 
        }
    }
	printf ("\nTotal de Pares: %d\n", contador);
	
	return 0;
	
}
//int é usado para números inteiros, no caso as variáveis inicio, fim, i e contador
//for é usado no sentido de "para", tipo ir de um lugar para outro já sabendo o caminho, nesse caso, usamos porque sabemos o início e o fim dos números que devem ser lidos