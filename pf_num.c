/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:03:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 20:16:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_n(t_struct *mod)
{
	int	i;

	i = 0;
	while (i < mod->minl)
	{
		pf_putchar(mod->cors[i], mod);
		i++;
	}
}

void	pf_nflag(t_struct *mod)
{
	int	i;

	i = 0;
	mod->minl = (ft_strlen(mod->cors) > mod->minl ? ft_strlen(mod->cors) \
			: mod->minl);
	while (mod->ljust && mod->minl-- && mod->cors[i])
		pf_putchar(mod->cors[i++], mod);
	while (mod->ljust && 1 + mod->minl--)
		pf_putchar(' ', mod);
	if (mod->ljust)
		return ;
	mod->cors = pf_padder(mod->minl, mod);
	pf_n(mod);
}

char	*pf_zerpad(t_struct *mod)
{
	int		i;
	int		len;
	char	*repad;

	len = mod->prec + mod->isneg;
	i = ft_strlen(mod->cors) - 1;
	if (!(repad = malloc(sizeof(char) * (len + 1))))
		return (mod->cors);
	if (mod->isneg)
		repad[0] = '-';
	repad[len] = '\0';
	len--;
	while (len >= mod->isneg)
	{
		if (mod->cors[i] && mod->cors[i] != '-')
			repad[len] = mod->cors[i];
		else
			repad[len] = '0';
		len--;
		i--;
	}
	free(mod->cors);
	return (repad);
}

void	pf_num(t_struct *mod)
{
	if (mod->src[mod->i] == 'u')
		mod->cors = ft_utoa(va_arg(mod->args, unsigned int));
	else
		mod->cors = pf_itoa(va_arg(mod->args, int), mod);
	if (mod->cors == NULL || (mod->cors[0] == '0' && mod->prec == 0))
		return ;
	if (mod->opad == 2)
		mod->prec = mod->minl;
	if (mod->opad && ((mod->prec > ft_strlen(mod->cors))))
		mod->cors = pf_zerpad(mod);
	pf_nflag(mod);
	free(mod->cors);
}
