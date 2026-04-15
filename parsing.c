/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:17:22 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/15 14:27:28 by yoneshev      ########   odam.nl         */
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

	offset = 1;
	if (!ft_strcmp(*av, "--adaptive") || !ft_strcmp(av[1], "--adaptive"))
		*strategy = ADAPTIVE;
	else if (!ft_strcmp(*av, "--simple") || !ft_strcmp(av[1], "--simple"))
		*strategy = SIMPLE;
	else if (!ft_strcmp(*av, "--medium") || !ft_strcmp(av[1], "--medium"))
		*strategy = MEDIUM;
	else
		*strategy = 0;
	if (!ft_strcmp(*av, "--bench") || !ft_strcmp(av[1], "--bench"))
		*bench = BENCH;
	else
		*bench = 0;
	if (*strategy)
		offset++;
	if (*bench)
		offset++;
	return (offset);
}
