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

int calculateHeight(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }
    return max(calculateHeight(root->left), calculateHeight(root->right)) + 1;
}

int main() {

    TreeNode *root = createBinaryTree();
    int height;

    height = calculateHeight(root);

    cout << endl << "Height: " << height << endl;

    return 0;
}
