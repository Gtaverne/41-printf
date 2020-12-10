/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:47:08 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 17:13:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		pf_lenhex(int n)
{
	int			res;
	long int	nbr;

	nbr = (long int)n;
	res = 1;
	if (nbr < 0)
		nbr = 4294967296 + nbr;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		res++;
	}
	return (res);
}

void	pf_puthex(long int n, int i, t_struct *mod)
{
	char	*hxbase;

	if (mod->src[mod->i] == 'X')
		hxbase = "0123456789ABCDEF";
	else
		hxbase = "0123456789abcdef";
	if (n < 0)
		n = n + 4294967296;
	mod->cors[mod->lex - 1] = hxbase[n % 16];
	while (n >= 16)
	{
		n = n / 16;
		mod->cors[mod->lex - i - 1] = hxbase[n % 16];
		i++;
	}
}

void	pf_hex(t_struct *mod)
{
	mod->tohex = va_arg(mod->args, long int);
	mod->lex = pf_lenhex(mod->tohex);
	if (!(mod->cors = malloc(sizeof(char) * (mod->lex + 1))))
		return ;
	pf_puthex(mod->tohex, 1, mod);
	mod->cors[mod->lex] = '\0';
	if (mod->cors == NULL || (mod->cors[0] == '0' && mod->prec == 0))
		return ;
	mod->cors = pf_padder(mod->prec, 1, mod->cors);
	pf_nflag(mod);
	free(mod->cors);
}
