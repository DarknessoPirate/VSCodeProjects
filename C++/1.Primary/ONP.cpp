#include <iostream>
#include <sstream>
#include <stack>
#include <map>
#include <cctype>

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isNumeral(char c)
{
    return c >= '0' && c <= '9';
}


std::string convert_to_onp (const std::string& str)
{
    std::stringstream ss;
    std::string buffer[15];
    std::stack<char> stos;
    std::map<char,int> dict;
    dict['^'] = 4;
    dict['*'] = 3;
    dict['/'] = 3;
    dict['+'] = 1;
    dict['-'] = 1;
    int i = 0;
    for (char c : str)
    {
        if(isdigit(c)){
            ss << c;
        }
        
        else if(isOperator(c)){
            ss << ' ';
            if(stos.empty()){
                stos.push(c);
            }

            else if(dict[stos.top()]<dict[c]){
                stos.push(c);
            }

            else if(dict[stos.top()]>=dict[c]){
                while(dict[stos.top()>=dict[c]]){
                    ss << ' ';
                    ss << stos.top();
                    stos.pop();
                }
                stos.push(c);
            }
        }

        else if(c == '('){
            stos.push(c);
        }

        else if(c == ')'){
            
            while(stos.top() != '('){
                ss << ' ';
                ss << stos.top();
                stos.pop();
            }
            stos.pop();
        }

    }

    while(!stos.empty())
        {
            ss << ' ';
            ss << stos.top();
            stos.pop();

        }
    return ss.str();
}

std::string convert_from_onp(const std::string& onp)
{
    std::stack<std::string> buffer;
    std::istringstream input(onp);
    std::string temp;
    std::stringstream output;

    while (input >> temp) {
        if (isdigit(temp[0]) || (temp[0] == '-' && temp.size() > 1)) {
            buffer.push(temp);
        } else if (isOperator(temp[0])) {
            std::string operand2 = buffer.top();
            buffer.pop();
            std::string operand1 = buffer.top();
            buffer.pop();
            std::string result = "(" + operand1 + " " + temp + " " + operand2 + ")";
            buffer.push(result);
        }
    }

    while(!buffer.empty())
    {
        output << buffer.top();
        buffer.pop();
    }

    return output.str();
}
int main()
{
    std::string onp= "4 + 3 - 7";
    std::string a = "4*(5-(6/3)+1)^2";  
    std::cout << "Wyrazenie: "<< onp << " = " << convert_from_onp(onp) << std::endl;
    std::cout<< "Wyrazenie: "<< a << " = "<< convert_to_onp(a);
}