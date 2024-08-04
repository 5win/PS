#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int res = 1987654321;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int calcMin() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!board2[i][j]) cnt++;
        }
    }
    return cnt;
}

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void see(int cNum, int val, int dir) {
    int y = cctv[cNum].first, x = cctv[cNum].second;
    
    board2[y][x] += val;
    int ny = y, nx = x;
    while(1) {
        ny = ny + dy[dir];
        nx = nx + dx[dir];
        if(!inRange(ny, nx) || board1[ny][nx] == 6) break;
        board2[ny][nx] += val;
    }
}

void dfs(int num) {

    if(num == cctv.size()) {
        res = min(res, calcMin());
        return;
    }
    int cctvNum = board1[cctv[num].first][cctv[num].second];

    if(cctvNum == 1) {
        for(int dir = 0; dir < 4; dir++) {
            see(num, 1, dir);
            dfs(num + 1);
            see(num, -1, dir);
        }
    }
    else if(cctvNum == 2) {
        for(int dir = 0; dir < 2; dir++) {
            see(num, 1, dir);
            see(num, 1, dir + 2);
            dfs(num + 1);
            see(num, -1, dir);
            see(num, -1, dir + 2);
        }
    }
    else if(cctvNum == 3) {
        for(int dir = 0; dir < 4; dir++) {
            see(num, 1, dir);
            see(num, 1, (dir + 1) % 4);
            dfs(num + 1);
            see(num, -1, dir);
            see(num, -1, (dir + 1) % 4);
        }
    }
    else if(cctvNum == 4) {
        for(int dir = 0; dir < 4; dir++) {
            see(num, 1, dir);
            see(num, 1, (dir + 1) % 4);
            see(num, 1, (dir + 2) % 4);
            dfs(num + 1);
            see(num, -1, dir);
            see(num, -1, (dir + 1) % 4);
            see(num, -1, (dir + 2) % 4);
        }
    }
    else if(cctvNum == 5) {
        for(int dir = 0; dir < 4; dir++)
            see(num, 1, dir);
        dfs(num + 1);
        for(int dir = 0; dir < 4; dir++)
            see(num, -1, dir);
    }
}

int main(void) {

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(0 < board1[i][j] && board1[i][j] < 6) {
                cctv.push_back({i, j});
            }
            else if(board1[i][j] == 6)
                board2[i][j]++;
        }
    }
    dfs(0);
    cout << res << endl;

    return 0;
}