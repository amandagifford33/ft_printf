/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:59:04 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 17:59:43 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_pointer(t_components *m)
{
	m->arg.u = va_arg(m->args, unsigned long int);
	m->num = ft_uitoa_base(m->arg.u, 16);
	ft_strcat(m->buff, "0x");
	ft_strcat(m->buff, m->num);
}
