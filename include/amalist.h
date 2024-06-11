#pragma once
#ifndef AMALIST_H
#define AMALIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct tagAmaList {
    void** data;
    size_t count;
    size_t capacity;
} ama_list;

void AmaListInit(ama_list* v);
void AmaListResize(ama_list* v, size_t new_size);
void AmaListPushBack(ama_list* v, void* value, size_t value_size);
void* AmaListGet(const ama_list* v, size_t index);
int AmaListRemove(ama_list* v, size_t index);
void AmaListFree(ama_list* v);

#endif /* AmaListH */