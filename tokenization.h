#pragma once

#ifndef _TOKENIZATION_H
# define _TOKENIZATION_H

#include <stdbool.h>

#define ISIT_TOKEN(N) case tokens[N]: return N;
#define SETIT *ret.ptr = target
#define REPEAT(N) for (autolike i = 0; i < N; i++)
#define __CLOSES__(N) N);
#define WRTS(BUF) wrtevnt(BUF, __CLOSES__
#define WRT WRTS(buf)

#define DUPC if (v.is_txt) {\
        buffer = v.v.ptr;\
        REPEAT(v.v.length) {buffer++};\
    } else {\
        translating(v.v, buffer);\
    };

const int _pads = sizeof(char*) * 5;

typedef void* autolike;

const char symbols[5] = "+-*/";

typedef struct {char v[13]} L13str;
typedef struct {char v[66]} L66str;
typedef union {
    L13str index[6];
    L66str const_value;
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

const L66str const_value = {"에 대하여서 더한값서 빼준값서 곱한값서 나눈몫"};
const keywords* const_value_indexer = (keywords*) &const_value;
const L13str* tokens = (L13str*) &keywords;

inline char _flagof(L13str* v) {
    switch (v[0]) {
        ISIT_TOKEN(0)
        ISIT_TOKEN(1)
        ISIT_TOKEN(2)
        ISIT_TOKEN(3)
        ISIT_TOKEN(4)
        default: return 5;
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
    for (_tokenizier_i_type i = {5, 0, prev}; *target; _tokenizer_i_count(i, target)) {
        if (i.flag - 5) {
            *i.prev.length = i.length;
            SETIT;
            ret++; target += _pads;
            *ret.length = 13;
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

inline char f(tokenized_index* x) {return x -  5?flag_of(x):5;};

inline void working_parser(tokenized_index* tokenized_arr, ParseTree** tree, ParserStackType* stack, tokenized_index* ends) {
    *stack.v = tokenized_arr;
    for (char flag = 5; tokenized_arr - ends; flag = f(++tokenized_arr++)) {
        if (flag - 5) {
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

void translating(ParseTree**, char*);

inline void translate_part(paramT argv, char* buf) {
    if (argv.is_txt) {
        buf = argv.v.ptr;
        REPEAT(argv.v.length){buf++};
    } else {
        translating(argv.v, buf);
    };
}

void translating(ParseTree** ParseTree, char* buffer) {
    paramT* i = *ParseTree.xy;
    buffer = "("; buffer++;
    translate_part(i[0], buffer)
    buffer = cmd[*ParseTree.fucksuckill]; buffer++;
    translate_part(i[1], buffer)
    buffer = ")"; buffer++;
}; //O(N)

inline void translate(char* target, char* buffer, tokenized_index** tokenizes_arr, ParseTree** tree, ParserStackType* stack) {
    tokenized_index* ends = *tokenized_arr
    tokenization(target, ends);
    working_parser(*tokenized_index, tree, stack, ends);
    umm(ParseTree, buffer);
};

inline void _fnfix(char* fn, char* fixs) {
    for (;*fn;fn++) {
        *fixs = *fn=='.'?'_':*fn;
        fixs++;
    };
}

inline void _hfnc(char* fn, char* chfn) {
    *chfn = '.';
    for (;*fn;fn++) {
        *chfn = *fn;
        chfn++;
    };
}

inline autolike len(char* str) {
    autolike i = 0;
    for (;*str;str++) {i++};
    return i;
}

typedef struct {
    autolike L;
    char* strv;
} Lcharptr;

inline Lcharptr hfn(char* fn) {
    Lcharptr ret;
    ret.L = len(fn); ret.L++;
    char[ret.L] rets, bufs;
    ret.strv = rets;
    _hfnc(fn, bufs);
    _hfnc(fn, ret.strv);
    return ret;
}

typedef struct {
    char L;
    char** values;
} csrct;

inline char* _csrcti(csrct v, bool p, char i) { return v.values[v.L*p + i]; };

const char csrctvc[33] = "\x01\x02\x04\x05\x06 \n#pragmaoncendifndefine"
const char* csrctv[14] = {&csrctvc[0], &csrctvc[1], &csrctvc[4], &csrctvc[2], &csrctvc[3], &csrctvc[4], &csrctvc[4], &csrctvc[5], &csrctvc[6],
&csrctvc[8], &csrctvc[14], &csrctvc[18], &csrctvc[23], &csrctvc[27]};
char csrct csrcc = {5, &csrctv};

/**
 * 0. %20
 * 1. \n#
 * 2. pragma
 * 3. once
 * 4. endif
 * 5. ifndef
 * 6. define
 **/
inline void wrtevnt(char* buf, char idx) {
    char* txt = _csrcti(csrcc, 1, idx);
    REPEAT(*_csrcti(csrcc, 0, idx)) {
        *buf = *txt;
        buf++; txt++;
    };
}

inline void wrtfn(char* buf, char* fn) {
    for(;*fn;fn++){*buf = *fn; buf++;};
}

inline void wrtsrc(autolike L, char* src, char* buf) {
    REPEAT(L) {*buf = *src; buf++; src++;};
}

inline void wrtc(char* fn, autolike L, char* src, char* buf) {
    WRT(1)
    WRT(2)
    WRT(0)
    WRT(3)
    WRT(1)
    WRT(5)
    WRT(0)
    wrtfn(buf, fn);
    WRT(1)
    WRT(6)
    WRT(0)
    wrtfn(buf, fn); wrtsrc(L, src);
    WRT(1)
    WRT(4)
}

//wow my code sucks!! ;) sans!!

#endif