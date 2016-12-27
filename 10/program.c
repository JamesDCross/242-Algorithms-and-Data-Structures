#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"/*links this to mylib h and therefore mylib c*/
static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
void array_sort(int* a, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
	{
            temp = a[i];
            j = i - 1;
            while ((temp < a[j]) && (j >= 0))
		{
                    a[j + 1] = a[j];
                    j = j - 1;
		}
            a[j + 1] = temp;
	}
}



int main(void) {
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);

    /*doubling the size fo the array if its full*/
    
    while (1 == scanf("%d", &item)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);


        }
        /*copying items over*/
        my_array[itemcount++] = item;
    }
    array_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);
    return EXIT_SUCCESS;
}

