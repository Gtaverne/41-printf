/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:39:34 by user42            #+#    #+#             */
/*   Updated: 2020/12/02 21:26:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	bckt_init(t_struct *bckt)
{
	bckt->Maxl = 0;
	bckt->opad = 0;
	bckt->rjust	= 0;
}

void	pf_flag(t_struct *mod)
{
	mod->i++;
}

void	pf_pars(t_struct *mod)
{
	bckt_init(mod);
	mod->i++;
	while (mod->src[mod->i] == '0' || mod->src[mod->i] == '*' || \
	mod->src[mod->i] == '-' || mod->src[mod->i] == '.')
		pf_flag(mod);
	if (mod->src[mod->i] == 'c' || mod->src[mod->i] == 's' || \
	mod->src[mod->i] == '%')
		pf_cors(mod);
	if (mod->src[mod->i] == 'd' || mod->src[mod->i] == 'i'  || \
	mod->src[mod->i] == 'u')
		pf_num(mod);
	if (mod->src[mod->i] == 'x' || mod->src[mod->i] == 'X')
		pf_hex(mod);
	if (mod->src[mod->i] == 'p')
		pf_ptr(mod);
}

int		ft_printf(const char *str, ...)
{
	t_struct	bckt;

	bckt.src = (char *)str;
	bckt.i = 0;
	bckt.res = 0;
	va_start(bckt.args, str);
	while (str[bckt.i])
	{
		if (str[bckt.i] == '%')
			pf_pars(&bckt);
		else
		{
			write(1, &bckt.src[bckt.i], 1);
			bckt.res++;
		}
		bckt.i++;
	}
	va_end(bckt.args);
	return (bckt.res);
}