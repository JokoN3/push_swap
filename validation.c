/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 14:18:26 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/10 14:26:11 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char **av)
{
	long long	ll_num;

	while (*av)
	{
		ll_num = ft_atoll(*av);
		if (ll_num > INT_MAX || ll_num < INT_MIN)
			return (0);
		if (ll_num == 0 && ft_strlen(*av) != 1)
			return (0);
		av++;		
	}
}

int	validate_input(char **av)
{
	if (check_int(av) == 0)
		return (0);	
	return (1);
}