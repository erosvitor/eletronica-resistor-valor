## Sobre
O projeto é um programa de computador para identificar o valor (Ohms) de um determinado resistor dada as cores das suas faixas.

O programa foi escrito nas seguintes linguagens de programação:

* C Ansi
* C++ Ansi
* Javascript
* Java 7
* Python 3
* Bash

## Resistor
O **resistor** é um componente cuja função primária é limitar a passagem da corrente num circuito elétrico/eletrônico. Existem resistores de diversos tamanhos e tipos. O **ValorResistor** foi escrito para trabalhar com os resistores de 1/4W com 4 faixas.

## Tabela de cores
A tabela de cores abaixo pode ser utilizada para identificar o valor de um resistor de forma manual.

![](referencias/tabelacores.png)

Para exemplificar o processo manual de identificação, vamos tomar como base o resistor abaixo:

![](referencias/resistor-exemplo.png)

Com base na tabela de cores, o valor da primeira faixa é 1, o valor da segunda faixa é 0 e o valor da terceira faixa é 100000. Para identificar o valor do resistor, deve-se unir os valores da primeira e segunda faixa e multiplicar pelo valor da terceira faixa. Ficando assim:

```
10 x 100000 = 1000000 = 1M ohms
```

Portanto, o valor do resistor é de **1M ohms**.

## Licença
Este projeto está sob licença do MIT. Para mais detalhes, ver o arquivo LICENSE.

## Histórico de lançamentos

* 1.0.0 (2021-04-28)
    * Primeira versão
