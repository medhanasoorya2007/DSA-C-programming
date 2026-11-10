/* Sum of digital roots
   QUESTION: Sum the digital root (repeat digit-sum until 1 digit) of every value.
   PATTERN : Helper for the number rule + (helper(this node) + left + right).
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
int digitalRoot(int n) {
    while (n > 9) {                              // until single digit
        int sum = 0;
        while (n > 0) {
            sum += n % 10;                       // last digit
            n /= 10;                             // drop last digit
        }
        n = sum;
    }
    return n;
}

int sumRoots(struct Node* root) {
    if (root == NULL) return 0;
    return digitalRoot(root->data) + sumRoots(root->left) + sumRoots(root->right);
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    printf("%d\n", sumRoots(root));
    return 0;
}
