#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct State {
    int cnt = 0;
    pair<int, int> red, blue;
};

int n, m;
string board[11];
State initState;
bool visited[11][11][11][11];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void redMove(int dir, State& state) {
    int ny = state.red.first, nx = state.red.second;
    while(true) {
        ny += dy[dir];
        nx += dx[dir];

        if(board[ny][nx] == '#') {
            ny -= dy[dir];
            nx -= dx[dir];
            break;
        }
        if(board[ny][nx] == 'O') 
            break;
    } 
    state.red = {ny, nx};
}

void blueMove(int dir, State& state) {
    int ny = state.blue.first, nx = state.blue.second;
    while(true) {
        ny += dy[dir];
        nx += dx[dir];

        if(board[ny][nx] == '#') {
            ny -= dy[dir];
            nx -= dx[dir];
            break;
        }
        if(board[ny][nx] == 'O') 
            break;
    } 
    state.blue = {ny, nx};
}

int bfs() {
    queue<State> q;
    q.push(initState);
    visited[initState.red.first][initState.red.second][initState.blue.first][initState.blue.second] = true;


    while(!q.empty()) {
        State cur = q.front();
        q.pop();

        // 빠졌는지 확인
        if(board[cur.red.first][cur.red.second] == 'O') {
            return cur.cnt;
        }

        if(cur.cnt == 10) continue;

        for(int dir = 0; dir < 4; dir++) {
            State nextState = cur;
            redMove(dir, nextState);
            blueMove(dir, nextState);
            nextState.cnt++;

            int& ry = nextState.red.first;
            int& rx = nextState.red.second;
            int& by = nextState.blue.first;
            int& bx = nextState.blue.second;

            if(board[by][bx] == 'O') continue;

            // 순서 조정
            if(ry == by && rx == bx) {
                int distRed = abs(ry - cur.red.first) + abs(rx - cur.red.second);
                int distBlue = abs(by - cur.blue.first) + abs(bx - cur.blue.second);
                if(distRed > distBlue) {
                    ry -= dy[dir];
                    rx -= dx[dir];
                } else {
                    by -= dy[dir];
                    bx -= dx[dir];
                }
            }
            
            if(visited[ry][rx][by][bx]) continue;
            visited[ry][rx][by][bx] = true;
            q.push(nextState);
        }
    }
    return -1;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R')
                initState.red = {i, j};
            else if(board[i][j] == 'B')
                initState.blue = {i, j};
        }
    }
    cout << bfs() << '\n';


    return 0;
}