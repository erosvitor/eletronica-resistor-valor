
######################################################################################################
# Descrição: Programa para calcular valor de resistor de 4 faixas.
# Linguagem: Python 3
# Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
# Data: 07/01/2020
# Versão: 1.0.0
######################################################################################################

import sys
import os

if len(sys.argv) != 4:
  print("Como usar:")
  print("")
  print("  python3 ValorResistor.py cor-faixa-1 cor-faixa-2 cor-faixa-3")
  print("")
  print("  Observação: ")
  print("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,")
  print("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a")
  print("  tolerância será de 10% para mais ou para menos.")
  print("") 
  quit()

def corValida(cor):
  cores = ["preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco"]
  corEncontrada = False
  for c in cores:
    if c == cor:
      corEncontrada = True
      break
  return corEncontrada

def obterValorFaixa(cor):
  if cor == "preto":
    return 0
  elif cor == "marrom":
    return 1
  elif cor == "vermelho":
    return 2
  elif cor == "laranja":
    return 3
  elif cor == "amarelo":
    return 4
  elif cor == "verde":
    return 5
  elif cor == "azul":
    return 6
  elif cor == "violeta":
    return 7
  elif cor == "cinza":
    return 8
  elif cor == "branco":
    return 9

corFaixa1 = sys.argv[1].lower()
corFaixa2 = sys.argv[2].lower()
corFaixa3 = sys.argv[3].lower()

if not corValida(corFaixa1) or not corValida(corFaixa2) or not corValida(corFaixa3):
  print("As cores informadas não são cores válidas para resistores.")
  quit()

valorFaixa1 = obterValorFaixa(corFaixa1)
valorFaixa2 = obterValorFaixa(corFaixa2)
valorFaixa3 = obterValorFaixa(corFaixa3)

tmp = int(str(valorFaixa1) + str(valorFaixa2))

multiplicadores = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000]
valorResistor = tmp * multiplicadores[valorFaixa3]

referencia = "R"
if valorResistor >= 1000000:
  valorResistor = valorResistor / 1000000
  referencia = "M"
elif valorResistor >= 1000:
  valorResistor = valorResistor / 1000
  referencia = "K"

valorResistorStr = ""
decimals = int((valorResistor - int(valorResistor)) * 100)
if decimals > 0:
  valorResistorStr = "{:.1f}".format(valorResistor)
else:
  valorResistorStr = "{:.0f}".format(valorResistor)

print("Valor do resistor: {}{} ohms".format(valorResistorStr, referencia))
print("")
print("  Observação: ")
print("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,")
print("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a")
print("  tolerância será de 10% para mais ou para menos.")
print("")

