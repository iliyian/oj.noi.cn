#include <iostream>
#include <cmath>
using namespace std;

int toTen(int num, const int &dec){
    int res = 0, t = 0;
    while(num){
        double which = num % 10;
        res += which * pow(dec,t++);
        num /= 10;
    }
    return res;
}

int get_max(int num){
    int max = -1;
    while(num){
        int mod = num % 10;
        if(mod > max){
            max = mod;
        }
        num /= 10;
    }
    return max;
}

int main(){
    int p, q, r;
    cin >> p >> q >> r;
    int dec = max(get_max(p), max(get_max(q), get_max(r)));

    for (int i = dec+1; i <= 16; ++i){
        if (toTen(p, i) * toTen(q, i) == toTen(r, i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}