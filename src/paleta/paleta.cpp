/*
DÚVIDAS:
- será que pode usar vector? no .h, pede "Representa uma paleta de cores, que é um conjunto de cores armazenadas em um array alocado
 * dinamicamente"?
- pode mudar o .h?
*/

#include "paleta.h"
#include <string>
#include <fstream> // depois ver se é melhor fstream (escrita e leitura) ou ifstream(só leitura)
#include <vector>
using namespace std;
// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h

Paleta::Paleta(int tamanho) : cores(new Cor[tamanho]), tamanho(tamanho) {};

Paleta::Paleta(const string& nomeArquivo) {
    vector<Cor> paleta_temp; // usada para descobrir o tamanhho;
    fstream arquivo(nomeArquivo);

    string cor_str;
    while (getline(arquivo, cor_str)) {
        // separa # r g b

        // converter de hexa para int
        int r = stoi(cor_str.substr(1, 2), 0, 16);
        int g = stoi(cor_str.substr(1, 2), 0, 16);
        int b = stoi(cor_str.substr(1, 2), 0, 16);

        Cor cor = {r, g, b};

        paleta_temp.push_back(cor);
    }
    arquivo.close();

    //inicializa o array dinâmico com valores do vector
    int tamanho = paleta_temp.size();
    Cor *cores = new Cor[tamanho];

    for (int i = 0; i< tamanho; i++) {
        cores[i] = paleta_temp[i];
    }   
};

int Paleta::obterTamanho() const {
    return tamanho;
};

int Paleta::obterQuantidade() const {
    return 0;
};

void Paleta::adicionarCor(const Cor& cor) {

};

Cor Paleta::obterCor(int indice) {
    Cor cor;
    return cor;
};