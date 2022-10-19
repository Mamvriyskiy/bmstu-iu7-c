#ifndef _READ_PRINT_H_
#define _READ_PRINT_H_

int fprint_matrix(char *name_file, double **data, size_t n, size_t m);
int read_matrix(FILE *f, double **data, size_t n, size_t m, size_t k);

#endif