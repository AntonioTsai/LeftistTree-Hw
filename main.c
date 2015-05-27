//
//  main.c
//  LeftistTree
//
//  Created by Antonio Tsai on 2015/5/19.

#include <stdio.h>
#include <stdlib.h>
#include "weightBiased.h"
#include "heightBiased.h"

int _print(leftistTree *parent, int is_left, int offset, int depth, char s[20][255]){
    char b[20];
    int i ,width = 5;
    
    if (!*parent) return 0;
    
    sprintf(b, " %03d ", (*parent)->key);
    
    int left  = _print(&(*parent)->leftChild,  1, offset, depth + 1, s);
    int right = _print(&(*parent)->rightChild, 0, offset + left + width, depth + 1, s);
    
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];
    
    if (depth && is_left) {
        
        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '=';
        
        s[2 * depth - 1][offset + left + width/2] = '|';
        s[2 * depth - 1][offset + left + width + right + width/2] = '|';
        
    } else if (depth && !is_left) {
        
        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '=';
        
        s[2 * depth - 1][offset + left + width/2] = '|';
        s[2 * depth - 1][offset - width / 2 - 1] = '|';
    }
    return left + width + right;
}

void printTree(leftistTree *parent){
    char s[20][255];
    int i;
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");
    
    _print(parent, 0, 0, 0, s);
    
    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}


int main(int argc, const char * argv[]) {
    FILE *sourse = fopen("left tree.txt", "r");
    
    char command;
    int num;
    leftistTree root = NULL;
    
    while (~fscanf(sourse, "%c", &command)) {
        switch (command) {
            case 'i':
                fscanf(sourse, "%d", &num);
                insertNode_H(num, &root);
                //printf("%d\n", num);
                break;
            case 'd':
                deleteNode_H(&root);
                break;
        }
    }
    printTree(&root);
    return 0;
}
