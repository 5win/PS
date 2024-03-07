#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int a, b, c;

int dfs(int k) {
    if(k == 1) {
        return a % c;
    }
    else if(k % 2 == 0) {
        long long ret = dfs(k / 2);
        return (ret * ret) % c;
    }
    else {
        long long ret = dfs(k / 2);
        return (ret * ret) % c * a % c;
    }
}

int main(void) {
    cin >> a >> b >> c;

    cout << dfs(b) << '\n';


    return 0;
}