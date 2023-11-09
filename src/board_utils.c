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
    b->map = NULL;
    b->width = 0;
    b->height = 0;
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

static int add_line(board *b, char const *start)
{
    b->map[b->added_lines] = malloc(sizeof(char) * (b->width + 1));
    if (b->map[b->added_lines] == NULL)
        return (0);
    my_strncpy(b->map[b->added_lines], start, b->width + 1);
    b->added_lines ++;
    return (1);
}

static int parse_buffer(char const *buff, size_t buff_size, board *b)
{
    size_t i = 0;

    (void)buff_size;
    if (!my_isnumeric(buff[0]))
        return (0);
    b->height = my_getnbr(buff);
    i += my_intlen(b->height);
    b->map = malloc(sizeof(char *) * b->height);
    if (buff[i] != '\n' || b->map == NULL)
        return (0);
    i += 1;
    b->width = my_strchr_index(buff + i, '\n');
    while (b->added_lines < b->height){
        if (!add_line(b, buff + i))
            return (0);
        i += b->width + 1;
    }
    return (1);
}

board *board_from_file(char const *file)
{
    board *b;
    ssize_t buff_size;
    char *buff = NULL;

    buff_size = file_to_buffer(file, &buff);
    if (buff_size == -1)
        return (NULL);
    b = create_empty_board();
    if (b == NULL){
        free(buff);
        return (NULL);
    }
    if (!parse_buffer(buff, buff_size, b)){
        free(buff);
        destroy_board(b);
        return (NULL);
    }
    free(buff);
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
    size_t i = 0;

    while (i < b->height){
        my_putstr(b->map[i]);
        my_putchar('\n');
        i ++;
    }
}

void destroy_board(board *b)
{
    size_t i = 0;

    while (i < b->height){
        free(b->map[i]);
        i ++;
    }
    free(b->map);
    free(b);
}
