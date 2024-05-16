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

int n, x;
int arr[250001];

int main(void) {
    FASTIO;

    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int maxVisit = 0;
    int cnt = 0;
    for(int i = 0; i <= n - x; i++) {
        int visit = arr[i + x] - arr[i];
        if(visit == maxVisit) {
            cnt++;
        }
        if(visit > maxVisit) {
            maxVisit = visit;
            cnt = 1;
        }
    }
    if(maxVisit == 0)
        cout << "SAD\n";
    else 
        cout << maxVisit << '\n' << cnt << '\n';

    return 0;
}