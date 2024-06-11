#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 40001;

int n, m;
bool w[MAX];

int main(void) {
    FASTIO;

    w[0] = true;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        
        stack<int> updateW;
        for(int j = 0; j < MAX; j++) {
            if(w[j]) {
                updateW.push(abs(j - input));
                updateW.push(j + input);
            }
        }
        while(!updateW.empty()) {
            w[updateW.top()] = true;
            updateW.pop();
        }
    }

    cin >> m;
    while(m--) {
        int ball; cin >> ball;
        if(w[ball])
            cout << "Y ";
        else 
            cout << "N ";
    }

    return 0;
}