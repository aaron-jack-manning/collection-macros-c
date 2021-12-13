#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAY_H
#define ARRAY_H

#define DECLARE_ARRAY(type, typecapitalised) \
    struct type##Array \
    { \
        int length; \
        type *data; \
    }; \
    typedef struct type##Array *typecapitalised##Array; \
    \
    typecapitalised##Array type##ArrayNew(int length, type initialValue) \
    { \
        typecapitalised##Array newArray = malloc(sizeof (struct type##Array)); \
        newArray->data = malloc(sizeof (type) * length); \
        newArray->length = length; \
    \
        for (int i = 0; i < length; i++) \
        { \
            *(newArray->data + i) = initialValue; \
        } \
    \
        return newArray; \
    } \
    \
    type type##ArrayGet(typecapitalised##Array array, int index) \
    { \
        if (index < 0 || index >= array->length) \
        { \
            fprintf(stderr, "Index was outside the bounds of the array.\n"); \
            exit (-1); \
        } \
    \
        return *(array->data + index); \
    } \
    \
    void type##ArraySet(typecapitalised##Array array, int index, type value) \
    { \
        if (index < 0 || index >= array->length) \
        { \
            fprintf(stderr, "Index was outside the bounds of the array.\n"); \
            exit (-1); \
        } \
    \
        *(array->data + index) = value; \
    } \
    \
    void type##ArrayFree(typecapitalised##Array array) \
    { \
        free(array->data); \
        free(array); \
    } \

#endif