#define DOCTEST_CONFIG_IMPLEMENT
#include <cstdlib>
#include <fstream>
#include "../doctest.h"
#include "terreno.h"  // veja que esse arquivo não existe ainda, você precisará criá-lo para definir a classe Terreno.

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  Terreno terreno(0); // 2^0 + 1 = 2
  CHECK(terreno.obterQtdLinhas() == 2);
  CHECK(terreno.obterQtdColunas() == 2);
}

TEST_CASE("Testa a Função de randomizar os cantos do terreno") {
  Terreno terreno(2);

  CHECK(terreno.gerarTerreno(2, 0.5) == true);
  CHECK(terreno.obterAltitude(0, 0) == 31);
}

TEST_CASE("Testa os valores default = -1 em matriz 5x5") {
  Terreno terreno(2);
  CHECK(terreno.obterQtdLinhas() == 5);
  CHECK(terreno.obterQtdColunas() == 5);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j<5; j++) {
      CHECK(terreno.matriz[i][j] == -1);
    }
  }
}

TEST_CASE("Testa salvar matriz 5x5 em arquivo") {
  // gerar terreno 5x5: n = 2
  Terreno terreno(2);
  CHECK(terreno.gerarTerreno(2, 0.5) == true);

  CHECK(terreno.salvarTerreno("terreno.txt"));

  std::ifstream arquivo("terreno.txt");

  int linhas, colunas, altitude;
  arquivo >> linhas >> colunas;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j<colunas; j++) {
      arquivo >> altitude;
      CHECK(altitude == terreno.matriz[i][j]);
    }
  }
}

TEST_CASE("Testa ler terreno 3x3 em arquivo") {
  //IMPLEMENTAR
  Terreno terreno(1);
  CHECK(terreno.lerTerreno("terreno_3_por_3.txt"));

  std::ifstream arquivo("terreno.txt");

  int linhas, colunas, altitude;
  arquivo >> linhas >> colunas;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j<colunas; j++) {
      arquivo >> altitude;
      CHECK(terreno.matriz[i][j] == altitude);
    }
  }
}

// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Os testes vão depender de como você estruturou o algoritmo de geração do terreno (Square e Diamond).
// Então, escreva seus próprios testes para os métodos das etapas Square e Diamond.
// Você pode torná-los públicos temporariamente para fins de teste.


// o main foi implementado aqui para inicializar o gerador de números aleatórios antes dos testes.
int main(int argc, char** argv) {
  // inicializa o gerador de números aleatórios uma única vez no programa.
  // o valor é fixo para que os testes sejam reprodutíveis, ou seja, que sempre gerem os mesmos resultados.
  // isso é importante para debugar. você pode alterar o valor para gerar diferentes terrenos aleatórios.
  std::srand(100);

  doctest::Context context;
  return context.run(); 
}