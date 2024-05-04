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

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
vector<int> arr;
stack<int> st;

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    int num = 1;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() == num) {
            st.pop();
            num++;
        }
        if(arr[i] == num) {
            num++;
        } else {
            st.push(arr[i]);
        }
    }

    while(!st.empty() && st.top() == num) {
        st.pop();
        num++;
    }

    if(num == n + 1) {
        cout << "Nice\n";
    } else {
        cout << "Sad\n";
    }

    return 0;
}