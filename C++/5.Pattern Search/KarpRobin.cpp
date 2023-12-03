#include <iostream>
#include <cstring>

// number in the input alphabet
# define D 256
// q -> prime number
void search(char pattern[], char text[], int q){
    int P = strlen(pattern);
    int T = strlen(text);
    int pattern_hash = 0;
    int substr_hash = 0;
    int h = 1; // used to store value used for calculating hash
    int j; // bigger variable scope

    for(int i = 0; i < P - 1; i++)
        h = (h * D) % q;

    // calculate hash value of pattern and hash value of first substring in text
    for(int i = 0; i < P; i++){
        pattern_hash = (D * pattern_hash + pattern[i]) % q;
        substr_hash = (D * substr_hash + pattern[i]) % q;
    }

    for(int i = 0; i <= T - P; i++ ){
        // check hash values of currently selected substring and pattern.
        // if hash values match then check the characters one by one
        if(pattern_hash == substr_hash){
            for(j = 0; j < P; j++){
                if(text[i+j] != pattern[j]){
                    break;
                }
            }
            if(j == P)
                std::cout << "Pattern found at index " << i << std::endl;
        }
            // calculate the hash value of the next substr
            if(i < T - P){
                substr_hash = (D * (substr_hash - text[i] * h) + text[P+i]) % q;

                if(substr_hash < 0)
                    substr_hash = substr_hash + q;
            }
        }
    }


int main(){

    char text[] = "ABABCABDFEG";
    char pattern[] = "AB";

    int q = INT_MAX;
    search(pattern, text, q);
}