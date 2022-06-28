#include <stdio.h>
#include <string.h>

int get_string_length(char* string)
{
    return strlen(string);
}

void print_chars_in_string(char* string)
{
    int length = strlen(string);

    for (int i = 0; i < length; i++){
        printf("%c ", string[i]);
    }
    printf("\n");
}

int main()
{
    char my_string[] = "Hello world";

    printf("String: %s\n", my_string);
    int length = get_string_length(my_string);
    printf("String length : %d\n", length);

    print_chars_in_string(my_string);

    return 0;
}
