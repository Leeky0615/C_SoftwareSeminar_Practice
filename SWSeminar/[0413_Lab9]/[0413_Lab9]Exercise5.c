#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
    char name[32];
    char phone[32];
} CONTACT;

CONTACT* AllocateContacts(int count);
void InputContacts(CONTACT *contacts, int count);
void PrintContacts(const CONTACT contacts, int count);

int main(void){
    CONTACT *contacts = NULL;
    int count = 0;

    printf("Number of contacts to save : ");
    scanf("%d", &count);
    while (getchar() != '\n');

    contacts = AllocateContacts(count);
    if(contacts==NULL) return -1;

    InputContacts(contacts, count);
    PrintContacts(contacts, count);

    free(contacts);
    contacts = NULL;
    return 0;
}

CONTACT* AllocateContacts(int count){
    CONTACT *result = NULL;
    result = (CONTACT *) malloc(sizeof(CONTACT) * count);
    if(result==NULL) printf("Dynamic memory allocation failed\n");
    else memset(result, 0, sizeof(CONTACT) * count);
    return result;
}
void InputContacts(CONTACT* contacts, int count){
    for (int i = 0; i < count; ++i) {
        printf("name : ");
        gets_s(contacts[i].name);
        printf("phone : ");
        gets_s(contacts[i].phone);
    }
}
void PrintContacts(const CONTACT* contacts, int count){
    printf(" --- Full Contact List ---\n");
    for (int i = 0; i < count; ++i) {
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}