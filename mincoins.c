#include "vec.h"
#include <stdio.h>

int main() {
  // inputs
  size_t sum = 13;
  size_t coins_arr[] = {1, 4, 5};
  Vec coins = {0};
  vec_init(&coins, sizeof(size_t), 8);
  vec_extend(&coins, coins_arr, 3);
  for (size_t i = 0; i < coins.len; i++) {
    printf("%zu\n", *(size_t *)vec_get(&coins, i));
  }
  vec_cleanup(&coins);
}
