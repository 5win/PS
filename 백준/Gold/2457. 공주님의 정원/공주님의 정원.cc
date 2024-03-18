#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) return true;
    else if(a.first == b.first) {
        if(a.second > b.second) return true;
    }
    return false;
}

int main(void) {

    int n;
    vector<pair<int, int>> flowers;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        flowers.push_back({s1 * 100 + s2, e1 * 100 + e2});
    }

    sort(flowers.begin(), flowers.end());

    // pair<int, int> prev = make_pair(0101, 0301);

    // 0301 이전에 피는 꽃들 중, 가장 늦게 피는 꽃
    int firstIdx = 0;
    int firstMax = -1;
    bool cantStart = true;
    for(int i = 0; i < n; i++) {
        if(flowers[i].first <= 301 && firstMax < flowers[i].second) {
            firstIdx = i;
            firstMax = flowers[i].second;
            cantStart = false;
        }
    }    

    if(cantStart) {
        cout << "0\n";
        return 0;
    }

    int cnt = 1;
    int cur = firstIdx;
    while(1) {

        if(flowers[cur].second > 1130) break;

        pair<int, int> nextF = make_pair(-1, -1);
        int nextIdx = -1;
        for(int i = cur + 1; i < flowers.size(); i++) {
            if(flowers[cur].second >= flowers[i].first) {
                if(flowers[i].second > nextF.second) {
                    nextF = flowers[i];
                    nextIdx = i;
                }
            }
        }

        if(nextIdx == -1) {
            cout << "0\n";
            return 0;
        }
        cnt++;
        cur = nextIdx;

    }

    cout << cnt << endl;

   
    return 0;
}