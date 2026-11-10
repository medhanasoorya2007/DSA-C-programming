/* Level order + count odd-length binary codes
   QUESTION: Print level order, then count values whose binary form has an odd number of bits.
   PATTERN : Binary length = how many times you can divide by 2 before reaching 0. Level order with a queue.
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
int binaryLength(int n) {
    int len = 0;
    while (n > 0) {
        len++;                                   // one more bit
        n /= 2;                                  // drop last bit
    }
    return len;
}

int levelOrder(struct Node* root) {
    struct Node* queue[MAX];
    int front = 0, rear = -1;
    int count = 0;
    if (root == NULL) return 0;
    queue[++rear] = root;
    while (front <= rear) {
        struct Node* cur = queue[front++];
        printf("%d ", cur->data);
        if (binaryLength(cur->data) % 2 == 1) count++;
        if (cur->left)  queue[++rear] = cur->left;
        if (cur->right) queue[++rear] = cur->right;
    }
    return count;
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int count = levelOrder(root);
    printf("\n%d\n", count);
    return 0;
}
