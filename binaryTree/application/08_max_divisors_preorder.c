/* Preorder + number with the most divisors
   QUESTION: Print preorder, then the value with the most divisors (first in preorder wins ties).
   PATTERN : Best-so-far tracking: start at 0, update only when strictly greater (>), so ties keep the first.
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
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) count++;
    return count;
}

void preorder(struct Node* root, int* best, int* bestCount) {
    if (root == NULL) return;
    printf("%d ", root->data);
    int c = countDivisors(root->data);
    if (c > *bestCount) {                        // strictly greater
        *bestCount = c;
        *best = root->data;
    }
    preorder(root->left, best, bestCount);
    preorder(root->right, best, bestCount);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int best = 0, bestCount = 0;
    preorder(root, &best, &bestCount);
    printf("\n%d\n", best);
    return 0;
}
