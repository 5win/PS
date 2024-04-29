#include <iostream>

int main() {

    using namespace std;
    int n;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}