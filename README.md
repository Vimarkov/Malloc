# Malloc
Recoding malloc function

Custom C implementation of the malloc library functions. It creates the shared library libft_malloc.so which can be used to replace malloc in any system commands.

It exposes the following methods:
```C
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t count, size_t size);
void *reallocf(void *ptr, size_t size);

// Debug calls

void show_alloc_mem(); // Print informations about allocated zones
void show_alloc_mem_ex(); // Print a hex dump of the heaps
````

# Commands
## Build
```C
make
make clean # Clean temporary built files
make fclean # Clean all built files
```
> gcc uses -fPIC to generate position independent code (PIC) for shared libraries.
## Testing
```C
# Use malloc with a ${CMD}
sh insert_lib.sh ${CMD} # ex: sh insert_lib.sh ls

# Run unit test
cd test
make && sh ./run_test.sh
```
# Implementation
Bonus:
* `calloc()`, `realloc()`
* Defragmentation of freed space
* Multi-thread safe with pthread
