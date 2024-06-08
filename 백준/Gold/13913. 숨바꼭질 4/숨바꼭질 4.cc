#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n, k;
vector<int> trace(100001);
// int trace[100001]
vector<int> dist(100001, -1);

bool inRange(int x) {
    return 0 <= x && x <= 100000;
}

void bfs() {
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : {cur - 1, cur + 1, cur * 2}) {
            if(!inRange(next) || dist[next] != -1) continue;

            dist[next] = dist[cur] + 1;
            trace[next] = cur;
            q.push(next);
        }
    }
}

int main(void) {
    FASTIO;

    iota(trace.begin(), trace.end(), 0);

    cin >> n >> k;
    bfs();
    cout << dist[k] << '\n';

    stack<int> st;

    int idx = k;
    st.push(idx);
    while(trace[idx] != idx) {
        st.push(trace[idx]);
        idx = trace[idx];
    }
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}