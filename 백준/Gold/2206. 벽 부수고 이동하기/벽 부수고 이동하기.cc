#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int dist[1001][1001];
int wDist[1001][1001];
vector<string> board;
vector<pair<int, int>> wall;

queue<pair<int, int>> q;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {

    // wall dist
    q.push({n - 1, m - 1});
    wDist[n - 1][m - 1] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int y = cur.first, x = cur.second;

        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || wDist[ny][nx]) continue;
            wDist[ny][nx] = wDist[y][x] + 1;
            if(board[ny][nx] == '1') continue;
            q.push({ny, nx});
        }
    }


    // dist
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int y = cur.first, x = cur.second;

        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + 1;
            if(board[ny][nx] == '1') continue;

            q.push({ny, nx});
        }
    }

    int originalDist = dist[n - 1][m - 1];
    int minDist = INT_MAX;
    if(minDist == 0) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < wall.size(); i++) {
        int y = wall[i].first, x = wall[i].second;
        if(wDist[y][x] == 0 || dist[y][x] == 0) continue;
        minDist = min(minDist, dist[y][x] - 1 + wDist[y][x]); 
    }

    if(originalDist == 0) {
        if(minDist == INT_MAX)
            cout << "-1\n";
        else
            cout << minDist << endl;
    }
    else 
        cout << min(minDist, originalDist) << endl;
}

int main(void) {

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        board.push_back(tmp);
        for(int j = 0; j < tmp.size(); j++) {
            if(tmp[j] == '1') {
                wall.push_back({i, j});
                // wDist[i][j] = 1;
                // q.push({i, j});
            }
        }
    }

    bfs();

    return 0;
}