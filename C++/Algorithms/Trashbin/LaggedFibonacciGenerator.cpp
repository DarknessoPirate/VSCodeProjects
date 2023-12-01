#include <iostream> 
#include <vector>

unsigned int UseOperator(int a, int b, char opr)
{
    switch(opr){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '^': return a^b;
        case '&': return a&b;
        case '|': return a|b;
    }
    return 0;
}
std::vector<unsigned int> Generator(unsigned int mod, char opr, std::vector<unsigned int>& data, int k , int n){
    for(int i = data.size()-1; i+1 < n; i++){
        unsigned int a = data[i];
        unsigned int b = data[i-k];
        data.push_back(UseOperator(a, b, opr) % mod);
    }
    return data;
}

int main()
{
std::vector<unsigned int> data;
std::cout << "Podaj 10 pierwszych wyrazow";
for(int i = 0; i < 10; i++)
{
    int temp;
    std::cin >> temp;
    data.push_back(temp);
}
char opr;
int k, n, mod; 
std::cout << "Podaj ile wyrazow wypisac: \n";
std::cin >> n ;
std::cout << "Podaj operator: \n";
std::cin >> opr ;
std::cout << "Podaj ktory wyraz wstecz: \n";
std::cin >> k ;
std::cout << "Podaj zakres gorny: \n";
std::cin >> mod;

std::vector<unsigned int> result = Generator(mod, opr, data , k, n);

for(unsigned int k: result)
{
    std::cout<< k << " ";
}
    
}