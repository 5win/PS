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

int main(void) {
    FASTIO;
    
    stack<int> st;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        switch(input) {
            case 1:
                int x; cin >> x;
                st.push(x);
                break;
            case 2:
                if(st.empty())
                    cout << "-1\n";
                else {
                    cout << st.top() << '\n';
                    st.pop();
                } 
                break;
            case 3:
                cout << st.size() << '\n';
                break;
            case 4:
                if(st.empty())
                    cout << "1\n";
                else
                    cout << "0\n";
                break;
            case 5:
                if(st.empty())
                    cout << "-1\n";
                else
                    cout << st.top() << '\n';
                break;
        }
    }

    return 0;
}