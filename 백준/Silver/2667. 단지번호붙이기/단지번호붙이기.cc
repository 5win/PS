#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
string board[26];
vector<int> res;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

void bfs() {
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '1') {
                int cnt = 0;
                board[i][j] = '0';
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    cnt++;
                    
                    int y = cur.first, x = cur.second;
                    for(int dir = 0; dir < 4; dir++) {
                        int ny = y + dy[dir], nx = x + dx[dir];
                        if(!inRange(ny, nx) || board[ny][nx] == '0') continue;
                        board[ny][nx] = '0';
                        q.push({ny, nx});
                    }
                }
                res.push_back(cnt);
            }
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    bfs();
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto i : res)
        cout << i << '\n';

    return 0;
}