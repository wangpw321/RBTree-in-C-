
#include "rbTree.hpp"
#include "rbNode.hpp"
#include <iostream>

rbTree::rbTree(){
    nil = new rbNode();
    root = nil;
    nil->setLeft(root);
}

void rbTree::rbInsert(int value){
    rbNode *node =  new rbNode();
    node->setKey(value);
    rbInsert(node);
}

void rbTree::rbInsert(rbNode* key){
    
    rbNode *y = nil;
    rbNode *x = root;
    
    while (x!=nil){
        y = x;
        if (key->getKey() <= y->getKey())
            x = x->getLeft();
        else x = x->getRight();
    }
    
    key->setParent(y);
    
    if (y==nil)
        this->root = key;
    else {
        if (key->getKey() <= y->getKey())
            y->setLeft(key);
        else y->setRight(key);
    }
    
    key->setColor(red);
    key->setLeft(nil);
    key->setRight(nil);
    
    rbInsertFixup(key);
}

void rbTree::rbInsertFixup(rbNode *x){
    rbNode *y = nil;
    while(x->getParent()!=nil&&x->getParent()->getColor()==red){
        if (x->getParent() == x->getParent()->getParent()->getLeft()){
            y = x->getParent()->getParent()->getRight();
            if(y!=nil&&y->getColor()==red){
                x->getParent()->setColor(black);
                y->setColor(black);
                x->getParent()->getParent()->setColor(red);
                x=x->getParent()->getParent();
            }
            else {if(x==x->getParent()->getRight()){
                x=x->getParent();
                leftRotate(x);
            }
                x->getParent()->setColor(black);
                x->getParent()->getParent()->setColor(red);
                rightRotate(x->getParent()->getParent());
            }
        }
        else if (x->getParent() == x->getParent()->getParent()->getRight()){
            y = x->getParent()->getParent()->getLeft();
            if(y!=nil&&y->getColor()==red){
                x->getParent()->setColor(black);
                y->setColor(black);
                x->getParent()->getParent()->setColor(red);
                x = x->getParent()->getParent();
            }
            else {if(x==x->getParent()->getLeft()){
                x=x->getParent();
                rightRotate(x);
            }
                x->getParent()->setColor(black);
                x->getParent()->getParent()->setColor(red);
                leftRotate(x->getParent()->getParent());
            }
            
        }
    }
    root->setColor(black);
}

void rbTree::leftRotate(rbNode *x){
    
    rbNode *y = nil;
    if(x->getRight()!=nil){
        y = x->getRight();
        x->setRight(y->getLeft());
        if(y->getLeft()!=nil)
            y->getLeft()->setParent(x);
        y->setParent(x->getParent());
        if(x->getParent()==nil)
            root = y;
        else if (x==x->getParent()->getLeft())
            x->getParent()->setLeft(y);
        else x->getParent()->setRight(y);
        y->setLeft(x);
        x->setParent(y);
    }
}

void rbTree::rightRotate(rbNode *x){
    
    rbNode *y = nil;
    if(x->getLeft()!=nil){
        y = x->getLeft();
        x->setLeft(y->getRight());
        if(y->getRight()!=nil)
            y->getRight()->setParent(x);
        y->setParent(x->getParent());
        if(x->getParent()==nil)
            root = y;
        else if (x==x->getParent()->getLeft())
            x->getParent()->setLeft(y);
        else x->getParent()->setRight(y);
        y->setRight(x);
        x->setParent(y);
    }
}

void rbTree::printTree(rbNode *x){
    if(x!=nil){
        std::cout <<"Key:"<< x->getKey() <<", Color: ";
        if(x->getColor()==black)
            std::cout<<"black;";
        else std::cout<<"red;";
        
        std::cout<<" Left: ";
        
        if(x->getLeft()!=nil){
            std::cout<<"Key:"<<x->getLeft()->getKey()<<", Color:";
            if(x->getLeft()->getColor()==black)
                std::cout<<"black";
                else std::cout<<"red";
        }
        else std::cout<<"Null";
        
        std::cout<<"; Right: ";
        if(x->getRight()!=nil){
            std::cout<<"Key:"<<x->getRight()->getKey()<<", Color:";
            if(x->getRight()->getColor()==black)
                std::cout<<"black."<<std::endl;
            else std::cout<<"red."<<std::endl;
        }
        else std::cout<<"Null."<<std::endl;
        
        if(x->getLeft()!= nil)
        this->printTree(x->getLeft());
        if(x->getRight()!= nil)
        this->printTree(x->getRight());
    }
    else std::cout<<"Empty Tree"<<std::endl;
}

