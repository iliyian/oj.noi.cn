#include <iostream>
#include <sstream>

int main(){
    std::string num;
    char ch;
    int sum = 0, next;
    std::stringstream ss;

    while(std::cin.get(ch)){
        if(ch == '+' || ch == '\n'){
            ss.clear();
            ss.str("");
            ss << num;
            ss >> next;
            sum += next;
            num = "";
            if(ch == '\n'){
                break;
            }
        }else{
            num = num + ch;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}