#include <stdlib.h>
#include <stdio.h>

/**
 * It receives a sorted array, its size, the element to be fetched and the initial and final indexes of the array
 * Find the middle of the array (or subarray)
 * Checks if the element is in the middle, if not, look for it on the left or right side of the array
 */
int binary_search(int *array, int size, int element, int begin, int end)
{
    if (end >= begin)
    {
        int mid = (end + begin) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        else if (element > array[mid])
        {
            return binary_search(array, size, element, mid + 1, end);
        }
        else if (element < array[mid])
        {
            return binary_search(array, size, element, begin, mid - 1);
        }
    }
}

/**
 * Receives an empty array, array size, and index for recursion
 * Receives the values of each array index
 */
void reading_array(int *array, int size, int i)
{
    if (i < size)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
        reading_array(array, size, ++i);
    }
}

/**
 * Function for debugging
 * It receives an array, the size of the array and an index for the recursion
 * Displays the values of each array index
 */
void printing_array(int *array, int size, int i)
{
    if (i < size)
    {
        printf("Array[%d] = %d\n", i, array[i]);
        printing_array(array, size, ++i);
    }
}

int main()
{
    int size;
    printf("Size: \n");
    scanf("%d", &size);

    int array[size];
    reading_array(array, size, 0);
    // printing_array(array, size, 0); // DEBUG

    /** Element to be searched */
    int element;
    printf("\nElement: \n");
    scanf("%d", &element);

    /** Index of the array that the element is */
    int index = binary_search(array, size, element, 0, size - 1);
    printf("\nIndex: %d\n", index);

    return 0;
}