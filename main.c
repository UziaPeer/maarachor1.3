#include <stdio.h>
#include "StrList.h"
#include <string.h>

char* getStringFromUser() {
    int size = 10;  
    char* str = (char*)malloc(size * sizeof(char));
    if (str == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int len = 0;  
    char temp;    

    do {
        temp = getchar();
    } while (temp == ' ' || temp == '\n');

    while (temp != ' ' && temp != '\n' && temp != EOF) {
        str[len++] = temp;

        if (len == size) {
            size += 10;  
            char* newstr = realloc(str, size * sizeof(char));
            if (newstr == NULL) {
                perror("Failed to reallocate memory");
                free(str);
                exit(EXIT_FAILURE);
            }
            str = newstr;
        }

        temp = getchar();  
    }

     str[len] = '\0';  
    return str;
}
int main() {
    
    StrList* list = StrList_alloc();
    if (!list) {
        return EXIT_FAILURE;
    }

    int choice;
    do {

if (scanf("%d", &choice) != 1) {
    fprintf(stderr, "Error reading choice.\n");
    while ((choice = getchar()) != '\n' && choice != EOF) { }
    continue; 
}



        switch (choice) {
            case 1: {
                int number;
                if (scanf("%d", &number) != 1) {
    fprintf(stderr, "Error reading the number of words.\n");
    while ((number = getchar()) != '\n' && number != EOF) { }
    continue; 
}
                for (size_t i = 0; i < number; i++)
                {
                    char* data= getStringFromUser();
                    if (data[0]!='\0'&&data[0]!='\n'){
                     StrList_insertLast(list,data);
                    }
                    free(data);
                }  
                break;
            }
            case 2: {
                int index;
                if (scanf("%d", &index) != 1) {
    fprintf(stderr, "Error reading the index.\n");
    while ((index = getchar()) != '\n' && index != EOF) { } 
    continue; 
}
                char* data= getStringFromUser();
                if (data!= NULL&& data[0]!='\n')
                {
                     StrList_insertAt(list, data, index);
                     free(data);
                }
                
                break;
            }
            case 3:
                StrList_print(list);
                break;
            case 4:
                printf("%zu\n", StrList_size(list));
                break;
            case 5: {
                int index;
                if (scanf("%d", &index) != 1) {
    fprintf(stderr, "Error reading the index.\n");
    while ((index = getchar()) != '\n' && index != EOF) { }
    continue; 
}
                StrList_printAt(list, index);
                break;
            }
            case 6:
                printf("%d\n", StrList_printLen(list));
                break;
            case 7: {
                char* data= getStringFromUser();
                printf("%d\n", StrList_count(list, data));
                free(data);
                break;
            }
            case 8: {
                char* data= getStringFromUser();
                StrList_remove(list, data);
                free(data);
                break;
            }
            case 9: {
                int index;
                if (scanf("%d", &index) != 1) {
    fprintf(stderr, "Error reading the index.\n");
    while ((index = getchar()) != '\n' && index != EOF) { } 
    continue; 
}
                StrList_removeAt(list, index);
                break;
            }
            case 10:
                StrList_reverse(list);
                break;
            case 11:
                StrList_free(list);
                list = NULL; 
                break;
            case 12:
                StrList_sort(list);
                break;
            case 13:
                if (StrList_isSorted(list)==1) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            default:
                if (choice != 0) {
                }
        }
    } while (choice != 0);

    if (list) {
        StrList_free(list);
    }

    return 0;
}
