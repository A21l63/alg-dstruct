//
// Created by Лаэтин  Андрей on 12.05.2022.
//

#include <gtest/gtest.h>
#include "colouring.c"


#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

#define ANSWER_LINE_LEN 100


TEST(IncorrectTest, OneVertexNoColours){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "1 0\n");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "0") == 0);
}

TEST(CoorectTest, OneVertexOneColour){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "1 1\n");
    fclose(input);
    Result(INPUT_FILENAME, OUTPUT_FILENAME);
    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "1") == 0);
}

TEST(IncorrectTest, TwoVertexesNoColours){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "2 0\n" \
					"1 2\n");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "0") == 0);
}

TEST(IncorrectTest, TwoVertexesOneColour){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "2 0\n" \
					"1 2\n");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "0") == 0);
}

TEST(CorrectTest, TwoVertexesTwoColours){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "2 2\n" \
					"1 2\n");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "1 2") == 0);
}


TEST(IncorrectTest, ThreeVertexesOneColour){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "3 1\n" \
					"1 2\n" \
					"2 3");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "0") == 0);
}


TEST(CorrectTest, ThreeVertexesThreeColours){
    FILE* input = fopen(INPUT_FILENAME, "w");
    fprintf(input, "3 3\n" \
					"1 2\n" \
					"2 3");
    fclose(input);

    Result(INPUT_FILENAME, OUTPUT_FILENAME);

    FILE* output = fopen(OUTPUT_FILENAME, "r");
    char ans[ANSWER_LINE_LEN] = {'\0'};
    fgets(ans, ANSWER_LINE_LEN, output);
    EXPECT_TRUE(strcmp(ans, "1 2 1") == 0);
}
