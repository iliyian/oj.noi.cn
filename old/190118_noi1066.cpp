#include <iostream>
using namespace std;

bool check(int n){
    for (int i = 2; i * i <= n;++i){
        if(!(n%i)){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    bool got = false;
    cin >> n;
    for(int i = 2; i < n - 1;++i){
        if(check(i) && check(i+2)){
            cout << i << " " << i + 2 << endl;
            got = true;
        }
    }
    if(!got)cout << "empty";
    return 0;
}