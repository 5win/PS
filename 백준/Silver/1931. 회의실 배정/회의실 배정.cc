#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;


int main(void) {

    int n;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    pair<int, int> prev = v[0];
    for(int i = 1; i < v.size(); i++) {
        pair<int, int> cur = v[i];
        if(cur.second <= prev.second) {
            if(prev.second == cur.first)
                cnt++;
            prev = cur;
        }
        else if(cur.first >= prev.second) {
            prev = cur;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}