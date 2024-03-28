#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, k;
int arr[100001];

int main(void) {
    FASTIO;

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int s = 0, e = k;
    int sum = 0;
    for(int i = 0; i < e; i++)
        sum += arr[i];
    
    int res = sum;
    while(e < n) {
        sum = sum - arr[s] + arr[e];
        res = max(res, sum);
        s++; e++;
    }
    cout << res << endl;

    return 0;
}