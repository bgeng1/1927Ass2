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

List getCollection(){
    FILE *collection = fopen("collection.txt", "r");

    char list[10]
    char save[10];

    int i;
    for (i = 0; (fscanf(collection, "%s", save) != EOF); i++)
    {
        int n;
        for (n = 0; n <= 9; n++)
        {
            list[n] = save;
            printf("%c", list[n]);
        }
    }
    fclose(collection);
}

Graph getGraph(){

}

List getInvertedList(){

}
