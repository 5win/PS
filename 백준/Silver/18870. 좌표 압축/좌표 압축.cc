#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n;
vector<int> arr, res;
map<int, int> m;

int main(void) {
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    res = arr;

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    
    for(int i = 0; i < res.size(); i++) {
        auto it = lower_bound(arr.begin(), arr.end(), res[i]);
        cout << it - arr.begin() << ' ';
    }
    cout << '\n';

    return 0;
}