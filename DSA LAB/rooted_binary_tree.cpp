#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct treeNode {
    char data;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode TN;

TN* createNode(char item) {
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
}

class BinTree {
public:
    TN* root;

    BinTree();
    ~BinTree();
    void print(TN* t, int depth);
    void preorder(TN* t);
    void postorder(TN* t);
    void inorder(TN* t);
};

BinTree::BinTree() {
    root = NULL;
}

BinTree::~BinTree() {
    // complete this method
    free(root);
}

void BinTree::preorder(TN* t) {
    if(t == NULL)
        return;
    printf("%c ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void BinTree::postorder(TN* t) {
    if(t == NULL){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    printf("%c ",t->data);
}

void BinTree::inorder(TN* t) {
    if(t == NULL){
        return;
    }
    inorder(t->left);
    printf("%c ",t->data);
    inorder(t->right);

}

void BinTree::print(TN* t, int depth) {
    if(t == NULL)
        return;
    print(t->right, depth+1);

    for(int i=0; i<depth; i++)
        printf("\t");
    printf("%c----------------------------------------\n", t->data);

    print(t->left, depth+1);
}

int main() {
    BinTree t;

    t.root = createNode('A');
    t.root->left = createNode('B');
    t.root->right = createNode('C');
    t.root->left->left = createNode('D');
    t.root->left->right = createNode('E');
    t.root->right->right = createNode('F');
    t.root->left->right->left = createNode('G');

//    t.preorder(t.root);

    
    t.print(t.root, 0);
    printf("\n");
    t.preorder(t.root);
    printf("\n");
    t.postorder(t.root);
    printf("\n");
    t.inorder(t.root);
    printf("\n");
    return 0;
}
