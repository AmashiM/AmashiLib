#include "amastr.h"

PAmaStr AmaStrCreate() {
    PAmaStr str = (PAmaStr)malloc(sizeof(AmaStr));
    if (str != NULL) {
        str->value = NULL;
        str->length = 0;
    }
    return str;
}

int AmaStrSet(PAmaStr str, const char* text) {
    if (str == NULL || text == NULL) {
        return -1;
    }
    size_t len = strlen(text);
    str->value = malloc((len + 1) * sizeof(char));
    if (str->value == NULL) {
        return -2;
    }
    strcpy((char*)str->value, text);
    str->length = len;
    return 0;
}

int AmaStrCat(PAmaStr str, const char* text) {
    if (str == NULL || text == NULL) {
        return -1;
    }
    size_t len1 = str->length;
    size_t len2 = strlen(text);
    void* newValue = realloc(str->value, (len1 + len2 + 1) * sizeof(char));
    if (newValue == NULL) {
        return -2;
    }
    str->value = newValue;
    strcpy((char*)str->value + len1, text);
    str->length = len1 + len2;
    return 0;
}

const char* AmaStrCStr(PAmaStr str) {
    if (str == NULL) {
        return NULL;
    }
    return (const char*)str->value;
}

void AmaStrFree(PAmaStr str) {
    if (str != NULL) {
        if(str->value != NULL){
            free(str->value);
            str->value = NULL;
        }
        str->length = 0;
        free(str);
    }
}

void AmaStrPrint(PAmaStr str)
{
    const char* text = AmaStrCStr(str);
    printf("%s", text);
}
