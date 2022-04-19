#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const *char format, ...);
int get_format(va_list arg, const char *string);
int check_percent(int *f, char a);
int _function_manager(char a, va_list arg);
int _switch(char c, va_list arg);
int function_manager(char c, va_list arg)


