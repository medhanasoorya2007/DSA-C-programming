/* Postorder traversal + bitwise OR
   QUESTION: Print postorder, then the OR of all values.
   PATTERN : Same as XOR question: postorder (print after both children). OR starts at 0.
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
void postorder(struct Node* root, int* orValue) {
    if (root == NULL) return;
    postorder(root->left, orValue);              // Left
    postorder(root->right, orValue);             // Right
    printf("%d ", root->data);                   // Root
    *orValue |= root->data;
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int orValue = 0;
    postorder(root, &orValue);
    printf("\n%d\n", orValue);
    return 0;
}
