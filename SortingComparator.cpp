#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};
vector<Player> comparator(vector<Player> players) {
    for(int i=0;i<players.size();i++){
        for(int j=i+1;j<players.size();j++){
            if(players[i].score<players[j].score){
                Player temp=players[i];
                players[i]=players[j];
                players[j]=temp;
            }
            else if(players[i].score==players[j].score){
                if(players[i].name>players[j].name){
                    Player temp=players[i];
                    players[i]=players[j];
                    players[j]=temp;
                }
            }
        }
    }
    return players;
}
int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
