#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct treeNode {
    char data;
    struct treeNode* sibling;
    struct treeNode* child;
};

typedef struct treeNode TN;

TN* createNode(char item) {
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->data = item;
    newNode->sibling = NULL;
    newNode->child = NULL;
}

class GenTree {
public:
    TN* root;

    GenTree();
    ~GenTree();
    void print(TN* t, int depth);
    void preorder(TN* t);
    void postorder(TN* t);
};

GenTree::GenTree() {
    root = NULL;
}

GenTree::~GenTree() {

}

void GenTree::preorder(TN* t) {
    if(t == NULL)
        return;

    printf("%c ", t->data);

    preorder(t->child);

    preorder(t->sibling);
}

void GenTree::postorder(TN* t) {
    if(t == NULL)
        return;

    postorder(t->child);

    printf("%c ", t->data);

    postorder(t->sibling);
}

void GenTree::print(TN* t, int depth) {
    if(t == NULL)
        return;

    for(int i=0; i<depth; i++)
        printf("\t");
    printf("%c----------------------------------------\n", t->data);

    print(t->child, depth+1);

    print(t->sibling, depth);
}

int main() {
    GenTree t;

    t.root = createNode('A');
    t.root->child = createNode('B');
    t.root->child->sibling = createNode('C');
    t.root->child->sibling->sibling = createNode('D');
    t.root->child->child = createNode('E');
    t.root->child->child->sibling = createNode('F');
    t.root->child->sibling->sibling->child = createNode('G');

    t.print(t.root, 0);

    return 0;
}
