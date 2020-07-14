#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int elems[n][m];

    for(int x=0;x<n;++x)
        for(int y=0;y<m;++y)
            cin >> elems[x][y];
    for(int y=0;y<m;++y){
        for(int x=n-1;x>=0;--x)
            cout << elems[x][y] << " ";
        cout << endl;
    }

    return 0;
}