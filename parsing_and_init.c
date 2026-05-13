/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_and_init.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:17:22 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 17:30:39 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_for_flags(char **av, int *strategy, int *bench)
{
	int	offset;

	*bench = 0;
	offset = 1;
	if (!av[1])
		return (offset);
	if (!ft_strcmp(*av, "--adaptive") || !ft_strcmp(av[1], "--adaptive"))
		*strategy = ADAPTIVE;
	else if (!ft_strcmp(*av, "--simple") || !ft_strcmp(av[1], "--simple"))
		*strategy = SIMPLE;
	else if (!ft_strcmp(*av, "--medium") || !ft_strcmp(av[1], "--medium"))
		*strategy = MEDIUM;
	else if (!ft_strcmp(*av, "--complex") || !ft_strcmp(av[1], "--complex"))
		*strategy = COMPLEX;
	else
		*strategy = 0;
	if (!ft_strcmp(*av, "--bench") || !ft_strcmp(av[1], "--bench"))
		*bench = BENCH;
	if (*strategy)
		offset++;
	if (*bench)
		offset++;
	return (offset);
}

void	init_counter(t_op_counter *count)
{
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->total = 0;
}
