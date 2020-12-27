/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:57:37 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 20:17:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_lenaddr(unsigned long int n, t_struct *mod)
{
	if (n >= 16)
		pf_lenaddr(n / 16, mod);
	mod->lex++;
}

void	pf_ptrljust(t_struct *mod)
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
	if (mod->opad)
	{
		while (mod->cors[i++])
			if (mod->cors[i] == 'x')
				mod->cors[i] = '0';
		mod->cors[1] = 'x';
	}
	pf_n(mod);
}

void	pf_ptr(t_struct *mod)
{
	int i;

	i = 0;
	mod->tohex = va_arg(mod->args, unsigned long int);
	pf_lenaddr(mod->tohex, mod);
	mod->lex = (mod->lex > mod->prec ? mod->lex : mod->prec) + 2;
	if (!(mod->cors = malloc(sizeof(char) * (mod->lex + 1))))
		return ;
	while (i < mod->lex)
		mod->cors[i++] = '0';
	pf_puthex(mod->tohex, 1, mod);
	if (mod->tohex == 0 && mod->prec == 0)
		mod->cors[mod->lex - 1] = '\0';
	mod->cors[mod->lex] = '\0';
	mod->cors = pf_padder(mod->prec, mod);
	mod->cors[0] = '0';
	mod->cors[1] = 'x';
	pf_ptrljust(mod);
	free(mod->cors);
}
