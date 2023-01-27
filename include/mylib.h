/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define MAX(x, y) (((x) > (y)) ? (x) : (y))

    int my_compute_power_rec(int nb, int p);
    int my_compute_power_it(int nb, int p);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_is_prime(int nb);
    int my_isneg(int n);
    int my_put_nbr_normal(int nb);
    int my_putchar(char c);
    void my_putchar_normal(char c);
    int my_putstr_normal(char const *str);
    char *my_revstr(char *str);
    int my_showmen(char const *str, int size);
    int my_showstr(char const *str);
    void my_sort_int_array(int *array, int size);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    char *int_to_str(int nb);

    int my_strlen2(char const *str);
    int my_strlen3(char const *str);
    int my_strlen4(char const *str);
    int my_strlen5(char const *str);
    int my_strlen6(char const *str);
    int my_strlen7(char const *str);
    int my_strlen_bis(char const *str);
    int my_strlen_third(char const *str);
    int my_compute_square_root(int nb);
    int reverse_num(int nb);
    int can_be_upped(char c);
    char *make_letter_capital(char *str, int len, int i);
    char upper_to_lower_case(char c);
    int check(char *str, char const *to_find, int i, int len);
    char lower_to_upper_case(char c);
    int check_for_lowercase(char c);
    int check_if_printable(char c);
    int check_letter(char c);
    int check_for_uppercase(char c);
    int check_number(char c);

    char *char_to_str(char c);

    int my_printf(const char *format, ...);

#endif /* MY_H_ */
