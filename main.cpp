
#include <iostream>
#include <fstream>
#include "Node.hpp"
#include "bTree.hpp"
#include "rbNode.hpp"
#include "rbTree.hpp"

using namespace std;

#define NUM 10

int main(int argc, const char * argv[]) {
    
    rbTree rbtree1;
    bTree btree1;
    int value[NUM];
    
    srand((unsigned)time(NULL));
    
    //Function test:insertion
    
    for(int i=0;i<NUM;i++){
        value[i] = rand()%100;
        std::cout<<value[i]<<"  ";
    }

    for(int i=0;i<NUM;i++){
        rbNode * rbnode = new rbNode();
        rbnode->setKey(value[i]);
        rbtree1.rbInsert(rbnode);
        std::cout<<std::endl;
        rbtree1.printTree(rbtree1.root);
        std::cout<<std::endl;
    }

     //Function test:deletion
    
    for (int i=0;i<NUM;i++){
        rbNode * rbnode1 = rbtree1.search(rbtree1.root, value[i]);
        rbtree1.rbDel(rbnode1);
        std::cout<<std::endl;
        rbtree1.printTree(rbtree1.root);
        std::cout<<std::endl;
    }
    
    //Perfomance test:insertion and deletion
    
    int SIZE = 1000, STEP = 1000, LOOP = 100;
    int maxSIZE = SIZE + LOOP*STEP;
    
    cout << "Size/"<<"RBT Insert/"<<"BST Insert/"<<"RBT Search/"<<"BST Search/"<<"RBT Delete/"<<"BST Delete"<<endl;
    
    while(SIZE < maxSIZE)
    {
        int key[SIZE];
        clock_t start, finish;

        for(int i=0;i<SIZE;i++){
            key[i] = rand()%SIZE;
        }
        cout << SIZE << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            rbtree1.rbInsert(key[i]);
        finish = clock();
        cout << (finish - start) << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            btree1.insert(key[i]);
        finish = clock();
        cout << (finish - start) << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            rbtree1.search(rbtree1.root, key[i]);
        finish = clock();
        cout << (finish - start) << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            btree1.search(btree1.root,key[i]);
        finish = clock();
        cout << (finish - start) << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            rbtree1.rbDel(key[i]);
        finish = clock();
        cout << (finish - start) << '\t';
        
        start = clock();
        for( int i = 0 ; i < SIZE; i ++)
            btree1.del(key[i]);
        finish = clock();
        cout << (finish - start) << endl;
        
        SIZE += STEP;
    }
    return 0;
    
}

