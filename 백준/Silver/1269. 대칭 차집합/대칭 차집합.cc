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

bool binarySearch(int *arr, int target, int lo, int hi) {

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(target < arr[mid]) hi = mid - 1;
        else if(arr[mid] == target) return true;
        else lo = mid + 1;
    }
    return false;
}

int main(void) {
    FASTIO;

    int a, b;
    int A[200001], B[200001];
    
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> B[i];
    }
    sort(A, A + a);
    sort(B, B + b);

    int ans = 0;
    for(int i = 0; i < a; i++) {
        if(!binarySearch(B, A[i], 0, b)) ans++;
    }
    for(int i = 0; i < b; i++) {
        if(!binarySearch(A, B[i], 0, a)) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}