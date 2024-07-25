#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m;
vector<int> input[101];

void compress(vector<int>& v) {
    vector<int> compV(v);

    sort(compV.begin(), compV.end());
    compV.erase(unique(compV.begin(), compV.end()), compV.end());

    for(int i = 0; i < v.size(); i++) {
        int idx = lower_bound(compV.begin(), compV.end(), v[i]) - compV.begin();
        v[i] = idx;
    }
}

int main(void) {
    FASTIO;

    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            input[i].push_back(tmp);
        }
    }

    for(int i = 0; i < m; i++) {
        compress(input[i]);
    }

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(input[i] == input[j]) {
                cnt++;
            }
        }
    }    
    cout << cnt << '\n';

    
    return 0;
}