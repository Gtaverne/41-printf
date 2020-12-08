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

void    pf_n1(t_struct *mod)
{
    int i;

    i = 0;
    while (mod->cors[i])
    {
        pf_putchar(mod->cors[i], mod);
        i++;
    }
}

void    pf_num(t_struct *mod)
{
    if (mod->src[mod->i] == 'u')
        mod->cors = ft_utoa(va_arg(mod->args, unsigned int));
    else
        mod->cors = ft_itoa(va_arg(mod->args, int));
    if (mod->cors == NULL)
        return;
    pf_n1(mod);
    free(mod->cors);
}
