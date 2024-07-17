#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int a, b;
int A[500001];
int B[500001];

int main(void) {
    FASTIO;

    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> B[i];
    }

    sort(A, A + a);
    sort(B, B + b);

    vector<int> res;
    for(int i = 0; i < a; i++) {
        if(!binary_search(B, B + b, A[i])) {
            res.push_back(A[i]);
        }
    }
    cout << res.size() << '\n';
    for(auto& i : res) {
        cout << i << ' ';
    }

    
    return 0;
}