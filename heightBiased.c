//
//  heightBiased.c
//  LeftistTree
//
//  Created by Antonio Tsai on 2015/5/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "heightBiased.h"

void minMeld(leftistTree *a, leftistTree *b)
{	/*
     meld the two min leftist trees *a and *b.
     The resulting min leftist tree is returned in *a,
     and *b is set to NULL
     */
    if (!*a)
        *a = *b;
    else if (*b)
        minUnion(a, b);
    *b = NULL;
}

void minUnion(leftistTree *a, leftistTree *b)
{	/*
     recursively combine two nonempty min leftist trees
     */
    leftistTree temp;
    //set a to be the tree with smaller root
    if((*a)->key > (*b)->key)
        SWAP(*a, *b, temp);
    
    /* create binary tree such that the smallest key in each subtree is the root */
    if(!(*a)->rightChild)
        (*a)->rightChild = *b;
    else
        minUnion(&(*a)->rightChild, b);
    
    //leftist tree property
    if(!(*a)->leftChild)
    {
        (*a)->leftChild = (*a)->rightChild;
        (*a)->rightChild = NULL;
    }
    else if((*a)->leftChild->shortest < (*a)->rightChild->shortest)
        SWAP((*a)->leftChild, (*a)->rightChild, temp);
    (*a)->shortest = (!(*a)->rightChild) ? 1 : (*a)->rightChild->shortest + 1;
    
}

void insertNode(int a, leftistTree *root)
{
    leftistTree node = (leftistTree)malloc(sizeof(struct leftist));
    node->key = a;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->shortest = 0;
    //printf("%d\n", node->key);
    minMeld(root, &node);
}

void deleteNode(leftistTree *root)
{
    if (*root) {
        leftistTree toDetele = *root;
        if (!(*root)->leftChild && !(*root)->rightChild ) {
            free(toDetele);
            (*root) = NULL;
        }
        minMeld(&(*root)->leftChild, &(*root)->rightChild);
        *root = (*root)->leftChild;
        printf("%d\n", toDetele->key);
        free(toDetele);
        
    }
}