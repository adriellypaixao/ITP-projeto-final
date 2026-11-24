#pragma once
#include <string>

class Terreno {
    int** matriz;
    int linhas;
    int colunas;

    bool randomizarCantos();
    bool diamondSquare();
    bool diamond();
    bool square();
    public:
    Terreno();
    Terreno(int n);
    ~Terreno();
    bool gerarTerreno(int n, float rugosidade);
    int obterAltitude(int linha, int coluna) const;
    int obterLargura() const; // nome confuso, qria trocar
    int obterProfundidade() const; // NOME MT CONFUSO, qria trocar
    int salvarTerreno(const std::string nomeArquivo) const;
    int lerTerreno(const std::string nomeArquivo);
};