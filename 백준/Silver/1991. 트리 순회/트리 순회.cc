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

struct TreeNode {
    char num;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(char num) : num(num) {}
};

int n;
vector<TreeNode*> lst(26, NULL);

void preOrder(TreeNode* cur) {
    if(cur == NULL) return;
    cout << cur->num;
    preOrder(cur->left);
    preOrder(cur->right);
}

void inOrder(TreeNode* cur) {
    if(cur == NULL) return;
    inOrder(cur->left);
    cout << cur->num;
    inOrder(cur->right);
}

void postOrder(TreeNode* cur) {
    if(cur == NULL) return;
    postOrder(cur->left);
    postOrder(cur->right);
    cout << cur->num;
}

int main(void) {
    FASTIO;

    cin >> n;

    for(int i = 0; i < n; i++) {
        lst[i] = new TreeNode('A' + i);
    }

    for(int i = 0; i < n; i++) {
        char u, v1, v2;
        cin >> u >> v1 >> v2;

        int cur = u - 'A', left = v1 - 'A', right = v2 - 'A';
        if(v1 != '.') {
            lst[left]->parent = lst[cur];
            lst[cur]->left = lst[left];
        }
        if(v2 != '.') {
            lst[right]->parent = lst[cur];
            lst[cur]->right = lst[right];
        }
    }
    preOrder(lst[0]);    cout << '\n';
    inOrder(lst[0]);     cout << '\n';
    postOrder(lst[0]);   cout << '\n';
    
    return 0;
}   