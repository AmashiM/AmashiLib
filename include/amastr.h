#pragma once
#ifndef AMA_STR_H
#define AMA_STR_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct tagAmaStr {
    void** value;
    size_t length;
} AmaStr, *PAmaStr;

PAmaStr AmaStrCreate();

int AmaStrSet(PAmaStr str, const char* text);

int AmaStrCat(PAmaStr str, const char* text);

const char* AmaStrCStr(PAmaStr str);

void AmaStrFree(PAmaStr str);

void AmaStrPrint(PAmaStr str);

#endif