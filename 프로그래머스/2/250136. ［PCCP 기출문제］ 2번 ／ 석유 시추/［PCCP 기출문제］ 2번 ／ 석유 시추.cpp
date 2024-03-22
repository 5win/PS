#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m;
int sum[501];
bool visited[501][501];
vector<vector<int>> board;
map<int, int> colList;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
           if(board[i][j] == 0 || visited[i][j]) continue;
                    
            q.push({i, j});
            visited[i][j] = true;
            int cnt = 1;
            //map<int, int> colList;
            colList.clear();
            colList[j] = j;
            
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                
                int y = cur.first, x = cur.second;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(!inRange(ny, nx) || visited[ny][nx] || !board[ny][nx]) continue;
                    cnt++;
                    visited[ny][nx] = true;
                    if(colList.find(nx) == colList.end())
                        colList[nx] = nx;
                    q.push({ny, nx});
                }
            }
            
            for(auto iter = colList.begin(); iter != colList.end(); iter++) {
                sum[iter->first] += cnt; 
            }
        }
    } 
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    board = land;
    
    bfs();
    
    for(int i = 0; i < m; i++) {
        answer = max(answer, sum[i]);
    }
        
    return answer;
}