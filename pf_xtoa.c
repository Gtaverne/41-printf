/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:48:26 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 17:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_itoafill(char *str, long int n, int i)
{
	str[i - 1] = (n % 10) + '0';
	n /= 10;
	if (n > 0)
		ft_itoafill(str, n, i - 1);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			sign;
	long int	nbr;

	nbr = (long int)n;
	sign = 0;
	i = 0;
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		sign++;
		i++;
	}
	if (!(res = malloc(sizeof(*res) * (ft_intlen(nbr) \
						+ sign + 1))))
		return (NULL);
	if (sign == 1)
		res[0] = '-';
	ft_itoafill(res + sign, nbr, ft_intlen(nbr));
	res[ft_intlen(nbr) + sign] = '\0';
	return (res);
}

void	ft_utoafill(char *str, long unsigned int n, int i)
{
	str[i - 1] = (n % 10) + '0';
	n /= 10;
	if (n > 0)
		ft_utoafill(str, n, i - 1);
}

char	*ft_utoa(unsigned int n)
{
	char				*res;
	long unsigned int	nbr;

	nbr = (long unsigned int)n;
	if (!(res = malloc(sizeof(*res) * (ft_intlen((long int)nbr) + 1))))
		return (NULL);
	ft_utoafill(res, nbr, ft_intlen((long int)nbr));
	res[ft_intlen(nbr)] = '\0';
	return (res);
}
