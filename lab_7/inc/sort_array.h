#ifndef _SORT_ARRAY_H_
#define _SORT_ARRAY_H_

void mysort(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *));
int compare(const void *first_el, const void *second_el);
void swap_el(void *first_el, void *second_el, size_t lenl);

#endif
