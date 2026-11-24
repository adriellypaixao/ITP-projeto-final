#pragma once
#include <string>

class Terreno {
    int** matriz;
    int linhas;
    int colunas;

    void alocar(int n);
    void liberar();
    bool randomizarCantos();
    bool diamondSquare();
    bool temPontoCentral();
    bool diamond();
    bool square();

    public:
        Terreno();
        Terreno(int n);
        ~Terreno();
        bool gerarTerreno(int n, float rugosidade);
        int obterAltitude(int linha, int coluna) const;
        int obterQtdColunas() const;
        int obterQtdLinhas() const; 
        int salvarTerreno(const std::string nomeArquivo) const;
        int lerTerreno(const std::string nomeArquivo);
};