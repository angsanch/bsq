/*
** EPITECH PROJECT, 2023
** bsq.h
** File description:
** Necesary functions and structs
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <stdlib.h>
    #include <unistd.h>

typedef struct board_data {
    size_t added_lines;
    size_t width;
    size_t height;
    ssize_t buff_size;
    char *buff;
    char **map;
} board_t;

typedef struct square_data {
    size_t size;
    size_t x;
    size_t y;
} square_t;

board_t *board_from_file(char const *file);
board_t *generate_board(char const *size, char const *pattern);
void print_board(board_t *b);
void destroy_board(board_t *b);

size_t biggest_square(board_t *b);

#endif
