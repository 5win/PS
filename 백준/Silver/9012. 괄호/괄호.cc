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
    
    stack<char> st;
    int t; cin >> t;
    string s;
    while(t--) {
        while(!st.empty()) st.pop();
        cin >> s;

        bool no = false;
        for(auto& c : s) {
            if(c == '(') {
                st.push('(');
            } else {
                if(st.empty() || st.top() != '(') {
                    no = true;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if(no || !st.empty()) 
            cout << "NO\n";
        else                   
            cout << "YES\n";
    }

    return 0;
}