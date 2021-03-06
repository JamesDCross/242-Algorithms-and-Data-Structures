#include <stdio.h>
#include <stdlib.h>

void display_repeat(int* a, int n)
{
    int i, j,*linearNumbers,*numberOfOccurences;
    linearNumbers = malloc(n * sizeof linearNumbers[0]);
    numberOfOccurences = malloc(n * sizeof numberOfOccurences[0]);

    for (i = 0; i < n; i++)
        {
            linearNumbers[i] = i;

        }
    for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                {
                    if (i == a[j])
                        {
                            numberOfOccurences[i] += 1;
                        }
                }
        }
    for (i = 0; i < n; i++)
        {
            if (numberOfOccurences[i] > 1)
                {
                    /* printf("%d occurs %d times\n", i, numberOfOccurences[i]);*/
                    printf("%d repeats %d times\n", i, numberOfOccurences[i]-1);
                }
        }
    free(linearNumbers);
    free(numberOfOccurences);
}

int main(void)
{
    int array_size = 0;
    int* my_array;
    int i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array)
        {
            fprintf(stderr, "memory allocation failed!\n");
            return EXIT_FAILURE;
        }
    for (i = 0; i < array_size; i++)
        {
            my_array[i] = rand() % array_size;
        }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++)
        {
            printf("%d ", my_array[i]);
        }
    printf("\n");

    display_repeat(my_array, array_size);
    free(my_array);
    return EXIT_SUCCESS;
}
