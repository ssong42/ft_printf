/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:50:38 by ssong             #+#    #+#             */
/*   Updated: 2018/03/21 20:50:05 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static t_info	*space_char(t_info *info, char c)
{
	char *temp;

	info->printed += info->space;
	temp = ft_memalloc(info->space + 1);
	temp = ft_memset(temp, ' ', info->space);
	if (info->left == 1)
		temp[0] = c;
	else
		temp[info->space - 1] = c;
	ft_putstr(temp);
	if (c == 0)
		ft_putchar(c);
	ft_memdel((void **)&temp);
	return (info);
}

t_info			*print_char(va_list *args, t_info *info)
{
	char c;

	c = 0;
	if (info->format == '%')
		c = '%';
	else
		c = (char)va_arg((*args), int);
	if (info->space > 0)
		space_char(info, c);
	else
	{
		ft_putchar(c);
		info->printed++;
	}
	return (info);
}
