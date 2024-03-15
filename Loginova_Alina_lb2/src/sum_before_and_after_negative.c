#include <stdlib.h>
#include "sum_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"

int sum_before_and_after_negative(int arr[], int size){
    int i, sum = 0,
        first_index = index_first_negative(arr, size),
        last_index = index_last_negative(arr, size);

    if (first_index == -1 || last_index == -1)
        return -1;
    for(i = 0; i < first_index; ++i)
        sum += abs(arr[i]);
    for(i = last_index; i < size; ++i)
        sum += abs(arr[i]);

    return sum;
}