#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n;
int minVal = 2 * INF + 1;
pair<int, int> res;
int arr[100001];

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s = 0, e = n - 1;
    while(s < e) {
        int val = arr[e] + arr[s];
        if(minVal > abs(val)) {
            minVal = abs(val);
            res = {s, e};
        }
        if(val < 0) {
            s++;
        } else if(val > 0) {
            e--;
        } else {
            break;
        }
    }
    cout << arr[res.first] << ' ' << arr[res.second] << '\n';
    
    return 0;
}