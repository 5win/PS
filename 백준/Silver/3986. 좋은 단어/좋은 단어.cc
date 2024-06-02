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

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000001;

int n;

bool isGood(string s) {
    stack<char> st;

    for(const auto& c : s) {
        if(!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    return st.empty();
}

int main(void) {
    FASTIO;

    cin >> n;
    int cnt = 0;
    while(n--) {
        string s; cin >> s;
        if(isGood(s)) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}