/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:53:58 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 13:54:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bckt_init(t_struct *mod)
{
	mod->ljust = 0;
	mod->minl = 0;
	mod->opad = 0;
	mod->prec = -1;
}

int		ft_atoi(char *str)
{
	int	res;
	int i;
	
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	pf_putchar(char c, t_struct *bckt)
{
	write(1, &c, 1);
	bckt->res++;
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*pf_padder(int prec, int typad, char *str)
{
	int	len;
	int	i;
	int ls;
	char *res;

	i = 0;
	ls = ft_strlen(str);
	len = (ls > prec ? ls : prec);
	if (!(res = malloc((sizeof(*res) * (len + 1)))))
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		if (ls > 0)
			res[len - 1] = str[ls - 1];
		else
			res[len - 1] = (typad > 0 ? '0' : ' ' );
		len--;
		ls--;
	}
	free(str);
	return (res);
}