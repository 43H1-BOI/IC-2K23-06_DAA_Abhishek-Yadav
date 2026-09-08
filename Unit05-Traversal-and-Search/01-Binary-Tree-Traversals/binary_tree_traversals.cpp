// Binary Tree Traversals: inorder, preorder, postorder (depth-first, recursive)
// and level order (breadth-first, uses a queue).
// The tree is given in level order; -1 means "no node here".
// Compile: g++ binary_tree_traversals.cpp -o binary_tree_traversals
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 15;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int readInt(string prompt, int lo, int hi) {
    int x;

    cout << prompt;
    cin >> x;

    while (x < lo || x > hi) {
        cout << "Invalid! Enter again: ";
        cin >> x;
    }

    return x;
}



Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Builds the tree from a level-order list; every created node waits in a queue
// until its left and right children have been read.
Node* buildTree(const int vals[], int n) {
    Node* queue[MAX_N];
    int head = 0, tail = 0, i = 1;
    Node* root = newNode(vals[0]);
    queue[tail++] = root;
    while (head < tail && i < n) {
        Node* cur = queue[head++];
        if (i < n && vals[i] != -1) { cur->left = newNode(vals[i]); queue[tail++] = cur->left; }
        i++;
        if (i < n && vals[i] != -1) { cur->right = newNode(vals[i]); queue[tail++] = cur->right; }
        i++;
    }
    return root;
}

void inorder(const Node* t)   { if (t) { inorder(t->left);   cout << t->data << " "; inorder(t->right); } }
void preorder(const Node* t)  { if (t) { cout << t->data << " "; preorder(t->left);  preorder(t->right); } }
void postorder(const Node* t) { if (t) { postorder(t->left); postorder(t->right); cout << t->data << " "; } }

void levelOrder(Node* root) {
    Node* queue[MAX_N];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node* cur = queue[head++];
        cout << cur->data << " ";
        if (cur->left)  queue[tail++] = cur->left;
        if (cur->right) queue[tail++] = cur->right;
    }
}

void freeTree(Node* t) {                            // postorder deletion
    if (!t) return;
    freeTree(t->left);
    freeTree(t->right);
    delete t;
}

int main() {
    int vals[MAX_N];
    int n = readInt("Enter number of entries in the level-order list (1-15): ", 1, MAX_N);
    cout << "Enter " << n << " values (0-999, or -1 for an empty child): ";
    vals[0] = readInt("", 0, 999);                  // the root cannot be empty
    for (int i = 1; i < n; i++) vals[i] = readInt("", -1, 999);

    Node* root = buildTree(vals, n);
    cout << "\nInorder    : "; inorder(root);
    cout << "\nPreorder   : "; preorder(root);
    cout << "\nPostorder  : "; postorder(root);
    cout << "\nLevel order: "; levelOrder(root);
    cout << "\n";
    freeTree(root);
    return 0;
}
