/* Count perfect squares in the BST
   QUESTION: Count how many values in the tree are perfect squares.
   PATTERN : Count pattern: NULL -> 0, then (check this node) + left + right.
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
int isSquare(int x) {
    for (int i = 1; i * i <= x; i++)
        if (i * i == x) return 1;
    return 0;
}

int countSquares(struct Node* root) {
    if (root == NULL) return 0;
    return isSquare(root->data) + countSquares(root->left) + countSquares(root->right);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    printf("%d\n", countSquares(root));
    return 0;
}
