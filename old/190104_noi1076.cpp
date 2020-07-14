#include <iostream>
#include <map>
#include <sstream>
using namespace std;

stringstream ss;
map<int,string> elems = {
    {10, "A"},
    {11, "B"},
    {12, "C"},
    {13, "D"},
    {14, "E"},
    {15, "F"},
};

int main(){
    int X, M;
    string res;
    cin >> X >> M;
    while(X){
        int next = X % M;
        if(next >= 10){
            res = elems[next] + res;
        }else{
            string snext;
            ss.clear();
            ss.str("");
            ss << next;
            snext = ss.str();
            res = snext + res;
        }
        X /= M;
    }
    cout << res;
    return 0;
}