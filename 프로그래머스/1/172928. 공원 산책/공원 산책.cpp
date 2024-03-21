#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> getDir = {{'E', 0}, {'S', 1}, {'W', 2}, {'N', 3}};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int n, int m, int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int n = park.size(), m = park[0].size();
    int y, x;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(park[i][j] == 'S') {
            	y = i;
                x = j;
                break;
            }
        }
    }
    
    for(int i = 0; i < routes.size(); i++) {
        int dir = getDir[routes[i][0]];
        int dist = routes[i][2] - '0';
        
        int ny = y, nx = x;
        bool canGo = true;
        //while(dist--) {
        for(int j = 0; j < dist; j++) {
            ny += dy[dir];
            nx += dx[dir];
            if(!inRange(n, m, ny, nx) || park[ny][nx] == 'X') {
               	canGo = false;
                break;
            }
        }
        if(canGo) {
            y = ny;
            x = nx;
        }
    }
   	answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}