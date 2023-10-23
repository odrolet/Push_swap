/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:32:41 by oldrolet          #+#    #+#             */
/*   Updated: 2023/10/23 17:57:09 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <limits.h>
# include "libft.h"
# include <stdbool.h>
# include <limits.h>

// typedef struct
// {
// }
extern int	g_debug; //rm ----------------
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void				free_2darray_minusone(char **argv);
void				free_stack(t_stack_node **stack);
void				error_free(t_stack_node **a, char *argv[],
						bool flag_argc_2);
int					error_syntax(char *str_nbr);
int					error_repetition(t_stack_node *a, int nbr);
char				**ps_split(char *str, char separator);
//static int			count_words(char *str, char separator);
//static char			*get_next_word(char *str, char separator);
void				set_current_position(t_stack_node *stack);
//static void			set_target_node(t_stack_node *a, t_stack_node *b);
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_cheapest(t_stack_node *b);
void				init_nodes(t_stack_node *a, t_stack_node *b);
// static void			rotate_both(t_stack_node **a, t_stack_node **b, 
// 						t_stack_node *cheapest_node);
// static void			reverse_rotate_both(t_stack_node **a, t_stack_node **b, 
// 						t_stack_node *cheapest_node);
void				finish_rotation(t_stack_node **stack, 
						t_stack_node *top_node, char stack_name);
// static void			move_nodes(t_stack_node **a, t_stack_node **b);
void				push_swap(t_stack_node **a, t_stack_node **b);
// static void			push(t_stack_node **dest, t_stack_node **src);
void				pa(t_stack_node **a, t_stack_node **b, bool checker);
void				pb(t_stack_node **b, t_stack_node **a, bool checker);
// static void			reverse_rotate(t_stack_node **stack);
void				rra(t_stack_node **a, bool checker);
void				rrb(t_stack_node **b, bool checker);
void				rrr(t_stack_node **a, t_stack_node **b, bool checker);
// static void			rotate(t_stack_node **stack);
void				ra(t_stack_node **a, bool checker);
void				rb(t_stack_node **b, bool checker);
void				rr(t_stack_node **a, t_stack_node **b, bool checker);
bool				stack_sorted(t_stack_node *stack);
// static t_stack_node	*find_highest(t_stack_node *stack);
void				tiny_sort(t_stack_node **a);
void				handle_five(t_stack_node **a, t_stack_node **b);
// static long			ft_atoips(const char *str);
// void				append_node(t_stack_node **stack, int nbr);
void				stack_init(t_stack_node **a, char *argv[], 
						bool flag_argc_2);
// static void			swap(t_stack_node **head);
void				sa(t_stack_node **a, bool checker);
void				sb(t_stack_node **b, bool checker);
void				ss(t_stack_node **a, t_stack_node **b, bool checker);
t_stack_node		*find_last_node(t_stack_node *head);
void				append_node(t_stack_node **stack, int nbr);
t_stack_node		*find_smallest(t_stack_node *stack);
t_stack_node		*return_cheapest(t_stack_node *stack);
int					stack_len(t_stack_node *stack);
void				ft_debug(t_stack_node *a);

#endif