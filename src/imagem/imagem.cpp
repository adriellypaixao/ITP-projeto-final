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

int Imagem::obterLargura() {
    return largura;
}

int Imagem::obterAltura() {
    return altura;
}

Pixel Imagem::obterPixel(int x, int y){
    return pixels[x][y];
}

void Imagem::definePixel(int x, int y, Pixel pixel) {
    pixels[x][y] = pixel;
}

bool Imagem::lerPPM(const std::string nomeArquivo) {
    // FALTA IMPLEMENTAR
    return false;
}

bool Imagem::salvarPPM(const std::string nomeArquivo) {
    // FALTA IMPLEMENTAR
    return false;
}