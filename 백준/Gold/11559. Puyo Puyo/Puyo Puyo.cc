#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
const int INF = 1987654321;

int n = 12, m = 6;
vector<string> board;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void fallDown() {
    vector<string> tmp(n);
    for(int i = 0; i < n; i++)
        tmp[i] = "......";
    
    for(int c = 0; c < m; c++) {
        int idx = n - 1;
        int tIdx = n - 1;
        while(idx >= 0) {
            if(board[idx][c] != '.') {
                tmp[tIdx][c] = board[idx][c];
                tIdx--;
            }
            idx--;
        }
    }
    for(int i = 0; i < n; i++)
        board[i] = tmp[i];
}

void bomb(vector<pair<int, int>> lst) {
    for(int i = 0; i < lst.size(); i++) {
        board[lst[i].first][lst[i].second] = '.';
    }
}

bool canBomb() {
    bool isBombed = false;

    queue<pair<int, int>> q;
    bool visited[12][12] = {0, };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.' || visited[i][j]) continue;
            vector<pair<int, int>> bombList;
            q.push({i, j});
            visited[i][j] = true;
            bombList.push_back({i, j});

            int cnt = 1;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                int y = cur.first, x = cur.second;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(!inRange(ny, nx) || board[ny][nx] != board[y][x] || visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    cnt++;
                    bombList.push_back({ny, nx});
                    q.push({ny, nx});
                }
            }
            if(cnt >= 4) {
                isBombed = true;
                bomb(bombList);
            }
        }
    }
    return isBombed;
}

int main(void) {

    for(int i = 0; i < n; i++) {
        string line; cin >> line;
        board.push_back(line);
    }

    int combo = 0;
    while(canBomb()) {
        combo++;
        fallDown();
    }
    cout << combo << endl;

    return 0;
}