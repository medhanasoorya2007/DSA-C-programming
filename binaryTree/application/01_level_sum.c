/* Sum of nodes at level K (0-based)
   QUESTION: Print the sum of all ages at level K of the BST. Root is level 0.
   PATTERN : k shrinks as you go down. When k == 0 you are at the level.
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
int levelSum(struct Node* root, int k) {
    if (root == NULL) return 0;                  // nothing here
    if (k == 0) return root->data;               // reached the level -> take value
    return levelSum(root->left, k - 1) + levelSum(root->right, k - 1);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int k;
    scanf("%d", &k);
    printf("%d\n", levelSum(root, k));
    return 0;
}
