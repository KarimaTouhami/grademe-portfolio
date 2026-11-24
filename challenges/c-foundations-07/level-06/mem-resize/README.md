# mem\_resize

Resize a heap block to a new size, preserving its leading bytes: realloc with an explicit old size

```c
void *mem_resize(void *ptr, size_t old_size, size_t new_size)
```

**Difficulty:** 5/5
**Allowed functions:** malloc, free

Solved as level 6 of the c-foundations-07 challenge.
Validated 2 times. Earlier versions are in this file's git history.

[Read the full exercise on Grademe](https://grademe.io/app/exercise/mem-resize)
