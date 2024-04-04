#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
int A[500001];
long long psum[500001];
vector<pair<int, int>> arr;

void solve() {

    int cnt = 1;
    int prev = arr[0].first;
    long long maxSum = 0, minSum = 0;
    for(int i = 1; i < arr.size(); i++) {
        int next = arr[i].first;
        if(prev != next) {
            minSum += (next - prev) * psum[cnt];
            maxSum += (next - prev) * (psum[n] - psum[n - cnt]);
        }
        cnt += arr[i].second;
        prev = next;
    }
    cout << minSum << ' ' << maxSum << '\n';
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++) {
        int s, e;   cin >> s >> e;
        arr.push_back({s, 1});
        arr.push_back({e + 1, -1});
    } 
    sort(arr.begin(), arr.end());
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + A[i];

    solve();

    return 0;
}   