/* Average of nodes at level K (1-based)
   QUESTION: Print the average of values at level K with 2 decimals. Root is level 1 here!
   PATTERN : Like level sum but also count nodes. Base case is k == 1. Cast to float before dividing.
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
void levelStats(struct Node* root, int k, int* sum, int* count) {
    if (root == NULL) return;
    if (k == 1) {                                // 1-based: root is level 1
        *sum += root->data;
        (*count)++;
        return;
    }
    levelStats(root->left, k - 1, sum, count);
    levelStats(root->right, k - 1, sum, count);
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
    int sum = 0, count = 0;
    levelStats(root, k, &sum, &count);
    if (count == 0) printf("0.00\n");
    else printf("%.2f\n", (float)sum / count);
    return 0;
}
