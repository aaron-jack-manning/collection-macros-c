#include<stdlib.h>
#include<stdio.h>

#ifndef QUEUE_H
#define QUEUE_H

#define DECLARE_QUEUE(type, typecapitalised) \
    \
    struct type##QueueNode \
    { \
        type data; \
        struct type##QueueNode *next; \
        struct type##QueueNode *prev; \
    }; \
    typedef struct type##Queue* typecapitalised##Queue; \
    struct type##Queue \
    { \
        int length; \
        struct type##QueueNode *first; \
        struct type##QueueNode *last; \
    }; \
    \
    typecapitalised##Queue type##QueueNew() \
    { \
        typecapitalised##Queue queue = malloc(sizeof (struct type##Queue)); \
    \
        queue->length = 0; \
        queue->first = NULL; \
        queue->last = NULL; \
    \
        return queue; \
    } \
    \
    void type##QueueEnqueue(typecapitalised##Queue queue, type value) \
    { \
        struct type##QueueNode *newNode = malloc(sizeof (struct type##QueueNode)); \
        newNode->data = value; \
        newNode->next = NULL; \
    \
        if (queue->first == NULL) \
        { \
            newNode->prev = NULL; \
            queue->first = newNode; \
            queue->last = newNode; \
        } \
        else \
        { \
            struct type##QueueNode *oldLast =  queue->last; \
            newNode->prev = oldLast; \
            oldLast->next = newNode; \
            queue->last = newNode; \
        } \
    \
        (queue->length)++; \
    } \
    \
    int type##QueueLength(typecapitalised##Queue queue) \
    { \
        return queue->length; \
    } \
    \
    void type##QueueFree(typecapitalised##Queue queue) \
    { \
        struct type##QueueNode *walk = queue->first; \
        struct type##QueueNode *prevWalk = NULL; \
    \
        while (walk != NULL) \
        { \
            prevWalk = walk; \
            walk = walk->next; \
            free(prevWalk); \
        } \
    \
        free(queue); \
    } \
    \
    type type##QueueDequeue(typecapitalised##Queue queue) \
    { \
        if (queue->first == NULL) \
        { \
            fprintf(stderr, "You cannot dequeue from an empty Queue."); \
            exit(1); \
        } \
        else \
        { \
            struct type##QueueNode *oldFirst = queue->first; \
            struct type##QueueNode *newFirst = oldFirst->next; \
            type returnValue = oldFirst->data; \
    \
            queue->first = newFirst; \
    \
            free(oldFirst); \
    \
            (queue->length)--; \
            return returnValue; \
        } \
    }

#endif