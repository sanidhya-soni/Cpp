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

// Calculating the Height of Binary Tree / Part of Binary Tree
int maxDepth(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Calculating Diameter of a Binary Tree
int diameterOfBinaryTree(TreeNode *root) {
    if(root == NULL)
        return 0;
    // Resolving all 3 possible cases
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
    int ans = max(op1, max(op2, op3));
    return ans;
}

int main() {

    TreeNode *root = createBinaryTree();

    int diameter = diameterOfBinaryTree(root);

    cout << endl << "Diameter: " << diameter << endl;

    return 0;
}
