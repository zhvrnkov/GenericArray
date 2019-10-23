#include <stdlib.h>
#include <stdio.h>

typedef char Byte;

typedef struct array_t {
  Byte *_content;
  size_t sizeOfElement;
  size_t count;
} Array;

Array *EmptyArray(size_t sizeOfElement);
void *subscript(int index, Array *array);
void append(void *element, Array *array);
void *pop(Array *array);
