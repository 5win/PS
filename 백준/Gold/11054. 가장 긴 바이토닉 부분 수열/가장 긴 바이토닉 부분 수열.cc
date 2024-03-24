#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[1001];
int leftDP[1001], rightDP[1001];

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++) {
        int mx = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i])
                mx = max(mx, leftDP[j]);
        }
        leftDP[i] = max(1, mx + 1);
    }

    for(int i = n - 1; i >= 0; i--) {
        int mx = 0;
        for(int j = n - 1; j > i; j--) {
            if(arr[j] < arr[i])
                mx = max(mx, rightDP[j]);
        }
        rightDP[i] = max(1, mx + 1);
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, leftDP[i] + rightDP[i] - 1);
    }
    cout << res << endl;

    return 0;
}