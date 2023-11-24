#include <iostream>
#include <vector>

std::vector<int> linearCongrugentialGenerator(int s, int mod , int multiplier, int increment, int numAmount)
{
    std::vector<int> numbers;
    int seed = s;

    for(int i = 0; i<numAmount;i++)
    {
        int temp = ((seed * multiplier) + increment)%mod; // number generation formula
        numbers.push_back(temp);
        seed = temp; // the last generated element becomes the seed for the next generated element
    }

    return numbers;
}

void printVector(const std::vector<int> vec)
{
    for(int i = 0; i<vec.size();i++)
        std::cout << vec[i] << " ";
}
int main()
{

std::vector<int> a = linearCongrugentialGenerator(12893,2147,16807,3,30);
printVector(a);


}