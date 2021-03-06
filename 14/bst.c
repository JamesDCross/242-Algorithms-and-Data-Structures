#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"



struct bst_node { /* should live in bst.c */
    char *key;
    bst left;
    bst right;
};




int bst_search(bst b, char *searchKey){
    int output = 0;
    if(b == NULL){
        return 0;
    }

    if(strcmp(b->key,searchKey)==0){
        return 1;
    }

    if(strcmp(b->key,searchKey) < 0){
        output = bst_search(b->right, searchKey);
    }

    if(strcmp(b->key,searchKey) > 0){
        output = bst_search(b->left, searchKey);
    }
    return output;
}

bst bst_delete(bst b,char *deleteKey){
    bst successor;
    
    char *tmp;  
    if(b == NULL){
        return b;
    }
    
    if(strcmp(deleteKey,b->key) < 0){
        b->left = bst_delete(b->left,deleteKey);
    }
    
    if(strcmp(deleteKey,b->key) > 0){
        b->right = bst_delete(b->right,deleteKey);
    }else{
        /*Case 1: no child*/
        if(b->left == NULL && b->right==NULL){
            free(b->key);
            free(b);
            b=NULL;
        }
        /*Case 2: One child*/
        else if(b->left ==NULL){
            
            free(b->key);
            free(b);
            return b->right;
        }
        else if(b->right ==NULL){
            /* temp = b;
               b = b->left;*/
            free(b->key);
            free(b);
            return b->left;
        }
        /*Case 3: 2 children*/
        else{
            successor = b->right;
            while(successor->left != NULL){
                successor = successor->left;
            }
            tmp = b->key;
            b->key = successor->key;
            successor->key = tmp;
            b->right = bst_delete(b->right, deleteKey);/*could be in findmin but this makes it "recursive"*/
        }
    }

    return b;
}


bst bst_new(){
    return NULL;

}

void bst_inorder(bst b, void f(char *s)){
    if(b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *s)){
    if(b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right,f);
}

bst bst_insert(bst b, char *insertKey){

    if(b ==NULL){

        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(insertKey)+1) * sizeof insertKey[0]);

        strcpy(b->key, insertKey);

        b->left = bst_new();
        b->right = bst_new();

    }
    /*this ment that everytime it copied it was the same*/
    /*if(strcmp(b->key,insertKey)==0){
      printf("fail");
      return 0;
      }*/
    /*the above is implied by these two if statements if its equal nothing happens*/
	
    if(strcmp(insertKey,b->key) < 0){

	b->left = bst_insert(b->left, insertKey);
	/*printf("insert left");*/
    }

    if(strcmp(insertKey,b->key) > 0){

	b->right = bst_insert(b->right, insertKey);
	/*printf("insert right");*/
    }

    return b;
}



bst bst_free(bst b){
    if(b == NULL){
        return b;
    }

    b->left = bst_free(b->left);
    b->right = bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}


