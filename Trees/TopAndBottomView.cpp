#include <iostream>
#include <vector>
#include <limits.h>
#include<queue>
#include<map>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = 0;
        this->left = left;
        this->right = right;
    }
};

TreeNode* createBinaryTree() {
    int val;
    cout << "Enetr Value (-1 for NULL): ";
    cin >> val;
    if(val == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << endl;
    root->left = createBinaryTree();
    cout << "Enter right child of " << val << endl;
    root->right = createBinaryTree();
    return root;
}

void preOrder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << " ";
}
void inOrder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    preOrder(root->left);
    cout << root->val << " ";
    preOrder(root->right);
}
void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    if(root == nullptr) {
        return;
    }
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}
void levelOrderLevelWise(TreeNode* root) {
    queue<TreeNode*> q;
    if(root == nullptr) {
        return;
    }
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode* temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

void leftView(TreeNode* root) {
    queue<TreeNode*> q;
    if(root == nullptr) {
        return;
    }
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(i == 0)
                cout << temp->val << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void rightView(TreeNode* root) {
    queue<TreeNode*> q;
    if(root == nullptr) {
        return;
    }
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(i == levelSize - 1)
                cout << temp->val << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void topView(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    map<int, int> topNode;
    queue<pair<TreeNode*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        if(topNode.find(temp.second) == topNode.end()) {
            topNode[temp.second] = temp.first->val;
        }
        if(temp.first->left)
            q.push(make_pair(temp.first->left, temp.second-1));
        if(temp.first->right)
            q.push(make_pair(temp.first->right, temp.second+1));
    }
    for(auto i: topNode) {
        cout << i.first << " -> " << i.second << endl;
    }
}

void bottomView(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    map<int, int> topNode;
    queue<pair<TreeNode*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        topNode[temp.second] = temp.first->val;
        if(temp.first->left)
            q.push(make_pair(temp.first->left, temp.second-1));
        if(temp.first->right)
            q.push(make_pair(temp.first->right, temp.second+1));
    }
    for(auto i: topNode) {
        cout << i.first << " -> " << i.second << endl;
    }
}

int main() {

    TreeNode* root;

    root = createBinaryTree();

    cout << endl << "Top View: " << endl;
    topView(root);
    cout << endl << "Bottom View: " << endl;
    bottomView(root);

    return 0;
}
