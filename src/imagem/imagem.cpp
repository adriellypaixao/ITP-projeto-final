#include "imagem.h"
#include <fstream>
#include <sstream>

void Imagem::liberar() {
    for (int i = 0; i < altura; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
}

void Imagem::alocar(int largura, int altura) {
    this->largura = largura;   
    this->altura = altura;
    this->pixels = new Pixel*[altura];
    for (int i = 0; i < altura; i++) {
        this->pixels[i] = new Pixel[largura];
    }
}

Imagem::Imagem() {
    this->largura = 0;
    this->altura = 0;
    this->pixels = nullptr;
}

Imagem::Imagem(int largura, int altura){ 
    alocar(largura, altura);
     // inicializar a matriz com zeros: mudou-se o valor padrão para os r, g, b 
    //no struct Cor para zero.
}

Imagem::~Imagem() {
    liberar();
}

int Imagem::obterLargura() {
    return largura;
}

int Imagem::obterAltura() {
    return altura;
}

Pixel Imagem::obterPixel(int x, int y){
    if (x < 0 || x >= largura || y < 0 || y >= altura) {
        return {0, 0, 0};
    }
    return pixels[y][x]; //x = coluna, y = linha
}

void Imagem::definePixel(int x, int y, Pixel pixel) {
    pixels[y][x] = pixel; //x = coluna, y = linha
}

/*
um método para ler uma imagem no formato PPM (P3), dado o nome do arquivo. 
Se as dimensões da imagem no arquivo forem diferentes da imagem atual, 
os dados devem ser redimensionados.
*/
bool Imagem::lerPPM(const std::string nomeArquivo) {
    std::ifstream arquivo (nomeArquivo);

    if (!arquivo.is_open()) { // nao abriu aqrquivo
        return false;
    }

    // add função: ler cabeçários do arquivo
    std::string identificador, larg_alt_str, valor_max_str;

    std::getline(arquivo, identificador);
    std::getline(arquivo, larg_alt_str);
    std::getline(arquivo, valor_max_str);

    int valor_max = std::stoi(valor_max_str);

    int novaLargura, novaAltura;

    std::istringstream iss(larg_alt_str);
    iss >> novaLargura >> novaAltura; // precisa ser dessa forma, não da certo com stoi, pois pode ser um char

    if (novaLargura != largura || novaAltura != altura) {
        liberar();
        alocar(novaLargura, novaAltura);
    }

    for (int i = 0; i<altura; i++) {
        std::string linha;
        std::getline(arquivo, linha);
        std::istringstream iss(linha);
        int r, g, b;

        for (int j = 0; j < largura; j++) {
            iss >> r >> g >> b;

            pixels[i][j] = {r, g, b};
        }
    }

    arquivo.close();

    return true;
}

/*
um método para salvar a imagem no formato PPM (P3), dado o nome do arquivo.
*/
bool Imagem::salvarPPM(const std::string nomeArquivo) {
    
    // FALTA IMPLEMENTAR
    return false;
}