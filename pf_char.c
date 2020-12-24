/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:23:34 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 14:49:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_padchar(t_struct *mod)
{
	int	i;

	i = 0;
	while (i < mod->minl - 1)
	{
		if (mod->opad == 1)
			pf_putchar('0', mod);
		else
			pf_putchar(' ', mod);
		i++;
	}
	pf_putchar(mod->cors[0], mod);
}

void	pf_char(t_struct *mod)
{
	int	i;

	i = 0;
	if (mod->ljust == 1 && mod->prec != 0)
	{
		pf_putchar(mod->cors[0], mod);
		while (i++ < mod->minl - 1)
			pf_putchar(' ', mod);
		return ;
	}
	/*
	else if (mod->prec == 0)
	{
		while (i++ < mod->minl && mod->opad == 0)
			pf_putchar(' ', mod);
		while (i++ - 1 < mod->minl && mod->opad == 1)
			pf_putchar('0', mod);
		return ;
	}
	*/
	else
		pf_padchar(mod);
}
