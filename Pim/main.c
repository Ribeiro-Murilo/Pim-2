#include <stdio.h>


//variaveis globais
int obraApresentada;




void perguntasPessois(){
    int idade;
    int obraApresentada=0;
    printf("Caso não queira responder uma em especifico digite 0\n");
    //printf("Qual obra acabou de se apresentar?\n1- 150 anos de Santos Dumont.\n2- 100 anos da arte moderna.\n3- olimpiadas París 2024.\n4- Tema a decidir");
    while (obraApresentada<1 || obraApresentada >4) {
        printf("Qual obra acabou de se apresentar?\n1- 150 anos de Santos Dumont.\n2- 100 anos da arte moderna.\n3- olimpiadas París 2024.\n4- Tema a decidir\n");
        scanf("%i",&obraApresentada);
        if(obraApresentada<1 || obraApresentada >4){
            printf("Valor invalido\n");
        }
    }
    scanf("%i", &obraApresentada);
    printf("Quantos anos tem?");
    scanf("%i",&idade);
    printf("demais perguntas para basear a analize de dados das obras");
}
void compraDeIngressos(){
    
}
void questionario(){
    int QuantDeQuestionario = 3;
    int respostasPergunta[3] ={-1,-1,-1};
    int perguntasPessoais;
    printf("Para uma melhor apresentação nos informe seu nivel de satisfação com cada pergunta sobre a obra apresentada\n");
    printf("Sendo 10 amei e 0 não gostei\n");
    
    for (int numeroQuestionario =0; numeroQuestionario<QuantDeQuestionario; numeroQuestionario++) {
        printf("ola\n");
        while (respostasPergunta[numeroQuestionario] < 0 || respostasPergunta[numeroQuestionario] > 10) {
            printf("Pergunta %i\n",numeroQuestionario+1);
            scanf("%i",&respostasPergunta[numeroQuestionario]);
            if(respostasPergunta[numeroQuestionario] < 0 || respostasPergunta[numeroQuestionario] >10){
                printf("Valor digitado invalido\n");
            }
        }
    }
//    printf("%i",respostasPergunta[0]);
  //  printf("%i",respostasPergunta[1]);
    //printf("%i",respostasPergunta[2]);
    
    printf("Varias perguntas...");
    printf("A seguir algumas perguntas pessoais. Caso quiser responder digite 1, caso não outro numero\n");
    scanf("%i",&perguntasPessoais);
    if(perguntasPessoais==1){
        perguntasPessois();
    }else{
        compraDeIngressos();
    }
}


void santosD(){
    obraApresentada = 1;
    printf("Aqui o texto de apresentação do Santos Dumont o verdadeiro criador do avião\nps:Com catapulta ate uma pedra voa ;)");
};
void arteM(){
    obraApresentada = 2;
    printf("Aqui o texto de apresentação dos 100 anos da arte moderna");
};
void paris24(){
    obraApresentada = 3;
    printf("Aqui o texto de apresentação dos jogos olimpicos de paris 2024");
};
void decidir(){
    obraApresentada = 4;
    printf("Aqui o texto de apresentação do a decidir");
};



int main() {
    //apresentação inicial do projeto
    //printf("Ola seja bem-vindo ao musel multematico da UNIP\n");
    //printf("Aqui estara sendo apresentada obras da de temas que estão presentes nos ultimos 3 anos ou que estarão presentes em 3 anos\n");
    
    //apresentação da obra
    //santosD();
    questionario();
        
    
}
















