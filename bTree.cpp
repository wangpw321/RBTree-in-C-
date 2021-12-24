
#include "bTree.hpp"
#include <iostream>

bTree::bTree(){
    root = nullptr;
    std::cout<<"Root is "<<root<<std::endl;
}

void bTree::inorderWalk(Node *x){
    if(x!=nullptr){
        this->inorderWalk(x->getLeft());
        std::cout << x->getKey() <<",";
        this->inorderWalk(x->getRight());
    }
}

Node* bTree::search(Node *x,int key){
    
    if(x==nullptr||x->getKey()==key)
        return x;
    if(x->getKey()<key)
        return search(x->getRight(),key);
    else return search(x->getLeft(),key);
}

Node* bTree::min(Node *x){
    while (x->getLeft())
        x = x->getLeft();
    return x;
}

Node* bTree::max(Node *x){
    while (x->getRight())
        x = x->getRight();
    return x;
}

Node* bTree::suc(Node *x){
    Node *y;
    if(x->getRight())
        return min(x->getRight());
    y=x->getParent();
    while(y && y->getRight() == x){
        x = y;
        y = y->getParent();
    }
    return y;
}

Node* bTree::pre(Node *x){
    Node *y;
    if(x->getLeft())
        return max(x->getLeft());
    y=x->getParent();
    while(y && y->getLeft() == x){
        x = y;
        y = y->getParent();
    }
    return y;
}

void bTree::insert(int key){
    Node *node = new Node();
    node->setKey(key);
    insert(node);
}
void bTree::insert(Node* key){
    
    Node *y = nullptr;
    Node *x = this->root;
    
    while (x!=nullptr){
        y = x;
        if (key->getKey() <= y->getKey())
            x = x->getLeft();
        else x = x->getRight();
    }
    
    if (y==nullptr)
        this->root = key;
    else {
        key->setParent(y);
        if (key->getKey() <= y->getKey())
            y->setLeft(key);
        else y->setRight(key);
    }
}

void bTree::del(int key){
    Node *node = search(this->root, key);
    del(node);
}
void bTree::del(Node* z){
    Node* y;
    Node* x;
    if(z->getRight()==nullptr||z->getLeft()==nullptr)
        y=z;
    else y=this->suc(z);
    
    if(y->getRight()!=nullptr)
        x = y->getRight();
    else x = y->getLeft();
    
    if(x!=nullptr)
        x->setParent(y->getParent());
    
    if(y->getParent()==nullptr)
        root = x;
    else if (y == y->getParent()->getLeft())
        y->getParent()->setLeft(x);
    else  y->getParent()->setRight(x);
    
    if (y!=z)
        z->setKey(y->getKey());
    
}
