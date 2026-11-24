#include "terreno.h"
#include <fstream>
#include <cmath>
# include <cstdlib>

void Terreno::alocar(int n){
    this->linhas = (pow(2, n) + 1);
    this->colunas = (pow(2, n) + 1);
    this->matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }
}

void Terreno::liberar(){
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

bool Terreno::randomizarCantos() {
    if(matriz == nullptr || linhas < 2 || colunas < 2) {
        return false; // Verifica se possui pelo menos 2 linhas e 2 colunas
    }
    matriz[0][0] = (std::rand() % 101); // Gera um número aleatório entre 0 e 100
    matriz[0][colunas-1] = (std::rand() % 101);
    matriz[linhas-1][0] = (std::rand() % 101);
    matriz[linhas-1][colunas-1] = (std::rand() % 101);
    return true;
}

bool Terreno::diamondSquare() {
    //IMPLEMENTAR DIAMOND SQUARE
    return true;
}

bool Terreno::diamond(int distancia) {
    //IMPLEMENTAR DIAMOND
    return true;
}

bool Terreno::square(int distancia) {
    //IMPLEMENTAR SQUARE
    return true;
}


Terreno::Terreno() {
    this->linhas = 0;
    this->colunas = 0;
    this->matriz = nullptr;
}

Terreno::Terreno(int n) {
    alocar(n); // 2 ^ n + 1
    
    // inicializar a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = -1;
        }
    }
}

Terreno::~Terreno() {
    liberar();
}

bool Terreno::gerarTerreno(int n, float rugosidade) {
    alocar(n);
    randomizarCantos();
    return true;
}

int Terreno::obterAltitude(int linha, int coluna) const {
    return matriz[linha][coluna];
}

int Terreno::obterQtdColunas() const {
    return colunas;
}

int Terreno::obterQtdLinhas() const {
    return linhas;
}


