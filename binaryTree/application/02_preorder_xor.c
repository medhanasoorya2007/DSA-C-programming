/* Preorder traversal + XOR of all values
   QUESTION: Print preorder, then the XOR of all values.
   PATTERN : Traversal that carries one running value through a pointer. XOR starts at 0.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* ================= TEMPLATE (same in every file) ================= */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);         // empty spot -> new node
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;                                       // always return root
}
/* ================= END TEMPLATE ================= */

/* ================= APPLICATION (this question) ================= */
void preorder(struct Node* root, int* xorValue) {
    if (root == NULL) return;
    printf("%d ", root->data);                   // Root
    *xorValue ^= root->data;
    preorder(root->left, xorValue);              // Left
    preorder(root->right, xorValue);             // Right
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int xorValue = 0;
    preorder(root, &xorValue);
    printf("\n%d\n", xorValue);
    return 0;
}
