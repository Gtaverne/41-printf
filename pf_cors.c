#include "ft_printf.h"

void    pf_cors2(t_struct *mod)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(mod->cors);
    while (i < len)
        pf_putchar(mod->cors[i++], mod);
}

void    pf_cors1(t_struct *mod)
{
    // Ici je gererai les flags
    pf_cors2(mod);
}

void    pf_cors(t_struct *mod)
{
    char c[2];

    if (mod->src[mod->i] == 'c')
    {
        c[0] = va_arg(mod->args, int);
        c[1] = '\0';
        mod->cors = c;
    }
    else if (mod->src[mod->i] == 's')
    {
        mod->cors = va_arg(mod->args, char *);
    }
    else if (mod->src[mod->i] == '%')
    {
        c[0] = '%';
        c[1] = '\0';
        mod->cors = c;
    }
    pf_cors1(mod);
}