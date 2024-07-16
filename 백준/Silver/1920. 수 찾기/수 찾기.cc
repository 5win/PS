#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n, m;
int A[100001];

bool binarySearch(int x) {
    int lo = 0, hi = n - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(A[mid] == x) return true;
        else if(A[mid] < x) hi = mid - 1;
        else lo = mid + 1;
    }
    return false;
}

int main(void) {
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);

    cin >> m;
    while(m--) {
        int x; cin >> x;
        if(binary_search(A, A + n, x)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }


    return 0;
}