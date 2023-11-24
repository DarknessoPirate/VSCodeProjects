#include <iostream>
#include <cstring>
#define N_OF_CHARS 256

void preprocessing(const std::string& str, int badChar[N_OF_CHARS]){
    // set all values to -1
    std::memset(badChar, -1, 4*N_OF_CHARS);

    for(int i = 0; i<str.size(); i++)
        badChar[(int)str[i]] = i;
}

void BoyerMoore(const std::string& pattern, const std::string& text){
    int P = pattern.size();
    int T = text.size();

    int badChar[N_OF_CHARS];

    preprocessing(pattern, badChar);

    // s = shift of the pattern in relation to the text
    int s = 0;

    while(s<= (T-P)){
        // we start from the end of the pattern
        int j = P - 1;

        // Keep reducing index of pattern while the characters are matching 
        // at the current shift value
        while(j >= 0 && pattern[j] == text[s+j])
            j--;

        if(j<0){
            std::cout << "Pattern occurs at shift = " << s << std::endl;
            s += (s + P < T )? P - badChar[text[s + P]] : 1;
        }
        else{
            s+= std::max(1,j-badChar[text[s+j]]);
        }

    }
}


int main(){
    std::string txt= "ABAAABCD"; 
    std::string pat = "ABC"; 
    BoyerMoore(txt, pat); 

}