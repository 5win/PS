#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

int n, m;
map<string, int> lst;

int main(void) {
    FASTIO;

    cin >> n >> m;
    string tmp; 
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        lst[tmp] = i;
    }

    vector<string> res;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        if(lst.find(tmp) != lst.end()) {
            res.push_back(tmp);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto i : res)
        cout << i << '\n';

    return 0;
}