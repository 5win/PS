#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1987654321;

int n;
int arr[1000001];
vector<int> v;

int binarySearch(int lo, int hi, int target) {

    int ret = lo;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(v[mid] >= target) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    v.push_back(arr[0]);

    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] < v[cnt - 1]) {
            int target = binarySearch(0, cnt, arr[i]);
            v[target] = arr[i];
        }
        else if(arr[i] > v[cnt - 1]) {
            v.push_back(arr[i]);
            cnt++;
        }
    }

    cout << cnt << endl;
    
    return 0;
}