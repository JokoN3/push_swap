/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:17:22 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/10 12:51:26 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_new_node(void)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	print_stack(t_stack *stack)
{
	while(stack)
	{
		ft_putnbr_fd(stack->num, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

t_stack	*init_stack_a(t_stack *stack_a, char **av)
{
	t_stack	*node;
	t_stack	*head;

	head = add_new_node();
	if (!head)
		return (NULL);
	head->num = ft_atoi(*av);
	av++;
	head->next = NULL;
	stack_a = head;	
	while (*av)
	{
		node = add_new_node();
		node->num = ft_atoi(*av);
		node->next = NULL;
		stack_a->next = node;
		stack_a = node;
		av++;
	}
	return (head);
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
