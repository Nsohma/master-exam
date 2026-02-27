#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int height(struct node* p);
struct node* create(int data);
struct node* insert(struct node* p, int data);
struct node* insert_avl(struct node* p, int data);
struct node* rotate_left(struct node* p);
struct node* rotate_right(struct node* p);


int main(void){
    int dataa[7] = {0, 2, 3, 4, 6, 1 ,5};
    int data[7] = {4, 2, 2, 2, 0, 4, 8};
    int data3[7] = {0, 2, 3, 4, 6, 1, 5};
    int data4[7] = {4, 2, 2, 2, 0, 4, 8};
    int data5[7] = {2, 5, 3, 0 ,1, 6, 4};

    struct node* root = NULL;
    for (int i=0; i<7; i++){
        root = insert(root, dataa[i]);
    }
    printf("data1:%d\n", height(root));

    root = NULL;
    for (int i=0; i<7; i++){
        root = insert(root, data[i]);
    }
    printf("data2:%d\n", height(root));

    root = NULL;
    for (int i=0; i<7; i++){
        root = insert_avl(root, data3[i]);
    }
    printf("avl1:%d\n", height(root));

    root = NULL;
    for (int i=0; i<7; i++){
        root = insert_avl(root, data4[i]);
    }
    printf("avl2:%d\n", height(root));

    root = NULL;
    for (int i=0; i<7; i++){
        root = insert_avl(root, data5[i]);
    }
    printf("avl3:%d\n", height(root));

    return 0;
}

int height(struct node* p){
    if (p == NULL) return -1;
    int left = height(p->left) + 1;
    int right = height(p->right) + 1;
    if (left > right) return left;
    else return right;
}

struct node* create(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

struct node* insert(struct node* p, int data){
    if (p == NULL) p = create(data);
    else if (data > p -> data) p->right = insert(p->right, data);
    else p->left = insert(p->left, data);
    return p;
}

struct node* insert_avl(struct node* p, int data){
    if (p == NULL) p = create(data);
    else if (data > p->data){
        p->right = insert_avl(p->right, data);
        if (height(p->right) - height(p->left) == 2){
            if (data > p->right->data) p = rotate_left(p);
            else{
                p -> right = rotate_right(p -> right);
                p = rotate_left(p);
            }
        }
    }
    else{
        p->left = insert_avl(p->left, data);
        if (height(p->left) - height(p->right) == 2){
            if (data > p->left->data){
                p->left = rotate_left(p->left);
                p = rotate_right(p);
            }
            else p = rotate_right(p);
        }
    }
    return p;
}

struct node* rotate_left(struct node* p){
    struct node* right_child = p -> right;
    p -> right = right_child -> left;
    right_child -> left = p;
    return right_child;
}

struct node* rotate_right(struct node* p){
    struct node* left_child = p -> left;
    p -> left = left_child -> right;
    left_child -> right = p;
    return left_child;
}

