#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    int quantidade;
    float preco_unitario;
    float total_vendas;
} Produto;

void gerar_relatorio() {
    FILE *arq = fopen("vendas.csv", "r");
    
    if (arq == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo vendas.csv!\n");
        return;
    }

    Produto produtos[MAX_PRODUTOS];
    int qtd_produtos = 0;
    float faturamento_total = 0;

    char cabecalho[100];
    fgets(cabecalho, sizeof(cabecalho), arq);

    char c;

    while ((c = fgetc(arq)) != EOF && qtd_produtos < MAX_PRODUTOS) {
        
        int i = 0;
        while (c != ',' && c != EOF) {
            produtos[qtd_produtos].nome[i] = c;
            i++;
            c = fgetc(arq);
        }
        produtos[qtd_produtos].nome[i] = '\0';

        fscanf(arq, "%d,", &produtos[qtd_produtos].quantidade);
        fscanf(arq, "%f", &produtos[qtd_produtos].preco_unitario);

        produtos[qtd_produtos].total_vendas = produtos[qtd_produtos].quantidade * produtos[qtd_produtos].preco_unitario;
        faturamento_total += produtos[qtd_produtos].total_vendas;
        
        qtd_produtos++;
    }

    fclose(arq);

    printf("=====================================================================\n");
    printf("                       RELATÓRIO DE VENDAS                           \n");
    printf("=====================================================================\n");
    printf("%-15s | %-11s | %-16s | %-15s\n", "Produto", "Qtd Vendida", "Preco Unit. (R$)", "Total Vendas (R$)");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < qtd_produtos; i++) {
        printf("%-15s | %-11d | %-16.2f | %-15.2f\n", 
               produtos[i].nome, 
               produtos[i].quantidade, 
               produtos[i].preco_unitario, 
               produtos[i].total_vendas);
    }

    printf("---------------------------------------------------------------------\n");
    printf("%-47s | R$ %-12.2f\n", "FATURAMENTO TOTAL DO PERIODO:", faturamento_total);
    printf("=====================================================================\n");
}

int main() {
    gerar_relatorio();
    return 0;
}
