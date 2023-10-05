#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void ft_putstr(char *ptr, int *len)
{
    while (*ptr)
    {
        write(1, ptr, 1);
        ptr++;
    }
}

void ft_putnbr(long long int nbr, int base, int *len)
{
    char *hex;

    hex = "0123456789abcdef";
    if (nbr < 0)
    {
        *len += write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr >= base)
        ft_putnbr(nbr/base, base, len);
    *len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int len;

    len = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &len);
            else if (*format == 'd')
                ft_putnbr((long long int)va_arg(args, int), 10, &len);
            else if (*format == 'x')
                ft_putnbr((long long int)va_arg(args, unsigned int), 16, &len);
        }
        else
        len += write(1, format, 1);
        format++;
    }
    return (va_end(args), len);
}

// free
void ft_free(char **ptr)
{
    int i = 0;

    while (ptr[i])
    {
        free(ptr[i]);
        ptr[i] = NULL;
    }
}
// strlen
size_t ft_strlen(const char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}
// strchr
char *ft_strchr(const char *s, int c)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] == (char)c)
            break;
        i++;
    }
    return ((char *)&s[i]);
}
// strdup
char *ft_strdup(const char *s1)
     {
        int i = 0;
        char *str;
        if (!s1)
            return (NULL);
        str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
        if (!str)
            return (NULL);
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        str[i] = '\0';
        return (str);
        }
// substr
char *ft_substr(const char *str, unsigned int start, size_t len)
     {

        int i = 0;
        char *ptr;

        if (!str[start])
            return (NULL);
        ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
        if (!ptr)
            return (NULL);
        while (str[start] && start < len)
        {
            ptr[i] = str[start];
            start++;
            i++;
        }
        ptr[i] = '\0';
        return (ptr);
    }
// strjoin
char *ft_strjoin(char *s1, char *s2)
     {

        int i = 0;
        int j = 0;
        char *str;

        str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!str)
            return (NULL);
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        while (s2[j])
        {
            str[i + j] = s2[j];
            j++;
        }
        str[i + j] = '\0';
        return (str);
    }
// ft_split
char *ft_split(char **buffer)
{
    char *line;
    char *excess_byte;
    int i = 0;

    while (buffer[0][i] != '\n' && buffer[0][i] != '\0')
        i++;
    line = ft_substr(buffer[0], 0, i + 1);
    excess_byte = ft_substr(buffer[0], i + 1, ft_strlen(buffer[0]));
    ft_free(buffer);
    *buffer = ft_strdup(excess_byte);
    ft_free(&excess_byte);
    if (!ft_strchr(line, '\n') && !ft_strlen(line))
        ft_free(&line);
    if (!ft_strchr(line, '\n'))
        ft_free(buffer);
    return (line);
}
// ft_concat
void ft_concat(char **line, char **chunk)
{
    char *tmp;
    if (!(*line))
        *line = ft_strdup(*chunk);
    else
    {
        tmp = ft_strjoin(*line, *chunk);
        ft_free(line);
        *line = tmp;
    }
}
// gnl
char *gnl(int fd)
{
    static char *line;
    char *chunk;
    int size;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    chunk = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    size = read(fd, chunk, BUFFER_SIZE);
    if (!chunk || size < 0)
        return (ft_free(&chunk), NULL);
    while (size > 0)
    {
        chunk[size] = '\0';
        ft_concat(&line, &chunk);
        if (ft_strchr(line, '\n'))
            break;
        size = read(fd, chunk, BUFFER_SIZE);
    }
    ft_free(&chunk);
    return (ft_split(&line));
}
// main

int main(void)
{
    // int i = 42;
    // ft_putstr("drey", &i);
    // ft_putnbr(5156454, 16, &i);
    // ft_printf("%d\n", ft_printf("%d\n", i));
    // printf("%d\n", printf("%d\n", i));
    // ft_printf("%d\n", ft_strlen("drey\n"));
    // ft_printf("%s\n", ft_strchr("drey\nwesson", '\n'));
    // ft_printf("%s\n", strchr("drey\nwesson", '\n'));
    // ft_printf("%s\n", ft_strdup("drey\nwesson"));
    // ft_printf("%s\n", ft_substr("drey\nwesson",5, 10));
    // ft_printf("%s\n", ft_strjoin("drey", "wesson"));
    int fd;

    fd = open("text", O_RDONLY);
    char *line;
    int i = 0;
    if (fd < 0)
    {
        printf("Bad read\n");
        return (1);
    }

    while (i < 2)
    {
        line = gnl(fd);
        printf("%s", line);
        free(line);
        i++;
    }
    
    return (0);
}