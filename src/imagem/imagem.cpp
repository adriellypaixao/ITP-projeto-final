#include "imagem.h"

Imagem::Imagem(int largura, int altura){
    this->largura = largura;
    this->altura = altura;
    this->pixels = new Pixel*[altura]; 
    for (int i = 0; i < altura; i++) {
        this->pixels[i] = new Pixel[largura];
    } // inicializar a matriz com zeros, mudou-se o valor padrão para os r, g, b 
    //no struct Cor para zero.
}

Imagem::~Imagem() {
    for (int i = 0; i < altura; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
}

Pixel Imagem::obterPixel(int x, int y){
    return pixels[x][y];
}

void Imagem::definirPixel(int x, int y, Pixel pixel) {
    pixels[x][y] = pixel;
}

bool Imagem::ler(const std::string nomeArquivo) {
    // FALTA IMPLEMENTAR
    return false;
}

bool Imagem::salvar(const std::string nomeArquivo) {
    // FALTA IMPLEMENTAR
    return false;
}