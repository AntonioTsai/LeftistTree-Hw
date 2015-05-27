//
//  heightBiased.c
//  LeftistTree
//
//  Created by Antonio Tsai on 2015/5/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "liftistTree.h"

//HBLT
void minMeld_H(leftistTree *a, leftistTree *b)
{	/*
     meld the two min leftist trees *a and *b.
     The resulting min leftist tree is returned in *a,
     and *b is set to NULL
     */
    if (!*a)
        *a = *b;
    else if (*b)
        minUnion_H(a, b);
    *b = NULL;
}

void minUnion_H(leftistTree *a, leftistTree *b)
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
        minUnion_H(&(*a)->rightChild, b);
    
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

void insertNode_H(int a, leftistTree *root)
{
    leftistTree node = (leftistTree)malloc(sizeof(struct leftist));
    node->key = a;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->shortest = 0;
    //printf("%d\n", node->key);
    minMeld_H(root, &node);
}

void deleteNode_H(leftistTree *root)
{
    if (*root) {
        leftistTree toDetele = *root;
        if (!(*root)->leftChild && !(*root)->rightChild ) {
            free(toDetele);
            (*root) = NULL;
        }
        minMeld_H(&(*root)->leftChild, &(*root)->rightChild);
        *root = (*root)->leftChild;
        printf("%d\n", toDetele->key);
        free(toDetele);
        
    }
}

//WBLT
void minMeld_W(leftistTree *a, leftistTree *b)
{	/*
     meld the two min leftist trees *a and *b.
     The resulting min leftist tree is returned in *a,
     and *b is set to NULL
     */
    if (!*a)
        *a = *b;
    else if (*b)
        minUnion_W(a, b);
    *b = NULL;
}

void minUnion_W(leftistTree *a, leftistTree *b)
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
        minUnion_W(&(*a)->rightChild, b);
    
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

void insertNode_W(int a, leftistTree *root)
{
    leftistTree node = (leftistTree)malloc(sizeof(struct leftist));
    node->key = a;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->shortest = 0;
    //printf("%d\n", node->key);
    minMeld_W(root, &node);
}

void deleteNode_W(leftistTree *root)
{
    if (*root) {
        leftistTree toDetele = *root;
        if (!(*root)->leftChild && !(*root)->rightChild ) {
            free(toDetele);
            (*root) = NULL;
        }
        minMeld_W(&(*root)->leftChild, &(*root)->rightChild);
        *root = (*root)->leftChild;
        printf("%d\n", toDetele->key);
        free(toDetele);
        
    }
}