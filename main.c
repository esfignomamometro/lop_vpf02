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

void processar_e_exibir_relatorio() {
    char dados[] = "Caderno,10,5.00Caneta,20,2.50Lápis,15,1.00Borracha,5,0.50Régua,8,3.00Calculadora,3,25.00";
    
    Produto produtos[MAX_PRODUTOS];
    int qtd_produtos = 0;
    float faturamento_total = 0;
    
    int tamanho_texto = strlen(dados);
    int indice_texto = 0;


    while (indice_texto < tamanho_texto && qtd_produtos < MAX_PRODUTOS) {
        
        int i = 0;
        while (dados[indice_texto] != ',' && indice_texto < tamanho_texto) {
            produtos[qtd_produtos].nome[i] = dados[indice_texto];
            i++;
            indice_texto++;
        }
        produtos[qtd_produtos].nome[i] = '\0';
        
        indice_texto++; 

        int caracteres_lidos;
        sscanf(&dados[indice_texto], "%d%n", &produtos[qtd_produtos].quantidade, &caracteres_lidos);
        indice_texto += caracteres_lidos; 
        
        indice_texto++;


        sscanf(&dados[indice_texto], "%f%n", &produtos[qtd_produtos].preco_unitario, &caracteres_lidos);
        indice_texto += caracteres_lidos; 

        produtos[qtd_produtos].total_vendas = produtos[qtd_produtos].quantidade * produtos[qtd_produtos].preco_unitario;
        faturamento_total += produtos[qtd_produtos].total_vendas;
        
        qtd_produtos++;
    }

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
    processar_e_exibir_relatorio();
    return 0;
}
