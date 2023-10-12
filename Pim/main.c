//
//  main.c
//  Trabalho PIM II
//
//  Created by Ribeiro on 26/09/23.
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


//variaveis globais
int idObraApresentada;
char obraApresentada;


void encerrar(){
    printf("Obrigado por vir ao museu");
}

void selecionarObra(){
    switch (idObraApresentada){
        case 1:
            obraApresentada= "150 anos de Santos Dumont";
        case 2:
            obraApresentada= "100 anos da arte moderna";
        case 3:
            obraApresentada= "Jogos olimpicos de paris 2024";
        case 4:
            obraApresentada= "Tema a definir";
    }
}

//parte de compra de ingressos
int tipoEntrada=0;
int quantEntrada;
int entrada1[2];
int entrada2[2];
int entrada3[2];
void marcarEntrada(){
    switch (tipoEntrada) {
            case 1:
            entrada1[0] = tipoEntrada;
            entrada1[1] = quantEntrada;
                break;
            case 2:
                entrada2[0]=tipoEntrada;
                entrada2[1]=quantEntrada;
                break;
            case 3:
                entrada3[0]=tipoEntrada;
                entrada3[1]=quantEntrada;
                break;
            default:
                break;
        }
    int outraEntrada=0;
    printf("Deseja comprar outro tipo de ingresso?");
    while (!(outraEntrada==1||outraEntrada==2)) {
        printf("Para compara outro tipo de entrada\n1 para sim \n2 para não: ");
        scanf("%i",&outraEntrada);
        if(outraEntrada==1){
            tipoEntrada=0;
        }else if(outraEntrada==2)
            perguntasPessois();
    }
}




//parte de apresentação da obra
void santosD(){
    idObraApresentada = 1;
    printf("\nAqui o texto de apresentação do Santos Dumont o verdadeiro criador do avião\nps:Com catapulta ate uma pedra voa ;)\n\n");
};
void arteM(){
    idObraApresentada = 2;
    printf("\nAqui o texto de apresentação dos 100 anos da arte moderna\n");
};
void paris24(){
    idObraApresentada = 3;
    printf("\nAqui o texto de apresentação dos jogos olimpicos de paris 2024\n");
};
void decidir(){
    idObraApresentada = 4;
    printf("\nAqui o texto de apresentação do a decidir\n");
};



int main(int argc, char *argv[]) {
    int aux = bilheteria();
     
        //Demonstrando valor lido e esperando usuário apertar o -Enter-
    printf("\n-->%d", aux);
    //compraDeIngressos();
    return 0;
    //apresentação inicial do projeto
    printf("Ola seja bem-vindo ao musel multematico da UNIP\n");
    printf("Aqui estara sendo apresentada obras da de temas que estão presentes nos ultimos 3 anos ou que estarão presentes em 3 anos\n");
    
    //... logica para selecionar a obra mais bem vista segundo alguns parametros
    //apresentação da obra
    santosD();
    selecionarObra();
    
        int QuantDeQuestionario = 3;
        int respostasPergunta[3] ={-1,-1,-1};
        
        printf("Para uma melhor apresentação nos informe seu nivel de satisfação com cada pergunta sobre a obra %c\n",obraApresentada);
        printf("Sendo 10 amei e 0 não gostei\n");
        
        for (int numeroQuestionario =0; numeroQuestionario<QuantDeQuestionario; numeroQuestionario++) {
            while (respostasPergunta[numeroQuestionario] < 0 || respostasPergunta[numeroQuestionario] > 10) {
                printf("Pergunta %i\n",numeroQuestionario+1);
                scanf("%i",&respostasPergunta[numeroQuestionario]);
                if(respostasPergunta[numeroQuestionario] < 0 || respostasPergunta[numeroQuestionario] >10){
                    printf("Valor digitado invalido\n");
                }
            }
        }
        
        printf("Varias perguntas...\n");
    //return 0;
        int querComprar=0;
        while (!(querComprar==1||querComprar==2)) {
            printf("Deseja comprar ingressos para a exposição\n1 para sim\n2 para não\n");
            scanf("%i",&querComprar);
        }
        if(querComprar==1){
            compraDeIngressos();
        }else if (querComprar == 2){
            perguntasPessois();
        }
    }
