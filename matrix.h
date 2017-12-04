
#ifndef matrix_h
#define matrix_h

typedef struct {

    double* matrix;
    unsigned int rowNum;
    unsigned int colNum;
    unsigned int offset;
    unsigned int strand;
    unsigned int skip;

} matrix;

void zero_matrix(unsigned int rows, unsigned int cols, matrix* m);

void random_matrix(unsigned int rows, unsigned int cols, matrix* m);

void eye(unsigned int size, matrix* m);

void free_matrix(matrix* m);

void print_matrix(matrix* m);

void add_matrices(matrix* m1, matrix* m2, matrix* res);

void subtract_matrices(matrix* m1, matrix* m2, matrix* res);

double element(matrix* m, unsigned int i, unsigned int j);

void set_element(matrix* m, unsigned int i, unsigned int j, double element);

void add_to_element(matrix* m, unsigned int i, unsigned int j, double element);

void submatrix(matrix* m, unsigned int rowNum, unsigned int colNum, unsigned int offset, unsigned int strand, unsigned int skip, matrix* res);

void copy_matrix(matrix* src, matrix* dest);

matrix* alloc_matrix();

#endif
