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

void Terreno::randomizarCantos() {
    matriz[0][0] = (std::rand() % 101); // Gera um número aleatório entre 0 e 100
    matriz[0][colunas-1] = (std::rand() % 101);
    matriz[linhas-1][0] = (std::rand() % 101);
    matriz[linhas-1][colunas-1] = (std::rand() % 101);
}

void Terreno::diamondSquare(int distancia) {
    diamond(distancia);
    square(distancia);
}

int Terreno::retornaMediaDiamond(int i, int j, int distancia) {
    distancia/=2;
    
    int p1 = matriz[i-distancia][j-distancia];
    int p2 = matriz[i+distancia][j - distancia];
    int p3 = matriz[i-distancia][j + distancia];
    int p4 = matriz[i+distancia][j+distancia];
    
    int media = (p1 + p2 + p3 + p4) / 4;
    
    return media;
}

void Terreno::diamond(int distancia) {
    int linha_atual = distancia/2;
    int coluna_atual = distancia/2;

    for (int i = linha_atual; i < linhas; i += distancia) {
        for (int j = coluna_atual; j < colunas; j += distancia) {
            matriz[i][j] = retornaMediaDiamond(i, j, distancia);
        }
    }
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

void Terreno::square(int distancia) {
    if (distancia < 1) return;
    
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
    if (n < 0 || rugosidade < 0.0) {
        return false;
    }
    alocar(n);
    randomizarCantos();
    for (int distancia = pow(2, n); distancia >= 1; distancia /= 2) {
        diamondSquare(distancia);
    }
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


