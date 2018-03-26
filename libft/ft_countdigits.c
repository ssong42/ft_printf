/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:28:05 by ssong             #+#    #+#             */
/*   Updated: 2018/03/16 20:30:17 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigits(int n)
{
	int		c;

	c = 0;
	if (n == 0)
		c++;
	else if (n < 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_lcountdigit(long n)
{
	int		c;

	c = 0;
	if (n == 0)
		c++;
	else if (n < 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_llcountdigits(unsigned long long n)
{
	int		c;

	c = 0;
	if (n == 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_ucountdigits(unsigned int n)
{
	int		c;

	c = 0;
	if (n == 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_sizet_countdigits(size_t n)
{
	int		c;

	c = 0;
	if (n == 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}
