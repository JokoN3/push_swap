/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 18:13:52 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/10 15:30:18 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "limits.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_operation_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_counter;

void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
t_stack	*last_el(t_stack *stack);
t_stack	*prev_el(t_stack *stack, t_stack *element);

t_stack	*init_stack_a(t_stack *stack_a, char **av);
t_stack	*add_new_node(void);

void	swap(t_stack **a);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	rev_rotate(t_stack **a);

int		validate_input(char **av);
int		check_dup(char **av);
int		check_int(char **av);
int		non_num_in_str(char *str);

#endif