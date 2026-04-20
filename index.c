/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 18:00:08 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/20 18:46:39 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(t_stack *stack)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * stack_size(stack));
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack->num;
		i++;
		stack = stack->next;
	}
	return (arr);
}

int	*index_bubble(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	index_stack(t_stack **stack_a)
{
	int		*arr;
	int		i;
	t_stack	*node;

	node = *stack_a;
	arr = fill_array(*stack_a);
	if (!arr)
		return (free_stack(*stack_a), 0);
	arr = index_bubble(arr, stack_size(*stack_a));
	while (node)
	{
		i = 0;
		while (arr[i] != node->num)
			i++;
		node->index = i;
		node = node->next;
	}
	free(arr);
	return (1);
}
