#include <iostream>
#include <sstream>

std::string convert_to_notation(const std::string& str)
{
    std::stringstream ss;
    std::string buffer[15];
    int i = 0;
    for (auto c : str)
    {
        if(c >= '0' && c <= '9')
        {
            ss << c;
            
        }
        else{
            buffer[i++]=c;
            ss<<" ";
        }
    }

    ss<<" ";

    for(int j=0;j<i;j++)
    {
        ss << buffer[j];
        ss << " ";
    }
    return ss.str();


}

int main()
{
std::string str = "2+2+15+20*17-40";
std::cout << convert_to_notation(str) << std::endl;

}