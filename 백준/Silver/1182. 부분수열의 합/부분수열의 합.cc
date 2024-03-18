#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, s;
int cnt;
vector<int> v;

void dfs(int len, int sum, int count) {

    if(len == n) {
        if(sum == s && count)
            cnt++;
        return;
    }

    dfs(len + 1, sum + v[len], count + 1);
    dfs(len + 1, sum, count);
}

int main(void) {

    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
   
    dfs(0, 0, 0);

    cout << cnt << endl;

    return 0;
}