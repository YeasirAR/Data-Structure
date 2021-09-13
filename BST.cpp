#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode TN;

TN* createNode(int item) {
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
}

class BST {
public:
    TN* root;

    BST();
    ~BST();
    void print(TN* t, int depth);
    void preorder(TN* t);
    void postorder(TN* t);
    void inorder(TN* t);
    TN* insert_item_rec(TN* t, int item);
    TN* insert_item(int item);
    TN* delete_item_rec(TN* t, int item);
    TN* delete_item(int item);
    TN* search_item(TN* t, int key);
};

BST::BST() {
    root = NULL;
}

BST::~BST() {
    // complete this method
}

void BST::preorder(TN* t) {
    if(t == NULL)
        return;
    printf("%c ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void BST::postorder(TN* t) {
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%c ", t->data);
}

void BST::inorder(TN* t) {
    if(t == NULL)
        return;
    inorder(t->left);
    printf("%c ", t->data);
    inorder(t->right);
}

void BST::print(TN* t, int depth) {
    if(t == NULL)
        return;
    print(t->right, depth+1);

    for(int i=0; i<depth; i++)
        printf("\t");
    printf("%d----------------------------------------\n", t->data);

    print(t->left, depth+1);
}

TN* BST::search_item(TN* t, int key) {
    if(t == NULL)
        return NULL;
    if(t->data == key)
        return t;
    else if(t->data > key)
        return search_item(t->left, key);
    else
        return search_item(t->right, key);
}

TN* BST::insert_item_rec(TN* t, int item) {
    if(t == NULL) {
        TN* newNode = createNode(item);
        return newNode;
    }
    if(t->data > item) {
        t->left = insert_item_rec(t->left, item);
        return t;
    }
    else {
        t->right = insert_item_rec(t->right, item);
        return t;
    }
}

TN* BST::insert_item(int item) {
    root = insert_item_rec(root, item);
    return root;
}

TN* BST::delete_item_rec(TN* t, int item) {
    if(t == NULL)
        return NULL;
    if(t->data == item){
        if(t->left == NULL){
            TN* temp = t->right;
            free(t);
            return temp;
        }
        else if(t->right == NULL){
            free(t);
            return NULL;
        }
        else{
            TN* suc = t->right;
            while(suc->left != NULL){
                suc = suc->left;
                t->data = suc->data;
                t->right = delete_item_rec(t->right, suc->data);
                return t;
            }
        }
    }
}

TN* BST::delete_item(int item) {
    root = delete_item_rec(root, item);
    return root;
}

int main() {

    BST T;

    T.insert_item(48);
    T.insert_item(24);
    T.insert_item(72);
    T.insert_item(36);
    T.insert_item(60);
    T.insert_item(12);
    T.insert_item(84);
    T.insert_item(96);
    T.insert_item(40);
    T.insert_item(65);
    T.insert_item(75);

    T.print(T.root, 0);
    printf("\n \n \n");
    T.delete_item_rec(T.root,24);
    T.delete_item_rec(T.root,75);
    T.print(T.root, 0);


    return 0;
}
