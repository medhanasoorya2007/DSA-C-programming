/* Level order + product of alternate values
   QUESTION: Print level order, then the product of 1st, 3rd, 5th... values of that order.
   PATTERN : Level order with a queue of node pointers. index % 2 == 0 for alternate. Product starts at 1, use long long.
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
long long levelOrder(struct Node* root) {
    struct Node* queue[MAX];
    int front = 0, rear = -1;
    long long product = 1;
    int index = 0;
    if (root == NULL) return product;
    queue[++rear] = root;                        // enqueue root
    while (front <= rear) {
        struct Node* cur = queue[front++];       // dequeue
        printf("%d ", cur->data);
        if (index % 2 == 0) product *= cur->data;
        index++;
        if (cur->left)  queue[++rear] = cur->left;
        if (cur->right) queue[++rear] = cur->right;
    }
    return product;
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    long long product = levelOrder(root);
    printf("\n%lld\n", product);
    return 0;
}
