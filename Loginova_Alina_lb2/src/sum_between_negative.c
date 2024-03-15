#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"

int sum_between_negative(int arr[], int size){
    int i, sum = 0,
        first_index = index_first_negative(arr, size),
        last_index = index_last_negative(arr, size);

    if (first_index == -1 || last_index == -1)
        return -1;
    for(i = first_index; i < last_index; ++i)
        sum += abs(arr[i]);

    return sum;
}