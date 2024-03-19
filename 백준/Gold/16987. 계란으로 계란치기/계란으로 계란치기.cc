#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int res;
vector<pair<int, int>> egg;

void calcCnt() {
    int brokenCnt = 0;
    for(int i = 0; i < n; i++) {
        if(egg[i].first <= 0)
            brokenCnt++;
    }
    res = max(res, brokenCnt);
}

void dfs(int curIdx) {
    // 이제 집을 계란이 없을 때
    if(curIdx == n) {
        calcCnt();
        return;
    }

    // 현재 계란이 깨져있다. 다음 계란을 선택
    if(egg[curIdx].first <= 0) {
        dfs(curIdx + 1);
        return;
    }

    bool canHit = false;
    for(int i = 0; i < n; i++) {
        if(curIdx == i) continue;
        if(egg[i].first > 0) {
            canHit = true;
            break;
        }
    }
    // 현재 계란으로 칠 수 있는 계란이 없다면
    if(!canHit) {
        calcCnt();
        return;
    }

    for(int i = 0; i < n; i++) {
        if(egg[i].first <= 0 || curIdx == i) continue;

        egg[curIdx].first -= egg[i].second;
        egg[i].first -= egg[curIdx].second;

        dfs(curIdx + 1);
        
        egg[curIdx].first += egg[i].second;
        egg[i].first += egg[curIdx].second;
    }

}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        int hp, w;
        cin >> hp >> w;
        egg.push_back({hp, w});
    }

    dfs(0);

    cout << res << endl;

    return 0;
}