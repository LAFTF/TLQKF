#pragma once

#ifndef _TOKENIZATION_H
# define _TOKENIZATION_H

#define ISIT_TOKEN(N) case tokens[N]: return N;
#define SETIT *ret.ptr = target

const int _pads = sizeof(char*) * 5;

typedef void* autolike;
typedef struct {char v[13]} L13str;
typedef struct {char v[79]} L79str;
typedef union {
    L13str index[6];
    L79str const_value;
} keywords;

typedef struct {
    autolike length;
    char* ptr;
} tokenized_index;

typedef struct {
    char flag;
    autolike current_length;
    tokenized_index* prev;
} _tokenizier_i_type;

const L79str const_value = {"에 대하여서 더한값서 빼준값서 곱한값서 나눈값서 나눈몫"};
const keywords* const_value_indexer = (keywords*) &const_value;
const L13str* tokens = (L13str*) &keywords;

inline char _flagof(L13str* v) {
    switch (v[0]) {
        ISIT_TOKEN(0)
        ISIT_TOKEN(1)
        ISIT_TOKEN(2)
        ISIT_TOKEN(3)
        ISIT_TOKEN(4)
        ISIT_TOKEN(5)
        default: return 6;
}

inline char flag_of(char* v) { return _flagof((L13str*) v); };

inline _tokenizer_i_count(_tokenizer_i_type* i, char* x) {
    *i.flag = flag_of(*x++);
    *i.current_length++;
}

inline void tokenization(char* target, tokenized_index* ret) {
    SETIT;
    tokenized_index* prev = ret;
    ret++;
    for (_tokenizier_i_type i = {6, 0, prev}; *target; _tokenizer_i_count(i, target)) {
        if (i.flag != 6) {
            *i.prev.length = i.length;
            SETIT;
            ret++; target += _pads;
            *ret.length = 6;
            i.prev = ret;
            SETIT;
        };
    };
} //O(n)

typedef struct {
    void* v;
    bool is_txt;
} paramT; //sucks!

typedef struct {
    paramT xy[2];
    char fucksuckill;
} ParseTree;

typedef union {
    ParamT v;
    ParseTree parseTreeV;
} ParserStackType;

typedef struct {ParserStackType arr[2];} L2ParserStackType;

inline char f(tokenized_index* x) {return x -  6?flag_of(x):6;};

void working_parser(tokenized_index* tokenized_arr, ParseTree** tree, ParserStackType* stack, tokenized_index* ends) {
    register L2ParserStackType* BP = (L2ParserStackType) *stack;
    *stack.v = tokenized_arr;
    for (char flag = 6; tokenized_arr - ends; flag = f(++tokenized_arr)) {
        if (flag - 6) {
            **tree.fucksuckill = flag;
            --stack--;
            **tree.v = (L2paramT) stack;
            *++stack = tree.parseTreeV;
            *++stack = null;
            --stack--;
            *tree++;
        } else {
            *stack.v = tokenized_arr;
        };
        stack++;
    };
}

//wow my code sucks!! ;) sans!!

#endif