/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 14:18:26 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/12 16:11:20 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	non_num_in_str(char *str)
{
	if (ft_strlen(str) == 1 && !ft_isdigit(*str))
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_int(char **av)
{
	long long	ll_num;

	while (*av)
	{
		ll_num = ft_atoll(*av);
		if (!non_num_in_str(*av))
			return (0);
		if (ll_num > INT_MAX || ll_num < INT_MIN)
			return (0);
		av++;
	}
	return (1);
}

int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 1;
		while (av[i + j])
		{
			if (ft_atoll(av[i]) == ft_atoll(av[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_input(char **av, int allocated_av)
{
	if (check_int(av) == 0)
	{
		if (!allocated_av)
			free_arr(av);
		return (ft_putstr_fd("Error\n", 1), 0);
	}
	if (check_dup(av) == 0)
	{
		if (!allocated_av)
			free_arr(av);
		return (ft_putstr_fd("Error\n", 1), 0);
	}
	return (1);
}
