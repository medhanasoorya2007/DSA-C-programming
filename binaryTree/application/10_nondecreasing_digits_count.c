/* Preorder + count numbers with non-decreasing digits
   QUESTION: Print preorder, then count values whose digits never decrease left to right (123, 455 yes; 321 no).
   PATTERN : Digits come out backwards (n % 10), so check they never INCREASE going right-to-left. prev starts at 9.
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
int isNonDecreasing(int n) {
    int prev = 9;
    while (n > 0) {
        int d = n % 10;                          // last digit
        if (d > prev) return 0;
        prev = d;
        n /= 10;
    }
    return 1;
}

void preorder(struct Node* root, int* count) {
    if (root == NULL) return;
    printf("%d ", root->data);
    if (isNonDecreasing(root->data)) (*count)++;
    preorder(root->left, count);
    preorder(root->right, count);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int count = 0;
    preorder(root, &count);
    printf("\n%d\n", count);
    return 0;
}
