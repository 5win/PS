#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

int n;
int arr[1001];
vector<int> twoSum;

int main(void) {
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            twoSum.push_back(arr[i] + arr[j]);
        }
    }
    sort(twoSum.begin(), twoSum.end()); 

    for(int k = n - 1; k >= 0; k--) {
        for(int z = k - 1; z >= 0; z--) {
            if(binary_search(twoSum.begin(), twoSum.end(), arr[k] - arr[z])) {
                cout << arr[k] << '\n';
                return 0;
            }
        }
    }

    return 0;
}