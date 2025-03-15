#include <stdio.h>    
//Criando um programa em linguagem C para o Jogo de Cartas: Super Trunfo. Neste nível novato, o programa solicita o jogador a inserção dos dados de duas cartas do jogo e ao final mostra o compilado das informações.
int main() {
    //Definindo variáveis de duas cartas do jogo. Cada variável é identificada com números 1 ou 2, que representam o número da carta.
    char estado1, estado2; //Definindo variável tipo char para Letra que represente o Estado..
    char codigodacarta1[3], codigodacarta2[3]; //Definindo variável tipo char (string) para o Código da Carta.
    char nomedacidade1[50], nomedacidade2[50]; //Definindo variável tipo char (string) para o Nome da Cidade.
    int pontosturisticos1, pontosturisticos2; //Definindo variável tipo inteira para Número de Habitantes e Quantidade de Pontos Turísticos.
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

    //Mostrando o atributo a ser comparado e o valor dele em cada carta
    printf("Comparação de cartas (Atributo: Super Poder)\n");
    printf("O Super Poder da Carta 1 é %.2f \n", superpoder1);
    printf("O Super Poder da Carta 2 é %.2f \n", superpoder2);
   
    //Usando a lógica if-else para validar a carta vencedora.
    if (superpoder1>superpoder2){
        printf("Carta 1 (%s) venceu!\n", nomedacidade1);
    }else{
        printf("Carta 2 (%s) venceu!\n", nomedacidade2);
    }
    return 0;
}
