

#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node(){
    
    Key = NULL;
    Left = nullptr;
    Right = nullptr;
    Parent = nullptr;
}

Node::Node(int x){
    
    Key = x;
    Left = nullptr;
    Right = nullptr;
    Parent = nullptr;
}

int Node::getKey(){
    return Key;
}
Node* Node::getLeft(){
    return Left;
}
Node* Node::getRight(){
    return Right;
}
Node* Node::getParent(){
    return Parent;
}
void Node::setKey(int x){
    Key = x;
}
void Node::setLeft(Node* newLeft){
    Left = newLeft;
}
void Node::setRight(Node* newRight){
    Right = newRight;
}
void Node::setParent(Node* newParent){
    Parent = newParent;
}
