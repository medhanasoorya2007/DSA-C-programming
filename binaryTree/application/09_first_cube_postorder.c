/* Postorder + first perfect cube
   QUESTION: Print postorder, then the first perfect cube met in that order, else -1.
   PATTERN : 'First' trick: answer starts at -1, only set it while it is still -1.
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
int isCube(int x) {
    for (int i = 1; i * i * i <= x; i++)
        if (i * i * i == x) return 1;
    return 0;
}

void postorder(struct Node* root, int* firstCube) {
    if (root == NULL) return;
    postorder(root->left, firstCube);
    postorder(root->right, firstCube);
    printf("%d ", root->data);
    if (*firstCube == -1 && isCube(root->data))
        *firstCube = root->data;                 // only set once
}

int main() {
    int N, x;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);          // build the BST
    }
    int firstCube = -1;
    postorder(root, &firstCube);
    if (firstCube == -1) printf("\n-1\n");
    else printf("\n%d \n", firstCube);           // sample shows a space after the cube
    return 0;
}
