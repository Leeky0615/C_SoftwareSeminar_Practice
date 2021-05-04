#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
typedef struct contact {
    char name[32];
    char phone[32];
} CONTACT;

int main(void) {
    CONTACT *contacts[MAX] = {NULL};
    int count = 0;
    char name[32];
    int i;

    int found;

    while (true) {
        printf("Search Name :  ");
        gets_s(name, sizeof(name));
        if (strcmp(name, ".") == 0) break;

        found = -1;
        for (i = 0; i < count + 1; i++) {
            if (strcmp(name, contacts[i]->name) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            if (count < MAX) {
                char saveOpt;
                printf("This contact is not saved. Do you want to save it?(Y/N) : ");
                scanf("%c", &saveOpt);
                while (getchar() != '\n');

                if (toupper(saveOpt) == 'Y') {
                    contacts[count] = (CONTACT *) malloc(sizeof(CONTACT));
                    memset(contacts[count], 0, sizeof(CONTACT));
                    strcpy_s(contacts[count]->name, sizeof(name), name);
                    printf("Enter Phone Number : ");
                    gets_s(contacts[count]->phone, sizeof(name));
                    count++;
                } else continue;
            } else printf("You can't save contact anymore.\n");
        } else {
            printf("Found Phone Number : ");
            puts(contacts[found]->phone);
        }
        printf("\n");
    }

    for (i = 0; i < count; ++i) {
        free(contacts[i]);
        contacts[i] = NULL;
    }
    return 0;
}