#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

#define DECLARE_STACK(type, typecapitalised) \
    \
    \
    struct type##StackNode \
    { \
        type data; \
        struct type##StackNode *next; \
    }; \
    struct type##Stack \
    { \
        int length; \
        struct type##StackNode *top; \
    }; \
    typedef struct type##Stack * typecapitalised##Stack;\
    \
    struct type##Stack* type##StackNew() \
    { \
        struct type##Stack *stack = malloc(sizeof (struct type##Stack)); \
    \
        stack->length = 0; \
        stack->top = NULL; \
    \
        return stack; \
    } \
    \
    void type##StackPush(struct type##Stack *stack, type value) \
    { \
        struct type##StackNode *newNode = malloc(sizeof (struct type##StackNode)); \
        newNode->data = value; \
        newNode->next = stack->top; \
        stack->top = newNode; \
    \
        (stack->length)++; \
    } \
    \
    type type##StackPeek(struct type##Stack *stack) \
    { \
        if (stack->top == NULL) \
        { \
            fprintf(stderr, "Cannot Peek an empty Stack.\n"); \
            exit (-1); \
        } \
        else \
        { \
            return stack->top->data; \
        } \
    } \
    \
    type type##StackPop(struct type##Stack *stack) \
    { \
        if (stack->top == NULL) \
        { \
            fprintf(stderr, "Cannot Pop an empty Stack.\n"); \
            exit (-1); \
        } \
        else \
        { \
            struct type##StackNode *oldTop = stack->top; \
            struct type##StackNode *newTop = oldTop->next; \
            type returnValue = oldTop->data; \
    \
            stack->top = newTop; \
    \
            free(oldTop); \
    \
            (stack->length)--; \
            return returnValue; \
        } \
    } \
    \
    int type##StackLength(struct type##Stack *stack) \
    { \
        return stack->length; \
    } \
    \
    void type##StackFree(struct type##Stack *stack) \
    { \
        struct type##StackNode *walk = stack->top; \
        struct type##StackNode *prevWalk = NULL; \
    \
        while (walk != NULL) \
        { \
            prevWalk = walk; \
            walk = walk->next; \
            free(prevWalk); \
        } \
    \
        free(stack); \
    }

#endif