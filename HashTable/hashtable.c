#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 255
#define TABLE_SIZE 10

#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE];
unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void printable_table()
{
    printf("Start\n");
    for (int i=0; i<TABLE_SIZE; i++) {
        if(hash_table[i] == NULL) {
            printf("\t%i\t-----\n",i);
        }else if(hash_table[i] == DELETED_NODE) {
            printf("\t%i\tDELETED\n",i);
        }
        else {
            printf("\t%i\t%s\n",   i,hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if(p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try=(index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL) {
            hash_table[try] = DELETED_NODE;
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person * hash_table_lookup(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(hash_table[try] != NULL && 
            strcmp(hash_table[try]->name,name) == 0) {

            return hash_table[try];
        }
    }
    return NULL;
}

person * hash_table_delete(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETED_NODE) continue;
        if(hash_table[try] != NULL && strcmp(hash_table[try]->name,name) == 0) {
            person *tmp =hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
   
}

int main()
{
    init_hash_table();
    printable_table();
    person Alex = {.name = "Alex", .age = 25};
    person John = {.name = "John", .age = 30};
    person Bob = {.name = "Bob", .age = 35};
    person Tom = {.name = "Tom", .age = 40};
    person Sam = {.name = "Sam", .age = 45};
    person Harry = {.name = "Harry", .age = 50};
    person Kate = {.name = "Kate", .age = 55};
    person Sara = {.name = "Sara", .age = 60};
    person Mike = {.name = "Mike", .age = 65};
    person Diks = {.name = "Diks", .age = 70};

    hash_table_insert(&Alex);
    hash_table_insert(&John);
    hash_table_insert(&Bob);
    hash_table_insert(&Tom);
    hash_table_insert(&Sam);
    hash_table_insert(&Harry);
    hash_table_insert(&Kate);
    hash_table_insert(&Sara);
    hash_table_insert(&Mike);
    hash_table_insert(&Diks);

    printable_table();


    person *tmp = hash_table_lookup("Alex");

    if(tmp == NULL){
        printf("Not found\n");
    }else{
        printf("Found %s\n",tmp->name);
    }

    tmp = hash_table_lookup("Harry");

    if(tmp == NULL){
        printf("Not found\n");
    }else{
        printf("Found %s\n",tmp->name);
    }

    tmp = hash_table_delete("Alex");
    tmp = hash_table_lookup("Alex");

    if(tmp == NULL){
        printf("Not found\n");
    }else{
        printf("Found %s\n",tmp->name);
    }

   

    // printf("Alex => %u\n",hash("Alex"));
    // printf("John => %u\n",hash("John"));
    // printf("Bob => %u\n",hash("Bob"));
    // printf("Tom => %u\n",hash("Tom"));
    // printf("Sam => %u\n",hash("Sam"));
    return 0;
}