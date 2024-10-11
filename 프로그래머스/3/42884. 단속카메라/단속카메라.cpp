#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
struct Route{
    int start, end;
    bool operator<(Route other) const{
        return start<other.start;
    }
};
Route makeRoute(int start, int end){
    Route route;
    route.start=start;
    route.end=end;
    return route;
}
int solution(vector<vector<int>> routes) {
    vector<Route> inputs;
    for(int i=0;i<routes.size();i++){
        Route route=makeRoute(routes[i][0], routes[i][1]);
        inputs.push_back(route);
    }
    sort(inputs.begin(), inputs.end());
    int lastCamera=-30001;
    int answer=0;
    for(int i=0;i<inputs.size();i++){
        int nowStart=inputs[i].start;
        int nowEnd=inputs[i].end;
        if(nowStart<=lastCamera) {
            if(nowEnd<=lastCamera) lastCamera=nowEnd;
            continue;
        }
        else{
            lastCamera=nowEnd;
            answer++;
        }
    }
    return answer;
}