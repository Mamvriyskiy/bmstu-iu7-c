#ifndef _GAUSS_METHOD_
#define _GAUSS_METHOD_

int gauss_method(double **a, size_t a_n, size_t a_m, double ***c, size_t *c_n, size_t *c_m);
void division_line(double *a, size_t k, size_t m);
void sub_line(double **data, size_t k, size_t n, size_t m);
void create_result_matrix(double **a, size_t a_n, size_t a_m, double **c, size_t c_n);

#endif
