#include <stdio.h>

int insertion_sort(int* arr, int length)
{
    int indexMinValue;
    int minValue;
    int times_sorted = 0;

    for (int i = 0; i < length - 1; i++)
    {
        indexMinValue = i;
        minValue = arr[i];
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < minValue)
            {
               indexMinValue = j;
               minValue = arr[j];
            }
        }
        int buffer = arr[i];
        arr[i] = arr[indexMinValue];
        arr[indexMinValue] = buffer;
        times_sorted++;
    }
    return times_sorted;
}

int bubble_sort(int* arr, int length)
{
    int sorted = 1;
    int times_sorted = 0;

    while (sorted != 0)
    {
        sorted = 0;
        for (int i = 0; i < length - 1; i++)
        {
           if (arr[i] > arr[i + 1])
           {
               int buffer = arr[i];
               arr[i] = arr[i + 1];
               arr[i + 1] = buffer;
               sorted = 1;
               times_sorted++;
           }
        }
    }

    return times_sorted;
}

void print_array(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int length = 10;
    int arr [] = {3, 4, 2, 1, 5, 10, 7, 3, 11, 0};

    // bubble sort
    int times_sorted = bubble_sort(arr, length);
    printf("Bubble sort: \n");
    print_array(arr, length);
    printf("\nTimes sorted: %d", times_sorted);

    // insertion sort
    times_sorted = insertion_sort(arr, length);
    printf("\nInsertion sort: \n");
    print_array(arr, length);
    printf("\nTimes sorted: %d", times_sorted);
    
    return 0;
}
