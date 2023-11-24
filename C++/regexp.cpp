#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <regex>

typedef std::pair<int,int> Pair;
typedef std::pair<int, Pair> pPair;



int main(){
/*
std::string a = "aaaaa                        aa              a                   a";
std::regex re ("\\s+");
std::string b;
std::regex_replace(std::back_inserter(b),a.begin(),a.end(),re," ");

std::string c;
c = std::regex_replace(a,re," ");
std::cout << b << std::endl;
std::cout << c << std::endl;
*/
/*
if(std::regex_match("www.website.com",std::regex("(www.).*")))
    std::cout << "regex found in string 1" << std::endl;

std::string s = "something123";
std::regex reg(".*123");
if(std::regex_match(s,reg))
    std::cout << "regex found in string 2" << std::endl;

if(std::regex_match(s.begin(),s.end(),reg))
    std::cout << "regex found in string 3";
*/
/*
std::regex r ("\\bwww.*com\\b");


std::smatch sm;
std::string st = ",awjdikajwiwww.dorime,awww.website.comiwdujiauwww.awd";
std::string st1 = "www.website.com";
std::regex pattern("www.*com");


std::regex_match(st,sm,r);
std::regex_search(st,sm,r);
for(int i = 0; i<sm.size();i++)
    std::cout << "["<< sm[i] << "] "; 
*/
/*
    // Iterator do przeszukiwania tekstu
std::string text = "www.website.com ,awjdikajwi www.dorime.com ,aiwdujiauwww.awd";
std::sregex_iterator iter(text.begin(), text.end(), pattern);
std::sregex_iterator end;

// Przeszukiwanie i wypisywanie dopasowanych linków
while (iter != end) {
    std::cout << iter->str() << std::endl;
    ++iter;
}
*/

/*
std::vector<std::string> v = {"www.website.com", "abc","www.google.com", "www.abc.com" };
std::vector<std::string> results;
std::string temp;
std::vector<std::string>::iterator i;

int size = v.size();
for(int i = 0 ; i <size ; i++){
    temp = v.back();
    v.pop_back();
    if(std::regex_match(temp,r))
        results.push_back(temp);
}

for(int i = 0; i<=results.size();i++)
    std::cout << results[i] << "\n";
*/
}