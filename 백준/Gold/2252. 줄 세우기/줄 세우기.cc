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
#include<map>

using namespace std;
const int INF = 1987654321;
const int MAX = 100001;
const int _MOD = 1000000007;

int c, n, m;
vector<int> adj[32001];
vector<int> ret;
bool visited[32001];
int indgree[32001];

void topologySort() {
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] && indgree[i] == 0)
            q.push(i);
    }
    if(q.empty())
            return;


    for(int i = 1; i <= n; i++) {
        int x = q.front();
        q.pop();

        ret.push_back(x);
        for(int j = 0; j < adj[x].size(); j++) {
            if(visited[adj[x][j]]) {
                if(--indgree[adj[x][j]] == 0)
                    q.push(adj[x][j]);
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        visited[i] = true;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a != b) {
            adj[a].push_back(b);
            indgree[b]++;
        }
    }

    topologySort();
    for(int i = 0; i < ret.size(); i++) 
        cout << ret[i] << ' ';
    cout << endl;

    return 0;
}