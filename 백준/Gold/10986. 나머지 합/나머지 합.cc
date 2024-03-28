#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
int arr[1000001];
long long psum[1000001];
long long modCnt[1001];

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++)
        psum[i] = (psum[i - 1] + arr[i]) % m;
    
    for(int i = 0; i <= n; i++)
        modCnt[psum[i]]++;

    long long res = 0;
    for(int i = 0; i < m; i++) {
        if(modCnt[i] >= 2) {
            res += (modCnt[i] * (modCnt[i] - 1)) / 2;
        }
    }
    cout << res << endl;

    return 0;
}