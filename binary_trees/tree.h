#ifndef __TREE_H
#define __TREE_H
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string&);
int num_nodes(Node*);
int leaf_nodes(Node*);
int num_non_leaf_nodes(Node*);
bool compare(Node*,Node*);
void swap(Node*);
void clone(Node*,Node*);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void clone_util(Node*,Node*);
#endif