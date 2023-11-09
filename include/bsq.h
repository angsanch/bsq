/*
** EPITECH PROJECT, 2023
** bsq.h
** File description:
** Necesary functions and structs
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <stdlib.h>

typedef struct board_data{
    size_t added_lines;
    size_t width;
    size_t height;
    ssize_t buff_size;
    char *buff;
    char **map;
} board;

board *board_from_file(char const *file);
board *generate_board(char const *size, char const *pattern);
void print_board(board *b);
void destroy_board(board *b);

size_t bsq(board *b);

#endif
