#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define TAM_TEXTO 100

typedef struct {
    int codigo;
    char titulo[TAM_TEXTO];
    char autor[TAM_TEXTO];
    int status;
} Livro;

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

// Protótipos das funções
void cadastrarLivro();
void consultarLivro();
void emprestarLivro();
void devolverLivro();
void listarLivros();
int buscarPorCodigo(int codigo);

int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Consultar livro\n");
        printf("3 - Emprestar livro\n");
        printf("4 - Devolver livro\n");
        printf("5 - Listar acervo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) { // Melhoria: evita loop infinito se digitar letra
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch(opcao) {
            case 1: cadastrarLivro(); break;
            case 2: consultarLivro(); break;
            case 3: emprestarLivro(); break;
            case 4: devolverLivro(); break;
            case 5: listarLivros(); break;
            case 0: printf("Finalizando sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Erro: Capacidade maxima atingida.\n");
        return;
    }

    int cod;
    printf("\n--- Novo Cadastro ---\n");
    printf("Codigo: ");
    scanf("%d", &cod);
    getchar();

    // Melhoria: Verifica se o código já existe
    if (buscarPorCodigo(cod) != -1) {
        printf("Erro: Ja existe um livro com o codigo %d!\n", cod);
        return;
    }

    biblioteca[totalLivros].codigo = cod;

    printf("Titulo: ");
    fgets(biblioteca[totalLivros].titulo, TAM_TEXTO, stdin);
    biblioteca[totalLivros].titulo[strcspn(biblioteca[totalLivros].titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(biblioteca[totalLivros].autor, TAM_TEXTO, stdin);
    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0;

    biblioteca[totalLivros].status = 0; // 0 = Disponível

    totalLivros++;
    printf("Livro cadastrado com sucesso!\n");
}

int buscarPorCodigo(int codigo) {
    for (int i = 0; i < totalLivros; i++) {
        if (biblioteca[i].codigo == codigo) {
            return i; 
        }
    }
    return -1;
}

void consultarLivro() {
    int cod, indice;
    printf("Digite o codigo: ");
    scanf("%d", &cod);

    indice = buscarPorCodigo(cod);

    if (indice != -1) {
        printf("\n[Livro Encontrado]\n");
        printf("Titulo: %s | Autor: %s | Status: %s\n", 
               biblioteca[indice].titulo, 
               biblioteca[indice].autor, 
               biblioteca[indice].status == 0 ? "Disponivel" : "Emprestado");
    } else {
        printf("Livro nao encontrado.\n");
    }
}

void emprestarLivro() {
    int cod, indice;
    printf("Codigo para emprestimo: ");
    scanf("%d", &cod);

    indice = buscarPorCodigo(cod);

    if (indice != -1) {
        if (biblioteca[indice].status == 0) {
            biblioteca[indice].status = 1;
            printf("Sucesso: Livro emprestado!\n");
        } else {
            printf("Erro: O livro ja esta ocupado.\n");
        }
    } else {
        printf("Erro: Codigo inexistente.\n");
    }
}

void devolverLivro() {
    int cod, indice;
    printf("Codigo para devolucao: ");
    scanf("%d", &cod);

    indice = buscarPorCodigo(cod);

    if (indice != -1) {
        if (biblioteca[indice].status == 1) {
            biblioteca[indice].status = 0;
            printf("Sucesso: Livro devolvido!\n");
        } else {
            printf("Aviso: O livro ja esta disponivel.\n");
        }
    } else {
        printf("Erro: Codigo inexistente.\n");
    }
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("\nBiblioteca vazia.\n");
        return;
    }

    printf("\n%-5s | %-20s | %-20s | %s\n", "ID", "TITULO", "AUTOR", "STATUS");
    for (int i = 0; i < totalLivros; i++) {
        printf("%-5d | %-20s | %-20s | %s\n", 
               biblioteca[i].codigo, 
               biblioteca[i].titulo, 
               biblioteca[i].autor, 
               biblioteca[i].status == 0 ? "Disponivel" : "Emprestado");
    }
}

// o #define cria constantes globais (ex: limites de tamanho) para facilitar a manutencao.
// o typedef struct cria um molde que agrupa diferentes tipos de dados (como texto e números) em um unico objeto (Livro).
// livro biblioteca e o armario fisico (vetor) que armazena todas as estruturas de livros na memoria.
// totalLivros e ariavel de controle que conta quantos livros estao cadastrados.
// scanf le numeros e exige o & para saber onde guardar o valor na memoria.
// getchar Limpa o "lixo" do teclado (o Enter) para não pular as proximas leituras.
// fgets le textos de forma segura, respeitando o limite de espaço para evitar erros.
// strcspn: "Limpa" o texto lido pelo fgets, removendo a quebra de linha indesejada no final.
// o %-20s e um omando de formatacao do printf para criar colunas alinhadas à esquerda, deixando a listagem organizada.