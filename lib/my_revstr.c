/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-adrien.audiard
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i = 0, j, k;
    while (str[i] != '\0') {
        i++;
    }
    char dest[i + 1];
    for (k = 0; str[k] != '\0'; k++) {
        dest[k] = str[k];
    }
    dest[k] = '\0';
    for (i -= 1, j = 0; str[j] != '\0'; i--, j++) {
        str[j] = dest[i];
    }
    return str;
}
