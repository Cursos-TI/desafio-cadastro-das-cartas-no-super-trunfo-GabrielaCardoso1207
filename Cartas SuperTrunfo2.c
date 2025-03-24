#include <stdio.h>    
//Criando um programa em linguagem C para o Jogo de Cartas: Super Trunfo. Neste nível novato, o programa solicita o jogador a inserção dos dados de duas cartas do jogo e ao final mostra o compilado das informações.
int main() {
    //Definindo variáveis de duas cartas do jogo. Cada variável é identificada com números 1 ou 2, que representam o número da carta.
    char estado1, estado2; //Definindo variável tipo char para Letra que represente o Estado..
    char codigodacarta1[3], codigodacarta2[3]; //Definindo variável tipo char (string) para o Código da Carta.
    char nomedacidade1[50], nomedacidade2[50], atributojogador1, atributojogador2, atributojogador3, atributojogador4; //Definindo variável tipo char (string) para o Nome da Cidade.
    int pontosturisticos1, pontosturisticos2, somaatributos, somaatributos2; //Definindo variável tipo inteira para Número de Habitantes e Quantidade de Pontos Turísticos.
    float area1, pib1, area2, pib2, pibpercapita1, pibpercapita2, densidade1, densidade2; //Definindo variável tipo float para Área em km² e Produto Interno Bruto (PIB).
    unsigned long int populacao1, populacao2;
    float superpoder1, superpoder2;

    printf("Bem vindo ao Jogo de Cartas Super Trunfo Países! Para começar insira os dados de duas cartas!\n"); //Apresentação do Jogo
    
    printf("\nVamos começar pela primeira carta. Insira uma letra, entre 'A' e 'H' que represente um Estado: \n");
    scanf(" %c", &estado1); //Alocando o dado inserido como definição da variável "estado1"

    printf("Insira o Código da Carta (Letra do Estado + um número de 01 a 04: \n");
    scanf("%s", &codigodacarta1); //Alocando o dado inserido como definição da variável "codigocarta1"

    printf("Qual o nome da cidade? \n");
    scanf("%s", &nomedacidade1); //Alocando o dado inserido como definição da variável "nomedacidade1"

    printf("Qual o número de habitantes desta cidade? \n");
    scanf("%lu", &populacao1);//Alocando o dado inserido como definição da variável "populacao1"

    printf("Qual é a área da cidade em quilômetros quadrados? \n");
    scanf("%f", &area1);//Alocando o dado inserido como definição da variável "area1"

    printf("Qual é o PIB (Produto Interno Bruto) da cidade? \n");
    scanf("%f", &pib1);//Alocando o dado inserido como definição da variável "pib1"
        
    printf("Quantos pontos turísticos essa cidade possui? \n");
    scanf("%i", &pontosturisticos1);//Alocando o dado inserido como definição da variável "pontosturisticos1"

    //Calculo de PIB Per Capita e Densidade Populacional Carta 01
    pibpercapita1 = pib1 / populacao1;
    densidade1 = populacao1 / area1;

    printf("\nVamos para a segunda carta!\n");//Seguindo para as entradas de dados da carta número dois.
    
    printf("Insira uma letra, entre 'A' e 'H' que represente um Estado: \n");
    scanf(" %c", &estado2);//Alocando o dado inserido como definição da variável "estado2"

    printf("Insira o Código da Carta (Letra do Estado + um número de 01 a 04: \n");
    scanf("%s", &codigodacarta2);//Alocando o dado inserido como definição da variável "codigodacarta2"

    printf("Qual o nome da cidade? \n");
    scanf("%s", &nomedacidade2);//Alocando o dado inserido como definição da variável "nomedacidade2"

    printf("Qual o número de habitantes desta cidade? \n");
    scanf("%lu", &populacao2);//Alocando o dado inserido como definição da variável "populacao2"

    printf("Qual é a área da cidade em quilômetros quadrados? \n");
    scanf("%f", &area2);//Alocando o dado inserido como definição da variável "area2"

    printf("Qual é o PIB (Produto Interno Bruto) da cidade? \n");
    scanf("%f", &pib2);//Alocando o dado inserido como definição da variável "pib2"
        
    printf("Quantos pontos turísticos essa cidade possui? \n");
    scanf("%i", &pontosturisticos2);//Alocando o dado inserido como definição da variável "pontosturisticos2"

    //Calculo de PIB Per Capita e Densidade Populacional Carta 02
    pibpercapita2 = pib2 / populacao2;
    densidade2 = populacao2 / area2;

    //Calculando o Super Poder
    superpoder1 = populacao1 + area1 + pib1 + pontosturisticos1 + pibpercapita1 + densidade1;
    superpoder2 = populacao2 + area2 + pib2 + pontosturisticos2 + pibpercapita2 + densidade2;

    //Menu interativo para jogador escolher dois atributos numéricos diferentes da Carta 1
    printf("\nEscolha dois atributos da Carta 1 para comparação nesta rodada.\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. PIB Per Capita\n");
    printf("6. Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf(" %i", &atributojogador1);
    printf("Escolha o segundo atributo: ");
    scanf(" %i", &atributojogador2);
   
    //Menu interativo para jogador escolher dois atributos numéricos diferentes da Carta 2
    printf("\nEscolha dois atributos da Carta 2 para comparação nesta rodada.\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. PIB Per Capita\n");
    printf("6. Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf(" %i", &atributojogador3);
    printf("Escolha o segundo atributo: ");
    scanf(" %i", &atributojogador4);
   
      // Comparar as somas dos atributos selecionados
      int soma1 = 0, soma2 = 0;

      switch (atributojogador1) {
          case 1: soma1 += populacao1; break;
          case 2: soma1 += area1; break;
          case 3: soma1 += pib1; break;
          case 4: soma1 += pontosturisticos1; break;
          case 5: soma1 += pibpercapita1; break;
          case 6: soma1 += densidade1; break;
      }
      switch (atributojogador2) {
          case 1: soma1 += populacao1; break;
          case 2: soma1 += area1; break;
          case 3: soma1 += pib1; break;
          case 4: soma1 += pontosturisticos1; break;
          case 5: soma1 += pibpercapita1; break;
          case 6: soma1 += densidade1; break;
      }
      switch (atributojogador3) {
          case 1: soma2 += populacao2; break;
          case 2: soma2 += area2; break;
          case 3: soma2 += pib2; break;
          case 4: soma2 += pontosturisticos2; break;
          case 5: soma2 += pibpercapita2; break;
          case 6: soma2 += densidade2; break;
      }
      switch (atributojogador4) {
          case 1: soma2 += populacao2; break;
          case 2: soma2 += area2; break;
          case 3: soma2 += pib2; break;
          case 4: soma2 += pontosturisticos2; break;
          case 5: soma2 += pibpercapita2; break;
          case 6: soma2 += densidade2; break;
      }
  
      // Comparar os valores
      if (soma1 > soma2) {
          printf("A Carta 1 venceu!\n");
      } else if (soma1 < soma2) {
          printf("A Carta 2 venceu!\n");
      } else {
          printf("Empate!\n");
      }
  
      return 0;
  }