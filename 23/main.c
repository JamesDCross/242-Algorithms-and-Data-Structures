#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"

int main(void){

   int num;
   graph g;
   int u;
   int v;
   scanf("%d", &num);
   g = graph_new(num);
   while(2 == scanf(" %d %d",&u,&v)){
      graph_directional_edge(g,u,v);
   }
   graph_dfs(g);
   graph_print(g);
   graph_free(g);
   return EXIT_SUCCESS;
}
