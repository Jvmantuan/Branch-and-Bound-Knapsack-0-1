#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <new>

using namespace std;

// Função que converte de string para int
int to_int(string str) {
    stringstream ss(str);
    int x = 0;
    ss >> x;
    return x;   
}

double *razao(double *obj, double *restricao, int tam) {
    double *v_razao = new(nothrow) double[tam];

    for (int i = 0; i < tam; i++) {
        v_razao[i] = obj[i] / restricao[i];
    }

    return v_razao;
}

int main(){
    ifstream entrada;
    string linha, c;
    
    entrada.open("instancias/entrada01.txt"); // Abre o arquivo

    // Se der erro ao abrir o arquivo, envia uma mensagem de erro
    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo!";
        return false;
    }
    
    getline(entrada, linha); // Lê o numero de variaveis
    int num_variaveis = to_int(linha); //Converte o valor lido para inteiro

    getline(entrada, linha); // Lê o valor do lado direito da restrição
    int b = to_int(linha);

    double *restricao = new(nothrow) double[num_variaveis]; // vetor das restrições
    double *obj = new(nothrow) double[num_variaveis]; // vetor da funcao objetivo
    //double *razao = new(nothrow) double[num_variaveis]; // vetor da razão
    
    // Se der erro de alocação, retorna false
    if(restricao == nullptr) {
        cerr << "Erro de alocação" << endl;
        return false; 
    } 
        
    // Lê a linha da f.o e passa para um vetor
    getline(entrada, linha);
    int j = 0; c.clear();
    for(int i = 0; i < linha.length(); i++){
        obj[j] = 0;
        if(linha[i] != ' ')
            c += linha[i];
        else {
            obj[j] = to_int(c);
            c.clear();
            j++;  
        }
    } 
    obj[j] = to_int(c); // Passa o ultimo valor do arquivo para a matriz
    
    cout << "Vetor da f.o: \n";
    for(int i = 0; i < num_variaveis; i++){
        cout << obj[i] << " ";
    }
    cout << endl;

    // Passa os coeficientes da restrição
    getline(entrada, linha);
    j = 0; c.clear();
    for(int i = 0; i < linha.length(); i++){
        restricao[j] = 0;
        if(linha[i] != ' ')
            c += linha[i];
        else {
            restricao[j] = to_int(c);
            c.clear();
            j++;  
        }
    } 
    restricao[j] = to_int(c); // Passa o ultimo valor do arquivo para a matriz

    cout << "Vetor das restricoes: \n";
    for(int i = 0; i < num_variaveis; i++){
        cout << restricao[i] << " ";
    }
    cout << endl;

    double *vetor_razao = razao(obj, restricao, num_variaveis);

    cout << "Razao de cada variavel: " << endl;
    for(int i = 0; i < num_variaveis; i++) {
        cout << vetor_razao[i] << " ";
    }    
}
