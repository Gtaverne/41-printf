/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:03:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 20:03:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    pf_n(t_struct *mod)
{
    int i;

    i = 0;
    while (i < mod->minl)
    {
        pf_putchar(mod->cors[i], mod);
        i++;
    }
}

void pf_nflag(t_struct *mod)
{
    int i;

    i = 0;
    mod->minl = (ft_strlen(mod->cors) > mod->minl ? ft_strlen(mod->cors) \
    : mod->minl);
    while (mod->ljust && mod->minl-- && mod->cors[i])
        pf_putchar(mod->cors[i++], mod);
    while (mod->ljust && 1 + mod->minl--)
        pf_putchar(' ',mod);
    if (mod->ljust)
        return;
    mod->cors = pf_padder(mod->minl, mod->opad, mod->cors);
    pf_n(mod);
}

void    pf_num(t_struct *mod)
{
    if (mod->src[mod->i] == 'u')
        mod->cors = ft_utoa(va_arg(mod->args, unsigned int));
    else
        mod->cors = ft_itoa(va_arg(mod->args, int));
    if (mod->cors == NULL || (mod->cors[0] == '0' && mod->prec == 0))
        return;
    mod->cors = pf_padder(mod->prec, 1, mod->cors);
    pf_nflag(mod);
    free(mod->cors);
}
