#include "terreno.h"
#include <fstream>
#include <cmath>

bool Terreno::randomizarCantos() {
    //IMPLEMENTAR ALEATORIZAR CANTOS
    return true;
}

bool Terreno::diamondSquare() {
    //IMPLEMENTAR DIAMOND SQUARE
    return true;
}

bool Terreno::diamond() {
    //IMPLEMENTAR DIAMOND
    return true;
}

bool Terreno::square() {
    //IMPLEMENTAR SQUARE
    return true;
}


Terreno::Terreno() {
    this->linhas = 0;
    this->colunas = 0;
    this->matriz = nullptr;
}

Terreno::Terreno(int n) {
    this->linhas = (pow(2, n) + 1);
    this->colunas = (pow(2, n) + 1);
    this->matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }
}

Terreno::~Terreno() {
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

bool Terreno::gerarTerreno(int n, float rugosidade) {
    //IMPLEMENTAR DIAMOND SQUARE
    return true;
}

int Terreno::obterAltitude(int linha, int coluna) const {
    return matriz[linha][coluna];
}

int Terreno::obterLargura() const {
    return colunas;
}

int Terreno::obterProfundidade() const {
    return linhas;
}


