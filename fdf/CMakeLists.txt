cmake_minimum_required(VERSION 3.15)
project(fdf C)

set(CMAKE_C_STANDARD 99)

add_executable(map fdf main.c fdf.h readmap.c ../../gnl/get_next_line.c ../../gnl/libft/ft_atoi.c
        ../../gnl/libft/ft_strchr.c
        ../../gnl/libft/ft_strdup.c
        ../../gnl/libft/ft_strjoin.c
        ../../gnl/libft/ft_strnew.c
        ../../gnl/libft/ft_strcmp.c
        ../../gnl/libft/ft_strdel.c
        ../../gnl/libft/ft_strlen.c
        ../../gnl/libft/ft_strsub.c)