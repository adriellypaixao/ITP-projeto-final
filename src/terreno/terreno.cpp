#include "terreno.h"
#include "imagem.h"
#include "paleta.h"
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
    matriz[0][0] = (std::rand() % 1001); // Gera um número aleatório entre 0 e 1000
    matriz[0][colunas-1] = (std::rand() % 1001);
    matriz[linhas-1][0] = (std::rand() % 1001);
    matriz[linhas-1][colunas-1] = (std::rand() % 1001);
}

int Terreno::randomizarRugosidade(float rugosidade) {
    return (std::rand() % 2001 - 1000) * rugosidade; // Gera um número entre -1000 e 1000 e multiplica pela rugosidade
}

void Terreno::diamondSquare(int distancia, float rugosidade) {
    diamond(distancia, rugosidade);
    square(distancia, rugosidade);
}

int Terreno::retornaMediaDiamond(int i, int j, int distancia, float rugosidade) {
    distancia/=2;
    
    int p1 = matriz[i-distancia][j-distancia];
    int p2 = matriz[i+distancia][j - distancia];
    int p3 = matriz[i-distancia][j + distancia];
    int p4 = matriz[i+distancia][j+distancia];
    
    int media = (p1 + p2 + p3 + p4) / 4;
    media+= randomizarRugosidade(rugosidade);
    media = (media < 0) ? 0 : media;
    return media;
}

void Terreno::diamond(int distancia, float rugosidade) {
    int linha_atual = distancia/2;
    int coluna_atual = distancia/2;

    for (int i = linha_atual; i < linhas; i += distancia) {
        for (int j = coluna_atual; j < colunas; j += distancia) {
            matriz[i][j] = retornaMediaDiamond(i, j, distancia, rugosidade);
        }
    }
}
 
int Terreno::retornaMediaSquare(int i, int j, int distancia, float rugosidade) {
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
    media+= randomizarRugosidade(rugosidade);
    media = (media < 0) ? 0 : media;
    return media;
}

void Terreno::square(int distancia, float rugosidade) {
    distancia /= 2;
    
    bool comecaDeslocado = true;
    for (int i = 0; i < linhas; i += distancia) {
        if (comecaDeslocado) {
            for (int j = distancia; j < colunas; j+=(distancia*2)) {
                matriz[i][j] = retornaMediaSquare(i, j, distancia, rugosidade);
            }
        }
        else { // começar a preencher pela coluna 0
            for (int j = 0; j < colunas; j+=(distancia*2)) {
                matriz[i][j] = retornaMediaSquare(i, j, distancia, rugosidade);
            }
        }
        comecaDeslocado = (comecaDeslocado == true) ? false : true; // inverter valores: se tá true, troca pra false e vice-versa
    }
}

int Terreno::maximoValor() const {
    int max = matriz[0][0];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
    }
    return max;
}

int Terreno::minimoValor() const {
    int min = matriz[0][0];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] < min) {
                min = matriz[i][j];
            }
        }
    }
    return min;
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
    if (n <= 0 || rugosidade < 0.0) {
        return false;
    }
    if (pow(2, n) + 1 != linhas || pow(2, n) + 1 != colunas || matriz == nullptr) {
        liberar();
        alocar(n);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = -1;
            }
        }
    }
    if(matriz[0][0] == -1 || matriz[0][colunas-1] == -1 || matriz[linhas-1][0] == -1 || matriz[linhas-1][colunas-1] == -1) {
        randomizarCantos();
    }
    //randomizarCantos();
    for (int distancia = pow(2, n); distancia > 1; distancia /= 2, rugosidade /= 2.0) {
        diamondSquare(distancia, rugosidade);
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

void Terreno::definirAltitude(int linha, int coluna, int altitude) {
    matriz[linha][coluna] = altitude;
}

bool Terreno::salvarTerreno(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo) {
        return false; // não conseguiu abrir o arquivo
    }
    //dimensoes da matriz
    arquivo << linhas << " " << colunas << "\n";

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << "\n";
    }
    arquivo.close();

    return true;
}

bool Terreno::lerTerreno(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    int linhas, colunas, altitude;
    arquivo >> linhas >> colunas;

    if (!arquivo.is_open() || arquivo.fail()) return false;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arquivo >> altitude;
            matriz[i][j] = altitude;
        }
    }
    arquivo.close();
    return true;
}

Imagem Terreno::gerarImagem(const Paleta& paleta, bool sombra) const {
    Imagem imagem(colunas, linhas);

    int max = maximoValor();
    int min = minimoValor();
    int quantidade = paleta.obterQuantidade();
    float range = (float)(max - min) / quantidade;
    if(range == 0) range = 1;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int altitude = matriz[i][j];
            int indexCor = (altitude - min) / range;
            if (indexCor >= quantidade) {
                indexCor = quantidade - 1;
            }
            Cor cor = paleta.obterCor(indexCor);
            Pixel pixel{cor.r, cor.g, cor.b};
            imagem.definePixel(j, i, pixel);
        }
    }
    if(sombra){
        sombrear(imagem);
    }
    return imagem;
}

void Terreno::sombrear(Imagem& imagem) const {
    for (int i=1; i<linhas; i++) {
        for (int j=1; j<colunas; j++) {
            int altitudeAtual = matriz[i][j];
            int altitudeVizinho = matriz[i-1][j-1];
            if (altitudeAtual < altitudeVizinho) {
                Pixel pixel = imagem.obterPixel(j, i);
                pixel.r *= 0.7;
                pixel.g *= 0.7;
                pixel.b *= 0.7;
                imagem.definePixel(j, i, pixel);
            }
        }
    }
}

