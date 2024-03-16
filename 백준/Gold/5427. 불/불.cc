#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int w, h;
string board[1001];
pair<int ,int> start;
vector< pair<int, int> > fire;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int dist[1001][1001];
int dist2[1001][1001];

int bfs() {
    queue< pair<int, int> > q;
    for(int i = 0; i < fire.size(); i++) {
        q.push(fire[i]);
        //dist[fire[i].first][fire[i].second] = 0;
    }
    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(dist[ny][nx] != 0 || board[ny][nx] == '#' || board[ny][nx] == '*') continue;
            q.push({ny, nx});
            dist[ny][nx] = dist[here.first][here.second] + 1;
        }
    }
    q.push(start);
    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) 
                return dist2[here.first][here.second] + 1;
            if(dist2[ny][nx] > 0) continue;
            if(board[ny][nx] != '.') continue;
            if(dist[ny][nx] != 0 && dist2[here.first][here.second] + 1 >= dist[ny][nx]) continue;
            q.push({ny, nx});
            dist2[ny][nx] = dist2[here.first][here.second] + 1;
        }
    }
    return -1;
}

void solve() {

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(board[i][j] == '@')
                start = {i, j};
            if(board[i][j] == '*')
                fire.push_back({i, j});
        }
    }
    int ret = bfs();
    if(ret == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ret << endl;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        fire.clear();
        for(int j = 0; j < 1001; j++) {
            memset(dist[j], 0, sizeof(dist[j]));
            memset(dist2[j], 0, sizeof(dist2[j]));
        }
        cin >> w >> h;
        for(int j = 0; j < h; j++) 
            cin >> board[j];
        solve();
    }

    return 0;
}