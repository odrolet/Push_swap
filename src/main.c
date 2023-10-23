/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:32:04 by oldrolet          #+#    #+#             */
/*   Updated: 2023/10/23 18:05:22 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_debug = 1; //rm -------------

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ps_split(argv[1], 32);
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else 
			push_swap(&a, &b);
	}
	free_stack(&a);
}

void	ft_debug(t_stack_node *a)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	while (a)
	{
		printf("position:%d target:%d valeur: %d\n", a->current_position, a->target_node->value, a->value);
		temp = temp->next;
	}
}
