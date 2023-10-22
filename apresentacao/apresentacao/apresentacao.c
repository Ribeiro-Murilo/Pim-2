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

//ja foi feito

// autentificação do codigo anteriormente comprado na bilheteria

// apresentação de acordo com o tiket que foi comprado


//aqui ainda sera feito

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
int valido = -1;  // Quando nao encontrado
char obraApresentada[50];
int respostaQ1[5];
int respostaQ2[5];
int respostaQ3[5];
int respostaQ4[5];
int respostaQ5[5];

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

                // Verifica se é o token que o user digitou
        if (token == tokenProcurado) {
            entradaObra = entradaAtual;
            quantidade = quantidadeAtual;
            printf("token:%i\nEntrada: %i\nQuantidade: %i\n",tokenProcurado,entradaObra,quantidade);
            valido=0;
            break;
        }
    }
    if(valido==-1){
        printf("Codigo invalido\n");
    }
        
    fclose(DBToken);
}


//bug quando a quantidade esta em 10 da baixa no sistema fica 90, acontece com 10,100,1000 etc


void baixaSistema(){
    FILE *DBToken = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBToken.csv", "r+");
    
    if (DBToken == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    char linha[TAMANHO_MAX_LINHA];
    int entradaAtual;
    int quantidadeAtual;
    int token;
    // le cada linha
    while (fgets(linha, TAMANHO_MAX_LINHA, DBToken) != NULL) {
        // Extrai os valores de token, entrada e quantidade da linha
        sscanf(linha, "%d;%d;%d", &token, &entradaAtual, &quantidadeAtual);
        // Verifica se é o token que estamos procurando
        if (token == tokenProcurado) {
            // Atualiza os valores
            quantidadeRestante = quantidadeAtual-1;
            // Reescreve a linha no arquivo com os novos valores
            fseek(DBToken, -strlen(linha), SEEK_CUR);//CUR
            //fputs(DBToken, "%d;%d;%i", token, entradaAtual, quantidadeRestante);
            fputs("", DBToken);
            break;
        }
    }
    if(quantidadeRestante>=0){
        printf("Esse Token de acesso esta disponivel para uso para mais %i acessos.",quantidadeRestante);
    }else{
        printf("Esse Token de acesso não esta mais disponivel para uso ou é invalido.");
    }
    fclose(DBToken);
}

void apresentarObra(){
    switch (entradaObra) {
        case 1:
            printf("\n-----------------------------------------------------------------\n");
          printf("- Apresentando a seção dos 150 anos de Santos Dumont:\n");
          printf("- Contexto: Em 2023, o Brasil comemorou os 150 anos de nascimento de Alberto Santos Dumont, considerado o ''Pai da Aviacao''. Para celebrar o legado do inventor, foram realizados diversos eventos em todo o pais, incluindo exposicoes, palestras e eventos culturais.\n");
          printf("- Exposicao: exposicao sobre a vida e obra de Santos Dumont, A exposição ''Santos Dumont: O Homem que Voou'', realizada no Museu do Amanha, no Rio de Janeiro, foi um dos destaques. A exposicao contou com uma série de objetos e documentos que contam a historia do inventor, incluindo o 14-bis, o primeiro aviao a levantar voo por conta propria.\n");
          printf("- Evento Cultural: O show 'Santos Dumont: O Homem que Voou'', realizado pelo grupo musical ''Trio de Ouro'', foi um dos destaques. O show contou com uma série de canções que homenageiam o inventor, incluindo ''O Aviador'', de Renato Teixeira.\n");
          printf("- O legado de Santos Dumont: O legado de Santos Dumont é importante nao apenas para o Brasil, mas também para o mundo. O inventor foi um pioneiro na aviação, e suas contribuições ajudaram a tornar o mundo um lugar mais conectado.\n");
            printf("\n-----------------------------------------------------------------\n");
          break;
        case 2:
          printf("\n-----------------------------------------------------------------\n");
          printf("Apresentando a seçao dos 100 anos da semana de Arte Moderna:\n");
          printf("- Pintores: Anita Malfatti, Emiliano Di Cavalcanti, Tarsila do Amaral, Victor Brecheret, Zina Aita, Cândido Portinari, entre outros.\n");
          printf("- Escritores: Mário de Andrade, Oswald de Andrade, Manuel Bandeira, Graça Aranha, entre outros.\n");
          printf("- Musicos: Heitor Villa-Lobos, Darius Milhaud, Arthur Rubinstein, entre outros.\n");
          printf("- Obras: Inspiracoes no cubismo, o futurismo, e o surrealismo\n");
          printf("- Local: Teatro Municipal de São Paulo\n");
          printf("- Contexto Historico: O país comemorava 100 anos de Independência, mas ainda enfrentava problemas como a desigualdade social e a pobreza. O evento também foi influenciado pelo contexto internacional, marcado pela Primeira Guerra Mundial e pela ascensão das vanguardas artisticas.\n");
            printf("\n-----------------------------------------------------------------\n");
          break;
        case 3:
            printf("\n-----------------------------------------------------------------\n");
          printf("Apresentando a seção dos Jogos Olimpicos de Paris 2024:\n");
          printf("- Jogos: serao 48 modalidades e 32 esportes, dentre eles uma novidade o Breakdance.\n");
          printf("- Alguns destaques: O recorde de medalhas de ouro do Brasil, com 21\n");
          printf("- A prata de Rayssa Leal no skate street, aos 13 anos\n");
          printf("- O ouro de Thiago Braz no salto com vara, após 13 anos\n");
          printf("- O ouro de Ana Marcela Cunha na maratona aquática, após 21 anos\n");
          printf("- Esportes\n");
          printf("- Aquáticos: natação, saltos ornamentais, polo aquático, nado sincronizado e canoagem.\n");
          printf("- Combate: boxe, esgrima, judô, taekwondo, luta-livre, karate.\n");
          printf("- Campo e pista: futebol, atletismo, ciclismo, ginástica, hipismo, pentatlo moderno, tênis, tênis de mesa, tiro, tiro com arco, vôlei e vôlei de praia\n");
            printf("\n-----------------------------------------------------------------\n");
          break;
        case 4:
            printf("\n-----------------------------------------------------------------\n");
          printf("Apresentando a seção de Inteligencia Artificial:\n");
          printf("- Definicao:\n");
          printf("- Uma definição comum de IA é a capacidade de uma máquina de imitar o comportamento humano inteligente. Isso pode incluir a capacidade de aprender, resolver problemas, tomar decisões e interagir com o mundo ao seu redor.\n");
          printf("- Historias:\n");
          printf("- A IA tem sido objeto de pesquisa por décadas, e houve um progresso significativo nos últimos anos. O campo da IA começou como um campo experimental nos anos 1950, e desde então tem experimentado uma série de avanços, incluindo o desenvolvimento de algoritmos de aprendizado de máquina, o surgimento de grandes modelos de linguagem e o desenvolvimento de sistemas de IA que podem realizar tarefas complexas de forma autônoma.\n");
          printf("- Aplicacoes:\n");
          printf("- Reconhecimento de imagem e fala: A IA é usada para identificar objetos e pessoas em imagens e áudio. Isso é usado em uma variedade de aplicações, como reconhecimento facial, identificação de fraudes e tradução de idiomas.\n");
          printf("- Machine learning: A IA é usada para treinar modelos que podem aprender com dados. Isso é usado em uma variedade de aplicações, como recomendação de produtos, previsão de demanda e diagnóstico médico.\n");
          printf("- Robótica: A IA é usada para controlar robôs. Isso é usado em uma variedade de aplicações, como manufatura, agricultura e serviços\n");
          printf("- Impacto:\n");
          printf("- A IA tem o potencial de revolucionar a maneira como vivemos e trabalhamos. No entanto, também há riscos associados ao desenvolvimento e uso da IA, como a possibilidade de discriminação e a perda de empregos.\n");
            printf("\n-----------------------------------------------------------------\n");
          break;
    }
}
void acharTema(){
    switch (entradaObra){
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

void lancarRespostas(){
    
    FILE *DBObra1 = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBObra1.csv", "a");
    if (DBObra1 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    
    FILE *DBObra2 = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBObra2.csv", "a");
    if (DBObra2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    
    FILE *DBObra3 = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBObra3.csv", "a");
    if (DBObra3 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    
    FILE *DBObra4 = fopen("/Volumes/Faculdade/faculdade/Pim/codigo/Pim/DBObra4.csv", "a");
    if (DBObra4 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    switch(entradaObra){
        case 1:
            fprintf(DBObra1,"\n%i;%i;%i;%i;%i",respostaQ1[0],respostaQ1[1],respostaQ1[2],respostaQ1[3],respostaQ1[4]);
            break;
        case 2:
            fprintf(DBObra2,"\n%i;%i;%i;%i;%i",respostaQ2[0],respostaQ2[1],respostaQ2[2],respostaQ2[3],respostaQ2[4]);
            break;
        case 3:
            fprintf(DBObra3,"\n%i;%i;%i;%i;%i",respostaQ3[0],respostaQ3[1],respostaQ3[2],respostaQ3[3],respostaQ3[4]);
            break;
        case 4:
            fprintf(DBObra4,"\n%i;%i;%i;%i;%i",respostaQ4[0],respostaQ4[1],respostaQ4[2],respostaQ4[3],respostaQ4[4]);
            break;
    }
    fclose(DBObra1);
    fclose(DBObra2);
    fclose(DBObra3);
    fclose(DBObra4);
}

void selecionarPerguntas(){
    char perguntasQ1[5][50] = {
            "Pergunta 1 obra1",
            "Pergunta 2 obra1",
            "Pergunta 3 obra1",
            "Pergunta 4 obra1",
            "Pergunta 5 obra1"
        };
    char perguntasQ2[5][50] = {
            "Pergunta 1 obra2",
            "Pergunta 2 obra2",
            "Pergunta 3 obra2",
            "Pergunta 4 obra2",
            "Pergunta 5 obra2"
        };
    char perguntasQ3[5][50] = {
            "Pergunta 1 obra3",
            "Pergunta 2 obra3",
            "Pergunta 3 obra3",
            "Pergunta 4 obra3",
            "Pergunta 5 obra3"
        };
    char perguntasQ4[5][50] = {
            "Pergunta 1 obra4",
            "Pergunta 2 obra4",
            "Pergunta 3 obra4",
            "Pergunta 4 obra4",
            "Pergunta 5 obra4",
        };
    switch (entradaObra){
        case 1:
            acharTema();
            printf("Perguntas devem ser respondidas de 0 a 10 em numeral a respeito da obra %s\n",obraApresentada);
            for (int questao=0; questao<5;questao++) {
                do{
                    printf("%s\n%i: ",perguntasQ1[questao],questao+1);
                    scanf("%i",&respostaQ1[questao]);
                }while(respostaQ1[questao]<0||respostaQ1[questao]>10);
            }
            lancarRespostas();
            break;
        case 2:
            acharTema();
            printf("Perguntas devem ser respondidas de 0 a 10 em numeral a respeito da obra %s\n",obraApresentada);
            for (int questao=0; questao<5;questao++) {
                do{
                    printf("%s\n%i: ",perguntasQ2[questao],questao+1);
                    scanf("%i",&respostaQ2[questao]);
                }while(respostaQ2[questao]<0||respostaQ2[questao]>10);
            }
            lancarRespostas();
            break;
        case 3:
            acharTema();
            printf("Perguntas devem ser respondidas de 0 a 10 em numeral a respeito da obra %s\n",obraApresentada);
            for (int questao=0; questao<5;questao++) {
                do{
                    printf("%s\n%i: ",perguntasQ3[questao],questao+1);
                    scanf("%i",&respostaQ3[questao]);
                }while(respostaQ3[questao]<0||respostaQ3[questao]>10);
            }
            lancarRespostas();
            break;
        case 4:
            acharTema();
            printf("Perguntas devem ser respondidas de 0 a 10 em numeral a respeito da obra %s\n",obraApresentada);
            for (int questao=0; questao<5;questao++) {
                do{
                    printf("%s\n%i: ",perguntasQ4[questao],questao+1);
                    scanf("%i",&respostaQ4[questao]);
                }while(respostaQ4[questao]<0||respostaQ4[questao]>10);
            }
            lancarRespostas();
            break;
    }
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
    
    //para fins de testes o restante nao é apresentado
    return 0;
    if(quantidadeRestante>=0){
        apresentarObra();
        selecionarPerguntas();
    }
    printf("Obrigado por vir");
    return 0;
}
