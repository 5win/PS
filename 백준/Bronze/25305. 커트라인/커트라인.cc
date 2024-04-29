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

const int INF = 1987654321;
const int MOD = 1000000007;


int main(void) {
    FASTIO;

    int n, k;
    int arr[1001] = {0, };
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<>());
    cout << arr[k - 1] << '\n';

    return 0;
}