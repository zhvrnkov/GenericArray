#include <stdio.h>
#include <stdlib.h>

#include "array.h"

typedef char Byte;

typedef struct _intRange {
    int lowerBound;
    int upperBound;
} IntRange;

int distance(IntRange range);

int main() {
  Array *empty = EmptyArray(sizeof(int));
  int i = 2;
  int y = 4;
  append(&i, empty);
  append(&y, empty);
  int fromArray = *(int *)subscript(0, empty);
  printf("%d\n", fromArray);

  int fromArrayT = *(int *)subscript(1, empty);
  printf("%d\n", fromArrayT);

  int fromArrayZ = *(int *)pop(empty);
  printf("%d\n", fromArrayZ);
  subscript(1, empty);
  
  return 0;
}

int distance(IntRange range) {
  return range.upperBound - range.lowerBound + 1;
}

void *arraySlice(const void *array, size_t sizeOfElement, IntRange range) {
  int d = distance(range);
  size_t sizeOfSlice = d * sizeOfElement;
  Byte *slice = (Byte *)malloc(sizeOfSlice);
  int sliceIndex = 0;
  for (int i = range.lowerBound; i < range.upperBound; i++)
    for (
	 long k = i * sizeOfElement;
	 k < (i + 1) * sizeOfElement;
	 k++, sliceIndex++
	 ) {
      slice[sliceIndex] = ((Byte *)array)[k];
    }
  for (int i = 0; i < sizeOfElement; i++, sliceIndex++)
    slice[sliceIndex] = 0;
  return slice;
}
