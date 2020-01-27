#include<bits/stdc++.h>
using namespace std;

struct node{
    int data, liss;
    node *left, *right;
};

node* newNode(int);
void LISS(node*);

int main(){
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    LISS(root);
    if(root == nullptr)
        cout << 0;
    else
        cout << root->liss << endl;
    return 0;
}

node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}

void LISS(node *root){
    if(root == nullptr)
        return;
    if(!root->left && !root->right){
        root->liss = 1;
        return;
    }
    int c, gc, temp1 = 0, temp2 = 0;

    LISS(root->left);
    LISS(root->right);
    c = (root->left ? root->left->liss : 0) + (root->right ? root->right->liss : 0);
    if(root->left)
        temp1 = (root->left->left ? root->left->left->liss : 0) + (root->left->right ? root->left->right->liss : 0);
    if(root->right)
        temp2 = (root->right->left ? root->right->left->liss : 0) + (root->right->right ? root->right->right->liss : 0);
    gc = 1 + temp1 + temp2;
    root->liss = max(c, gc);
}
