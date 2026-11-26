#pragma once
#include <string>

class Terreno {
    private:
        int** matriz;
        int linhas;
        int colunas;

        void alocar(int n);
        void liberar();
        void randomizarCantos();
        int randomizarRugosidade(float rugosidade);
        void diamondSquare(int distancia, float rugosidade);
        int retornaMediaDiamond(int i, int j, int distancia, float rugosidade);
        void diamond(int distancia, float rugosidade);
        int retornaMediaSquare(int i, int j, int distancia, float rugosidade);
        void square(int distancia, float rugosidade);

    public:
        Terreno();
        Terreno(int n);
        ~Terreno();
        bool gerarTerreno(int n, float rugosidade);
        int obterAltitude(int linha, int coluna) const;
        int obterQtdColunas() const;
        int obterQtdLinhas() const; 
        void definirAltitude(int linha, int coluna, int altitude);
        bool salvarTerreno(const std::string& nomeArquivo) const;
        bool lerTerreno(const std::string& nomeArquivo); //falta
};