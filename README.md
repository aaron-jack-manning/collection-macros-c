# C Collection Macros

Due to the lack of a proper generic type system in C, some implementations of generally useful collections become very clunky with a lot of duplicate code, or use `void *` and give up static type checking.

This repository is comprised of macros I use to get generic, type checked collections in C, which work by calling the macro to declare a new set of functions for each collection implementation based on the type.

For example:

```
DECLARE_STACK(int, Int)
```

creates a full implementation of a stack, with the corresponding functions to create, add to, remove from and free a stack, for the type `int`.

Implementations are also present here for queues, single dimensional arrays and doubly linked lists.

Note that due to the fact that macros are used, each `.h` file ***does not*** have a corresponding `.c` file, and can just be included directly and on its own.