#include <iostream>
using namespace std;

int main(){
    char ch;
    string word(100, '1'), x;
    do{
        cin.get(ch);
        if(ch != ' '){
            x = x + ch;
        }else{
            if(x.length() < word.length()){
                word = x;
            }
            x = "";
        }
    }while(ch != '.');
    if(x.length() < word.length())
        word = x.substr(0,x.length()-1);
    cout << word;
    return 0;
}