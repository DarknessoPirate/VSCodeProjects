#include <iostream>
#include <cstring>
#define N_OF_CHARS 256

// preprocessing looks for indexes of each original character in the pattern and saves its last occurence in a given array(in this case badChar)
void preprocessing(const std::string& str, int badChar[N_OF_CHARS]){
    // set all values to -1 first
    std::memset(badChar, -1, 4*N_OF_CHARS);

    for(int i = 0; i<str.size(); i++)
        badChar[(int)str[i]] = i;
}

void BoyerMoore(const std::string& pattern, const std::string& text){
    int P = pattern.size();
    int T = text.size();

    int badChar[N_OF_CHARS];

    // fill the badChar array with -1 to initialize it
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
        // if the pattern fully matches at this shift j will finally reach -1
        if(j<0){
            std::cout << "Pattern occurs at index = " << s << std::endl;
            // if pattern length + another shift is less than full text, shift the pattern so that the next character in text aligns with the
            // last occurence of this character in pattern
            if(s + P < T)
                s += P - badChar[text[s+P]];
            else
                s += 1;
        }
        else{
            // shift the pattern so that the bad character in text aligns with the last occurence of it in the pattern
            s+= std::max(1,j-badChar[text[s+j]]);
        }

    }
}


int main(){
    std::string txt= "ABAAABCDABC"; 
    std::string pat = "ABC"; 
    BoyerMoore(pat, txt); 

}