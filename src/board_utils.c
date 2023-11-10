/*
** EPITECH PROJECT, 2023
** board_utils.c
** File description:
** Manage the boards
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/bsq.h"

static board *create_empty_board(void)
{
    board *b = malloc(sizeof(board) * 1);

    if (b == NULL)
        return (NULL);
    b->buff = NULL;
    b->map = NULL;
    b->width = 0;
    b->height = 0;
    b->added_lines = 0;
    return (b);
}

static ssize_t file_to_buffer(char const *file, char **buff)
{
    struct stat file_stat;
    int fd = open(file, O_RDONLY);

    if (fd < 0)
        return (-1);
    if (stat(file, &file_stat) != 0){
        close(fd);
        return (-1);
    }
    *buff = malloc(sizeof(char) * file_stat.st_size);
    if (*buff == NULL){
        close(fd);
        return (-1);
    }
    if (read(fd, *buff, file_stat.st_size) != file_stat.st_size){
        free(buff);
        close(fd);
        return (-1);
    }
    return (file_stat.st_size);
}

static int add_line(board *b, size_t offset)
{
    size_t i = 0;
    size_t row = b->added_lines;
    char c;

    b->map[row] = b->buff + offset;
    while (i < b->width){
        c = b->map[row][i];
        if (c != '.' && c != 'o')
            return (0);
        i ++;
    }
    if (b->buff[offset + i] != '\n')
        return (0);
    b->added_lines ++;
    return (1);
}

static int parse_buffer(board *b)
{
    size_t i = 0;

    if (!my_isnumeric(b->buff[0]))
        return (0);
    b->height = my_getnbr(b->buff);
    i += my_intlen(b->height);
    b->map = malloc(sizeof(char *) * b->height);
    if (b->buff[i] != '\n' || b->map == NULL)
        return (0);
    i += 1;
    b->width = my_strchr_index(b->buff + i, '\n');
    while (b->added_lines < b->height){
        if (!add_line(b, i))
            return (0);
        i += b->width + 1;
    }
    return (1);
}

board *board_from_file(char const *file)
{
    board *b;

    b = create_empty_board();
    if (b == NULL)
        return (NULL);
    b->buff_size = file_to_buffer(file, &b->buff);
    if (b->buff_size == -1){
        destroy_board(b);
        return (NULL);
    }
    if (!parse_buffer(b)){
        destroy_board(b);
        return (NULL);
    }
    return (b);
}

board *generate_board(char const *size, char const *pattern)
{
    (void)size;
    (void)pattern;
    return (NULL);
}

void print_board(board *b)
{
    int len = my_intlen(b->height) + 1;

    write(1, b->buff + len, b->buff_size - len);
}

void destroy_board(board *b)
{
    free(b->buff);
    free(b->map);
    free(b);
}
