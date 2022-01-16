
/*****************************************************************************************************
 * Descrição: Programa para calcular valor de resistor de 4 faixas.
 * Linguagem: Java 7
 * Autor: Eros Vitor Bornatowski (erosborna@gmail.com)
 * Data: 07/01/2020
 * Versão: 1.0.0
 ****************************************************************************************************/

public class ValorResistor {

  public static void main(String[] args) {

    if (args.length != 3) {
      System.out.println("Como usar:");
      System.out.println("");
      System.out.println("  java ValorResistor cor-faixa-1 cor-faixa-2 cor-faixa-3");
      System.out.println("");
      System.out.println("  Observação: ");
      System.out.println("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,");
      System.out.println("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a");
      System.out.println("  tolerância será de 10% para mais ou para menos.");
      System.out.println("");
      return;      
    }
     
    String corFaixa1 = args[0].toLowerCase();
    String corFaixa2 = args[1].toLowerCase();
    String corFaixa3 = args[2].toLowerCase();
    
    if (!corValida(corFaixa1) || !corValida(corFaixa2) || !corValida(corFaixa3)) {
      System.out.println("As cores informadas não são cores válidas para resistores.");
      return;
    }

    int valorFaixa1 = obterValorFaixa(corFaixa1);
    int valorFaixa2 = obterValorFaixa(corFaixa2);
    int valorFaixa3 = obterValorFaixa(corFaixa3);
    
    int tmp = Integer.parseInt(String.valueOf(valorFaixa1) + String.valueOf(valorFaixa2));

    long multiplicadores[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    double valorResistor = tmp * multiplicadores[valorFaixa3];
    
    String referencia = "R";
    if (valorResistor >= 1000000) {
      valorResistor = valorResistor / 1000000;
      referencia = "M";
    } else if (valorResistor >= 1000) {
      valorResistor = valorResistor / 1000;
      referencia = "K";
    }
    
    String valorResistorStr = null;
    int decimals = (int)((valorResistor - (int)valorResistor) * 100);
    if (decimals > 0) {
      valorResistorStr = String.format("%.1f", valorResistor);
    } else {
      valorResistorStr = String.format("%.0f", valorResistor);
    }
    System.out.println(String.format("Valor do resistor: %s%s ohms", valorResistorStr, referencia));
    System.out.println("");
    System.out.println("  Observação: ");
    System.out.println("  A quarta faixa indica a tolerância do resistor. Se a cor for dourada,");
    System.out.println("  a tolerância será de 5% para mais ou para menos. Caso seja prata, a");
    System.out.println("  tolerância será de 10% para mais ou para menos.");
    System.out.println("");
  }
  
  private static boolean corValida(String cor) {
    String cores[] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco"};
    boolean corEncontrada = false;
    for (String c : cores) {
      if (c.equals(cor)) {
        corEncontrada = true;
        break;
      }
    }
    return corEncontrada;
  }
  
  private static int obterValorFaixa(String cor) {
    int valor = 0;
    switch (cor) {
      case "preta": valor = 0; break;
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

}
