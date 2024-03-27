#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>
#include <math.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1987654321;

int n, m;
int board[12][12];
int num = 1;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent(10);

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    bool visited[12][12] = {0, };
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] || board[i][j] == 0) continue;

            q.push({i, j});
            visited[i][j] = true;
            board[i][j] = num;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                int y = cur.first, x = cur.second;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(!inRange(ny, nx) || visited[ny][nx] || board[ny][nx] == 0) continue;
                    visited[ny][nx] = true;
                    board[ny][nx] = num;
                    q.push({ny ,nx});
                }
            }
            num++;
        }
    }
}

void getEdge() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) continue;

            int islandNum = board[i][j];
            for(int dir = 0; dir < 4; dir++) {
                int len = 0;
                int ny = i, nx = j;
                while(true) {
                    ny += dy[dir]; nx += dx[dir];
                    if(!inRange(ny, nx)) break;
                    if(board[ny][nx] == islandNum) break;       // 섬 안 이면
                    else if(board[ny][nx] > 0) {                // 섬 밖이며 물이 아니면
                        if(len > 1) {
                            edges.push_back({len, {islandNum, board[ny][nx]}});
                        }
                        break;
                    }
                    len++;
                }
            }
        }
    }
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < 10; i++)
        parent[i] = i;

    bfs();
    getEdge();
    sort(edges.begin(), edges.end());

    int res = 0;
    for(auto &e : edges) {
        int a = e.second.first, b = e.second.second;
        if(find(a) == find(b)) continue;
        merge(a, b);
        res += e.first;
    }
    
    int u = find(1);
    for(int i = 2; i < num; i++) {
        if(u != find(i)) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << res << endl;

    return 0;
}