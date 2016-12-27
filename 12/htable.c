#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"

struct htablerec{
   int capacity;
   int *frequency;
   int num_keys;
   char **keys;
};

htable htable_new(int capacity){
   int i;
   /*this is run at compile time so it all it does is set aside memory for the future htable object*/
   htable hash = emalloc(sizeof *hash);
   /*size of returns the int the memory hash is pointing to*/
   hash->capacity = capacity;
   hash->num_keys = 0;
	
   hash->frequency = emalloc(capacity * sizeof hash->frequency[0]);
   hash->keys = emalloc(capacity * sizeof hash->keys[0]);
   for(i = 0; i < capacity; i++){
      hash->frequency[i] = 0;/*fill with zeros*/
      hash->keys[i] = NULL; /*fill with nulls*/
   }
   return hash;
}

void htable_free(htable h ){
   int i;
   
   for(i = 0; i < h->capacity; i++){
      if(NULL != h->keys[i]){
         free(h->keys[i]);
      }
   }
   free(h->keys);
   free(h->frequency);
   free(h);
}

/*given method*/
static unsigned int htable_word_to_int(char *word) {
unsigned int result = 0;
 
while (*word != '\0') {
	
    result = (*word++ + 31 * result);
    /*this is incrementing the pointer (which moves along the char array)r*/
}
return result;
}

int htable_insert(htable h, char *str){
   int i = htable_word_to_int(str) % h->capacity;
   int wrap = i;
   

	/*3. A string is at that position, but it isn’t the right one.*/
	/*this method just increments the i along until the condition is not met
	at which point it will fall down to condition a or b.(its basically scanning 
	through unitl the condition is not met).
	*/
      while(h->keys[i] != NULL && strcmp(h->keys[i],str) != 0){
      /*increment*/
	  i++;
	  /*mod by table capacity--to wrap around*/
      i = i % h->capacity;
	  /*so if it wraps around back into itself and the conditions still hold*/
	  /*return 0 the table is full*/
      if(i == wrap){
      return 0;
	  /*0 also EXIT_SUCCESS*/
      }
   }
   

   
   /*1(a). There is no string at that position. - enter key*/
   if(h->keys[i] == NULL){ 
      h->keys[i] = emalloc((strlen(str)+1) * sizeof h->keys[0][0]);
      strcpy(h->keys[i], str);
	  h->frequency[i]++; /*"set freq to 1"*/
      h->num_keys++;
      return h->frequency[i];/*was not returning freq so just dropped through
                              and edit freq in the next if statement*/
   }

   

	/*2(b). The exact same string is at that position. - up the frequency*/
   if(strcmp(h->keys[i],str) == 0){
      h->frequency[i]++;
	  return h->frequency[i];
   }
   return 0;

}

void htable_print(htable h, FILE *stream){
   int i;
   for(i = 0; i < h->capacity; i++){
	   /*dont print nulls*/
      if(h->keys[i] != NULL){
         fprintf(stream, "%d ", h->frequency[i]);
         fprintf(stream, "%s\n", h->keys[i]);
      }
   }
}

int htable_search(htable h, char *str){
	/*create, and initialise, a value to hold the number of collisions*/
   int collisions = 0;
   /*calculate the position at which we should start looking for our key*/
   int i = htable_word_to_int(str) % h->capacity;
   
   int wrap = i;
   /*while there is an item at that position, but it isn't the key,*/
   while(h->keys[i] != NULL && strcmp(h->keys[i],str) != 0 && i!=wrap){
      
	  /*increment*/
      i++;
	  /*wrap around*/
      i = i % h->capacity;
      
	  collisions++;
	  /*check if we are back at the start*/
	  /*and we haven't yet checked the entire hashtable */
	  /*if(i == wrap){
		  exit the while loop because weve looked at whole hashtable
     
	  
      }*/
      
   }
   if(collisions == h->capacity){
         return 0;
      }else{
		return h->frequency[i];  
	  }
   }






