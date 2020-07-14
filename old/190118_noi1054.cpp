#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool **map = new bool*[n];
    for (int i = 0;i < n;++i){
        bool *line = new bool[m];
        for (int j = 0; j < m;++j){
            char x;
            cin >> x;
            if(x == '*')
                line[j] = true;
            else{
                line[j] = false;
            }
        }
        map[i] = line;
    }
    for (int r = 0; r < n;++r){
        for (int c = 0; c < m;++c){
            int cnt = 0;
            if(map[r][c]){
                cout << "*";
                continue;
            }
            for (int i = -1; i <= 1;++i){
                for (int j = -1; j <= 1;++j){
                    if(!i && !j)continue;
                    if(r + i < 0 || r + i >= n)continue;
                    if(c + j < 0 || c + j >= m)continue;
                    cnt += map[r + i][c + j];
                }
            }
            cout << cnt;
        }
        cout << endl;
    }
    for (int i = 0; i < n;++i){
        delete[] map[i];
        map[i] = NULL;
    }
    delete[] map;
    map = NULL;
    return 0;
}