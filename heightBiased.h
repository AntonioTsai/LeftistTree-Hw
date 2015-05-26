//
//  heightBiased.h
//  LeftistTree
//
//  Created by Antonio Tsai on 2015/5/25.
//
#include <stdio.h>
#define SWAP(a, b, t) {t = a; a = b; b = t;}

typedef struct leftist *leftistTree;
struct leftist
{
    leftistTree	leftChild;
    leftistTree	rightChild;
    int key;
    int shortest;
};

void minMeld(leftistTree *a, leftistTree *b);
void minUnion(leftistTree *a, leftistTree *b);
void insertNode(int a, leftistTree *root);
void deleteNode(leftistTree *root);