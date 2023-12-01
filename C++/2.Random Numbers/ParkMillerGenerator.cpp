#include <iostream>
#include <vector>

std::vector<int> generateRandomNumberPM(int s, int multiplier, int mod,int amountOfNumbers)// seed and modulo have to be coprime(their greatest common divisor = 1    )
{
    std::vector<int> result;
    int seed = s;
    int temp;
    for(int i = 0; i<amountOfNumbers;i++)
    {
        temp = (multiplier * seed )%mod;
        seed = temp;
        result.push_back(temp);
    }

    return result;
} 

void printVector(const std::vector<int> vec)
{
    for(int i = 0; i<vec.size();i++)
        std::cout << vec[i] << " ";
}


int main()
{
std::vector<int> nums = generateRandomNumberPM(187,16807,2147,10);
printVector(nums);




}