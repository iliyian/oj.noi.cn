#include <iostream>
using namespace std;

void merge_sort(int *A, int x, int y, int *T) {
    if (y - x > 1) {
        int m = x + (y - x) / 2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while (p < m || q < y) {
            if (q >= y || (p < m && A[p] <= A[q]))
                T[i++] = A[p++];
            else
                T[i++] = A[q++];
        }
        for (int i = x; i < y; ++i)
            A[i] = T[i];
    }
}

int main() {
    int n;
    cin >> n;
    int *s = new int[n], *t = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    merge_sort(s, 0, n, t);
    for (int i = 0; i < n; ++i)
        cout << s[i] << " ";
    return 0;
}