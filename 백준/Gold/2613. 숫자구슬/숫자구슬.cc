#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m;
int maxVal;
vector<int> arr;

bool decision(int x) {
    int sum = 0, mCnt = 0;
    int gCnt = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > x) {
            sum = arr[i];
            gCnt++;
        }
        mCnt++; 
    }
    gCnt++;

    return m >= gCnt;
}

int parametricSearch() {
    int lo = maxVal - 1, hi = 30000;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main(void) {
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
        maxVal = max(maxVal, tmp);
    }
    int ans = parametricSearch();
    cout << ans << endl;

    int sum = 0, mCnt = 0, gCnt = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > ans) {
            cout << mCnt << ' ';
            mCnt = 0;
            gCnt++;
            sum = arr[i];
        }
        mCnt++;
        if(n - i == m - gCnt) {
            while(m - gCnt > 0) {
                cout << mCnt << ' ';
                gCnt++;
                mCnt = 1;
            }
            break;
        }
    }


    return 0;
}