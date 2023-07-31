#include <iostream>
#include <vector>
#include <limits.h>
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

// Creating a Binary Tree
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

/* void checkIdentical(TreeNode *root1, TreeNode *root2, bool &identical) {
    if(root1 == nullptr && root2 == nullptr) {
        return;
    }
    if(root1 == nullptr || root2 == nullptr) {
        identical = false;
        return;
    }
    if(identical == true && root1->val != root2->val) {
        identical = false;
    }
    checkIdentical(root1->left, root2->left, identical);
    checkIdentical(root1->right, root2->right, identical);
} */

bool checkIdentical(TreeNode *root1, TreeNode *root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr) {
        return false;
    }

    bool left = checkIdentical(root1->left, root2->left);
    bool right = checkIdentical(root1->right, root2->right);
    bool current = root1->val == root2->val;

    return left && right && current;
}

int main() {
    cout << "Enter Details for Tree 1" << endl;
    TreeNode *root1 = createBinaryTree();
    cout << "Enter Details for Tree 2" << endl;
    TreeNode *root2 = createBinaryTree();

    bool identical;

    identical = checkIdentical(root1, root2);

    cout << endl << "Identical: " << identical << endl;

    return 0;
}
