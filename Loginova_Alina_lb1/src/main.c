#include <stdio.h>
#include <stdlib.h>

int index_first_negative(int arr[], int size){
    int i;
    for(i = 0; i < size; ++i){
        if (arr[i] < 0)
            return i;
    }
    return -1;
}

int index_last_negative(int arr[], int size){
    int i;
    for(i = size - 1; i >= 0; --i){
        if (arr[i] < 0)
            return i;
    }
    return -1;
}

int sum_between_negative(int arr[], int size, int first_index, int last_index){
    int i, sum = 0;
    if (first_index == -1 || last_index == -1)
        return -1;
    for(i = first_index; i < last_index; ++i)
        sum += abs(arr[i]);
    return sum;
}

int sum_before_and_after_negative(int arr[], int size, int first_index, int last_index){
    int i, sum = 0;
    if (first_index == -1 || last_index == -1)
        return -1;
    for(i = 0; i < first_index; ++i)
        sum += abs(arr[i]);
    for(i = last_index; i < size; ++i)
        sum += abs(arr[i]);
    return sum;
}

int main(){
    int task, user_input[100] = {0}, size = 0;
    scanf("%d", &task);
    do{
        scanf("%d", &user_input[size]);
        ++size;
    } while (fgetc(stdin) != '\n' && size < 100);
    
    switch(task){
        case 0:
            printf("%d\n", index_first_negative(user_input, size));
            break;
        case 1:
            printf("%d\n", index_last_negative(user_input, size));
            break;
        case 2:
            printf("%d\n", sum_between_negative(user_input, size,
                                                index_first_negative(user_input, size),
                                                index_last_negative(user_input, size)));
            break;
        case 3:
            printf("%d\n", sum_before_and_after_negative(user_input, size,
                                                         index_first_negative(user_input, size),
                                                         index_last_negative(user_input, size)));
            break;
        default:
            printf("Данные некорректны");
            break;
    }
    return 0;
}