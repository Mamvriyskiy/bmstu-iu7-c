#ifndef _FILTER_ARRAY_H_
#define _FILTER_ARRAY_H_

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
long long int create_sum(const int *pb_src, const int *pe_src);
size_t count_correct_element(const int *pb_src, const int *pe_src, long long int suml);
void search_right_element(const int *pb_src, const int *pe_src, int *pb_tmp, long long int suml);

#endif
