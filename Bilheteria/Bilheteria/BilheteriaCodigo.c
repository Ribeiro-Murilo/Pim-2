//
//  Pim
//
//  Created by Ribeiro on 03/10/23.
//
//  Grup{
//        MURILO RIBEIRO                        Ra:N0565C2
//        LUIS ISAAC STREICH AYALA              RA:N314524
//        Gabriel ELIAS SILVA                   Ra:N049596
//        JOSI APARECIDA VELA PEREIRA           RA:G8224J1
//        IGOR APARECIDO FALCÃO FRANCHETO       RA:G7323J5
//        SILAS HENRIQUE GOMES PINTO            RA:N0720H2
//  }

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAMANHO_MAX_CODIGO 5


//variaveis globais
char obraApresentada[30];
int idObraApresentada;
int codigoToken;
int aceitarCompra;


void selecionarObra(){
    switch (idObraApresentada){
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

int apresentacao;
int tipoEntrada=0;
int quantEntrada;
int entrada1[3];
int entrada2[3];
int entrada3[3];
void marcarEntrada(){
    switch (tipoEntrada) {
            case 1:
                entrada1[0] = apresentacao;
                entrada1[1] = tipoEntrada;
                entrada1[2] = quantEntrada;
                break;
            case 2:
                entrada2[0] = apresentacao;
                entrada2[1]= tipoEntrada;
                entrada2[2] = quantEntrada;
                break;
            case 3:
                entrada3[0] = apresentacao;
                entrada3[1]= tipoEntrada;
                entrada3[2] = quantEntrada;
                break;
            default:
                break;
        }
}
void compraDeIngressos(){
    int entradaInteira =30;
    int entradaMeia =15;
    int entradaIsenta =0;
    
    printf("Os valores da entrada são:\n%i Reais para entrada inteira\n%i Reais para meia entrada\n%i Reais para entrada isenta.\n",entradaInteira, entradaMeia, entradaIsenta);
    
    while (!(tipoEntrada==1||tipoEntrada==2||tipoEntrada==3)) {
        printf("Para compara a entrada inteira selecione 1\nPara compara a meia entrada selecione 2\nPara compara a entrada isenta selecione 3\nEntrada: ");
        scanf("%i",&tipoEntrada);
        printf("Qual a quantidade: ");
        scanf("%i",&quantEntrada);
        marcarEntrada();
    }
    
}


void compraTipoEntrada(){
    int entradaInteira =30;
    int entradaMeia =15;
    int entradaIsenta =0;
    
    printf("\nOs valores da entrada são:\n- %i Reais para entrada inteira\n- %i Reais para meia entrada\n- %i Reais para entrada isenta.\n",entradaInteira, entradaMeia, entradaIsenta);
    
    do{
        printf("\nPara compara a entrada inteira selecione 1\nPara compara a meia entrada selecione 2\nPara compara a entrada isenta selecione 3\nEntrada: ");
        scanf("%i",&tipoEntrada);
    }while (tipoEntrada<1 || tipoEntrada>3);
    printf("Qual a quantidade: ");
    scanf("%i",&quantEntrada);
    marcarEntrada();
}

void lancarSistema(){
    FILE *DBToken;
    DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "a");
    if (DBToken == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    if(entrada1[1]==1){
        fprintf(DBToken,"\n%i;%i;%i;%i;%i",codigoToken,entrada1[0],entrada1[2],entrada1[1],entrada1[2]);
    }else if (entrada2[1]==2){
        fprintf(DBToken,"\n%i;%i;%i;%i;%i",codigoToken,entrada2[0],entrada2[2],entrada2[1],entrada2[2]);
    }else if (entrada3[1]==3){
        fprintf(DBToken,"\n%i;%i;%i;%i;%i",codigoToken,entrada3[0],entrada3[2],entrada3[1],entrada3[2]);
    }
    fclose(DBToken);
}

bool buscaValidacao() {
    char linha[256];
    FILE *DBToken;
    DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r");
    if (DBToken == NULL) {
        printf("Erro ao abrir o arquivo CSV.\n");
        return false;
    }
    while (fgets(linha, sizeof(linha), DBToken) != NULL) {
        int tokenRecebido;
        int entradaAtualRecebido;
        int quantidadeAtualRecebido;
        int tipoEntradaRecebido;
        int quatidadeCompradaRecebido;
        sscanf(linha, "%d;%d;%d;%d;%d", &tokenRecebido, &entradaAtualRecebido, &quantidadeAtualRecebido, tipoEntradaRecebido, quatidadeCompradaRecebido);
            if (!(tokenRecebido == codigoToken)) {
                return true;
            }
    }
    fclose(DBToken);
    
    return false;
    
}

void gerarCodigo() {
    srand(time(NULL));
    int codigo=0;
    
    codigo = rand() % 10000;
    codigoToken = codigo;
}

void validarToken() {
    int numLinhasCSV = 3;
    bool codigoValido;
    
    while(!buscaValidacao){
        gerarCodigo();
        buscaValidacao();
    }
    printf("Token para a entrada gerado: %i\n", codigoToken);
}


void confirmarCompra(){
    int comprar;
    int quantidadeIngressos;
    int valorFinal;
    if(entrada1[1]==1){
        idObraApresentada=entrada1[0];
        quantidadeIngressos=entrada1[2];
        valorFinal = quantidadeIngressos * 30;
        printf("Valor final: %i\n",valorFinal);
    }else if (entrada2[1]==2){
        idObraApresentada=entrada2[0];
        quantidadeIngressos=entrada2[2];
        valorFinal = quantidadeIngressos * 15;
        printf("Valor final: %i",valorFinal);
    }else if (entrada3[1]==3){
        idObraApresentada=entrada3[0];
        quantidadeIngressos=entrada3[2];
        valorFinal = quantidadeIngressos * 0;
        printf("Valor final: %i",valorFinal);
    }
    selecionarObra();
    printf("Confirma que deseja comprar %i ingressos para %s?\n",quantidadeIngressos,obraApresentada);
    do{
        printf("1 - Sim\n2 - Não\n");
        scanf("%i", &aceitarCompra);
    }while(!(aceitarCompra==1 || aceitarCompra==2));
    
}

int main() {
    printf("Bilheteria\n");

    for (int repet = 1; repet <= 4; repet++) {
        idObraApresentada = repet;
        selecionarObra();
        printf("Obra %i: %s\n", repet, obraApresentada);
    }

    do {
        printf("Escolha 1-4: ");
        scanf("%i", &apresentacao);
    } while (apresentacao < 1 || apresentacao > 4);
    

    compraTipoEntrada();
    
    gerarCodigo();
        
    buscaValidacao();
    
    validarToken();
    
    confirmarCompra();
    
    if(aceitarCompra==1){
        lancarSistema();
        if(entrada1[1]==1){
            printf("Codigo valido em %i acessos.\n",entrada1[2]);
        }else if (entrada2[1]==2){
            printf("Codigo valido em %i acessos.\n",entrada2[2]);
        }else if (entrada3[1]==3){
            printf("Codigo valido em %i acessos.\n",entrada3[2]);
        }
    }
    return 0;
}
