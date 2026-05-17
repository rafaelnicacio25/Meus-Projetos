//Analisador de dados

#include <stdio.h>

int main() {
    int numeros[10];
    int maior, menor;
    float soma = 0, media;
    
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    
        if(i == 0) {
            maior = numeros[i];
            menor = numeros[i];
        } else {
            if (numeros[i] > maior) maior = numeros[i];
            if (numeros[i] < menor) menor = numeros[i];
        }
    }
    
    media = soma / 10.0;
    
    printf("\nMenor valor: %d", menor);
    printf("\nMaior valor: %d", maior);
    printf("\nMedia: %.2f", media);
    
    printf("\n\nValores acima da media: ");
    for(int i = 0; i < 10; i++) {
        if (numeros[i] > media) {
            printf("%d ", numeros[i]);
        }
    }
    
    return 0;        
}

//Nesse caso usamos ambas as variáveis, tanto int quanto float, pois usaremos números inteiros e compostos
//o for é usado para ler os números em um determinado começo e fim (o primeiro número colocado e o último)
//o if (i == 0) serve basicamente para comparar o primeiro número com os demais, como se o primeiro número fosse o maior e o menor ao mesmo tempo, aí os próximos números colocados serão os novos maiores e menores da lista
//o i++ é basicamente um somatório de 1 em 1, o i = 0 é o ponto de partida e o i < 10 é o fim