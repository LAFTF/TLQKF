#pragma once

#ifndef _TOKENIZATION_H
# define _TOKENIZATION_H

#include <stdbool.h>

#define ISIT_TOKEN(N) case tokens[N]: return N;
#define SETIT *ret.ptr = target
#define REPEAT(N) for (autolike i = 0; i < N; i++)

#define DUPC if (v.is_txt) {\
        buffer = v.v.ptr;\
        REPEAT(v.v.length) {buffer++};\
    } else {\
        translating(v.v, buffer);\
    };

const int _pads = sizeof(char*) * 5;

typedef void* autolike;

typedef struct {char v[12]} L12str;
typedef struct {char v[61]} L61str;
typedef union {
    L12str index[5];
    L61str const_value;
} cmdtypr;

const L61str constv = {"num.oper.addnum.oper.sunnum.oper.motnum.oper.divnum.oper.mod"};
const cmdtypr* cmdtypring = (cmdtypr*) &constv;
const L13str* cmd = *cmdtypring.index;

typedef struct {char v[13]} L13str;
typedef struct {char v[79]} L73str;
typedef union {
    L13str index[6];
    L73str const_value;
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

const L73str const_value = {"에 대하여서 더한값서 빼준값서 곱한값서 나눈값서 나눈몫"};
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

inline void working_parser(tokenized_index* tokenized_arr, ParseTree** tree, ParserStackType* stack, tokenized_index* ends) {
    *stack.v = tokenized_arr;
    for (char flag = 6; tokenized_arr - ends; flag = f(++tokenized_arr++)) {
        if (flag - 6) {
            **tree.fucksuckill = flag;
            --stack;
            **tree.xy = {stack, stack++};
            *--stack = null;
            *--stack = tree.parseTreeV;
            stack.is_txt = false;
            *tree++;
        } else {
            *stack.v = tokenized_arr;
            staxk.is_txt = true;
        };
        stack++;
    };
}//O(n)

inline void translating(ParseTree** ParseTree, char* buffer) {
    buffer = cmd[*ParseTree.fucksuckill];
    ++++++++++++buffer++++++++++++;
    buffer = "("; buffer++;
    ParamT* v = ParseTree.xy;
    DUPC
    buffer = ", "; ++buffer++; v++;
    DUPC
    buffer = ")"; buffer++;
}; //O(N)

inline void translate(char* target, char* buffer, tokenized_index** tokenizes_arr, ParseTree** tree, ParserStackType* stack) {
    tokenized_index* ends = *tokenized_arr
    tokenization(target, ends);
    working_parser(*tokenized_index, tree, stack, ends);
    umm(ParseTree, buffer);
};

//wow my code sucks!! ;) sans!!

#endif