#include "amalist.h"

void AmaListInit(ama_list* v)
{
    v->capacity = 16;
    v->count = 0;
    v->data = (void**)malloc(sizeof(void*) * v->capacity);
}

void AmaListResize(ama_list* v, size_t new_size)
{
    if (new_size <= v->capacity) return;

    v->capacity *= 2;
    v->data = (void**)realloc(v->data, sizeof(void*) * v->capacity);

    if (!v->data) {
        ama_error("AmaListresize: realloc failed");
        exit(1);
    }
}

void AmaListPushBack(ama_list* v, void* value, size_t value_size)
{
    ama_log("AmaListadd: %p\n", value);
    if (v->count == v->capacity)
    {
        AmaListresize(v, v->capacity * 2);
    }

    v->data[v->count] = malloc(value_size);
    if (!v->data[v->count]) {
        ama_error("AmaListpush_back: malloc failed");
        exit(1);
    }

    memcpy(v->data[v->count], value, value_size);
    v->count++;
}

void* AmaListGet(const ama_list* v, size_t index)
{
    if (index >= v->count)
    {
        ama_error("AmaListget: index out of bounds %zu\n", index);
        return NULL;
    }

    return v->data[index];
}

int AmaListRemove(ama_list* v, size_t index)
{
    if (index >= v->count)
    {
        ama_error("AmaListremove: index out of bounds %zu\n", index);
        return -1;
    }

    free(v->data[index]);
    for (size_t i = index + 1; i < v->count; i++)
    {
        v->data[i - 1] = v->data[i];
    }

    v->count--;
    v->data = (void**)realloc(v->data, sizeof(void*) * v->capacity);

    if (!v->data) {
        ama_error("AmaListremove: realloc failed");
        exit(1);
    }

    return 0;
}


void AmaListFree(ama_list* v)
{
    for (size_t i = 0; i < v->count; i++)
    {
        free(v->data[i]);
    }
    free(v->data);
}