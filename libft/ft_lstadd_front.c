/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:57:38 by oldrolet          #+#    #+#             */
/*   Updated: 2023/09/18 13:59:18 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

/*#include<stdio.h>

int       main(void)
{
  char test[] = "test-test-test1";
  t_list *struc;
  t_list **testt;
  testt = &struc;
  char test2[] = "test-test-test2";
  ft_lstadd_front(testt, struc);
}
*/