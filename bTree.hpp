

#ifndef bTree_hpp
#define bTree_hpp

#include <stdio.h>
#include "Node.hpp"

class bTree{
public:
    Node *root;
    bTree();
    void inorderWalk(Node *);
    Node* search(Node *,int);
    Node* min(Node *);
    Node* max(Node *);
    Node* pre(Node *);
    Node* suc(Node *);
    void insert(Node *);
    void del(Node *);
    void insert(int);
    void del(int);
};

#endif /* bTree_hpp */
