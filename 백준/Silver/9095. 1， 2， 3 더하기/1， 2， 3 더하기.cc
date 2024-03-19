#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int cache[20];

int main(void) {

    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    for(int i = 3; i <= 12; i++) 
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];

    int t; cin >> t;
    while(t--) {
        cin >> n;
        cout << cache[n] << endl;
    }

    return 0;
}