/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:38:52 by ssong             #+#    #+#             */
/*   Updated: 2018/03/21 11:26:14 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int		isformat(char c)
{
	if (c == 'd' || c == 'D' || c == 'p')
		return (1);
	else if (c == 'i' || c == 'o' || c == 'O')
		return (1);
	else if (c == 'u' || c == 'U' || c == 's' || c == 'S')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	else if (c == '%' || c == 'n')
		return (1);
	return (0);
}

int		isplusminus(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

t_info	*init_info(void)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	info->left = 0;
	info->hash = 0;
	info->minus = 0;
	info->format = 0;
	info->zero = 0;
	info->sign = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->precision = -1;
	info->modifier = 0;
	info->printed = 0;
	info->index = 0;
	info->end = 0;
	info->functions = malloc(sizeof(t_functions) * 16);
	info->functions = set_fptr(info->functions);
	return (info);
}

t_info	*reset_info(t_info *info)
{
	info->left = 0;
	info->precision = -1;
	info->minus = 0;
	info->plus = 0;
	info->zero = 0;
	info->width = 0;
	info->hash = 0;
	info->space = 0;
	info->format = 0;
	info->modifier = 0;
	info->sign = 0;
	return (info);
}
