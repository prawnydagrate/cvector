#ifndef VEC_H

#define VEC_H

#include <stdlib.h>

#define EXPAND_SIZE 4

typedef struct {
  void *data;
  size_t esize;
  size_t len;
  size_t capacity;
} Vec;

/**
 * This function takes an empty vector (set to `{0}`),
 * the size of each element of the vector (all elements must
 * be of the same type), and the initial capacity, and
 * initializes the vector. **This function must be executed
 * before the vector is used**, and `vec_cleanup` **must be
 * called after use**.
 *
 * @param vec A pointer to the vector, set to `{0}`.
 * @param esize The size of each element of the vector.
 * @param init_capacity The initial capacity of the vector.
 * @return The result of the initialization. This function
 * may return an error if dynamic memory allocation fails.
 */
Vec *vec_init(Vec *vec, size_t esize, size_t init_capacity);

/**
 * This function frees the memory allocated for a vector, and
 * uninitializes it.
 *
 * @param vec A pointer to the vector.
 */
void vec_cleanup(Vec *vec);

/**
 * This function pushes an element into a vector.
 *
 * @param vec A pointer to the vector.
 * @param e A pointer to the element being added. The size of
 * this element must be equivalent to `vec->esize`.
 * @return The result of pushing. This function may return an
 * error if dynamic memory reallocation fails while resizing the vector
 * as needed.
 */
Vec *vec_push(Vec *vec, void *e);

/**
 * This function pops the last element out of a vector.
 *
 * @param vec A pointer to the vector.
 * @return A pointer to the popped element. **This pointer
 * must be `free`d after use**. This pointer may point to
 * `NULL`, if the vector is empty or if dynamic memory allocation
 * for the element failed.
 */
void *vec_pop(Vec *vec);

/**
 * This function inserts an element into a vector.
 *
 * @param vec A pointer to the vector.
 * @param idx The index at which to insert the element.
 * @param e A pointer to the element being added. The size of
 * this element must be equivalent to `vec->esize`.
 * @return The pointer to the vector. If dynamic memory reallocation
 * failed when resizing the vector as needed, the return value will
 * point to `NULL`.
 */
Vec *vec_insert(Vec *vec, size_t idx, void *e);

/**
 * This function removes an element from a vector.
 *
 * @param vec A pointer to the vector.
 * @param idx The index of the element to remove.
 * @return A pointer to the removed element. **This pointer
 * must be `free`d after use**. This pointer may point to
 * `NULL`, if the vector is empty, the index is out of bonds,
 * or if dynamic memory allocation for the element failed.
 */
void *vec_remove(Vec *vec, size_t idx);

/**
 * This function accesses an element in a vector.
 *
 * @param vec A pointer to the vector.
 * @param idx The index of the element to get.
 * @return A pointer to the element. This pointer becomes
 * invalid if this element is removed from the vector.
 */
void *vec_get(Vec *vec, size_t idx);

/**
 * This function pushes many elements into a vector.
 *
 * @param vec A pointer to the vector.
 * @param arr An array containing the elements to be pushed. The size of
 * each element must be equivalent to `vec->esize`.
 * @param count The number of elements in the array.
 * @return The result of pushing. This function may return an
 * error if dynamic memory reallocation fails while resizing the vector
 * as needed.
 */
Vec *vec_extend(Vec *vec, void *arr, size_t count);

/**
 * This function clears a vector.
 *
 * @param vec A pointer to the vector to clear.
 */
void vec_clear(Vec *vec);

#endif
