#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
int arr[1001][1001];
int visited[1001][1001];
pair<int, int> start;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int y = cur.first, x = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || visited[ny][nx] || arr[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                start = {i, j};
        }
    }
    bfs();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0)
                cout << "0 ";
            else if(!visited[i][j])
                cout << "-1 ";
            else
                cout << visited[i][j] - 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}