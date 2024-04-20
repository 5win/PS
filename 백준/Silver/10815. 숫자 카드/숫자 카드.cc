#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, m;
int arr[500001];

bool binarySearch(int target) {
    int lo = 0, hi = n - 1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main(void) {
    FASTIO;

    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> m;
    while(m--) {
        cin >> num;
        if(binarySearch(num))
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}