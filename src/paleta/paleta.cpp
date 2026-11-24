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
// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h

Cor converterHexaParaCor(const std::string& cor_str) {
    int r = std::stoi(cor_str.substr(1, 2), 0, 16);
    int g = std::stoi(cor_str.substr(3, 2), 0, 16);
    int b = std::stoi(cor_str.substr(5, 2), 0, 16);
    return Cor{r, g, b};
}

Paleta::Paleta(int tamanho) : cores(new Cor[tamanho]), tamanho(tamanho), quantidade(0) {};

Paleta::Paleta(const std::string& nomeArquivo){
    std::vector<Cor> paleta_temp; // usada para descobrir o tamanhho;
    std::ifstream arquivo(nomeArquivo);

    std::string cor_str;
    while (getline(arquivo, cor_str)) {
        // converter de hexa para int
        Cor cor = converterHexaParaCor(cor_str);

        paleta_temp.push_back(cor);
    }
    arquivo.close();

    int tam = paleta_temp.size();
    this->cores = new Cor[tam];

    for (int i = 0; i< tam; i++) {
        cores[i] = paleta_temp[i];
    }   

    this->tamanho=tam;
    this->quantidade=tam;
};

Paleta::~Paleta() {
    delete[] cores;
}

int Paleta::obterTamanho() const {
    return tamanho;
};

int Paleta::obterQuantidade() const {
    return quantidade;
};

void Paleta::adicionarCor(const Cor& cor) {
    if (quantidade < tamanho) {
        cores[quantidade] = cor;
        quantidade++;
    }
};

Cor Paleta::obterCor(int indice) {
    if (indice < 0 || indice >= quantidade) {
        return Cor{0, 0, 0};
    }
    return cores[indice];
};