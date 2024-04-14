#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
vector<pair<int, int>> arr;

int main(void) {
    FASTIO;

    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    for(auto& i : arr)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}