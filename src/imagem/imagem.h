/**
 * Declaração da classe Imagem.
 */

#include <string>
#include "../paleta/paleta.h"
#pragma once
using Pixel = Cor; // Pixel agora é outro nome para Cor, representando a cor de um pixel da imagem.

class Imagem {
    private:
        int largura;
        int altura;
        Pixel** pixels;
        void liberar();
        void alocar(int largura, int altura);

    public:
        Imagem();
        Imagem(int largura, int altura);
        ~Imagem();
        Pixel obterPixel(int x, int y);
        int obterLargura();
        int obterAltura();
        void definePixel(int x, int y, Pixel pixel);
        bool lerPPM(const std::string nomeArquivo);
        bool salvarPPM(const std::string nomeArquivo);
};

// Lembre-se de:
// 1. verificar no arquivo de teste o nome correto da classe, dos métodos que você deve implementar, bem como os
//    parâmetros e tipos de retorno de cada método.
// 2. documentar a classe e seus métodos, seguindo o padrão do arquivo paleta.h.
// 3. implementar no arquivo imagem.cpp os métodos da classe.
