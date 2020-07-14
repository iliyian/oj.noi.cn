#include <iostream>
using namespace std;

long long pow(int x){
    if(x == 0 || x == 1){
        return x;
    }else{
        return x*pow(x-1);
    }
}

int main(){
    long long n, m;
    cin >> n >> m;
    if(n == m || !n || !m)cout << 1;
    else cout << pow(n)/(pow(n-m)*pow(m)) << endl;
    return 0;
}