/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 14:26:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/20 18:44:29 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while(stack)
	{
		ft_putstr_fd("num: ", 1); // new
		ft_putnbr_fd(stack->num, 1);
		ft_putstr_fd("   |   index: ", 1); // new
		ft_putnbr_fd(stack->index, 1); //new
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

t_stack	*add_new_node(void)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	free_stack(t_stack *stack)
{
	t_stack	*node;

	while (stack)
	{
		node = stack->next;
		free(stack);
		stack = node;
	}
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}