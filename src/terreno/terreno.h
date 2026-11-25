#pragma once
#include <string>

class Terreno {
    public:
        int** matriz;
        int linhas;
        int colunas;

        void alocar(int n);
        void liberar();
        void randomizarCantos();
        void diamondSquare(int distancia);
        int retornaMediaDiamond(int i, int j, int distancia);
        void diamond(int distancia);
        int retornaMediaSquare(int i, int j, int distancia);
        void square(int distancia);

    public:
        Terreno();
        Terreno(int n);
        ~Terreno();
        bool gerarTerreno(int n, float rugosidade);
        int obterAltitude(int linha, int coluna) const;
        int obterQtdColunas() const;
        int obterQtdLinhas() const; 
        bool salvarTerreno(const std::string& nomeArquivo) const;
        bool lerTerreno(const std::string& nomeArquivo); //falta
};