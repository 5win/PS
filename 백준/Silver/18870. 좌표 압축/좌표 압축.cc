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
vector<int> X;

int main(void) {
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        X.push_back(tmp);
    }
    vector<int> sortedX(X);
    
    // copy(X.begin(), X.end(), back_inserter(sortedX));
    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());

    for(int i = 0; i < n; i++) {
        cout << lower_bound(sortedX.begin(), sortedX.end(), X[i]) - sortedX.begin() << '\n';
    }


    return 0;
}