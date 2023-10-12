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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int gerarCodigo(){
    srand(time(NULL));
        // Gera um número aleatório entre 0 a 9999
        int codigo = rand() % 10000;
        return codigo;
}

char obraApresentada[30];
int idObraApresentada;
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
            strcpy(obraApresentada, "Tema a definir");
            break;
    }
}

//parte de compra de ingressos
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
    
    
    
    
    
    
    int outraEntrada;
    printf("Deseja comprar outro tipo de ingresso?\n");
    do{
        printf("Para compara outro tipo de entrada\n1 para sim \n2 para não: ");
        scanf("%i",&outraEntrada);
        if(outraEntrada==1){
            outraEntrada=0;
        }else if(outraEntrada==2)
            printf("teste");
            //perguntasPessois();
    }while (!(outraEntrada==1||outraEntrada==2));
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

//escolhe o tipo de entrada
void compraTipoEntrada(){
    int entradaInteira =30;
    int entradaMeia =15;
    int entradaIsenta =0;
    
    printf("Os valores da entrada são:\n- %i Reais para entrada inteira\n- %i Reais para meia entrada\n- %i Reais para entrada isenta.\n",entradaInteira, entradaMeia, entradaIsenta);
    
    do{
        printf("Para compara a entrada inteira selecione 1\nPara compara a meia entrada selecione 2\nPara compara a entrada isenta selecione 3\nEntrada: ");
        scanf("%i",&tipoEntrada);
    }while (tipoEntrada<1 || tipoEntrada>3);
    printf("Qual a quantidade: ");
    scanf("%i",&quantEntrada);
    marcarEntrada();
}

int main(int argc, char *argv[]) {
    printf("Bilhereria\n");
    
    //printa na tela quais as obras
    for (int repet=1; repet<=4; repet++) {
        idObraApresentada = repet;
        selecionarObra();
        printf("Obra %i: %s\n",repet, obraApresentada);
    }
    
    //escolhe a obra
    do{
        printf("Escolha 1-4: ");
        scanf("%i",&apresentacao);
    }while (apresentacao<1 || apresentacao>4);
    
    //escolher tipo de entrada\ meia \ inteira etc
    
    //concertar quando o cara quer comprar mais de um tipo de entrada
    compraTipoEntrada();
    
}
