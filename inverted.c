/*
 
You need to write a program in the file named inverted.c that reads data from a given collection of pages in collection.txt and generates
an "inverted index" that provides a list (set) of urls for every word in a given collection of pages. You need to "normalise" words by
removing leading and trailing spaces and converting all characters to lowercases before inserting words in your index. In each list (set),
duplicate urls are not allowed. Your program should output this "inverted index" to a file named invertedIndex.txt. The list should be
alphabetically ordered, using ascending order.
 
List_of_Urls <= GetCollection(  )
InvertedIndex invertedIdx <= GetInvertedList (List_of_Urls)
Output  invertedIdx to  “invertedIndex.txt”

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>			
#include "inverted.h"
#include "queue.h"
#include "BSTree.h"

#define MAXNAMESIZE 10
#define MAXWORDSIZE 20

/*********************************
make a queue -> get collection
make a BSTree -> getBStree

printTreetofile
*********************************/

typedef struct Node *Link;

typedef struct Node {
    char *val;
    char **vertex;
    Link  next;
} Node;

typedef struct SetRep {
    int   nelems;
    int   arraylen;
    Link  elems;
} SetRep;

int main(void){

	Queue newQ = newQueue();
	getCollection(newQ);

	BSTree newT = newBSTree();
	

	//maybe make this into it's own function?
	int counter = 1;
	char *current;
	char buffer[MAXWORDSIZE];
	char name[MAXNAMESIZE];
	FILE *fp;

	while(!emptyQueue(newQ)){
		current = leaveQueue(newQ);
		sprintf(name, "%s.txt",current);
		fp = fopen(name, "r");

		while(strcmp(buffer,"Section-2") != 0){
			fscanf(fp,%s,buff);
		}

		fscanf(fp, "%s", buff);

		while(strcmp(buffer, "#end") != 0){
			if(counter = 1){
				newT = BSTreeInsert(newT, cleanString(buffer),cleanString(current));
			}
			else {
				//BSTreeInsert(newT, CleanString(buffer),CleanString(current));
				counter = 0;
			}
			fscanf(fp,"%s",buffer);
		}
		fclose(fp);
	}
	//make extra changes to newT?

	//FILE *fpdummy;
	fp = fopen("invertedIndex.txt","w");
	assert(fp != NULL);
	printTree(tree,fp);
	fclose(fp);

    return 0;
}

/**
maybe just include normalisation in other function

void normalise(char *string){
	while(){
		*string = tolower(*string);
		string++;
	}
}
**/

//uses recursion to print BST
void printTree(BSTree t, FILE *toPrint){
	assert(t != NULL);
	printTree(t->left, toPrint);
	//showTree?
	printTree(t->right, toPrint);
}

void getCollection(Queue q){
	char buffer[MAXBUFFSIZE];
	FILE *fp;
	assert(fp != NULL);

	//prety sure a set is easier to implement.. 
	Set newS = newSet(); 				//Or Linked List?
	
	while(fscanf(fp, "%s", buffer) > 0){
		if(!isElem(newS,buffer)){
			enterQueue(q,buffer);
			//slightly edited version of set's insertInto() function
			Link curr, prev;
			int found = findNode(newS->elems,str,&curr,&prev);
			if(found) return;
			Link newN = newNode(str,0);
			newS->arraylen = 0;

			newS->nelems++;
			if(prev == NULL){
				newN->next = s->elems;
				newS->elems = new;
			}
			else{
				newN->next = prev->next;
				prev->next = newN;
			}
		}
	}
	//freeSet;
	fclose(fp);
}
