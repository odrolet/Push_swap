/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:16:22 by oldrolet          #+#    #+#             */
/*   Updated: 2023/10/18 19:09:45 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* on a besoin d'atoi pour convertir tout les donnees en long*/

static long	ft_atoips(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

// void	append_node(t_stack_node **stack, int nbr)
// {
// 	t_stack_node	*node;
// 	t_stack_node	*last_node;

// 	if (!stack)
// 		return ;
// 	node = malloc(sizeof(t_stack_node));
// 	if (!node)
// 		return ;
// 	node->next = NULL;
// 	node->value = nbr;
// 	if (*stack == NULL)
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }

/*creer la stack avec la valeur de la ligne d'argument
*/

void	stack_init(t_stack_node **a, char *argv[], bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoips(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_2darray_minusone(argv);
}
