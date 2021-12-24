
#include "rbNode.hpp"
#include <iostream>

using namespace std;

rbNode::rbNode(){
    this->setNil();
}

int rbNode::getKey(){
    return Key;
}
rbNode* rbNode::getLeft(){
    return Left;
}
rbNode* rbNode::getRight(){
    return Right;
}
rbNode* rbNode::getParent(){
    return Parent;
}
void rbNode::setKey(int x){
    Key = x;
}
void rbNode::setLeft(rbNode* newLeft){
    Left = newLeft;
}
void rbNode::setRight(rbNode* newRight){
    Right = newRight;
}
void rbNode::setParent(rbNode* newParent){
    Parent = newParent;
}


rbColor rbNode::getColor(){
    return Color;
}

void rbNode::setColor(rbColor x){
     this->Color = x;
}

void rbNode::setNil(){
    setColor(black);
    setKey(-1);
    setParent(this);
    setRight(this);
    setLeft(this);
}

