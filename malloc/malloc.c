#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int merge_sort_count = 0;

int* get_array(int size);
void random_array(int* array, int size, int range);
void print_array(int* array, int size);
void merge_sort(int* array, int size);
void merge_sort_recursive(int* array, int left, int right);
void merge_sorted_arrays(int* array, int left, int middle, int right);

int main()
{
    int size = 20000000;
    int range = 20;
    int* arr1 = get_array(size);
    random_array(arr1, size, range);

    clock_t t;
    t = clock();
    merge_sort(arr1, size);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Times sorted: %d\n", merge_sort_count);
    printf("Time taken: %fs", time_taken);

    free(arr1);

    return 0;
}

int* get_array(int size)
{
    int* a = malloc(sizeof(int) * size);

    return a;
}

void random_array(int* array, int size, int range)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        array[i] = rand() % range;
    }
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge_sort(int* array, int size)
{
    merge_sort_recursive(array, 0, size - 1);
}

void merge_sort_recursive(int* array, int left, int right)
{
    if (left < right){
        int middle = (left + right) / 2;

        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);

        merge_sorted_arrays(array, left, middle, right);
    }
}

void merge_sorted_arrays(int* array, int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int* temp_left = get_array(left_length);
    int* temp_right = get_array(right_length);

    int i, j, k;

    for (int i = 0; i < left_length; i++){
        temp_left[i] = array[left + i];
    }
    for (int i = 0; i < right_length; i++){
        temp_right[i] = array[middle + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; k++){
        merge_sort_count++;
        if (i < left_length &&
                (j >= right_length || temp_left[i] < temp_right[j])){
            array[k] = temp_left[i];
            i++;
        } else {
            array[k] = temp_right[j];
            j++;
        }
    }

    free(temp_right);
    free(temp_left);
}
