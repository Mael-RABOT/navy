/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    static const int MAX_PREC = 38;
    static const int STD_PREC = 6;

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define MAX(x, y) (((x) > (y)) ? (x) : (y))

    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>

    int my_printf(const char *format, ...);
    int my_putchar(char c);
    int my_putchar_c(char c, int len);
    int my_putstr(char const *str, int prc);
    int my_put_nbr(unsigned int nombre, int prc);
    int my_put_nbr_u(unsigned int nb, int prc);
    int my_print_bin(unsigned int nb);
    int my_non_printable(char *src);
    int my_octal_print(unsigned int nb, int prc);
    int my_hexa_print(unsigned int nb, int offset, int prc);
    int len_to_ptr(int *ptr, int len);
    int my_nbrlen(double nbr);
    int my_is_double_neg(double nbr, int prc, int offset, char flag);
    int my_put_double(double nbr, int precision, int offset, char flag);
    int double_prc_null(double nbr, int offset);
    int my_is_expo_neg(double nbr, int prc, int offset, char flag);
    int my_put_exponant(double nbr, int prc, int offset, char flag);
    int my_hashtag(const char *format, va_list *params, int *i, int len);
    int my_space(const char *format, va_list *params, int *i, int len);
    int crash(int len);
    int my_str_isnum(char const c);
    int intra_selector(const char *format, va_list *params, int *i, int len);
    int selector(const char *format, va_list *params, int *i, int len);
    int minus_flag(const char *format, va_list *params, int *i, int len);
    int dot_flag(const char *format, va_list *params, int *i, int len);
    int dot_flag_bis(const char *format, va_list *params, int *i, int sum);
    int prc_g(double nbr, int prc, int len, char flag);
    int flag_g(double nb, int prc, int offset);
    int print_erno(void);
    int extract_nbr(const char *format, int *i);
    int plus_flag(const char *format, va_list *params, int *i, int len);
    int my_put_inf_or_nan(double nbr, int offset);
    int chose_h_selector(const char *format, va_list *params, int *i, int len);
    int chose_l_selector(const char *format, va_list *params, int *i, int len);
    int my_l_selector(const char *format, va_list *params, int *i, int len);
    int power_flag_a(double *nbr);
    int flag_a(double nbr, int prc, int offset, char trc);
    int length_modifier(const char *format, va_list *params, int *i, int sum);
    int my_strlen(char const *str);
    int is_flag_format(char c);
    int zero_flag(const char *format, va_list *params, int *i, int len);
    int get_nbr(const char *format, int *i);

    char *trunct(char *str, int i, char flag);
    char *my_nbr_to_str(char *str, double nombre, char flag, int *i);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *alpha_to_maj(char *str, int offset);
    char *my_double_to_hex(char *str, double nbr, int prc);
    char *precision_null_a(char *str, double nbr);
    char *my_revstr(char *str);

    char *plus_flag_c(const char *format, va_list *params, int *i, int len);
    char *plus_flag_c_up(const char *format, va_list *params, int *i, int len);
    char *plus_flag_d(int number, int prc);
    char *plus_bin_conv(unsigned int nb);
    char *plus_octal_conv(unsigned int nb);
    char *plus_hexa_conv(unsigned int nb, int offset);
    char *plus_non_printable(char *str);
    char *plus_flag_u(unsigned int number);
    char *zero_flag_d(int number, int prc);

    double my_power_rec(int nb, int p);

    void check_flag_format(const char *format, int *i, int *flag);

#endif /* !MY_H_ */
