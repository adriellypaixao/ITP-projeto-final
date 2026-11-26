/**
 * Arquivo com a função principal do programa, que executa os testes das classes Paleta, Imagem e Terreno.
 */
#include <cstdlib>
#include <ctime>
#include "../paleta/paleta.h"
#include "../imagem/imagem.h"
#include "../terreno/terreno.h"
// integre aqui as demais classes para criar o seu programa, conforme especificado no enunciado da última etapa do projeto.

int main() {
    // inicializa o gerador de números aleatórios uma única vez no programa.
    std::srand(time(nullptr));
    Paleta paleta("cores.hex");
    Terreno terreno;
    terreno.gerarTerreno(8, 0.5);
    terreno.gerarImagem(paleta, false).salvarPPM("terreno.ppm");

    return 0;
}