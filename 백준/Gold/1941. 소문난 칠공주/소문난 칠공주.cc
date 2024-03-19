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
int cnt = 0;
string s[5];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool visited[5][5];
bool visit_permu[25];

void BFS() {
    for(int i = 0; i < 5; i++)
        memset(visited[i], 0, sizeof(visited[i]));

    queue< pair<int, int> > q;
    for(int i = 0; i < 25; i++)
        if(visit_permu[i]) {
            q.push({i / 5, i % 5});
            visited[i / 5][i % 5] = true;
            break;
        }
    int count = 1;
    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        if(count == 7) {
            cnt++;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if(!visit_permu[ny * 5 + nx] || visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
            count++;
        }
    }
}

void DFS(int start, int len) {
    if(len == 7) {
        int count = 0;
        for(int i =0; i < 25; i++)
            if(visit_permu[i] && s[i / 5][i % 5] == 'S')
                count++;
        if(count >= 4) {
            BFS();
        }
        return;
    }
    for(int i = start; i < 25; i++) {
        if(!visit_permu[i]) {
            visit_permu[i] = true;
            DFS(i + 1, len + 1);
            visit_permu[i] = false;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    for(int i = 0; i < 5; i++) 
        cin >> s[i];
    DFS(0, 0);
    cout << cnt << endl;

    return 0;
}