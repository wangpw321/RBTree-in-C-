

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
class Node {
private:
    int Key;
    Node *Left;
    Node *Right;
    Node *Parent;
public:
    Node();
    Node(int);
    friend class rTree;
    int getKey();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setKey(int x);
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setParent(Node* newParent);
};
#endif /* Node_hpp */
