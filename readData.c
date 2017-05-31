/*
pseudocode i guess?!

List_of_Urls <-- GetCollection(	)
  Create	a	set	(list)	of	urls to	process	by	reading	data	from	file	
  “collection.txt”
  
Graph	g	<-- GetGraph(List_of_Urls )
  Create	empty	graph	(use	graph	ADT	in	say	graph.h and	graph.c)
  For	each	url in	the	above	list	
    • read	<url>.txt	file,	and	update	graph	by	adding	a	node	and	
      outgoing	links	
      
InvertedList <-- GetInvertedList(List_of_Urls )
  Create	empty	inverted	list	(use	say	List	of	lists,	BST	where	values	are	
  lists,	etc)
  For	each	url in	List_of_Urls
    • read	<url>.txt	file,	and	update	inverted	index	
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "readData.h"
#include "graph.h"

#define urlLength 100
#define listLength 100
#define MAXNAMESIZE 20
#define MAXWORDSIZE 30


typedef char** List;
//need to typedef a list (array of strings) - how to do that?
List getCollection(FILE *collection){

    char urlList[listLength][urlLength];
    int i;

  
    for (i = 0; (fscanf(collection, "%s", urlList[i]) != EOF); i++)
    {
            //printf(" %s \n", urlList[i]);
        strcat(urlList[i],".txt");
        if(strcmp(urlList[i],"Section-1")==0) i = -1;
        if(strcmp(urlList[i],"#end")==0) break;
        
    }
    //fclose(collection);
    char **temp = (char**)urlList;
    return temp;
}

Graph getGraph(List collection){
  printf("im in getgraph \n");
  Graph new = newGraph(50);
  char listOutbound[50][50];
  int i,n = 0,x,y;
  char **names = malloc(sizeof(char)*1000); 
  //printf("variables set \n");
  for(i = 0; strcmp(collection[n],"#end")!=0; i++){
  	//will have .txt on the end (need to fix)
	     addVertex(collection[i],names,i);
  }
  printf("vertex added \n");
  for(n = 0; strcmp(collection[n],"#end")!= 0 ;n++){
        FILE *urlFile = fopen(collection[n],"r");
        for(x = 0; (fscanf(urlFile, "%s", listOutbound[x]))!=EOF; x++)
        {
          if(strcmp(listOutbound[i],"Section-1")==0) x = -1;
          if(strcmp(listOutbound[i],"#end")==0) break;

        }
        printf("reached end of document for %dth url of the collection \n",n);
	     for(y = 0; strcmp(listOutbound[y],"#end")!=0; y++)
	     {
		      addEdge(new, collection[n],listOutbound[x]);
		
    	 }	
       printf("added all outgoing edges for above url \n");
  }
  return new;
}

List getInvertedList(BSTree todoT, Queue todoQ){
	int counter = 1;
	char *current;
	char buffer[MAXWORDSIZE];
	char name[MAXNAMESIZE];
	FILE *fp;

	while(!emptyQueue(todoQ)){
		current = leaveQueue(todoQ);
		sprintf(name, "%s.txt",current);
		fp = fopen(name, "r");

		while(strcmp(buffer,"Section-2") != 0){
			fscanf(fp,%s,buff);
		}

		fscanf(fp, "%s", buff);

		while(strcmp(buffer, "#end") != 0){
			if(counter = 1){
				todoT = BSTreeInsert(todoT, cleanString(buffer),cleanString(current));
			}
			else {
				//BSTreeInsert(newT, CleanString(buffer),CleanString(current));
				counter = 0;
			}
			fscanf(fp,"%s",buffer);
		}
		fclose(fp);
	}
}
