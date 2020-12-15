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

char	*pf_nulptr(t_struct *mod)
{
	char	*res;
	int		i;

	i = 3;
	free(mod->cors);
	if (mod->prec != 0)
		i++;
	if (!(res = malloc(sizeof(char) * i)))
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	res[2] = '\0';
	if (mod->prec != 0)
	{
		res[2] = '0';
		res[3] = '\0';
	}
	return (res);
}

void	pf_ptr(t_struct *mod)
{
	mod->opad = 0;
	mod->tohex = va_arg(mod->args, unsigned long int);
	pf_lenaddr(mod->tohex, mod);
	mod->lex += 2;
	if (!(mod->cors = malloc(sizeof(char) * (mod->lex + 1))))
		return ;
	pf_puthex(mod->tohex, 1, mod);
	mod->cors[mod->lex] = '\0';
	mod->cors[0] = '0';
	mod->cors[1] = 'x';
	if (mod->tohex == 0)
	{
		mod->prec = (mod->prec == 0 ? 0 : -1);
		mod->cors = pf_nulptr(mod);
	}
	mod->prec = -1;
	mod->cors = pf_padder(mod->prec, mod);
	pf_nflag(mod);
	free(mod->cors);
}
