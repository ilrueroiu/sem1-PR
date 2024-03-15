#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"
#include "sum_before_and_after_negative.h"

#define ARR_SIZE 100

int main(){
    int task, user_input[ARR_SIZE] = {0}, size = 0;
    scanf("%d", &task);
    do{
        scanf("%d", &user_input[size]);
        ++size;
    } while (fgetc(stdin) != '\n' && size < ARR_SIZE);
    
    switch(task){
        case 0:
            printf("%d\n", index_first_negative(user_input, size));
            break;
        case 1:
            printf("%d\n", index_last_negative(user_input, size));
            break;
        case 2:
            printf("%d\n", sum_between_negative(user_input, size));
            break;
        case 3:
            printf("%d\n", sum_before_and_after_negative(user_input, size));
            break;
        default:
            printf("Данные некорректны");
            break;
    }
    return 0;
}