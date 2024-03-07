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
int r, c;
string arr[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> start;
vector< pair<int, int> > fire;

bool solve() {
    queue< pair<int, int> > q1;
    for(int i = 0; i < fire.size(); i++) {
        q1.push(fire[i]);
        dist1[fire[i].first][fire[i].second] = 0;
    }
    
    while(!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(dist1[ny][nx] >= 0 || arr[ny][nx] == '#') continue;
            dist1[ny][nx] = dist1[cur.first][cur.second] + 1;
            q1.push({ny, nx});
        }
    }

    queue< pair<int, int> > q2;
    q2.push(start);
    dist2[start.first][start.second] = 0;
    while(!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) {
                cout << dist2[cur.first][cur.second] + 1 << endl;
                return true;
            }
            if(dist2[ny][nx] >= 0 || arr[ny][nx] == '#') continue;
            if(dist1[ny][nx] != -1 && dist2[cur.first][cur.second] + 1 >= dist1[ny][nx]) continue;
            dist2[ny][nx] = dist2[cur.first][cur.second] + 1;
            q2.push({ny, nx});
        }
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        arr[i] = temp;
        for(int j = 0; j < temp.length(); j++) {
            if(temp[j] == 'J')
                start = {i, j};
            if(temp[j] == 'F')
                fire.push_back({i, j});
        }
    }
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
 

    if(!solve()) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}