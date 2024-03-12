#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
vector<int> v;

void dfs(int start, int len) {

    if(len == m) {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i <= n; i++) {
        v.push_back(i);
        dfs(i, len + 1);
        v.pop_back();
    }
}

int main(void) {
    
    cin >> n >> m;

    dfs(1, 0); 

    return 0;
}