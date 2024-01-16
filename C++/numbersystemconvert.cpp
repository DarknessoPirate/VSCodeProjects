#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
std::string reverse_string(std::string text){
    std::string result = "";
    for(int i = text.length()-1; i>=0; i--)
        result+= text[i];
    return result;
}

std::string convert_to_base(int number, int base){
        std::string converted_number;
        while(number > 0)
    {
        int temp = number % base;
        number /= base;
        converted_number += std::to_string(temp);
    }
        return reverse_string(converted_number);
    }

int convert_to_decimal(std::string number, int base){
    int number_index = 0;
    int result = 0;
    for(std::string::reverse_iterator it = number.rbegin(); it != number.rend(); it++){
        int current_number = *it - '0';
        if(number_index == 0)
            result += current_number;
        else{
            result += current_number*pow(base, number_index);
        }
        number_index++;
    }
    return result;
}

std::string convert_to_ascii(std::string text){
    std::string result = "";
    for(int i = 0; i<text.length(); i++){
        result += std::to_string(int(text[i]));
        result += " "; 
    }
    return result;
}


std::string cipher_word(const std::string text_argument){
    int current_letter = 0;
    int int_buffer;
    std::string str_buffer;
    std::string result = "";
    std::string text = convert_to_ascii(text_argument);
    int i = 0;
    while(i < text.length()){
        while(text[i] != ' ' && i<text.length()){
            str_buffer += text[i];
            i++;
        }
        if(current_letter == 0){
            int_buffer = std::stoi(str_buffer);
            result += convert_to_base(std::stoi(str_buffer),2);
            result += " ";
        }
        else{
            int base = int_buffer%8 + 2;
            int_buffer = std::stoi(str_buffer);
            result += convert_to_base(std::stoi(str_buffer),base);
            result += " ";
        }
        current_letter++;
        i++;
        str_buffer = "";
    }
    return result;
}

std::string decipher_word(std::string word){
    int current_letter = 0;
    int int_buffer;
    std::string str_buffer;
    std::string result;
    int i = 0;
    int base;
    while(i < word.length()){
        while(word[i] != ' '){
            str_buffer += word[i];
            i++;
        }

        if(current_letter == 0){
            int_buffer = convert_to_decimal(str_buffer,2);
            result += char(int_buffer);
        }
        else{
            base = int_buffer%8 + 2;
            int_buffer = convert_to_decimal(str_buffer,base);
            result += char(int_buffer);
        }
        current_letter++;
        i++;
        str_buffer = "";
    }
    return result;
}
int main(){
    std::string test = "Bit";
    std::string ciphered_word = cipher_word(test);
    std::cout << ciphered_word << "\n";
    std::string deciphered_word = decipher_word(ciphered_word);
    std::cout << deciphered_word;
}