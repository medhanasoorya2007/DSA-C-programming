/* Preorder + LCM of values inside [X, Y]
   QUESTION: Print preorder, then the LCM of every tree value that lies between X and Y (inclusive).
   PATTERN : lcm = lcm / gcd * value. Start lcm at 1. Use long long.
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
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void preorder(struct Node* root, int x, int y, long long* lcm) {
    if (root == NULL) return;
    printf("%d ", root->data);
    if (root->data >= x && root->data <= y)
        *lcm = (*lcm / gcd(*lcm, root->data)) * root->data;
    preorder(root->left, x, y, lcm);
    preorder(root->right, x, y, lcm);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) { int t = a; a = b; b = t; }
    long long lcm = 1;
    preorder(root, a, b, &lcm);
    printf("\n%lld\n", lcm);
    return 0;
}
