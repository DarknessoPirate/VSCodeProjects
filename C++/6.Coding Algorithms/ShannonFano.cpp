#include <iostream>

struct Node{
    std::string Symbol;
    float frequency;
    int arr[20];
    int top;
}nodes[20];


void Shannon(int start, int size, Node nodes[]){
    float gr1 = 0, gr2 = 0, diff1 = 0, diff2 = 0; // initializing variables for the first time to use later
    if((start + 1) == size || (start == size) || (start > size)){
        if((start == size) || (start > size))
            return;

        nodes[size].arr[++(nodes[size].top)] = 0;
        nodes[start].arr[++(nodes[start].top)] = 1;
        return;
    }
    else{
        for(int i = start; i<= size; i++){
            gr1 += nodes[i].frequency;
        }

        gr2 += nodes[size].frequency;
        diff1 = gr1 - gr2;
        if(diff1 < 0);
            diff1 *= -1;

        int k;
        int j = 2;
        while(j != size - start + 1){
            k = size - j;
            gr1 = 0;
            gr2 = 0;

            for(int i = start; i <= k; i++)
                gr1 += nodes[i].frequency;

            for(int i = size; i > k; i-- )
                gr2 += nodes[i].frequency;

            diff2 = gr1 - gr2;
            if(diff2 < 0)
                diff2 *= -1;
            if(diff2 > diff1)
                break;
            diff1 = diff2;
            j++;
        }

        k++;
        for(int i = start; i <= k; i++)
            nodes[i].arr[++(nodes[i].top)] = 1;
        for(int i = k+1; i <= size; i++)
            nodes[i].arr[++(nodes[i].top)] = 0;


        Shannon(start, k, nodes);
        Shannon(k+1, size, nodes);
    }
}

void sortByFrequency(Node nodes[], int size){
    Node temp;
    for(int i = 1; i <= size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if((nodes[j].frequency) > (nodes[j+1].frequency)){
                temp.frequency = nodes[j].frequency;
                temp.Symbol = nodes[j].Symbol;

                nodes[j].frequency = nodes[j+1].frequency;
                nodes[j].Symbol = nodes[j+1].Symbol;

                nodes[j+1].frequency = temp.frequency;
                nodes[j+1].Symbol = temp.Symbol;
            }
        }
    }
}

void printCodes(Node nodes[], int size){
    std::cout << "Symbol\t\tProbability\tCode";
    for(int i = size-1; i >= 0; i--){
        std::cout << "\n\t" << nodes[i].Symbol << "\t\t" << nodes[i].frequency << "\t";
        for(int j = 0; j < nodes[i].top + 1; j++){
            std::cout << nodes[i].arr[j];
        }
    }
}

int main(){

    int no_of_symbols;
    std::string symbol;
    float total = 0;
    float freq;
    std::cout << "Enter number of symbols: ";
    std::cin >> no_of_symbols; 

    for(int i = 0; i < no_of_symbols; i++){
        std::cout << "Enter symbol";
        std::cin >> symbol;
        nodes[i].Symbol = symbol;
    }

    for(int i = 0; i < no_of_symbols; i++){
        std::cout << "Enter frequency of symbol " << nodes[i].Symbol << ": ";
        std::cin >> nodes[i].frequency;
        total += nodes[i].frequency;

        if(total > 1){
            std::cout << "Invalid frequency, total exceeds 1. Enter new value: ";
            total -= nodes[i].frequency;
            i--;
        }
    }

    sortByFrequency(nodes , no_of_symbols);

    for(int i = 0; i < no_of_symbols; i++)
        nodes[i].top = -1;

    Shannon(0, no_of_symbols - 1, nodes);

    printCodes(nodes, no_of_symbols);
}