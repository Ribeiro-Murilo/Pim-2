#include <stdio.h>


//variaveis globais
int idObraApresentada;
char obraApresentada;



void perguntasPessois(){
    int idade;
    printf("Caso não queira responder uma em especifico digite 0\n");
    printf("Quantos anos tem?\n");
    scanf("%i",&idade);
    printf("demais perguntas para basear a analize de dados das obras\n");
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

void compraDeIngressos(){
    int entrada;
    int entradaInteira =30;
    int entradaMeia =15;
    int entradaIsenta =0;
    printf("Os valores da entrada são:\n%i Reais para entrada inteira\n%i Reais para meia entrada\n%i Reais para entrada isenta.\n",entradaInteira, entradaMeia, entradaIsenta);
    
    while (!(entrada==1||entrada==2||entrada==3)) {
        printf("Para compara a entrada inteira selecione 1\nPara compara a meia entrada selecione 2\nPara compara a entrada isenta selecione 3\n");
        scanf("%i",&entrada);
    }
}


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
    compraDeIngressos();
    return 0;
        int querComprar=0;
        while (querComprar < 1 || querComprar > 2) {
            printf("Deseja comprar ingressos para a exposição\n1 para sim\n2 para não\n");
            scanf("%i",&querComprar);
        }
        if(querComprar==1){
            compraDeIngressos();
        }
    }
