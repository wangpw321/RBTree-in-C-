
#ifndef rbTree_hpp
#define rbTree_hpp

#include <stdio.h>
#include "rbNode.hpp"


class rbTree{

public:
    rbNode *root;
    rbNode *nil;
    rbTree();
    void leftRotate(rbNode *);
    void rightRotate(rbNode *);
    void printTree(rbNode *);
   
    rbNode* search(rbNode *,int);
    rbNode* min(rbNode *);
    rbNode* max(rbNode *);
    rbNode* pre(rbNode *);
    rbNode* suc(rbNode *);    
    
    void rbInsert(rbNode *);
    void rbInsert(int);
    void rbInsertFixup(rbNode *);
    void rbDel(rbNode *);
    void rbDel(int);
    void rbDelFixup(rbNode *);
    
};

#endif /* rbTree_hpp */
