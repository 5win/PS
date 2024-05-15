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

int t, n, m;
int arr1[1001], arr2[1001];
vector<int> psum1, psum2;

int main(void) {
    FASTIO;

    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> arr2[i];
    }

    for(int i = 1; i <= n; i++) {
        int sum = arr1[i];
        psum1.push_back(sum);
        for(int j = i + 1; j <= n; j++) {
            sum += arr1[j];
            psum1.push_back(sum);
        }
    }
    for(int i = 1; i <= m; i++) {
        int sum = arr2[i];
        psum2.push_back(sum);
        for(int j = i + 1; j <= m; j++) {
            sum += arr2[j];
            psum2.push_back(sum);
        }
    }

    sort(psum1.begin(), psum1.end());

    long long cnt = 0;
    for(int i = 0; i < psum2.size(); i++) {
        int target = t - psum2[i];
        int lo = lower_bound(psum1.begin(), psum1.end(), target) - psum1.begin();
        int hi = upper_bound(psum1.begin(), psum1.end(), target) - psum1.begin();
        cnt += hi - lo;
    }
    cout << cnt << '\n';

    return 0;
}