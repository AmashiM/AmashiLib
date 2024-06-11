#include "encode_base.h"

static char base16_alphabet[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F'
};

char *encode_base_16(const char *text)
{
    size_t len = strlen(text);
    char* out = (char*)malloc(sizeof(char) * (len * 2) + 1);
    if(out == NULL){
        printf("failed to allocate space for base16 conversion.\n");
        return NULL;
    }
    for(size_t i = 0; i < len; i++){
        char c = text[i];
        uint8_t a = (uint8_t)(c & 0b11110000) >> 4;
        uint8_t b = (uint8_t)(c & 0b00001111);
        size_t pos = i * 2;
        out[pos] = base16_alphabet[a];
        out[pos+1] = base16_alphabet[b];
    }
    out[len * 2] = '\0';
    return out;
}

char base_16_decode_single(char c){
    char out = 0;
    if(c >= '0' && c <= '9') {
        out = c - '0';
    } else if (c >= 'A' && c <= 'F'){
        out = c - 'A' + 10;
    }
    return out;
}

char *decode_base_16(const char* text){
    size_t len = strlen(text);
    size_t real_len = (len - 1) / 2;
    char* out = (char*)malloc(sizeof(char) * (real_len + 1));
    if(out == NULL){
        printf("failed to decode text\n");
        return NULL;
    }
    for(size_t i = 0; i < (real_len + 1); i++){
        size_t pos = i * 2;
        uint8_t a = base_16_decode_single(text[pos]);
        uint8_t b = base_16_decode_single(text[pos+1]);
        char c = (a << 4) | b;
        out[i] = c;
    }
    out[real_len+1] = '\0';
    return out;
}