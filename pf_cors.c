/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:17:38 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 20:16:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*pf_prestr(int prec, char *str)
{
	int		len;
	int		i;
	int		ls;
	char	*res;

	i = 0;
	ls = ft_strlen(str);
	len = (ls < prec ? ls : prec);
	if (!(res = malloc((sizeof(*res) * (len + 1)))))
		return (NULL);
	while (i < len)
	{
		if (i < ls)
			res[i] = str[i];
		else
			res[i] = ' ';
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*pf_wstr(t_struct *mod)
{
	int		len;
	int		ls;
	char	*res;

	ls = ft_strlen(mod->cors);
	len = (ls > mod->minl ? ls : mod->minl);
	if (!(res = malloc((sizeof(*res) * (len + 1)))))
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		if (ls > 0)
			res[len - 1] = mod->cors[ls - 1];
		else if (ls <= 0 && mod->opad == 1)
			res[len - 1] = '0';
		else
			res[len - 1] = ' ';
		len--;
		ls--;
	}
	return (res);
}

void	pf_cors2(t_struct *mod)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mod->cors);
	while (i < len)
		pf_putchar(mod->cors[i++], mod);
}

void	pf_cors1(t_struct *mod)
{
	int		i;
	char	*tmp;

	i = 0;
	mod->minl = (ft_strlen(mod->cors) > mod->minl ? ft_strlen(mod->cors) \
			: mod->minl);
	while (mod->ljust && mod->minl-- && mod->cors[i])
		pf_putchar(mod->cors[i++], mod);
	while (mod->ljust && 1 + mod->minl--)
		pf_putchar(' ', mod);
	if (mod->ljust)
	{
		if (mod->prec >= 0)
			free(mod->cors);
		return ;
	}
	tmp = pf_wstr(mod);
	if (mod->prec >= 0)
		free(mod->cors);
	mod->cors = tmp;
	pf_cors2(mod);
	free(mod->cors);
}

void	pf_cors(t_struct *mod)
{
	char	c[2];

	if (mod->src[mod->i] == 's')
	{
		mod->cors = va_arg(mod->args, char *);
		if (mod->cors == NULL)
			mod->cors = "(null)";
		if (mod->prec >= 0)
			mod->cors = pf_prestr(mod->prec, mod->cors);
		pf_cors1(mod);
	}
	else if (mod->src[mod->i] == '%' || mod->src[mod->i] == 'c')
	{
		if (mod->src[mod->i] == 'c')
			c[0] = va_arg(mod->args, int);
		else
			c[0] = '%';
		c[1] = '\0';
		mod->prec = (mod->prec == 0 ? 0 : 1);
		mod->cors = c;
		pf_char(mod);
	}
}
