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

// const int INF = 1987654321;
const int INF = 1e9;
// const long long INF = 1e13;
const int MOD = 1000000007;
const int MAX = 1000001;

int n;
int arr[MAX], indexMap[MAX];
vector<int> LIS;

int binarySearch(int lo, int hi, int target) {
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(LIS[mid] >= target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    LIS.push_back(arr[1]);
    indexMap[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(arr[i] > LIS.back()) {
            LIS.push_back(arr[i]);
            indexMap[i] = LIS.size() - 1;
        } else {
            int idx = binarySearch(0, LIS.size() - 1, arr[i]);
            LIS[idx] = arr[i];
            indexMap[i] = idx;
        }
    }
    cout << LIS.size() << '\n';

    stack<int> st;
    int idx = LIS.size() - 1;
    for(int i = n; i > 0; i--) {
        if(indexMap[i] == idx) {
            st.push(arr[i]);
            idx--;
        }
    }
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}