#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, m, block;
    cin >> n >> m;
    int **pic1 = new int*[m];
    int **pic2 = new int*[m];
    for (int i = 0; i < m;++i){
        pic1[i] = new int[n];
        pic2[i] = new int[n];
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n;++j){
            cin >> block;
            pic1[i][j] = block;
        }
    }
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n;++j){
            cin >> block;
            pic2[i][j] = block;
        }
    }


    double t = 0.0;

    for (int i = 0; i < m;++i)
        for (int j = 0; j < n;++j)
            if(pic1[i][j] == pic2[i][j])
                ++t;

    cout << fixed << setprecision(2) << t / n / m * 100 << endl;
    return 0;
}