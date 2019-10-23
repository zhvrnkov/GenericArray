#include "array.h"

Array *EmptyArray(size_t sizeOfElement) {
  Array *t = malloc(sizeof(Array));
  t->_content = NULL;
  t->sizeOfElement = sizeOfElement;
  t->count = 0;

  return t;
}

void *subscript(int index, Array *array) {
  if (index >= array->count) {
    printf("subscript: index out of bounds\n");
    return NULL;
  }
  return (void *)&array->_content[index * array->sizeOfElement];
}

void append(void *element, Array *array) {
  size_t preCount = array->count;
  size_t sizeOfElem = array->sizeOfElement;
  array->count++;
  array->_content = realloc(array->_content, array->count * sizeOfElem);
  Byte *eptr = (Byte *)element;
  for (int i = 0; i < sizeOfElem; i++) {
    array->_content[preCount * sizeOfElem + i] = eptr[i];
  }
}

void *pop(Array *array) {
  if (!array->count) {
    return NULL;
  }
  array->count--;
  return (void *)&array->_content[array->count * array->sizeOfElement];
}
