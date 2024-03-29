#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m, k;
int board[1001][1001];
bool visited[1001][1001];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int calcSum() {
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(visited[i][j]) cnt++;
    return cnt;
}

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(int y, int x, int d) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        y = cur.first; x = cur.second;
        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || board[ny][nx] > d || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int canBfs(int d) {

    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        if(board[i][0] <= d && !visited[i][0])
            bfs(i, 0, d);
        if(board[i][m - 1] <= d && !visited[i][m - 1])
            bfs(i, m - 1, d);
    }
    for(int i = 0; i < m; i++) {
        if(board[0][i] <= d && !visited[0][i])
            bfs(0, i, d);
    }

    return calcSum();
}

int binarySearch(int lo, int hi) {

    while(lo < hi) {
        int mid = (lo + hi) / 2;
        int cnt = canBfs(mid);
        
        if(cnt >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << binarySearch(1, 1000001) << '\n';
        
    return 0;
}