rbNode* rbTree::search(rbNode *x,int key){
    
    if(x==nil||x->getKey()==key)
        return x;
    if(x->getKey()<key)
        return search(x->getRight(),key);
    else return search(x->getLeft(),key);
}

rbNode* rbTree::min(rbNode *x){
    while (x->getLeft()!=nil)
        x = x->getLeft();
    return x;
}

rbNode* rbTree::max(rbNode *x){
    while (x->getRight()!=nil)
        x = x->getRight();
    return x;
}

rbNode* rbTree::suc(rbNode *x){
    rbNode *y = nil;
    if(x->getRight()!=nil)
        return min(x->getRight());
    y=x->getParent();
    while(y!=nil && y->getRight() == x){
        x = y;
        y = y->getParent();
    }
    return y;
}

rbNode* rbTree::pre(rbNode *x){
    rbNode *y = nil;
    if(x->getLeft()!=nil)
        return max(x->getLeft());
    y=x->getParent();
    while(y!=nil && y->getLeft() == x){
        x = y;
        y = y->getParent();
    }
    return y;
}

void rbTree::rbDel(int value){
    rbNode *node =  search(this->root,value);
    if(node!=nil)
    rbDel(node);
    else std::cout<<"No such node in the Tree."<<std::endl;
}

void rbTree::rbDel(rbNode *z){
    rbNode* y = nil;
    rbNode* x = nil;
    if(z->getRight()==nil||z->getLeft()==nil)
        y=z;
    else y=this->pre(z);
    
    if(y->getLeft()!=nil)
        x = y->getLeft();
    else x = y->getRight();
    
    x->setParent(y->getParent());
    
    if(y->getParent()==nil)
        root = x;
    else if (y == y->getParent()->getLeft())
        y->getParent()->setLeft(x);
    else  y->getParent()->setRight(x);
    
    if (y!=z)
        z->setKey(y->getKey());
    
    if(y->getColor()==black)
        rbDelFixup(x);
    
}

void rbTree::rbDelFixup(rbNode *x){
    rbNode *w = nil;
    
    while ((x->getColor()==black)&&x!=root){
       rbNode *p = x->getParent();
        if(x==p->getLeft()){
            w = p->getRight();
            if(w->getColor()==red){
                w->setColor(black);
                p->setColor(red);
                leftRotate(p);
                w = p->getRight();
            }
            if((w->getLeft()->getColor()==black)&&(w->getRight()->getColor()==black)){
                w->setColor(red);
                x = p;
            }
            else if(w->getRight()->getColor()==black){
                w->getLeft()->setColor(black);
                w->setColor(red);
                rightRotate(w);
                w = p->getRight();
            }
            else{
            w->setColor(p->getColor());
            p->setColor(black);
            w->getRight()->setColor(black);
            leftRotate(p);
            x = root;
            }
        }
        else {
            w = p->getLeft();
            if(w->getColor()==red){
                w->setColor(black);
                p->setColor(red);
                rightRotate(p);
                w = p->getLeft();
            }
            if((w->getLeft()->getColor()==black)&&(w->getRight()->getColor()==black)){
                w->setColor(red);
                x = p;
            }
            else if(w->getLeft()->getColor()==black){
                w->getRight()->setColor(black);
                w->setColor(red);
                leftRotate(w);
                w = p->getLeft();
            }
            else{
            w->setColor(p->getColor());
            p->setColor(black);
            w->getLeft()->setColor(black);
            rightRotate(p);
                x = root;}
            
        }
        
    }
    x->setColor(black);
}
