#include <stdlib.h>
#include <stdio.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#define DECLARE_DOUBLY_LINKED_LIST(type, typecapitalised) \
    \
    struct type##DLListNode \
    { \
        type data; \
        struct type##DLListNode *next; \
        struct type##DLListNode *prev; \
    }; \
    typedef struct type##List* typecapitalised##DLList; \
    struct type##List \
    { \
        int length; \
        struct type##DLListNode *first; \
        struct type##DLListNode *last; \
    }; \
    \
    typecapitalised##DLList type##ListNew() \
    { \
        typecapitalised##DLList list = malloc(sizeof (struct type##List)); \
    \
        list->length = 0; \
        list->first = NULL; \
        list->last = NULL; \
    \
        return list; \
    } \
    \
    void type##ListAddFront(typecapitalised##DLList list, type value) \
    { \
        struct type##DLListNode *newNode = malloc(sizeof (struct type##DLListNode)); \
        newNode->data = value; \
        newNode->prev = NULL; \
    \
        if (list->first == NULL) \
        { \
            newNode->next = NULL; \
            list->first = newNode; \
            list->last = newNode; \
        } \
        else \
        { \
            struct type##DLListNode *oldFirst = list->first; \
            newNode->next = oldFirst; \
            oldFirst->prev = newNode; \
            list->first = newNode; \
        } \
    \
        (list->length)++; \
    } \
    \
    void type##ListAddBack(typecapitalised##DLList list, type value) \
    { \
        struct type##DLListNode *newNode = malloc(sizeof (struct type##DLListNode)); \
        newNode->data = value; \
        newNode->next = NULL; \
    \
        if (list->first == NULL) \
        { \
            newNode->prev = NULL; \
            list->first = newNode; \
            list->last = newNode; \
        } \
        else \
        { \
            struct type##DLListNode *oldLast =  list->last; \
            newNode->prev = oldLast; \
            oldLast->next = newNode; \
            list->last = newNode; \
        } \
    \
        (list->length)++; \
    } \
    \
    int type##ListLength(typecapitalised##DLList list) \
    { \
        return list->length; \
    } \
    \
    struct type##DLListNode *type##DLListNodeAtIndex(typecapitalised##DLList list, int index) \
    { \
        if (index < (list->length)/2) \
        { \
            int counter = 0; \
    \
            struct type##DLListNode *walk = list->first; \
    \
            while (walk != NULL) \
            { \
                if (counter == index) \
                { \
                    return walk; \
                } \
    \
                walk = walk->next; \
    \
                counter++; \
            } \
    \
            fprintf(stderr, "If this error occurs, there is an error in the implementation of the doubly linked list.\n"); \
            exit(1); \
        } \
        else if (index < list->length) \
        { \
            int counter = list->length - 1; \
    \
            struct type##DLListNode *walk = list->last; \
    \
            while (walk != NULL) \
            { \
                if (counter == index) \
                { \
                    return walk; \
                } \
    \
                walk = walk->prev; \
    \
                counter--; \
            } \
    \
            fprintf(stderr, "If this error occurs, there is an error in the implementation of the doubly linked list.\n"); \
            exit(1); \
        } \
        else \
        { \
            fprintf(stderr, "Index out of bounds of List.\n"); \
            exit(1); \
        } \
    } \
    \
    type type##ListGetAtIndex(typecapitalised##DLList list, int index) \
    { \
        struct type##DLListNode *node = type##DLListNodeAtIndex(list, index); \
        return node->data; \
    } \
    \
    void type##ListFree(typecapitalised##DLList list) \
    { \
        struct type##DLListNode *walk = list->first; \
        struct type##DLListNode *prevWalk = NULL; \
    \
        while (walk != NULL) \
        { \
            prevWalk = walk; \
            walk = walk->next; \
            free(prevWalk); \
        } \
    \
        free(list); \
    } \
    \
    void type##ListSetAtIndex(typecapitalised##DLList list, int index, type value) \
    { \
        struct type##DLListNode *node = type##DLListNodeAtIndex(list, index); \
        node->data = value; \
    } \
    \
    void type##ListSwapAtIndex(typecapitalised##DLList list, int index1, int index2) \
    { \
        type value1 = type##ListGetAtIndex(list, index1); \
        type value2 = type##ListGetAtIndex(list, index2); \
    \
        type##ListSetAtIndex(list, index2, value1); \
        type##ListSetAtIndex(list, index1, value2); \
    } \
    \
    void type##ListRemoveAtIndex(typecapitalised##DLList list, int index) \
    { \
        struct type##DLListNode *node = type##DLListNodeAtIndex(list, index); \
    \
        (list->length)--; \
    \
        struct type##DLListNode *prev = node->prev; \
        struct type##DLListNode *next = node->next; \
    \
        if (prev == NULL) \
        { \
            next->prev = NULL; \
    \
            list->first = next; \
    \
            free(node); \
        } \
        else if (next == NULL) \
        { \
            prev->next = NULL; \
    \
            list->last = prev; \
    \
            free(node); \
        } \
        else \
        { \
            prev->next = next; \
            next->prev = prev; \
    \
            free(node); \
        } \
    } \

#endif