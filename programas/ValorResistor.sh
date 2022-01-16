#!/bin/bash
######################################################################################################
# Descrição: Programa para calcular valor de resistor de 3 faixas.
# Linguagem: Bash
# Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
# Data: 08/01/2020
# Versão: 1.0.0
######################################################################################################

if [ $# -ne 3 ]; then
  echo "Como usar:"
  echo ""
  echo "  bash ValorResistor.sh cor-faixa-1 cor-faixa-2 cor-faixa-3"
  echo ""
  echo "  Observação: "
  echo "  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,"
  echo "  a tolerância será de 5% para mais ou para menos. Caso seja prata, a"
  echo "  tolerância será de 10% para mais ou para menos."
  echo ""
  exit
fi

corValida() {
  cores[0]="preto"
  cores[1]="marrom"
  cores[2]="vermelho"
  cores[3]="laranja"
  cores[4]="amarelo"
  cores[5]="verde"
  cores[6]="azul"
  cores[7]="violeta"
  cores[8]="cinza"
  cores[9]="branco"
  corEncontrada=0
  for c in "${cores[@]}"
  do
    if [ $1 == $c ]; then
      corEncontrada=1
      break
    fi
  done
  return "$corEncontrada"
}

obterValorFaixa() {
  valor=0
  case $1 in
    "preto")
      valor=0
      ;;
    "marrom")
      valor=1
      ;;
    "vermelho")
      valor=2
      ;;
    "laranja")
      valor=3
      ;;
    "amarelo")
      valor=4
      ;;
    "verde")
      valor=5
      ;;
    "azul")
      valor=6
      ;;
    "violeta")
      valor=7
      ;;
    "cinza")
      valor=8
      ;;
    "branco")
      valor=9
      ;;
  esac
  return "$valor"
}

corFaixa1=$1
corFaixa2=$2
corFaixa3=$3

corValida "$corFaixa1"
resultCorFaixa1=$?

corValida "$corFaixa2"
resultCorFaixa2=$?

corValida "$corFaixa3"
resultCorFaixa3=$?

if [[ $resultCorFaixa1 -ne 1 || $resultCorFaixa2 -ne 1 || $resultCorFaixa3 -ne 1 ]]; then
  echo "As cores informadas não são cores válidas para resistores."
  exit
fi

obterValorFaixa "$corFaixa1"
valorFaixa1=$?

obterValorFaixa "$corFaixa2"
valorFaixa2=$?

obterValorFaixa "$corFaixa3"
valorFaixa3=$?

tmp="$valorFaixa1$valorFaixa2"

multiplicadores[0]=1
multiplicadores[1]=10
multiplicadores[2]=100
multiplicadores[3]=1000
multiplicadores[4]=10000
multiplicadores[5]=100000
multiplicadores[6]=1000000
multiplicadores[7]=10000000
multiplicadores[8]=100000000
multiplicadores[9]=1000000000

multiplicador="${multiplicadores[$valorFaixa3]}"
valorResistor=$(($tmp * $multiplicador))

referencia="R"
if [[ $valorResistor -ge 1000000 ]]; then
  valorResistor=$(bc -l <<< "scale=2; $valorResistor/1000000")
  referencia="M"
elif [[ valorResistor -ge 1000 ]]; then
  valorResistor=$(bc -l <<< "scale=2; $valorResistor/1000")
  referencia="K"
fi

echo "Valor do resistor: $valorResistor$referencia ohms"
echo ""
echo "  Observação: "
echo "  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,"
echo "  a tolerância será de 5% para mais ou para menos. Caso seja prata, a"
echo "  tolerância será de 10% para mais ou para menos."
echo ""
