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
    int weight;
};
//HBLT
void minMeld_H(leftistTree *a, leftistTree *b);
void minUnion_H(leftistTree *a, leftistTree *b);
void insertNode_H(int a, leftistTree *root);
void deleteNode_H(leftistTree *root);
//WBLT
void minMeld_W(leftistTree *a, leftistTree *b);
void minUnion_W(leftistTree *a, leftistTree *b);
void insertNode_W(int a, leftistTree *root);
void deleteNode_W(leftistTree *root);