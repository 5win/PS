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
int m, k;
bool arr[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solve() {
    int cnt = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j]) {
                cnt++;
                q.push({i, j});
                arr[i][j] = false;
                while(!q.empty()) {
                    pair<int, int> here = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int ny = here.first + dy[k];
                        int nx = here.second + dx[k];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if(!arr[ny][nx]) continue;
                        q.push({ny, nx});
                        arr[ny][nx] = false;
                    }
                }
            }
        }
    }
    return cnt;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        for(int j = 0; j < n; j++) 
            memset(arr[j], 0, sizeof(arr[j]));
        
        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = true;
        }
        cout << solve() << endl;
    }

    return 0;
}