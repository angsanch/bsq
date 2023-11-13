/*
** EPITECH PROJECT, 2023
** bsq.c
** File description:
** Find the biggest square
*/

#include <stdlib.h>
#include "../include/bsq.h"

static int scan_row(board *b, size_t row, size_t start, size_t end)
{
    while (start < end){
        if (b->map[row][start] != '.')
            return (0);
        start ++;
    }
    return (1);
}

static int scan_column(board *b, size_t column, size_t start, size_t end)
{
    while (start < end){
        if (b->map[start][column] != '.')
            return (0);
        start ++;
    }
    return (1);
}

size_t biggest_here(board *b, size_t x, size_t y)
{
    size_t size = 0;

    if (b->map[y][x] != '.')
        return (0);
    while (size + x < b->width && size + y < b->height){
        if (!scan_row(b, y + size, x, x + size + 1))
            return (size);
        if (!scan_column(b, x + size, y, y + size))
            return (size);
        size ++;
    }
    return (size);
}

void draw_square(board *b, square *s)
{
    size_t i = s->x;
    size_t j = s->y;
    size_t x_limit = s->size + s->x;
    size_t y_limit = s->size + s->y;

    while (j < y_limit){
        while (i < x_limit){
            b->map[j][i] = 'x';
            i ++;
        }
        j ++;
        i = s->x;
    }
}

static void squares_row(board *b, square *max, size_t y)
{
    size_t x = 0;
    size_t temp;

    while (x < b->width){
        temp = biggest_here(b, x, y);
        if (temp > max->size){
            max->size = temp;
            max->x = x;
            max->y = y;
        }
        x ++;
    }
}

static void start_square(square *s)
{
    s->size = 0;
    s->x = 0;
    s->y = 0;
}

size_t bsq(board *b)
{
    square max;
    size_t y = 0;

    start_square(&max);
    while (y < b->height){
        squares_row(b, &max, y);
        y ++;
    }
    draw_square(b, &max);
    return (0);
}
