/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 22:27:34 by ssong             #+#    #+#             */
/*   Updated: 2018/03/20 10:26:46 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

t_info	*print_udecimal(va_list *args, t_info *info)
{
	intmax_t	num;
	char		*buf;
	char		*temp;

	temp = NULL;
	num = 0;
	if (info->modifier == 0 && info->format == 'u')
		num = (uintmax_t)va_arg((*args), unsigned int);
	if (info->modifier == 0 && info->format == 'U')
		num = (uintmax_t)va_arg((*args), unsigned long int);
	else if (info->modifier == 'l')
		num = (uintmax_t)va_arg((*args), unsigned long int);
	// ll
	else if (info->modifier == 'm')
		num = (uintmax_t)va_arg((*args), unsigned long long int);
	else if (info->modifier == 'h')
		num = (uintmax_t)va_arg((*args), unsigned long int);
	// hh
	else if (info->modifier == 'a')
		num = (uintmax_t)(unsigned char)va_arg((*args), unsigned int);
	else if (info->modifier == 'j')
		num = va_arg((*args), uintmax_t);
	else if (info->modifier == 'z')
		num = (uintmax_t)va_arg((*args), size_t);
	buf = ft_uintmaxt_itoa(num);
	if (info->space < (int)ft_strlen(buf))
		info->space = 0;
	if (info->precision > (int)ft_strlen(buf))
	{
		temp = ft_memalloc(info->precision + 1);
		temp = ft_memset(temp, '0', info->precision);
		buf = ft_strrcpy(temp, buf, ft_strlen(temp), ft_strlen(buf));
	}
	if (info->space > 0)
	{
		info->printed += info->space;
		temp = ft_memalloc(info->space + 1);
		if (info->zero == 1)
			temp = ft_memset(temp, '0', info->space);
		else
			temp = ft_memset(temp, ' ', info->space);
		if (info->left == 1)
			temp = ft_strncpy(temp, buf, ft_strlen(buf));
		if (info->left == 0)
			temp = ft_strrcpy(temp, buf, ft_strlen(temp), ft_strlen(buf));
		ft_putstr(temp);
	}
	else
	{
		info->printed += ft_strlen(buf);
		ft_putstr(buf);
	}
	free(buf);
	return (info);
}
