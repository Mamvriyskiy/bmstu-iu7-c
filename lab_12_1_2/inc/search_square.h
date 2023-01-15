#ifndef _SEARCH_SQUARE_H_
#define _SEARCH_SQUARE_H_

#define EPS 0.00001
#define ERR_LEN 1
#define OK 0

size_t get_len(const int *arr, size_t len);
int is_square(int number);
int filter(const int *src, size_t src_len, int *dst, size_t *dst_len);

#endif
