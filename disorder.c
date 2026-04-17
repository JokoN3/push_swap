/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 16:26:05 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/17 14:31:29 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->num > compare->num)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((float) mistakes / total_pairs);
}

void put_disorder(float disorder, int fd)
{
	char	c;
	int		next;

	c = (int) disorder + '0';
	write(fd, &c, 1);
	write(fd, ".", 1);
	disorder = disorder * 10;
	c = (int) disorder % 10 + '0';
	write(fd, &c, 1);
	disorder = disorder * 10;
	next = (int) (disorder * 10) % 10;
	if (next >= 5)
		c = (int) disorder % 10 + '0' + 1;
	else
		c = (int) disorder % 10 + '0';
	write(fd, &c, 1);
}
