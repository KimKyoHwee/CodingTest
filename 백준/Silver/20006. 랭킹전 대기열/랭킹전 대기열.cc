#include <iostream>
#include <vector>
#include <algorithm>
int P, M;
using namespace std;

struct Player{
    string id;
    int level;
};
struct Room{
    int level;
    vector<Player> players;
};
bool cmp(Player a, Player b){
    return a.id<b.id;
}
vector<Room> rooms;

int main(){
    cin>>P>>M;
    while(P--){
        int L;
        string N;
        cin>>L>>N;
        Player player;
        player.id=N;
        player.level=L;
        bool flag=true;
        for(int i=0;i<rooms.size();i++){
            if((rooms[i].level-10)<=L&&(rooms[i].level+10)>=L&&rooms[i].players.size()<M) {
                flag=false;
                rooms[i].players.push_back(player);
                break;
            }
        }
        if(flag){
            Room room;
            room.level=L;
            room.players.push_back(player);
            rooms.push_back(room);
        }
    }
    for(int i=0;i<rooms.size();i++){
        if(rooms[i].players.size()==M) cout<<"Started!\n";
        else cout<<"Waiting!\n";
        sort(rooms[i].players.begin(), rooms[i].players.end(), cmp);
        for(int j=0;j<rooms[i].players.size();j++){
            cout<<rooms[i].players[j].level<<" "<<rooms[i].players[j].id<<"\n";
        }
    }
    return 0;
}