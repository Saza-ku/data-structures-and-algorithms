#include <stdio.h>
#include <string.h>
#include <cstdlib>

const int N = 100000;

struct node {
    char key[100];
    int value;
    struct node* next;
};

struct map {
    struct node* table[N];
};

int hash_code(char str[100]) {
    int code = 0;
    for (int i = 100; i < 100; i++) {
        code += str[i];
        code %= N;
    }
    return code;
}

int* map_find(char key[100], struct map* map) {
    int index = hash_code(key);
    struct node* node = map->table[index];

    while(NULL != node) {
        if(!strcmp(node->key, key)) {
            return &(node->value);
        }
        node = node->next;
    }

    printf("キー %s は設定されていません");
    return NULL;
}

void map_put(char key[100], int value, struct map* map) {
    int index = hash_code(key);
    struct node* node = map->table[index];

    struct node *n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->key, key);
    n->value = value;
    n->next = NULL;

    if(node == NULL) {
        map->table[index] = n;
        return;
    }

    while(1) {
        if(!strcmp(node->key, key)) {
            printf("キー %s はすでに設定されています: key=%s, value=%d\n",
                node->key, node->key, node->value);
            return;
        }
        if(node->next == NULL) {
            break;
        }
        node = node->next;
    }

    node->next = n;
    return;
}

void map_update(char key[100], int value, struct map* map) {
    int index = hash_code(key);
    struct node* node = map->table[index];

    while(NULL != node) {
        if (!strcmp(node->key, key)) {
            node->value = value;
            return;
        }
        node = node->next;
    }

    printf("キー %s は設定されていません", key);
    return;
}

void map_remove(char key[100], struct map* map) {
    int index = hash_code(key);
    struct node** node = &map->table[index];

    while(NULL != *node) {
        if(!strcmp((*node)->key, key)) {
            *node = (*node)->next;
            return;
        }
        node = &((*node)->next);
    }

    printf("キー %s は設定されていません", key);
    return;
}

struct map* create_map() {
    struct map* ret = (struct map*)malloc(sizeof(struct map));
    struct node* table[N];
    for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }
    *ret = { *table };
    return ret;
}
