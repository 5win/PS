#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9 + 9;
const int MAX = 40001;

int n, k;
int cnt = 0;
bool finish = false;

void dfs(int sum, string expr) {
    if(finish) return;
    if(sum == n) {
        if(++cnt == k) {
            cout << expr << '\n';
            finish = true;
        }
        return;
    } else if(sum > n) {
        return;
    }

    for(int next = 1; next <= 3; next++) {
        dfs(sum + next, expr + "+" + to_string(next));
    }
}

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 1; i <= 3; i++) {
        if(finish) break;
        dfs(i, to_string(i));
    }
    if(!finish)
        cout << -1 << '\n';

    return 0;
}