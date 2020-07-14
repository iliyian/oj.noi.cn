#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int **scores = new int*[n];
    int **rules = new int*[m];

    for (int i = 0; i < n; ++i) {
        scores[i] = new int[5];
        for (int j = 0; j < 5; ++j) {
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        rules[i] = new int[6];
        for (int j = 0; j < 5; ++j) {
            cin >> rules[i][j];
        }
        cin >> rules[i][5];
    }

    for (int i = 0; i < m; ++i) {
        int *student = scores[rules[i][5] - 1];
        int mark = 0;
        for (int j = 0; j < 5; ++j) {
            mark += student[j] * rules[i][j];
        }
        cout << mark << " ";
    }

    return 0;
}