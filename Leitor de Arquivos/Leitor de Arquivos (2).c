//Leitor de arquivos
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char ch[150];

    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo. Verifique se ele existe!\n");
        return 1; 
    }

    printf("Dados encontrados:\n");

    while (fgets(ch, 150, arquivo) != NULL) {
        printf("%s", ch);
    }

    fclose(arquivo);

    return 0;
}