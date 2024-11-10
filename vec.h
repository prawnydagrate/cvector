#ifndef VEC_H
#define VEC_H

#include <stdlib.h>

typedef struct {
  void *data;
  size_t esize;
  size_t len;
  size_t capacity;
} Vec;

Vec *vec_init(Vec *vec, size_t esize, size_t init_capacity);

Vec *vec_resize(Vec *vec, size_t by);

Vec *vec_push(Vec *vec, void *e);

void *vec_pop(Vec *vec);

Vec *vec_insert(Vec *vec, size_t idx, void *e);

void *vec_remove(Vec *vec, size_t idx);

void *vec_get(Vec *vec, size_t idx);

Vec *vec_extend(Vec *vec, void *arr, size_t count);

#endif
