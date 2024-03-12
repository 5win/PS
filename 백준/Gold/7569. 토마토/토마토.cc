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
int m;
int h;
int arr[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Point{
    int y;
    int x;
    int z;
};
queue<Point> q;

// q.empty이면서 false반환이면 -1출력
bool isEnd() {
    for(int i = 0; i < n * h; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i % n][j][i / n] == 0)
                return false;
        }
    }
    return true;
}
int _max() {
    int ret = 0;
    for(int i = 0; i < n * h; i++)
        for(int j = 0; j < m; j++) 
            ret = max(ret, arr[i % n][j][i / n]);
    return ret;
}

void solve() {
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();

        for(int i = 0; i < 6; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nz = cur.z + dz[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h) continue;
            if(arr[ny][nx][nz] != 0) continue;
            
            q.push(Point{ny, nx, nz});
            arr[ny][nx][nz] = arr[cur.y][cur.x][cur.z] + 1;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;
    for(int i = 0; i < n * h; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i % n][j][i / n];
            if(arr[i % n][j][i / n] == 1) {
                q.push(Point{i % n, j, i / n});
            }
        }
    }
    solve();
    if(isEnd()) 
        cout << _max() - 1 << endl;
    else
        cout << -1 << endl;

    return 0;
}