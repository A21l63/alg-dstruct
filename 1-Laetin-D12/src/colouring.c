#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colouring.h"

#define UNCOLOURED -1

int ColouringSolv(struct matrix *mat, int currentPos, int *colourized) {
    int *colours_check = (int *) malloc(sizeof(int) * mat->size);
    memset(colours_check, 0, sizeof(int) * mat->colourNumber);

    for (int i = 0; i < mat->size; i++) {
        if (mat->lines[currentPos][i] != 0 && mat->lines[currentPos][i] != UNCOLOURED)
            colours_check[mat->lines[currentPos][i] - 1] = 1;
    }

    for (int c = 1; c <= mat->colourNumber; c++) {
        if (colours_check[c - 1] == 0) {

            for (int k = 0; k < mat->size; k++)
                if (mat->lines[k][currentPos] != 0)
                    mat->lines[k][currentPos] = c;

            (*colourized)++;

            for (int i = 0; i < mat->size; i++) {
                if (mat->lines[currentPos][i] == UNCOLOURED) {
                    if (ColouringSolv(mat,  i,  colourized) == 1) {
                        free(colours_check);
                        return 1;
                    }
                }
            }

            if (mat->size == *colourized) {
                free(colours_check);
                return 1;
            }
            break;
        }
    }
    free(colours_check);
    return 0;
}


int Colouring(struct matrix *mat) {
    int colorized = 0;
    return ColouringSolv(mat,  0,  &colorized);
}

int *ColoursArr(struct matrix *mat) {
    int *colours = (int *) malloc(sizeof(int) * mat->size);
    if (colours == NULL)
        return NULL;
    int *node_curr = colours;

    for (int i = 0; i < mat->size; i++) {
        for (int k = 0; k < mat->size; k++) {
            if (mat->lines[k][i] != 0 && mat->lines[k][i] != UNCOLOURED) {
                *node_curr++ = mat->lines[k][i];
                break;
            }
        }
    }
    return colours;
}

int readMatrix(const char *filename, struct matrix *mat) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fscanf(file, "%d %d", &mat->size, &mat->colourNumber);

    mat->lines = (int**) malloc(mat->size * sizeof(int *));
    if (mat->lines == NULL) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < mat->size; i++) {
        mat->lines[i] = (int *) malloc(sizeof(int) * (mat->size));
        if (mat->lines[i] == NULL) {
            fclose(file);
            for (int k = 0; k < i; k++)
                free(mat->lines[i]);
            return 0;
        }
        memset(mat->lines[i], 0, sizeof(int) * (mat->size));
    }

    int x, y;
    while (fscanf(file, "%d %d\n", &x, &y) == 2) {
        mat->lines[x - 1][y - 1] = UNCOLOURED;
        mat->lines[y - 1][x - 1] = UNCOLOURED;
    }

    if (mat->size == 1)
        return  mat->lines[0][0] = UNCOLOURED;
    fclose(file);
    return 1;
}

void Result(const char *input_filename, const char *output_filename) {
    struct matrix mat;
    readMatrix(input_filename, &mat);

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL)
        return;

    if (Colouring(&mat) == 0) {
        putc('0', output_file);
    } else {
        int *node_colours = ColoursArr(&mat);

        for (int i = 0; i < mat.size; i++) {
            if (i < mat.size - 1)
                fprintf(output_file, "%d ", node_colours[i]);
            else
                fprintf(output_file, "%d", node_colours[i]);
        }
        free(node_colours);
    }
    for (int i = 0; i < mat.size; i++)
        free(mat.lines[i]);
    fclose(output_file);
}