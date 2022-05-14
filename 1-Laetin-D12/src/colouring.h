//
// Created by Лаэтин  Андрей on 12.05.2022.
//

#ifndef LAB4_COLOURING_H
#define LAB4_COLOURING_H

struct matrix{
    int** lines;
    int size;
    int colourNumber;
};

int Colouring(struct matrix *mat);

int* ColoursArr(struct matrix *mat);

int readMatrix(const char* filename, struct matrix *mat);

void Result(const char* input_filename, const char* output_filename);
#endif //LAB4_COLOURING_H
