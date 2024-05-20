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
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n;
int nums[15];
int op[5];

int minVal = INF, maxVal = -INF;
vector<int> seq;

void calcMinMax() {
    int res = nums[0];
    for(int i = 1; i < n; i++) {
        switch(seq[i - 1]) {
            case 0:
                res += nums[i];
                break;
            case 1:
                res -= nums[i];
                break;
            case 2:
                res *= nums[i];
                break;
            case 3:
                res /= nums[i];
                break;
        }
    }
    minVal = min(minVal, res);
    maxVal = max(maxVal, res);
}

void dfs(int curCnt) {
    if(curCnt == n - 1) {
        calcMinMax(); 
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(op[i] > 0) {
            op[i]--;
            seq.push_back(i);
            dfs(curCnt + 1);
            seq.pop_back();
            op[i]++;
        }
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    dfs(0);
    cout << maxVal << '\n' << minVal << '\n';

    return 0;
}