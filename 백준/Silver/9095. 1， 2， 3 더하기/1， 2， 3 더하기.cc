#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int cache[20];

int dfs(int curNum) {

    if(curNum < 0) return 0;
    else if(curNum == 0) return 1;

    int &ret = cache[curNum];
    if(ret != -1)
        return ret;

    int cnt = 0;
    cnt += dfs(curNum - 1);
    cnt += dfs(curNum - 2);
    cnt += dfs(curNum - 3);

    return ret = cnt;
}

int main(void) {

    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        cout << dfs(n) << endl;
    }

    return 0;
}