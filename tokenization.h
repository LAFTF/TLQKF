#pragma once

#ifndef _TOKENIZATION_H
# define _TOKENIZATION_H

typedef struct {char v[13]} L13str;
typedef struct {char v[79]} L79str;
typedef union {
    L13str index[6];
    L79str const_value;
} keywords;

const L79str = {"

int is(L13str* v, L13str)

void tokenization(char* target, char* ret, int length) {
    do {
        //pass
    } while (++target);
}

#endif