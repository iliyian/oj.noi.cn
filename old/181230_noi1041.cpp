#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
    int k;
    int s;
};

bool sort_score(const Player *, const Player *);
void print_sth(const Player *, const Player *);

vector<Player*>players;

int main(){
    int n, m, k, s;
    cin >> n >> m;
    for (int i = 0; i < n;++i){
        cin >> k >> s;
        Player *newone = new Player{k,s};
        players.push_back(newone);
    }
    sort(players.begin(), players.end(), sort_score);
    int passn = m * 1.5;
    int passs = players[passn-1]->s;

    vector<Player *>::iterator from;
    for (auto it : players){
        if(it->s < passs){
            players.erase(it, players.end());
            break;
        }
    }

    cout
        << players[players.size() - 1]->s << " " << players.size() << endl;

    for(auto &x : players){
        cout << x->k << " " << x->s << endl;
    }
    for(auto &x : players){
        delete [] x;
        x = NULL;
    }
    return 0;
}

bool sort_score(const Player* A, const Player* B){
    if(A->s > B->s){
        return true;
    }else if(A->s == B->s && A->k < B->k){
        return true;
    }else{
        return false;
    }
}

void print_sth(const Player* A){
    cout << A->k << " " << A->s << " " << endl;
}