/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:39:29 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 18:21:27 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_hm(char *str)
{
	while (ft_isdigit(*str) == 1)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar(':');
	str++;
	while (ft_isdigit(*str) == 1)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar(' ');
}

static void		print_year(char *str)
{
	ft_putchar(' ');
	while (*str != '\n' && *str != '\0')
		str++;
	str -= 4;
	while (ft_isdigit(*str))
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar(' ');
}

static char		*print_md(char *str)
{
	str += 4;
	while (ft_isalpha(*str) == 1)
	{
		ft_putchar(*str);
		str++;
	}
	str++;
	ft_putchar(' ');
	if (ft_isdigit(*str) == 1)
		ft_putchar(*str);
	else
		ft_putchar(' ');
	str++;
	ft_putchar(*str);
	str += 2;
	ft_putchar(' ');
	return (str);
}

void			print_time(time_t file_time)
{
	time_t		get_time;
	time_t		t;
	char		*str;

	str = ctime(&file_time);
	get_time = time(&t);
	str = print_md(str);
	if (ABS((file_time - t)) > 15778463)
		print_year(str);
	else
		print_hm(str);
}
