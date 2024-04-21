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

string s;
map<string, bool> m;

void dfs(int cur, string& sub) {
    if(cur == s.size()) return;

    sub.push_back(s[cur]);
    m[sub] = true;
    dfs(cur + 1, sub);
    sub.pop_back();
}

int main(void) {
    FASTIO;

    cin >> s;
    string subString;
    for(int i = 0; i < s.size(); i++)
        dfs(i, subString);
    cout << m.size() << '\n';
    
    return 0;
}