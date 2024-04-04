#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

vector<int> arr;

void order(int left, int right) {
    if(left > right) return;

    int root = left;
    int pivot = right + 1;
    for(int i = left + 1; i <= right; i++) {
        if(arr[root] < arr[i]) {
            pivot = i;
            break;
        }
    }
    
    order(left + 1, pivot - 1);
    order(pivot, right);
    cout << arr[root] << '\n';
}

int main(void) {
    FASTIO;

    int num, len = 0;;
    while(cin >> num) {
        arr.push_back(num);
        len++;
    }
    order(0, len - 1);

    return 0;
}   