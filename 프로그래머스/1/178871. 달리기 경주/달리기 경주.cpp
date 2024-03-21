#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
  	map<string, int> uIdx;
    for(int i = 0; i < players.size(); i++) {
        uIdx[players[i]] = i;
    }
   	 
    string tmp;
    for(int i = 0; i < callings.size(); i++) {
        int cur = uIdx[callings[i]];
        
        tmp = players[cur];
        players[cur] = players[cur - 1];
        players[cur - 1] = tmp;
        
        uIdx[players[cur]] = cur;
        uIdx[players[cur - 1]] = cur - 1;
    }
    
    return players;
}