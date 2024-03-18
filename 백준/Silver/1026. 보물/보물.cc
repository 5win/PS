#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {

    int n;
    int A[51], B[51];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + n, compare);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (A[i] * B[i]);
    }
    cout << sum << endl;

    return 0;
}