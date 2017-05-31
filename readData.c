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

//need to define a list (array of strings) - how to do that?
List getCollection(FILE *collection){

    char urlList[listLength][urlLength];

    int i;
    for (i = 0; (fscanf(collection, "%s", list[i]) != EOF); i++)
    {
            //printf(" %s \n", list[i]);
        
    }
    //fclose(collection);
    return urlList;
}

Graph getGraph(List collection){
  Graph new = newGraph(100);
  int i = 0;
  collection[i]??
  return new;
}

List getInvertedList(){

}
