#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n;
bool visited[101][101];
string board[101];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int bfs(bool canDiff) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
     
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]) continue;

            q.push({i, j});
            visited[i][j] = true;

            char curColor = board[i][j];
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                int y = cur.first;
                int x = cur.second;
                
                for(int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(!inRange(ny, nx) || visited[ny][nx]) continue;
                    if(canDiff && curColor != board[ny][nx]) continue;
                    else if(!canDiff) {
                        if(curColor != 'B' && board[ny][nx] == 'B') continue;
                        else if(curColor == 'B' && board[ny][nx] != 'B') continue;
                    }

                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
            cnt++;
        }
    }
    return cnt;
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    cout << bfs(true) << ' ' << bfs(false) << endl;


    return 0;
}