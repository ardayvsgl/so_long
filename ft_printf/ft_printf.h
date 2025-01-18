#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printc(int c);
int	ft_printcapitalx(unsigned int d);
int	ft_printf(const char *str, ...);
int	ft_printi(int d);
int	ft_printp(unsigned long long d);
int	ft_prints(char *s);
int	ft_printu(unsigned int d);
int	ft_printx(unsigned int d);

#endif
