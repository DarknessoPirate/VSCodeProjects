#include <iostream>
#include <vector>

std::vector<int> naivePatternSearch(const std::string& pattern, const std::string& text){
    int P = pattern.size();
    int T = text.size();
    std::vector<int> indices;

    for(int i = 0; i<T;i++){
        int j;

        for(j = 0; j<P; j++){
            if(text[i+j] != pattern[j])
                break;
        }

        if(j == P){
            std::cout << "pattern found at index " << i << std::endl; 
            indices.push_back(i);
        }

    }
    return indices;
}

int main(){

    std::vector<int> result = naivePatternSearch("ABC","AABCACDBABCABABCabcsa");

    std::cout << "Indexes: ";
    for(int i: result)
        std::cout << i << " ";


}