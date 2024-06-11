#pragma once
#ifndef ENCODE_BASE_H
#define ENCODE_BASE_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

char *encode_base_16(const char *text);
char base_16_decode_single(char c);
char *decode_base_16(const char* text);

#endif
