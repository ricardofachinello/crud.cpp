//git test
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct distro{
    string nome;
    string versao;
    string kernelver;
    string arq;
};

int main(){
    struct distro dist;
    int a;
    while(true){
        cout << "Escrever (1)\nLer (2)\n-> ";
        if(scanf("%u",&a)==EOF){
            return 0;
        }
    if(a==1){
        cout << "Nome da distro: ";
        cin >> dist.nome;
        cout << "Versao da distro: ";
        cin >> dist.versao;
        cout << "Versao do kernel: ";
        cin >> dist.kernelver;
        cout << "Arquitetura: ";
        cin >> dist.arq;
        cout << "\n";
        ofstream escrita;
        escrita.open("data.txt", ofstream::out | ofstream::binary | ofstream::app);
        if(!escrita.is_open()){
            cout << "O arquivo não pode ser aberto!\n";
            return 1;
        }
        string data = dist.nome + "æ" + dist.versao + "Æ" + dist.kernelver + "½" + dist.arq;
        escrita << data << "¼";
    }
    else if(a==2){
        ifstream leitura;
        leitura.open("data.txt", ifstream::in | ifstream::binary);
        if(!leitura.is_open()){
            cout << "O arquivo não pode ser aberto!\n";
            return 1;
        }
        string s;
        while(getline(leitura,s)){
            int lel = s.find_first_of("æ");
            dist.nome = s.substr(0,lel-1);
            cout << "\nNome da distro : " << dist.nome;
            int lel2 = s.find_first_of("Æ");
            dist.versao = s.substr(lel+1,lel2-lel-2);
            cout << "\nVersao da distro : " << dist.versao;
            int lel3 = s.find_first_of("½");
            dist.kernelver = s.substr(lel2+1,lel3-lel2-2);
            cout << "\nVersao do kernel : " << dist.kernelver;
            int lel4 = s.find_first_of("¼");
            dist.arq = s.substr(lel3+1,lel4-lel3-2);
            cout << "\nArquitetura : " << dist.arq;
            cout << "\n";
        }

    }
    else{
        cout << "Funcao nao implementada!\n";
    }
    }
    
    
    return 0;
}