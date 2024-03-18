#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>

using namespace std;
vector<char> v;
int l, c;

bool isA(char c) {
    char arr[] = {'a', 'e', 'i', 'o', 'u'};

    for(int i = 0; i < 5; i++) {
        if(arr[i] == c)
            return true;
    }
    return false;
}
// a c i s t w
void solve(string s, int start, int a_count, int b_count) {
    
    if(s.length() == l) {
        if(a_count >= 1 && b_count >= 2) {
            cout << s << endl;
        }
        return;
    }
    if(start == v.size())
        return;


    for(int i = start; i < v.size(); i++) {
        
        s.push_back(v[i]);

        if(isA(v[i])) 
            solve(s, i + 1, a_count + 1, b_count);
        else
            solve(s, i + 1, a_count, b_count + 1);
        s.erase(s.end() - 1, s.end());      //?
    }
    return;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> l >> c;

    char temp;

    for(int i = 0; i < c; i++) {
        cin >> temp;
        v.push_back(temp);    
    }
    sort(v.begin(), v.end());
    string s;
    solve(s, 0, 0, 0);
    
    return 0;
}