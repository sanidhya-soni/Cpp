#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class TreeNode {
    public:

    // Declaring Variables

    int val;
    TreeNode *left;
    TreeNode *right;

    // Defining Constructors

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

    TreeNode(int val, TreeNode *left, TreeNode *right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

TreeNode* createBinaryTree() {
    int data;

    cout << "Enter the value (or -1 for no TreeNode): ";

    cin >> data;

    // Base case

    if(data == -1)
        return nullptr;

    TreeNode *root = new TreeNode(data);
    
    // Call for left TreeNode
    cout << "Enter left child of " << data << endl;
    root->left = createBinaryTree();
    
    // Call for right TreeNode
    cout << "Enter right child of " << data << endl;
    root->right = createBinaryTree();

    return root;
}

void leftView(TreeNode *root) {

    cout << endl << endl << "Left View of the Tree: ";

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            if(i == 0) {
                cout << q.front()->val << " ";
            }
            if(q.front()->left != nullptr)
                q.push(q.front()->left);
            if(q.front()->right != nullptr)
                q.push(q.front()->right);
            q.pop();
        }
    }

    cout << endl;
}

void rightView(TreeNode *root) {
    cout << endl << endl << "Right View of the Tree: ";

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            if(i == len - 1) {
                cout << q.front()->val << " ";
            }
            if(q.front()->left != nullptr)
                q.push(q.front()->left);
            if(q.front()->right != nullptr)
                q.push(q.front()->right);
            q.pop();
        }
    }

    cout << endl;
}

int main() {

    TreeNode *root = nullptr;

    root = createBinaryTree();

    leftView(root);
    rightView(root);

    return 0;
}
