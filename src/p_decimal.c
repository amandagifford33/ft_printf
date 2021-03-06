/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:03:10 by agifford          #+#    #+#             */
/*   Updated: 2018/08/10 14:06:14 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*ft_itoa_base(long long int value, int base)
{
	char *str;
	unsigned long long int n;
	int len;
	int i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	str = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		str[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		str[i] = HEX[n % base];
		n /= base;
	}
	str[len - 1] = '\0';
	return (str);
}*/

static void		format(t_components *m)
{
	m->num = ft_itoa_base(m->arg.i, 10);
	m->len = ft_strlen(m->num);
	if (m->prec > m->len)
		m->zeroes = m->prec - m->len;
	if (m->width > (m->len + m->zeroes))
		m->spaces = m->width - (m->len + m->zeroes);
	if (CHECK_PLUS(m->e_flags) && !(IS_NEG(m->arg.i)))
		m->sign = '+';
	if (CHECK_ZERO(m->e_flags) && CHECK_PLUS(m->e_flags))
		m->spaces--;
	if (CHECK_SPACE(m->e_flags) && !(IS_NEG(m->arg.i)) && m->spaces == 0)
		m->spaces++;
}

void	p_decimal(t_components *m)
{
	if (CHECK_DD(m->e_flags))
		ASSIGN_L(m->e_flags);
	sign_sign(m);
	format(m);
	if (CHECK_MINUS(m->e_flags))
	{
		if (CHECK_PLUS(m->e_flags) && !CHECK_ZERO(m->e_flags))
			print_char(m, m->sign, 1);
		print_char(m, '0', m->zeroes);
		print_num(m);
		print_char(m, ' ', m->spaces);
	}
	else
	{
		if (CHECK_PLUS(m->e_flags))
			print_char(m, m->sign, 1);
		if (m->prec != -1)
			print_char(m, ' ', m->spaces);
		else
			(CHECK_ZERO(m->e_flags)) ? print_char(m, '0', m->spaces)
				: print_char(m, ' ', m->spaces);
		print_char(m, '0', m->zeroes);
		print_num(m);
	}
}
