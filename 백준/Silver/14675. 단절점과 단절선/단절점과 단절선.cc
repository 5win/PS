#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, q;
int degree[100001];

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    cin >> q;
    while(q--) {
        int t, k;
        cin >> t >> k;
        if(t == 1) {
            if(degree[k] > 1)   cout << "yes\n";
            else                cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }

    return 0;
}