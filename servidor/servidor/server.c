//
//  main.c
//  servidor
//
//  Created by Ribeiro on 12/10/23.
//

#include <stdio.h>
#include <string.h>
//sera feito

//print das informações que forem solicitadas

//faz um switch case perguntando oq precisa

//info a serem espostas:
    //quantidade que cada obra teve venda
    //quantidade de cada tipo de ingreço (meia inteira izenta)
    //fazer media das respostas que seram de 0 a 10 e mostras a media que esta sendo aquela obra
    //oq mais quier
//variaveis globais
int resposta[5];
int entradaObra;
float media;

char obraApresentada[50];

void acharTema(int indicadoreObra){
    switch (indicadoreObra){
        case 1:
            strcpy(obraApresentada, "150 anos de Santos Dumont");
            break;
        case 2:
            strcpy(obraApresentada, "100 anos da arte moderna");
            break;
        case 3:
            strcpy(obraApresentada, "Jogos olimpicos de paris 2024");
            break;
        case 4:
            strcpy(obraApresentada, "Inteligencia Artificial");
            break;
    }
}

void DBsatisfacao(int indicadoreObra, int select){
    acharTema(indicadoreObra);
    FILE *DBSatisfacao = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBSatisfacao.csv", "r");
    if (DBSatisfacao == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    char linha [100];
    if(select==1){
        double mediaGeral=0.0;
        int quantidadeRespostas=0;
        while(fgets(linha, 100, DBSatisfacao)!= NULL){
            sscanf(linha, "\n%d;%d;%d;%d;%d;%d;%f",&entradaObra,&resposta[0],&resposta[1],&resposta[2],&resposta[3],&resposta[4],&media);
            if(indicadoreObra==entradaObra){
                quantidadeRespostas ++;
                mediaGeral = mediaGeral + media;
            }
        }
        mediaGeral = mediaGeral/quantidadeRespostas;
        printf("\nEntrada para: %s\nMedia: %.2f",obraApresentada,mediaGeral);
        fclose(DBSatisfacao);
    }
    else if(select==2){
        printf("A seguir todas as respostas de satisfação\nTema %s\n",obraApresentada);
        while(fgets(linha, 100, DBSatisfacao)!= NULL){
            sscanf(linha, "\n%d;%d;%d;%d;%d;%d;%f",&entradaObra,&resposta[0],&resposta[1],&resposta[2],&resposta[3],&resposta[4],&media);
            if(indicadoreObra==entradaObra){
                for(int repet=0; repet<5; repet++){
                    printf(" %i|",resposta[repet]);
                }
                printf("\n");
            }
        }
        fclose(DBSatisfacao);
    }
    else if(select==3){
        int linhaAtual=0;
        printf("A seguir todas as respostas de satisfação\n");
        while(fgets(linha, 100, DBSatisfacao)!= NULL){
            linhaAtual++;
            sscanf(linha, "\n%d;%d;%d;%d;%d;%d;%f",&entradaObra,&resposta[0],&resposta[1],&resposta[2],&resposta[3],&resposta[4],&media);
            if(linhaAtual>1){
                printf("Obra: %i->  ",entradaObra);
                for(int repet=0; repet<5; repet++){
                    printf(" %i|",resposta[repet]);
                }
                printf("\n");
            }
        }
    }
}
void mostrarIndicadores(int select){
    int indicadoreObra=0;
    
    int token;
    int entrada;
    int quantidade;
    int tipoEntrada;
    int quantidadeComprada;
    double receitaFinal=0.0;
    double quantidadeTotalVendida=0.0;
    double receita=0.0;

    double quantidadeRestanteobra1 =0.0;
    double quantidadeRestanteobra2 =0.0;
    double quantidadeRestanteobra3 =0.0;
    double quantidadeRestanteobra4 =0.0;
    
    switch(select){
        case 1:
            printf("\nQual obra quer ver a media das respostas?\n");
            printf("1 - 150 anos de Santos Dumont\n");
            printf("2 - 100 anos da arte moderna\n");
            printf("3 - Jogos olimpicos de paris 2024\n");
            printf("4 - Inteligencia Artificial\n");
            scanf("%i",&indicadoreObra);
            DBsatisfacao(indicadoreObra,select);
            break;
        case 2:
            printf("\nQual obra quer ver todas as notas?\n");
            printf("1 - 150 anos de Santos Dumont\n");
            printf("2 - 100 anos da arte moderna\n");
            printf("3 - Jogos olimpicos de paris 2024\n");
            printf("4 - Inteligencia Artificial\n");
            scanf("%i",&indicadoreObra);
            DBsatisfacao(indicadoreObra,select);
            break;
        case 3:
            DBsatisfacao(indicadoreObra,select);
            break;
        case 4:
            printf("\nQual obra quer ver os indicadores de venda?\n");
            printf("1 - 150 anos de Santos Dumont\n");
            printf("2 - 100 anos da arte moderna\n");
            printf("3 - Jogos olimpicos de paris 2024\n");
            printf("4 - Inteligencia Artificial\n");
            scanf("%i",&indicadoreObra);
            FILE *DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r");
            if (DBToken == NULL) {
                printf("Erro ao abrir o arquivo.\n");
            }
            char linha [100];
            while(fgets(linha, 100, DBToken)!=NULL){
                sscanf(linha, "%i;%d;%d;%d;%d", &token, &entrada, &quantidade, &tipoEntrada, &quantidadeComprada);
                if(indicadoreObra==entrada){
                    if(tipoEntrada==1){
                        receita = quantidadeComprada*30;
                    }
                    else if(tipoEntrada==2){
                        receita = quantidadeComprada*15;
                    }
                    else if(tipoEntrada==3){
                        receita = quantidadeComprada*0;
                    }
                    receitaFinal = receitaFinal + receita;
                    quantidadeTotalVendida = quantidadeTotalVendida + quantidadeComprada;
                }
            }
            acharTema(indicadoreObra);
            printf("Obra: %s",obraApresentada);
            printf("Quantidade total vendida: %.1f",quantidadeTotalVendida);
            printf("Valor de receita foi: R$ %.1f",receitaFinal);
            fclose(DBToken);
            break;
        case 5:
            printf("Quantidades restantes das obras:\n");
            FILE *DBTokenFaltantes = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r");
            if (DBTokenFaltantes == NULL) {
                printf("Erro ao abrir o arquivo.\n");
            }
            while(fgets(linha, 100, DBTokenFaltantes)!=NULL){
                sscanf(linha, "%i;%d;%d;%d;%d", &token, &entrada, &quantidade, &tipoEntrada, &quantidadeComprada);
                if(entrada==1){
                    if(quantidade>0){
                        quantidadeRestanteobra1 = quantidadeRestanteobra1 + quantidade;
                    }
                }
                if(entrada==2){
                    if(quantidade>0){
                        quantidadeRestanteobra2 = quantidadeRestanteobra2 + quantidade;
                    }
                }
                if(entrada==3){
                    if(quantidade>0){
                        quantidadeRestanteobra3 = quantidadeRestanteobra3 + quantidade;
                    }
                }
                if(entrada==4){
                    if(quantidade>0){
                        quantidadeRestanteobra4 = quantidadeRestanteobra4 + quantidade;
                    }
                }
                
            }
            if(quantidadeRestanteobra1>0){
                printf("150 anos de Santos Dumont: %1.f\n",quantidadeRestanteobra1);
            }
            if (quantidadeRestanteobra2>0){
                printf("100 anos da arte moderna: %1.f\n",quantidadeRestanteobra2);
            }
            if (quantidadeRestanteobra3>0){
                printf("Jogos olimpicos de paris 2024: %1.f\n",quantidadeRestanteobra3);
            }
            if (quantidadeRestanteobra4>0){
                printf("Inteligencia Artificial: %1.f\n",quantidadeRestanteobra4);
            }
    }

}

int main(int argc, const char * argv[]) {
    int select;
    printf("O que deseja ver?\n");
    do{
        printf("1- Media das respostas de satisfação.\n");
        printf("2- Todas as respostas de satisfação de um tema.\n");
        printf("3- Todas as respostas de satisfação de todos os temas.\n");
        printf("4- Quantidade de vendas com valores.\n");
        printf("5- Quantidade de ingreço disponiveis para uso.\n");
        scanf("%i",&select);
    }while(!(select==1||select==2||select==3||select==4||select==5));
    mostrarIndicadores(select);
    return 0;
}
