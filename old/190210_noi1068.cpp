#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> img(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            img[i].push_back(x);
        }
    }
    string str;
    cin >> str;
    for (int x = 0; x < str.length(); ++x) {
        vector<vector<int>> newImg;
        int t;
        switch (str[x]) {
            case 'A':
                newImg.resize(n);
                for (int i = 0; i < n; ++i) {
                    for (int j = m - 1; j >= 0; --j) {
                        newImg[i].push_back(img[j][i]);
                    }
                }
                t = m;
                m = n;
                n = t;
            break;
            case 'B':
                newImg.resize(n);
                for (int i = n - 1; i >= 0; --i) {
                    for (int j = 0; j < m; ++j) {
                        newImg[n-i-1].push_back(img[j][i]);
                    }
                }
                t = m;
                m = n;
                n = t;
            break;
            case 'C':
                newImg.resize(m);
                for (int i = 0; i < m; ++i) {
                    for (int j = n - 1; j >= 0; --j) {
                        newImg[i].push_back(img[i][j]);
                    }
                }
            break;
            case 'D':
                newImg.resize(m);
                for (int i = m - 1; i >= 0; --i) {
                    for (int j = 0; j < n; ++j) {
                        newImg[m-i-1].push_back(img[i][j]);
                    }
                }
                break;
        }
        img = newImg;
    }

    for (int i = 0, j; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}