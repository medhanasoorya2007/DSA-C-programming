/* ============================================================
   BST FULL TEMPLATE -- every common operation in one file
   Part 1: create / insert / search / min / max / delete
   Part 2: traversals (preorder, inorder, postorder, level order)
   Part 3: measuring (height, count, leaves, sum)
   Part 4: free the tree
   ============================================================ */
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
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    return root;                                       // always return root
}
/* ================= END TEMPLATE ================= */


/* ---------------- PART 1: SEARCH / MIN / MAX / DELETE ---------------- */
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data) 
        return search(root->left, key);    // smaller -> left
    return search(root->right, key);                         // bigger  -> right
}

struct Node* findMin(struct Node* root) {      // keep going left
    while (root->left != NULL) 
        root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {      // keep going right
    while (root->right != NULL) 
        root = root->right;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) 
        return NULL;
    if (key < root->data) 
        root->left = deleteNode(root->left, key);
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);
    else {
        /* case 1 and 2: zero or one child */
        if (root->left == NULL) {
            struct Node* t = root->right;
            free(root);
            return t;
        }
        if (root->right == NULL) {
            struct Node* t = root->left;
            free(root);
            return t;
        }
        /* case 3: two children -> copy inorder successor, delete it */
        struct Node* s = findMin(root->right);
        root->data = s->data;
        root->right = deleteNode(root->right, s->data);
    }
    return root;
}

/* ---------------- PART 2: TRAVERSALS ---------------- */
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    struct Node* queue[MAX];
    int front = 0, rear = -1;
    if (root == NULL) 
        return;
    queue[++rear] = root;                      // enqueue root
    while (front <= rear) {
        struct Node* cur = queue[front++];     // dequeue
        printf("%d ", cur->data);
        if (cur->left)  queue[++rear] = cur->left;
        if (cur->right) queue[++rear] = cur->right;
    }
}

/* ---------------- PART 3: MEASURING ---------------- */
int height(struct Node* root) {                // empty = -1, single node = 0
    if (root == NULL) return -1;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int sumNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

/* ---------------- PART 4: FREE ---------------- */
void freeTree(struct Node* root) {             // postorder: children first
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* ---------------- DEMO ---------------- */
int main() {
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    struct Node* root = NULL;
    for (int i = 0; i < 7; i++) root = insert(root, values[i]);

    printf("Preorder   : "); preorder(root);   printf("\n");
    printf("Inorder    : "); inorder(root);    printf("\n");
    printf("Postorder  : "); postorder(root);  printf("\n");
    printf("Level order: "); levelOrder(root); printf("\n");
    printf("Height %d, Nodes %d, Leaves %d, Sum %d\n",
           height(root), countNodes(root), countLeaves(root), sumNodes(root));
    printf("Min %d, Max %d\n", findMin(root)->data, findMax(root)->data);
    printf("Search 60: %s, Search 65: %s\n",
           search(root, 60) ? "found" : "not found",
           search(root, 65) ? "found" : "not found");

    root = deleteNode(root, 20);               // leaf
    printf("Delete 20 (leaf)      : "); inorder(root); printf("\n");
    root = deleteNode(root, 30);               // one child
    printf("Delete 30 (one child) : "); inorder(root); printf("\n");
    root = deleteNode(root, 50);               // two children (root)
    printf("Delete 50 (two child) : "); inorder(root); printf("\n");

    freeTree(root);
    return 0;
}