
/*****************************************************************************************************
 * Descrição: Programa para calcular valor de resistor de 4 faixas.
 * Linguagem: C Ansi
 * Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
 * Data: 07/01/2020
 * Versão: 1.0.0
 ****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char corValida(char *cor) {
  char *cores[10] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco"};
  char corEncontrada = 0;
  for (int i=0; i < 10; i++) {
    if (strcmp(cor, cores[i]) == 0) {
      corEncontrada = 1;
      break;
    }
  }
  return corEncontrada;
}

int obterValorFaixa(char *cor) {
  int valor = 0;
  if (strcmp(cor, "preta") == 0) {
    valor = 0;
  } else if (strcmp(cor, "marrom") == 0) {
    valor = 1;
  } else if (strcmp(cor, "vermelho") == 0) {
    valor = 2;
  } else if (strcmp(cor, "laranja") == 0) {
    valor = 3;
  } else if (strcmp(cor, "amarelo") == 0) {
    valor = 4;
  } else if (strcmp(cor, "verde") == 0) {
    valor = 5;
  } else if (strcmp(cor, "azul") == 0) {
    valor = 6;
  } else if (strcmp(cor, "violeta") == 0) {
    valor = 7;
  } else if (strcmp(cor, "cinza") == 0) {
    valor = 8;
  } else if (strcmp(cor, "branco") == 0) {
    valor = 9;
  }
  return valor;
}

int main(int argc, char *argv[]) {

  if (argc != 4) {
    puts("Como usar:");
    puts("");
    puts("  ./ValorResistor cor-faixa-1 cor-faixa-2 cor-faixa-3");
    puts("");
    puts("  Observação: ");
    puts("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,");
    puts("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a");
    puts("  tolerância será de 10% para mais ou para menos.");
    puts("");
    return 0;
  }

  char corFaixa1[10];
  strcpy(corFaixa1, argv[1]);

  char corFaixa2[10];
  strcpy(corFaixa2, argv[2]);

  char corFaixa3[10];
  strcpy(corFaixa3, argv[3]);

  if (!corValida(corFaixa1) || !corValida(corFaixa2) || !corValida(corFaixa3)) {
    puts("As cores informadas não são cores válidas para resistores.");
    return 0;
  }

  int valorFaixa1 = obterValorFaixa(corFaixa1);
  int valorFaixa2 = obterValorFaixa(corFaixa2);
  int valorFaixa3 = obterValorFaixa(corFaixa3);

  char str[3];
  sprintf(str, "%d%d", valorFaixa1, valorFaixa2);

  int tmp = atoi(str);

  long multiplicadores[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
  double valorResistor = tmp * multiplicadores[valorFaixa3];

  char referencia = 'R';
  if (valorResistor >= 1000000) {
    valorResistor = valorResistor / 1000000;
    referencia = 'M';
  } else if (valorResistor >= 1000) {
    valorResistor = valorResistor / 1000;
    referencia = 'K';
  }

  char valorResistorStr[10];
  int decimals = (int)((valorResistor - (int)valorResistor) * 100);
  if (decimals > 0) {
    sprintf(valorResistorStr, "%.1f", valorResistor);
  } else {
    sprintf(valorResistorStr, "%.0f", valorResistor);
  }
  printf("Valor do resistor: %s%c ohms\n", valorResistorStr, referencia);
  puts("");
  puts("  Observação: ");
  puts("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,");
  puts("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a");
  puts("  tolerância será de 10% para mais ou para menos.");
  puts("");

  return 1;
}

