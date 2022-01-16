
/*****************************************************************************************************
 * Descrição: Programa para calcular valor de resistor de 4 faixas.
 * Linguagem: C++ Ansi
 * Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
 * Data: 07/01/2020
 * Versão: 1.0.0
 ****************************************************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>

bool corValida(std::string cor) {
  std::string cores[10] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco"};
  bool corEncontrada = false;
  for (int i=0; i < 10; i++) {
    if (cor.compare(cores[i]) == 0) {
      corEncontrada = true;
      break;
    }
  }
  return corEncontrada;
}

int obterValorFaixa(std::string cor) {
  int valor = 0;
  if (cor.compare("preta") == 0) {
    valor = 0;
  } else if (cor.compare("marrom") == 0) {
    valor = 1;
  } else if (cor.compare("vermelho") == 0) {
    valor = 2;
  } else if (cor.compare("laranja") == 0) {
    valor = 3;
  } else if (cor.compare("amarelo") == 0) {
    valor = 4;
  } else if (cor.compare("verde") == 0) {
    valor = 5;
  } else if (cor.compare("azul") == 0) {
    valor = 6;
  } else if (cor.compare("violeta") == 0) {
    valor = 7;
  } else if (cor.compare("cinza") == 0) {
    valor = 8;
  } else if (cor.compare("branco") == 0) {
    valor = 9;
  }
  return valor;
}

int main(int argc, char *argv[]) {

  if (argc != 4) {
    std::cout << "Como usar:" << std::endl;
    std::cout << std::endl;
    std::cout << "  ./ValorResistor cor-faixa-1 cor-faixa-2 cor-faixa-3" << std::endl;
    std::cout << std::endl;
    std::cout << "  Observação: " << std::endl;
    std::cout << "  A quarta faixa indica a tolerância do resistor. Se a cor for dourada," << std::endl;
    std::cout << "  a tolerância será de 5% para mais ou para menos. Caso seja prata, a" << std::endl;
    std::cout << "  tolerância será de 10% para mais ou para menos." << std::endl;
    std::cout << std::endl;
    return 0;
  }

  std::string corFaixa1(argv[1]);
  std::string corFaixa2(argv[2]);
  std::string corFaixa3(argv[3]);

  if (!corValida(corFaixa1) || !corValida(corFaixa2) || !corValida(corFaixa3)) {
    std::cout << "As cores informadas não são cores válidas para resistores." << std::endl;
    return 0;
  }

  int valorFaixa1 = obterValorFaixa(corFaixa1);
  int valorFaixa2 = obterValorFaixa(corFaixa2);
  int valorFaixa3 = obterValorFaixa(corFaixa3);

  std::string str = std::to_string(valorFaixa1) + std::to_string(valorFaixa2);

  int tmp = std::stoi(str);

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
  std::cout << "Valor do resistor: " << valorResistorStr << referencia << " ohms" << std::endl;
  std::cout << std::endl;
  std::cout << "  Observação: " << std::endl;
  std::cout << "  A quarta faixa indica a tolerância do resistor. Se a cor for dourada," << std::endl;
  std::cout << "  a tolerância será de 5% para mais ou para menos. Caso seja prata, a" << std::endl;
  std::cout << "  tolerância será de 10% para mais ou para menos." << std::endl;
  std::cout << std::endl;

  return 1;
}

