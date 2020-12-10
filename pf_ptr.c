/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:57:37 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 17:15:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_lenaddr(unsigned long int n, t_struct *mod)
{
	if (n >= 16)
		pf_lenaddr(n / 16, mod);
	mod->lex++;
}

void	pf_ptr(t_struct *mod)
{
	mod->opad = 0;
	mod->prec = -1;
	mod->tohex = va_arg(mod->args, unsigned long int);
	pf_lenaddr(mod->tohex, mod);
	mod->lex += 2;
	if (!(mod->cors = malloc(sizeof(char) * (mod->lex + 1))))
		return ;
	pf_puthex(mod->tohex, 1, mod);
	mod->cors[mod->lex] = '\0';
	mod->cors[0] = '0';
	mod->cors[1] = 'x';
	if (mod->cors == NULL || (mod->cors[0] == '0' && mod->prec == 0))
		return ;
	mod->cors = pf_padder(mod->prec, 1, mod->cors);
	pf_nflag(mod);
	free(mod->cors);
}
