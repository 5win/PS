#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int a, b;
vector<pair<int, int>> trace(10001);
vector<bool> visited(10001, false);

int rotate(bool isLeft, int num) {
    if(isLeft) {
        return (num * 10) % 10000 + (num / 1000);
    } else {
        return (num / 10) + (num % 10) * 1000;
    }
}

int operD(int num) {
    return (num * 2) % 10000;
}

int operS(int num) {
    return num == 0 ? 9999 : num - 1;
}

void bfs() {
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == b) return;

        int oper = -1;
        for(int next : {operD(cur), operS(cur), rotate(true, cur), rotate(false, cur)}) {
            oper++;
            if(visited[next]) continue;
            visited[next] = true;
            trace[next] = {cur, oper};
            q.push(next);
        }
    }
}


int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        fill(visited.begin(), visited.end(), false);
        generate(trace.begin(), trace.end(), [i = 0]() mutable { return make_pair(i++, 0); });

        cin >> a >> b;
        bfs();

        int idx = b;
        stack<int> st;
        while(trace[idx].first != idx) {
            st.push(trace[idx].second);
            idx = trace[idx].first;
        }
        char op[4] = {'D', 'S', 'L', 'R'};
        while(!st.empty()) {
            cout << op[st.top()];
            st.pop();
        }
        cout << '\n';
    }

    return 0;
}