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
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
pair<int, int> start;
pair<int, int> target;
int board[301][301];

int solve() {
    queue< pair<int, int> > q;
    q.push(start);

    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        if(here == target)
            return board[here.first][here.second];
        for(int i = 0; i < 8; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(board[ny][nx] != 0) continue;
            q.push({ny, nx});
            board[ny][nx] = board[here.first][here.second] + 1;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cin >> start.first >> start.second;
        cin >> target.first >> target.second;
        for(int i = 0; i < n; i++) 
            memset(board[i], 0, sizeof(board[i]));
        cout << solve() << endl;
    }

    return 0;
}