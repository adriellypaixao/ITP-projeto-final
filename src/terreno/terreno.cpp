#include "terreno.h"
#include <fstream>
#include <cmath>
#include <cstdlib>

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
 
int Terreno::retornaMediaSquare(int i, int j, int distancia) {
    int p1 = ((i - distancia) >= 0) ? matriz[i-distancia][j] : 0; // ponto de cima 
    int p2 = ((j - distancia) >= 0) ? matriz[i][j - distancia] : 0; // ponto da esquerda
    int p3 = ((j + distancia) < colunas) ? matriz[i][j + distancia] : 0; // ponto da direita
    int p4 = ((i + distancia) < linhas) ? matriz[i+distancia][j] : 0; // ponto de baixo 
    
    int qtd_pontos = 4;
    
    // definir a média:
    if (i == 0 || i == (linhas - 1) || j == 0 || j == (colunas - 1) ) { //bordas, só vai ter 3 pontos pŕoximos
        qtd_pontos -= 1; 
    }
    
    int media = (p1 + p2 + p3 + p4) / qtd_pontos;
    
    return media;
}

bool Terreno::square(int distancia) {
    if (distancia < 1) return false;

    bool comecaDeslocado = true;
    for (int i = 0; i < linhas; i += distancia) {
        if (comecaDeslocado) {
            for (int j = distancia; j < colunas; j+=(distancia*2)) {
                matriz[i][j] = retornaMediaSquare(i, j, distancia);
            }
        }
        else { // começar a preencher pela coluna 0
            for (int j = 0; j < colunas; j+=(distancia*2)) {
                matriz[i][j] = retornaMediaSquare(i, j, distancia);
            }
        }
        comecaDeslocado = (comecaDeslocado == true) ? false : true; // inverter valores: se tá true, troca pra false e vice-versa
    }
    
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


