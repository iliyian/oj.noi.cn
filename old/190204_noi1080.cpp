#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string article;
    map<char, int> chart;
    for (int i = 0; i < 4; ++i) {
        string para;
        getline(cin, para);
        article += para;
    }
    for (int i = 65; i <= 90; ++i) chart[i] = 0;
    for (int i = 0; i < article.length(); ++i) {
        char ch = article[i];
        if (isalpha(ch)) {
            ++chart[ch];
        }
    }
    int x = -100;
    for (int i = 65; i <= 90; ++i) {
        if (chart[i] > x) {
            x = chart[i];
            //idx = i;
        }
    }
    int a = x;
    for (int i = 0; i < a; ++i, --x) {
        for (int i = 65; i <= 90; ++i) {
            if (chart[i] == x) {
                cout << "*";
                --chart[i];
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}