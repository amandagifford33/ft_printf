/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:20:10 by agifford          #+#    #+#             */
/*   Updated: 2018/08/12 21:35:49 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(long long int value, int base)
{
	uint64_t	n;
	char		*ret;
	int			len;
	int			i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	ret = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		ret[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		ret[i] = HEX[n % base];
		n /= base;
	}
	ret[len - 1] = '\0';
	return (ret);
}
