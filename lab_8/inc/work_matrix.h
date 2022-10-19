#ifndef _WORK_MATRIX_H_
#define _WORK_MATRIX_H_

double** allocated_matrix(size_t n, size_t m);
int create_matrix(FILE *f, double ***a, size_t *n, size_t *m, size_t *k);
int read_matrix(FILE *f, double **a, size_t n, size_t m, size_t k);
int matrix_addition(double **a, size_t a_n, size_t a_m, double **b, size_t b_n, size_t b_m, \
    double ***c, size_t *c_n, size_t *c_m);
int matrix_multiplication(double **a, size_t a_n, size_t a_m, double **b, size_t b_n, size_t b_m, \
    double ***c, size_t *c_n, size_t *c_m);
// void matrix_free(double **data, size_t n);

#endif