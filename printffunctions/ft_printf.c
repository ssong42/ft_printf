/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:42:53 by ssong             #+#    #+#             */
/*   Updated: 2018/03/23 08:57:16 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

t_functions	*set_fptr(t_functions *functions)
{
	functions[0] = (t_functions){'d', print_decimal};
	functions[1] = (t_functions){'D', print_decimal};
	functions[2] = (t_functions){'i', print_decimal};
	functions[3] = (t_functions){'%', print_char};
	functions[4] = (t_functions){'c', print_char};
	functions[5] = (t_functions){'C', print_char};
	functions[6] = (t_functions){'s', print_str};
	functions[7] = (t_functions){'S', print_wstr};
	functions[8] = (t_functions){'x', print_hexi};
	functions[9] = (t_functions){'X', print_hexi};
	functions[10] = (t_functions){'o', print_octal};
	functions[11] = (t_functions){'O', print_octal};
	functions[12] = (t_functions){'u', print_udecimal};
	functions[13] = (t_functions){'U', print_udecimal};
	functions[14] = (t_functions){'p', print_address};
	functions[15] = (t_functions){'n', print_printed};
	return (functions);
}

t_info		*find_call(t_functions *functions, t_info *info, va_list *args)
{
	int i;

	i = 0;
	while (functions[i].format != info->format)
		i++;
	info = functions[i].ptr(args, info);
	return (info);
}

t_info		*find_format(const char *str, t_info *info, va_list *args)
{
	info->end = info->index + 1;
	while (!isformat(str[info->end]) && str[info->end])
		info->end++;
	if (!str[info->end])
	{
		ft_putchar('%');
		info->index++;
		return (info);
	}
	set_flag_info(info, str, args);
	info->format = str[info->end];
	info = find_call(info->functions, info, args);
	info->index = info->end + 1;
	reset_info(info);
	return (info);
}

int			ft_printf(const char *str, ...)
{
	t_info		*info;
	va_list		args;
	int			chars;

	va_start(args, str);
	info = init_info();
	while (str[info->index])
	{
		/*
		if (str[info->index] == '%')
			info = find_format(str, info, &args);
		else
		{
			ft_putchar(str[info->index]);
			info->printed++;
			info->index++;
		}
		*/
		ft_putchar(str[info->index]);
		info->index++;
	}
	chars = info->printed;
	ft_memdel((void **)&info);
	return (chars);
}
