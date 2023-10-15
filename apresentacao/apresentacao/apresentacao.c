//
//  main.c
//  apresentacao
//
//  Created by Ribeiro on 12/10/23.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//aqui sera feito

// autentificação do codigo anteriormente comprado na bilheteria

// apresentação de acordo com o tiket que foi comprado

// perguntas a respeito da obra apresentada

// perguntas pessoais

//upload dos dados recolhidos para o csv


//variaveia globais
char codigoToken[5];
#define TAMANHO_MAX_LINHA 100
int entradaObra;
int quantidade;
int entradaAtual;
int quantidadeAtual;
int tokenProcurado;
int quantidadeRestante;
int valido = -1;  // Inicializa com um valor que indica que o token não foi encontrado
//

void acessarInfoSistema(){
    FILE *DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r");

    if (DBToken == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        //return 1;
    }

    char linha[TAMANHO_MAX_LINHA];

    // Lê cada linha do arquivo
    while (fgets(linha, TAMANHO_MAX_LINHA, DBToken) != NULL) {
        int token;
        int entradaAtual;

        // Extrai os valores de token e entrada da linha
        sscanf(linha, "%d;%d;%d", &token, &entradaAtual, &quantidadeAtual);

                // Verifica se é o token que estamos procurando
        if (token == tokenProcurado) {
            entradaObra = entradaAtual;
            quantidade = quantidadeAtual;
            printf("token:%i\nEntrada: %i\nQuantidade: %i\n",tokenProcurado,entradaObra,quantidade);
            valido=0;
            break;  // Encerra a busca, já encontramos o token colocado pelo user
        }
    }
    if(valido==-1){
        printf("Codigo invalido\n");
    }
        
    fclose(DBToken);
}

void baixaSistema(){
    FILE *DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r+");
    
    if (DBToken == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    char linha[TAMANHO_MAX_LINHA];
    int entradaNova;
    int entradaAtual;
    int quantidadeAtual;
    int token;
    // Lê cada linha do arquivo
    while (fgets(linha, TAMANHO_MAX_LINHA, DBToken) != NULL) {
        // Extrai os valores de token, entrada e quantidade da linha
        sscanf(linha, "%d;%d;%d", &token, &entradaAtual, &quantidadeAtual);
        // Verifica se é o token que estamos procurando
        if (token == tokenProcurado) {
            // Atualiza os valores
            quantidadeRestante = quantidadeAtual-1;
            // Reescreve a linha no arquivo com os novos valores
            fseek(DBToken, -strlen(linha), SEEK_CUR);
            fprintf(DBToken, "%d;%d;%d\n", token, entradaAtual, quantidadeRestante);
            break;
        }
    }
    if(quantidadeRestante>=1){
        printf("Esse Token de acesso esta disponivel para uso para mais %i acessos.",quantidadeRestante);
    }else{
        printf("Esse Token de acesso não esta mais disponivel para uso ou é invalido.");
    }
    fclose(DBToken);
}


int main(int argc, const char * argv[]) {
    do{
        printf("Token: ");
            fgets(codigoToken, sizeof(codigoToken), stdin);

            // Remover o caractere de nova linha (\n) inserido pelo fgets
        codigoToken[strcspn(codigoToken, "\n")] = '\0';
        
        tokenProcurado=atoi(codigoToken);
        acessarInfoSistema();
    }while(valido==-1);
    
    //da baixa do tokem no sistema
    baixaSistema();
    return 0;
}
