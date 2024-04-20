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

int main(void) {
    FASTIO;

    int n;
    string name, state;

    cin >> n;
    map<string, bool> logs;
    while(n--) {
        cin >> name >> state;
        if(state == "enter") {
            logs[name] = true;
        } else {
            logs.erase(name);
        }
    }

    vector<string> ans;
    for(auto& i : logs)
        ans.push_back(i.first);
    sort(ans.begin(), ans.end(), greater<>());
    for(auto& i : ans)
        cout << i << '\n';
    
    return 0;
}