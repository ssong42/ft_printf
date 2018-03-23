/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:35:32 by ssong             #+#    #+#             */
/*   Updated: 2018/03/21 20:50:06 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char	*precision_str(t_info *info, char *str)
{
	if (!info->precision)
		str = ft_memset(str, 0, ft_strlen(str));
	else
		str[info->precision] = 0;
	return (str);
}

static char	*space_str(t_info *info, char *str)
{
	char *temp;

	temp = ft_memalloc(info->space + 1);
	temp = ft_memset(temp, ' ', info->space);
	if (info->left == 1)
		temp = ft_strncpy(temp, str, ft_strlen(str));
	if (info->left == 0)
		temp = ft_strrcpy(temp, str, ft_strlen(temp), ft_strlen(str));
	ft_memdel((void **)&str);
	return (temp);
}

t_info	*print_str(va_list *args, t_info *info)
{
	char *str;

	if (info->modifier == 'l')
		return (print_wstr(args, info));
	str = va_arg((*args), char *);
	if (!str)
	{
		ft_putstr("(null)");
		info->printed += 6;
		return (info);
	}
	str = ft_strdup(str);
	if (info->precision >= 0)
		str = precision_str(info, str);
	if (info->space > 0)
		str = space_str(info, str);
	info->printed += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
	return (info);
}
