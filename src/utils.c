/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:16:52 by oldrolet          #+#    #+#             */
/*   Updated: 2023/10/19 14:38:14 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*cherche la derniere node et la change*/

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*trouve la plus petite node (valeur)*/

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/*return cheapest node that is flagged*/

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
