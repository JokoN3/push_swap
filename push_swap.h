/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 18:13:52 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/09 18:55:47 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"

typedef struct s_stack
{
	int				num;
	typedef struct	s_stack *next;
}	t_stack;

#endif