#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,t=0,num,number;
    cin >> n;
    number=n;
    while(n){
        n/=10;
        t++;
    }
    cout << t <<endl;
    for(int i=1;i<=t;i++){
        int a=number/int(pow(10.0,t-i));
        while(a/10){
            a%=10;
        }
        cout << a << endl;
    }
    return 0;
}