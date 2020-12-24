/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:59:06 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 17:09:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	va_list		args;
	char		*src;
	int			i;
	int			res;
	int			isneg;
	int			minl;
	int			prec;
	int			opad;
	int			ostr;
	int			ljust;
	long int	tohex;
	int			lex;
	char		*cors;
}				t_struct;

int				ft_printf(const char *str, ...);
void			bckt_init(t_struct *bckt);
void			pf_putchar(char c, t_struct *bckt);
void			bckt_init(t_struct *bckt);
void			pf_pars(t_struct *bckt);
void			pf_cors(t_struct *bckt);
int				ft_strlen(char *str);
void			pf_cors2(t_struct *mod);
void			pf_cors1(t_struct *mod);
void			pf_n(t_struct *mod);
void			pf_num(t_struct *mod);
void			pf_nflag(t_struct *mod);
int				ft_intlen(long int n);
void			ft_itoafill(char *str, long int n, int i);
char			*pf_itoa(int n, t_struct *mod);
void			ft_utoafill(char *str, long unsigned int n, int i);
char			*ft_utoa(unsigned int n);
void			pf_puthex(long int n, int i, t_struct *mod);
void			pf_hex(t_struct *mod);
int				pf_lenhex(long int n);
void			pf_ptr(t_struct *mod);
int				ft_atoi(char *str);
void			pf_minl(t_struct *mod);
char			*pf_padder(int prec, t_struct *mod);
char			*pf_zerpad(t_struct *mod);
void			pf_padchar(t_struct *mod);
void			pf_char(t_struct *mod);

#endif
