#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person {
    string gender;
    double height;
};

bool sort_males(const Person & A, const Person & B){
    if(A.height < B.height){
        return true;
    }else{
        return false;
    }
}

bool sort_females(const Person & A, const Person & B){
    if(A.height > B.height){
        return true;
    }else{
        return false;
    }
}

void _print(const Person & one){
    cout << fixed << setprecision(2) << one.height << " ";
}

vector<Person> males;
vector<Person> females;
int main(){
    int n;
    string gender;
    double height;

    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> gender;
        cin >> height;
        Person newone = Person{gender, height};
        if(gender == "male"){
            males.push_back(newone);
        }else{
            females.push_back(newone);
        }
    }
    sort(males.begin(), males.end(), sort_males);
    sort(females.begin(), females.end(), sort_females);
    for_each(males.begin(), males.end(), _print);
    for_each(females.begin(), females.end(), _print);
    return 0;
}