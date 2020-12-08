/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:47:08 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 13:47:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    pf_puthex(long int n, t_struct *mod)
{
    char        *hxbase;

    if (mod->src[mod->i] == 'X')
        hxbase = "0123456789ABCDEF";
    else
        hxbase = "0123456789abcdef";
    if (n < 0)
        n = n + 4294967296;
    if (n >= 16)
        pf_puthex(n / 16, mod);
    pf_putchar(hxbase[n % 16], mod);   
}

void    pf_hex(t_struct *mod)
{
    mod->tohex = va_arg(mod->args, long int);
    pf_puthex(mod->tohex, mod);
}