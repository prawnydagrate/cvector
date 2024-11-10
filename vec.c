#include <stdlib.h>
#include <string.h>

const size_t EXPAND_SIZE = 4;

typedef struct {
  void *data;
  size_t esize;
  size_t len;
  size_t capacity;
} Vec;

Vec *vec_init(Vec *vec, size_t esize, size_t init_capacity) {
  void *mem = malloc(esize * init_capacity);
  if (mem == NULL)
    return NULL;
  vec->data = mem;
  vec->esize = esize;
  vec->len = 0;
  vec->capacity = init_capacity;
  return vec;
}

Vec *vec_resize(Vec *vec, size_t by) {
  void *mem = realloc(vec->data, vec->capacity + by * vec->esize);
  if (mem == NULL)
    return NULL;
  vec->data = mem;
  vec->capacity += by;
  return vec;
}

Vec *vec_resize_if_needed(Vec *vec, size_t ecount) {
  // allow for EXPAND_SIZE more elements to avoid constant reallocation
  if (vec->len + ecount > vec->capacity &&
      vec_resize(vec, ecount + EXPAND_SIZE) == NULL)
    return NULL;
  return vec;
}

Vec *vec_push_no_resize(Vec *vec, void *e) {
  memcpy(vec->data + vec->len * vec->esize, e, vec->esize);
  vec->len++;
  return vec;
}

Vec *vec_push(Vec *vec, void *e) {
  if (vec_resize_if_needed(vec, 1) == NULL)
    return NULL;
  vec_push_no_resize(vec, e);
  return vec;
}

void *vec_pop(Vec *vec) {
  if (vec->len == 0)
    return NULL;
  vec->len--;
  return vec->data + vec->len * vec->esize;
}

Vec *vec_insert(Vec *vec, size_t idx, void *e) {
  if (vec_resize_if_needed(vec, 1) == NULL)
    return NULL;
  if (idx > vec->len)
    return NULL;
  if (idx == vec->len)
    return vec_push_no_resize(vec, e);
  // shifting elements to the right
  /* for (size_t i = vec->len - 1; i >= idx; i--) {
    memmove(vec->data + (i + 1) * vec->esize, vec->data + i * vec->esize,
            vec->esize);
  } */
  memmove(vec->data + (idx + 1) * vec->esize, vec->data + idx * vec->esize,
          (vec->len - idx) * vec->esize);
  // inserting the element
  memcpy(vec->data + idx * vec->esize, e, vec->esize);
  vec->len++;
  return vec;
}

void *vec_remove(Vec *vec, size_t idx) {
  if (idx >= vec->len)
    return NULL;
  if (idx == vec->len - 1)
    return vec_pop(vec);
  // obtaining the element being removed
  void *e = malloc(vec->esize);
  if (e == NULL)
    return NULL;
  memmove(e, vec->data + idx * vec->esize, vec->esize);
  // shifting elements to the left
  /* for (size_t i = idx + 1; i < vec->len; i++) {
    memmove(vec->data + (i - 1) * vec->esize, vec->data + i * vec->esize,
            vec->esize);
  } */
  memmove(vec->data + idx * vec->esize, vec->data + (idx + 1) * vec->esize,
          (vec->len - idx - 1) * vec->esize);
  vec->len--;
  return e;
}

void *vec_get(Vec *vec, size_t idx) {
  if (idx >= vec->len)
    return NULL;
  return vec->data + idx * vec->esize;
}

Vec *vec_extend(Vec *vec, void *arr, size_t count) {
  for (size_t i = 0; i < count; i++) {
    if (vec_push(vec, arr + i * vec->esize) == NULL)
      return NULL;
  }
  return vec;
}
