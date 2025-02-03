/*OPTIONAL*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char *ft_puthex_lower(int value)
{
    unsigned char *hex_chars = "0123456789abcdef";
    unsigned char *result;
    unsigned int byte_index;
    unsigned int size = sizeof(int);

    result = malloc(size * 2 + 1);
    if (!result)
        return NULL;

    for (byte_index = 0; byte_index < size; byte_index++)
    {
        result[byte_index * 2] = hex_chars[(value >> (8 * (size - 1 - byte_index) + 4)) & 0x0F];
        result[byte_index * 2 + 1] = hex_chars[(value >> (8 * (size - 1 - byte_index))) & 0x0F];
    }
    result[size * 2] = '\0';
    return result;
}

unsigned char *ft_puthex_upper(int value)
{
    unsigned char *hex_chars = "0123456789ABCDEF";
    unsigned char *result;
    unsigned int byte_index;
    unsigned int size = sizeof(int);

    result = malloc(size * 2 + 1);
    if (!result)
        return NULL;

    for (byte_index = 0; byte_index < size; byte_index++)
    {
        result[byte_index * 2] = hex_chars[(value >> (8 * (size - 1 - byte_index) + 4)) & 0x0F];
        result[byte_index * 2 + 1] = hex_chars[(value >> (8 * (size - 1 - byte_index))) & 0x0F];
    }
    result[size * 2] = '\0';
    return result;
}

void free_hex_string(unsigned char *hex_str)
{
    if (hex_str)
        free(hex_str);
}

int main()
{
    int value = 10; // Example integer value (0x12345678 in hex)

    // Convert to lowercase hex and print
    unsigned char *lower_hex = ft_puthex_lower(value);
    if (lower_hex)
    {
        printf("Lowercase hex: %s\n", lower_hex);
        free_hex_string(lower_hex);
    }
    else
    {
        printf("Failed to convert to lowercase hex.\n");
    }

    // Convert to uppercase hex and print
    unsigned char *upper_hex = ft_puthex_upper(value);
    if (upper_hex)
    {
        printf("Uppercase hex: %s\n", upper_hex);
        free_hex_string(upper_hex);
    }
    else
    {
        printf("Failed to convert to uppercase hex.\n");
    }

    return 0;
}
