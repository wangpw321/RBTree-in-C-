
#ifndef rbNode_hpp
#define rbNode_hpp

#include <stdio.h>

enum rbColor{red, black};


class rbNode{
    
    int Key;
    rbNode *Left;
    rbNode *Right;
    rbNode *Parent;
    rbColor Color;
    
public:
    
    rbNode();
    friend class rbTree;
    int getKey();
    rbNode* getLeft();
    rbNode* getRight();
    rbNode* getParent();
    void setKey(int x);
    void setLeft(rbNode* newLeft);
    void setRight(rbNode* newRight);
    void setParent(rbNode* newParent);
    rbColor getColor();
    void setColor(rbColor);
    void setNil();
};

#endif /* rbNode_hpp */
