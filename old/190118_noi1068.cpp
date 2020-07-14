#include <iostream>
#include <vector>
using namespace std;

void clear(vector<vector<int>> v){
    for(int i=0;i<v.size();++i){
        v[i].clear();
    }
    v.clear();
}

int  main(){
    int m, n, x;
    cin >> m >> n;
    vector<vector<int>> pic(m);
    for (int i = 0; i < m;++i){
        pic[i].resize(n);
        for (int j = 0; j < n;++j){
            cin >> pic[i][j];
        }
    }
    cin.clear();
    cin.ignore();
    char ch;
    bool run = true;
    for (;run;){
        int cnt = 0;
        cin.get(ch);
        switch(ch){
            case 'A':
            vector<vector<int>> x(n);
            for(int c=0;c<n;++c){
                for(int r=m-1;r>=0;--r){
                    x[cnt++/m].push_back(pic[c][r]);
                }
            }
            break;
            case 'B':
            for(int c=n-1;c>=0;--c){
                for(int r=0;r>=0;++r){
                    x[cnt++/m].push_back(pic[c][r]);
                }
            }
            break;
            default:
            run = !run;
        }
        clear(pic);
        pic = x;
        clear(x);
    }
    for(int i=0;i<pic.size();++i){
        for(int j=0;j<pic[i].size();++j){
            cout << pic[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}