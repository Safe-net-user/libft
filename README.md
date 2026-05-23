*This project has been created as part of the 42 curriculum by gd-hallu*
# LIBFT
## Description

LIBFT is a custom C library developed following the 42 school curriculum guidelines.  
It reimplements a subset of standard C library functions while also providing additional utilities such as memory handling, string manipulation, linked lists, sorting algorithms, and more.

Some functions may not yet match the performance of optimized implementations found in libc/glibc, since the goal of this project is educational and focused on building foundational low-level programming skills.

The project is organized into modules such as:

- Strings
- Memory
- I/O
- Standard library utilities
- Data structures
- Math
- Sorting
- Cryptography
```text
.
├── include
│   ├── ft_io.h
│   ├── ft_linkedlist.h
│   ├── ft_memory.h
│   ├── ft_stdlib.h
│   └── ft_strings.h
├── Makefile
├── README.md
├── src
│   ├── crypto
│   ├── ds
│   │   └── linked_list
│   ├── io
│   ├── math
│   ├── mem
│   ├── sort
│   ├── stdlib
│   │   └── malloc
│   └── strings
└── test
    └── test_strings.c
```
## Buid Instruction

This project uses **make** for compilation.
A **MODE** variable is available to build the project with different compiler flags and sanitizers.

- **debug**: Create a executble with basic compilztor optimisation (-g -O1 -std=c99), useful for to monitor with **perf** command.
```bash
make fclean
make MODE=debug
```
 - **debug_memory**: Create an executable with basic optimisations and memory and undefined sanitizers ASAN (-g -O1 -std=c99 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer)
```bash
make fclean
make MODE=debug_memory
```
 - **debug_thread**: Create an executable with basic optimisations and thread sanitizers TSAN (-g -O1 -std=c99 -fsanitize=thread -fno-omit-frame-pointer)
```bash
make fclean
make MODE=debug_thread
```
 - **release**: Create an executable optimized but not portable, we use -march=native so this work for intel / arm x86-64
```bash
make fclean
make MODE=release
```

## TO-DO
Planned additions:
 - Hashtable
 - Graph
 - Binary tree
 - Doubly linked list
 - Stack
 - Queue
 - Vector / dynamic array
 - Additional algorithms

Future optimizations:
 - Improve performance to approach libc/glibc implementations
 - SIMD optimizations using XMM/SSE/AVX instructions
 - Better memory management strategies
 - Architecture-specific optimizations