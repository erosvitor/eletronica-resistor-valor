
/*****************************************************************************************************
 * Descrição: Programa para calcular valor de resistor de 4 faixas.
 * Linguagem: Javascript
 * Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
 * Data: 07/01/2020
 * Versão: 1.0.0
 ****************************************************************************************************/

var multiplicador = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000];

function calcularValorResistor(corFaixa1, corFaixa2, corFaixa3) {
  var valorFaixa1 = obterValorFaixa(corFaixa1);
  var valorFaixa2 = obterValorFaixa(corFaixa2);
  var valorFaixa3 = obterValorFaixa(corFaixa3);

  var tmp = parseInt(valorFaixa1.toString() + valorFaixa2.toString());
 
  var valorResistor = tmp * multiplicador[valorFaixa3];

  var referencia = "R";
  if (valorResistor >= 1000000) {
    valorResistor = valorResistor / 1000000;
    referencia = "M";
  } else if (valorResistor >= 1000) {
    valorResistor = valorResistor / 1000;
    referencia = "K";
  }

  var valorResistorStr = null;
  var decimals = parseInt((valorResistor - parseInt(valorResistor)) * 100);
  if (decimals > 0) {
    valorResistorStr = parseFloat(valorResistor).toFixed(1);
  } else {
    valorResistorStr = parseFloat(valorResistor).toFixed(0);
  }

  return valorResistorStr + referencia + " ohms"
}

function obterValorFaixa(cor) {
 var valor = 0;
  switch (cor) {
    case "preto": valor = 0; break;
    case "marrom": valor = 1; break;
    case "vermelho": valor = 2; break;
    case "laranja": valor = 3; break;
    case "amarelo": valor = 4; break;
    case "verde": valor = 5; break;
    case "azul": valor = 6; break;
    case "violeta": valor = 7; break;
    case "cinza": valor = 8; break;
    case "branco": valor = 9; break;
  }
  return valor;
}

var valorDoResistor = calcularValorResistor("preto", "marrom", "vermelho")
console.log("Valor do resistor: " + valorDoResistor + " ohms\n");
console.log("");
console.log("  Observação: ");
console.log("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,");
console.log("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a");
console.log("  tolerância será de 10% para mais ou para menos.");
console.log("");
