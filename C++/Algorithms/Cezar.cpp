#include <iostream>
#include <typeinfo>

void Cezar(std::string& text, int key){

    for(int i = 0; i<text.size();i++){
      if(text[i] >= 'a' && text[i] <= 'z'){
        if(text[i]+key > 'z')
          text[i] -= 26;
        if(text[i]+key < 'a')
          text[i] += 26;
      }
      
      if(text[i] >= 'A' && text[i] <= 'Z'){
        if(text[i]+key > 'Z')
          text[i] -= 26;
        if(text[i]+key < 'A')
          text[i] += 26;
      }
     

      text[i] += key;
    }
}

int main(){
    std::string str = "ABCDabcd#";
    Cezar(str,-2);
    std::cout << str << std::endl;
    Cezar(str,2);
    std::cout << str << std::endl;
}
