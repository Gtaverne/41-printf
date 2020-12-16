/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:39:34 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 23:16:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_zorleft(t_struct *mod)
{
	while (mod->src[mod->i] == '0' || mod->src[mod->i] == '-')
	{
		if (mod->src[mod->i] == '0')
			mod->opad = 1;
		if (mod->src[mod->i] == '-')
			mod->ljust = 1;
		mod->i++;
	}
}

void	pf_minl(t_struct *mod)
{
	if (mod->src[mod->i] == '*')
	{
		mod->minl = va_arg(mod->args, int);
		mod->i++;
		if (mod->minl < 0)
		{
			mod->ljust = 1;
			mod->minl = -mod->minl;
		}
	}
	if (mod->src[mod->i] > '0' && mod->src[mod->i] <= '9')
	{
		mod->minl = ft_atoi(mod->src + mod->i);
		while (mod->src[mod->i] >= '0' && mod->src[mod->i] <= '9')
			mod->i++;
	}
}

void	pf_prec(t_struct *mod)
{
	mod->prec = 0;
	mod->i++;
	if (mod->src[mod->i] == '*')
	{
		mod->prec = va_arg(mod->args, int);
		mod->i++;
	}
	else
	{
		mod->prec = ft_atoi(mod->src + mod->i);
		while (mod->src[mod->i] >= '0' && mod->src[mod->i] <= '9')
			mod->i++;
	}
	if (mod->prec < 0)
		mod->prec = -1;
	else
		mod->opad = 0;
}

void	pf_pars(t_struct *mod)
{
	bckt_init(mod);
	mod->i++;
	pf_zorleft(mod);
	if (mod->src[mod->i] == '*' || (mod->src[mod->i] > '0' && \
	mod->src[mod->i] <= '9'))
		pf_minl(mod);
	if (mod->src[mod->i] == '.')
		pf_prec(mod);
	if (mod->src[mod->i] == 'c' || mod->src[mod->i] == 's' || \
	mod->src[mod->i] == '%')
		pf_cors(mod);
	if (mod->src[mod->i] == 'd' || mod->src[mod->i] == 'i' || \
	mod->src[mod->i] == 'u')
		pf_num(mod);
	if (mod->src[mod->i] == 'x' || mod->src[mod->i] == 'X')
		pf_hex(mod);
	if (mod->src[mod->i] == 'p')
		pf_ptr(mod);
	if (mod->src[mod->i] == '\0')
		return ;
	mod->i++;
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
			bckt.i++;
		}
	}
	va_end(bckt.args);
	return (bckt.res);
}
