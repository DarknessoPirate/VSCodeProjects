#include <iostream>
#include <vector>
// wspolczynnik uzywany do generatora LCG
#define a 69071
// wspolczynniki opoznienia do AWCG 
#define l 23
#define k 43
// modulo do generatorow
#define m 12893

int reg[k]; // tablica ktora zostanie zapelniona przez generator LCG a potem uzyta przez AWCG

unsigned long i; // okresla wewnetrzne przesuniecie w tablicy
unsigned long c; // wspolczynnik przesuniecia uzywany w AWCG

void LCGinit(unsigned long seed) // generator lcg używany do zainicjowania tablicy liczb losowych używanej w generatorze AWCG
{
    reg[0] = seed;
    for(int j = 1; j<k; j++)
    {
        reg[j] = (a * reg[j-1])% m;
    }
}


unsigned long AWCGgenerate()
{
    unsigned long result;
    result = (reg[k + i - l] % k + reg[i] + c);
    
    if(result < m){
        c = 0;
    }
    else{
        c = 1;
    }

    reg[i] = result;
    i = (i + 1) % k; // przesuniecie i o 1

    return result;
}

std::vector<unsigned long> GenerateRandomAWCG(int n)
{
    std::vector<unsigned long> result;
    for(int I = 1; I<n;I++)
    {
        result.push_back(AWCGgenerate());
    }
    return result;
}

void printVector(const std::vector<unsigned long>& vec)
{
    for(int i = 0; i<vec.size();i++)
        std::cout << vec[i] << " ";
}

int main()
{
    unsigned long seed;
    unsigned int n;
    std::cout << "Podaj seed: ";
    std::cin >> seed;
    std::cout << "Podaj ilosc liczb do wylosowania: ";
    std::cin >> n;
    i = 0; // ustawienie domyslnych wartosci na 0
    c = 0;
    LCGinit(seed);

    std::vector <unsigned long> liczbyWylosowane = GenerateRandomAWCG(n);
    printVector(liczbyWylosowane);
}