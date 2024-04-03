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

void order(int inLeft, int inRight, int pLeft, int pRight) {
    
    if(inLeft > inRight || pLeft > pRight) return;

    int pivot = pRight;
    int mid;
    for(int i = inLeft; i <= inRight; i++) {
        if(post[pivot] == in[i]) {
            mid = i;
            break;
        }
    }
    cout << in[mid] << ' ' ;
    int leftSize = mid - inLeft;
    int rightSize = inRight - mid;
    order(inLeft, mid - 1, pLeft, pLeft + leftSize - 1);
    order(mid + 1, inRight, pLeft + leftSize, pRight - 1);
}

int main(void) {
    FASTIO;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        in.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        post.push_back(tmp);
    }
    order(0, n - 1, 0, n - 1);
    
    return 0;
}   