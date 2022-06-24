#include <stdio.h>
#include <stdlib.h>

int qs_times_sorted = 0;
int ms_times_sorted = 0;
int times_sorted = 0;

void merge_sorted_arrays(int array[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = array[left + i];
    }
    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = array[middle + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        ms_times_sorted++;
        if ((i < left_length) && 
                (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            array[k] = temp_left[i];
            i++;
        }
        else
        {
            array[k] = temp_right[j];
            j++;
        }

    }
}

void merge_sort_recursive(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);

        merge_sorted_arrays(array, left, middle, right);
    }
}

void merge_sort(int array[], int length)
{
    merge_sort_recursive(array, 0, length - 1);
}

void fill_arr_with_rand_nums(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand();
    }
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int low, int high)
{
    int pivot_value = array[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        qs_times_sorted++;
        if (array[j] <= pivot_value)
        {
            swap(&array[j], &array[i]);
            i++;
        }
    }

    swap(&array[i], &array[high]);

    return i;
}

void quick_sort_recursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);

        quick_sort_recursion(array, low, pivot_index - 1);
        quick_sort_recursion(array, pivot_index + 1, high);
    }
}

void quick_sort(int array[], int length)
{
    quick_sort_recursion(array, 0, length - 1);
}

int insertion_sort(int arr[], int length)
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
            times_sorted++;
            if (arr[j] < minValue)
            {
               indexMinValue = j;
               minValue = arr[j];
            }
        }
        int buffer = arr[i];
        arr[i] = arr[indexMinValue];
        arr[indexMinValue] = buffer;
    }

    return times_sorted;
}

int bubble_sort(int arr[], int length)
{
    int sorted = 1;
    int times_sorted = 0;

    while (sorted != 0)
    {
        sorted = 0;
        for (int i = 0; i < length - 1; i++)
        {
           times_sorted++;
           if (arr[i] > arr[i + 1])
           {
               int buffer = arr[i];
               arr[i] = arr[i + 1];
               arr[i + 1] = buffer;
               sorted = 1;
           }
        }
    }

    return times_sorted;
}

void print_array(int arr[], int length)
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
    int arr2 [] = {4, 2, 1, 3, 11, 0, 6, 5, 7, 20};
    int arr3 [] = {1, 3, 10, 2, 4, 5, 8, 6, 20, 31};
    int arr4 [] = {4, 2, 6, 9, 1, 0, 10, 5, 3, 41};

    // small numbers
    printf("---------Small numbers----------\n");
    // bubble sort
    times_sorted = bubble_sort(arr, length);
    printf("Bubble sort: \n");
    print_array(arr, length);
    printf("\nTimes sorted: %d", times_sorted);

    // insertion sort
    times_sorted = insertion_sort(arr2, length);
    printf("\nInsertion sort: \n");
    print_array(arr2, length);
    printf("\nTimes sorted: %d", times_sorted);

    // quick sort
    printf("\nQuick sort: \n");
    quick_sort(arr3, length);
    print_array(arr3, length);
    printf("\nTimes sorted: %d", qs_times_sorted);

    // merge sort
    printf("\nMerge sort: \n");
    merge_sort(arr4, length);
    print_array(arr4, length);
    printf("\nTimes sorted: %d", ms_times_sorted);

    // big guns :)
    int big_length = 20000;
    int arr1_big[big_length];
    int arr2_big[big_length];
    int arr3_big[big_length];
    int arr4_big[big_length];

    fill_arr_with_rand_nums(arr1_big, big_length);
    fill_arr_with_rand_nums(arr2_big, big_length);
    fill_arr_with_rand_nums(arr3_big, big_length);
    fill_arr_with_rand_nums(arr4_big, big_length);

    // big numbers
    printf("\n---------Big numbers----------\n");

    // bubble sort
    times_sorted = bubble_sort(arr1_big, big_length);
    printf("Bubble sort times: %d\n", times_sorted);

    // insertion sort
    times_sorted = insertion_sort(arr2_big, big_length);
    printf("Insertion sort times: %d\n", times_sorted);

    // quick sort
    qs_times_sorted = 0;
    quick_sort(arr3_big, big_length);
    printf("Quick sort times: %d\n", qs_times_sorted);

    // merge_sort
    ms_times_sorted = 0;
    merge_sort(arr4_big, big_length);
    printf("Merge sort times: %d\n", ms_times_sorted);
    
    return 0;
}
