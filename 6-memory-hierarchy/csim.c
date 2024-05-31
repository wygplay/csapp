#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "cachelab.h"

typedef struct node {
    long key;
    struct node *prev;
    struct node *next;
} Node;

typedef struct cache {
    int size;
    int MAX_SIZE;
    Node *head;
    Node *tail;
} Cache;

Cache *createCache(int maxSize) {
    Cache *cache = (Cache *)malloc(sizeof(Cache)); 
    cache->size = 0;
    cache->MAX_SIZE = maxSize;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

Node *createNode(long key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void initCache(Cache *cache, int maxSize) {
    cache->size = 0;
    cache->MAX_SIZE = maxSize;
    cache->head = NULL;
    cache->tail = NULL;
}

int isEmpty(Cache *cache) {
    return cache->size == 0;
}

int isFull(Cache *cache) {
    return cache->size == cache->MAX_SIZE;
}

void addToHead(Node *node, Cache *cache) {
    if(isEmpty(cache)) {
        cache->head = node;
        cache->tail = node;
    } else {
        cache->head->prev = node;
        node->next = cache->head;
        node->prev = NULL;
        cache->head = node;
    }
    cache->size++;
}


void moveToHead(Node *node, Cache *cache) {
    if(cache->size == 1 || cache->head == node) {
        return;
    } else if(cache->tail == node) {
        cache->tail = node->prev;
        node->prev->next = NULL;
        cache->head->prev = node;
        node->next = cache->head;
        node->prev = NULL;
        cache->head = node;
    } else {
        // 前置
        node->prev->next = node->next;
        // 后置
        node->next->prev = node->prev;
        // head
        cache->head->prev = node;
        node->next = cache->head;
        node->prev = NULL;
        cache->head = node;
    }
}

void deleteTail(Cache *cache) {
    if(isEmpty(cache)) {
        return;
    }
    Node *node = cache->tail;
    if(cache->size == 1) {
        cache->head = NULL;
        cache->tail = NULL;
    } else {
        cache->tail->prev->next = NULL;
        cache->tail = cache->tail->prev;
    }
    cache->size--;
    free(node);
    node = NULL;
}

void put(Node *node, Cache *cache) {
    if (isFull(cache)) {
        deleteTail(cache);
    }
    addToHead(node, cache);
}

void putByKey(long key, Cache *cache) {
    Node *node = createNode(key);
    put(node, cache);
}

int isPresent(long key, Cache *cache) {
    if (cache->size == 0){
        return 0;
    }
    Node *node = cache->head;
    while (node != NULL) {
        if (node->key == key) {
            moveToHead(node, cache);
            return 1;
        }
        node = node->next;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    int opt;
    int verbose = 0;
    int sets = 0;
    int lines = 0;
    int offset = 0;
    char *file = NULL;
    while ((opt = getopt(argc, argv, "s:E:b:t:hv")) != -1) {
        switch (opt) {
            case 'h':
                printf("help info;\n");
                return 1;
            case 'v':
                verbose = 1;
                break;
            case 's':
                sets = atoi(optarg);
                break;
            case 'E':
                lines = atoi(optarg);
                break;
            case 'b':
                offset = atoi(optarg);
                break;
            case 't':
                file = optarg;
                break;
            case '?':
                printf("unkown option: %c\n", optopt);
                break;
            default:
                abort();

        }
    }
    if (!(sets && lines && offset) || file == NULL) {
        printf("缺少必传参数: -s,-e,-b\n");
        return 1;
    }
    long arraySize = 1 << sets; 
    int t = 64 - sets - offset;
    if (t <= 0) {
        printf("-s,-b's sum value can't be above 64");
        exit(1);
    }
    // 解析指令
    FILE *fp;
    char line[100];
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    // 初始化cache
    long size = 1 << sets;
    printf("size: %ld\n", size);
    Cache *caches[size];
    for (long i = 0; i < size; i++) {
        caches[i] = createCache(lines);
    }
    int hits = 0;
    int misses = 0;
    int evictions = 0;
    char *hit;
    char *miss;
    char *eviction;
    while (fgets(line, 100, fp) != NULL) {
        if (line[0] != 0x20)
            continue;
        miss = "";
        eviction = "";
        hit = "";
        char a, b[20], c[10];
        sscanf(line, " %c %[^,],%s", &a, b, c);
        unsigned long b_num = strtol(b, NULL, 16);
        long c_num = atol(c);
        long key = b_num >> (sets + offset);
        unsigned long setsIndex = (b_num << t) >> (t + offset);
        Cache *cache = caches[setsIndex];
        if (a == 'I') {
            continue;
        } else if(isPresent(key, cache)) {
            if (a == 'M') {
                hits += 2;
                hit = "hit hit";
            } else {
                hits++; 
                hit = "hit";
            }
        } else {
            misses++;
            miss = "miss";
            if (isFull(cache)) {
                evictions++;
                eviction = "eviction";
            }
            putByKey(key, cache);
            if (a == 'M') {
                hits++;
                hit = "hit";
            }
        }

        if (verbose) {
            line[strlen(line) - 1] = '\0';
            printf("%s %s %s %s\n", line, miss, eviction, hit);
        }
    }
    fclose(fp);
    for (int i = 0; i < size; i++) {
        free(caches[i]);
    }
    printSummary(hits, misses, evictions);
    return 0;
}
