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

int n;
vector<int> in, post;
int pivotIdx[100001];

void order(int inLeft, int inRight, int pLeft, int pRight) {
    
    if(inLeft > inRight || pLeft > pRight) return;

    int pivot = pRight;
    
    // in배열에서 특정값의 인덱스가 몇인지 저장한 배열 pivotIdx를 사용.
    int mid = pivotIdx[post[pivot]];

    cout << in[mid] << ' ' ;
    int leftSize = mid - inLeft;
    int rightSize = inRight - mid;
    order(inLeft, mid - 1, pLeft, pLeft + leftSize - 1);
    order(mid + 1, inRight, pLeft + leftSize, pLeft + leftSize + rightSize - 1);
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        in.push_back(tmp);
        pivotIdx[tmp] = i;
    }

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        post.push_back(tmp);
    }
    order(0, n - 1, 0, n - 1);
    
    return 0;
}   