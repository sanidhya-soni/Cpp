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

// Creating a Binary Tree form Level Order Input Format
TreeNode* createFromLevelOrder() {
    queue<TreeNode*> q;
    TreeNode *root;

    // Creating root node
    int data;
    cout << endl << "Enter Root Node Data: ";
    cin >> data;

    if(data != - 1) {
        root = new TreeNode(data);
        q.push(root);
    }

    while(!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();

        // Enter Left Node Data
        cout << endl << "Enter data for left node of " << temp->val << endl;
        cin >> data;

        if(data != -1) {
            temp->left = new TreeNode(data);
            q.push(temp->left);
        }

        // Enter Right Node Data
        cout << endl << "Enter data for right node of " << temp->val << endl;
        cin >> data;

        if(data != -1) {
            temp->right = new TreeNode(data);
            q.push(temp->right);
        }
    }
    return root;
}

// For Printing InOrder Traversal (Left Root Right)
void inOrderTraversal(TreeNode *root) {
    if(root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

// For Printing PreOrder Traversal (Root Left Right)
void preOrderTraversal(TreeNode *root) {
    if(root == nullptr)
        return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// For Printing Post Order Traversal (Left Right Root)
void postOrderTraversal(TreeNode *root) {
    if(root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

// For Printing Level-Order Traversal in Single line
void levelOrderTraversal(TreeNode *root) {

    queue<TreeNode *> q;

    // Adding root TreeNode to the queue
    q.push(root);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        cout << temp->val << " ";
        q.pop();

        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
    }
}

// For printing LevelOrder Traversal Levelwise in different lines
void levelOrderTraversalLevelwise(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " ";

            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
        cout << endl;
    }
}

int main() {

    TreeNode *root = nullptr;

    // root = createBinaryTree();
    root = createFromLevelOrder();

    cout << endl << "InOrder: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PreOrder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "PostOrder: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "LevelOrder: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "LevelOrder Levelwise: " << endl;
    levelOrderTraversalLevelwise(root);
    cout << endl;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1  LevelWise Input
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1  Direct Input
