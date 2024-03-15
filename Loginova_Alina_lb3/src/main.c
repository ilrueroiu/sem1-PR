#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEFAULT_ARR_SIZE 1
#define DEFAULT_STRING_SIZE 1


int clear_555(char* str)
{
    if(strstr(str, " 555 ") || strstr(str, " 555.")
    || strstr(str, " 555;") || strstr(str, " 555?")
    || (strstr(str, "555 ") == str))
    {
        return 1;
    }
    return 0;
}

int main(){
    int current_arr_size = DEFAULT_ARR_SIZE, current_string_size = DEFAULT_STRING_SIZE;
    char **array = (char**)malloc(current_arr_size * sizeof(char*));
    int current_sentence = -1, current_char = 0;
    char symbol, *temp;

    do
    {   
        // Проверка на наличие памяти
        if (current_sentence >= current_arr_size)
            {
                current_arr_size *= 2;
                array = (char**)realloc(array, current_arr_size * sizeof(char*));
            }


        current_sentence++;
        array[current_sentence] = (char*)malloc(current_string_size * sizeof(char));

        do
        {
            // Проверка на наличие памяти
            if (current_char >= current_string_size)
            {
                current_string_size *= 2;
                array[current_sentence] = (char*)realloc(array[current_sentence], current_string_size * sizeof(char));
            }


            // Считывание символа
            symbol = getc(stdin);


            // Убирает whitespaces в начале предложения
            if (!(current_char == 0 && (symbol == ' ' || symbol == '\t' || symbol == '\n')))
            {
            array[current_sentence][current_char] = symbol;
            current_char++;
            }


            // Проверка на терминальное предложение
            temp = array[current_sentence];
            temp[current_char] = '\0';
            if(strcmp("Dragon flew away!", temp) == 0)
            {
                break;
            }


        } while(symbol != '.' && symbol != '?' && symbol != ';');


    array[current_sentence][current_char] = '\0';
    current_char = 0;


    } while(strcmp("Dragon flew away!", array[current_sentence]) != 0);

    int amount = current_sentence, upgraded_amount = -1;

    int i;

    for(i = 0; i < current_sentence + 1; ++i)
    {  

        if (clear_555(array[i]) == 0)
        {
            upgraded_amount++;
            printf("%s\n", array[i]);

        }


    }

    printf("Количество предложений до %d и количество предложений после %d\n", amount, upgraded_amount);

    return 0;
}