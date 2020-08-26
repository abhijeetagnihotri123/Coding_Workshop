#ifndef __LIST_H
#define __LIST_H
#include <iostream>
#include <string>
using namespace std;
struct Node {
    int coeff;
    int power;
    Node *next;
    Node(int a,int b) {
        coeff = b;
        power = a;
        next = NULL;
    }
};
class List {
  public:
    Node *L;
    void push(int);
    int pop();
    List() { 
        L = new Node(-1,-1);// L is dummy 
    }
};
void display_list(List&);
void insert(List&,int,int);
void Delete(List&,int);
#endif