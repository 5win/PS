#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int n;
int T[20], P[20];
int res;

void dfs(int curIdx, int sum) {
    
    for(int i = curIdx + T[curIdx]; i < n; i++) {
        if(i + T[i] - 1 < n)
            dfs(i, sum + P[i]);
    }
    res = max(res, sum);
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> T[i] >> P[i];
    }
    for(int i = 0; i < n; i++) {
        if(i + T[i] - 1 < n)
            dfs(i, P[i]);
    }
    cout << res << endl;
    
    return 0;
}