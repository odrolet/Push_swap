/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:26:03 by oldrolet          #+#    #+#             */
/*   Updated: 2023/09/18 13:59:43 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//2147483647, -2147483648

static unsigned int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static unsigned int	ft_check_longueur(int nb)
{
	unsigned int	res;

	if (nb < 0)
		res = nb * -1;
	else
		res = nb;
	if (res > 1000000000)
		return (10);
	else if (res >= 100000000)
		return (9);
	else if (res >= 10000000)
		return (8);
	else if (res >= 1000000)
		return (7);
	else if (res >= 100000)
		return (6);
	else if (res >= 10000)
		return (5);
	else if (res >= 1000)
		return (4);
	else if (res >= 100)
		return (3);
	else if (res >= 10)
		return (2);
	return (1);
}

char	*ft_itoa(int nb)
{
	char			*res;
	unsigned int	len;
	long int		n;

	n = (long int)nb;
	len = ft_check_longueur(nb) + ft_sign(nb);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		n = n * -1;
	res[len] = '\0';
	len--;
	if (n == 0)
		res[len] = '0';
	while (len >= 0 && n > 0)
	{
		res[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	if (ft_sign(nb) == 1)
		res[len] = '-';
	return (res);
}

/*int main()
{
	printf("%s", ft_itoa(-2147483648));
}*/

/*#include "libft.h"

static int	nod(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ret;
	size_t		j;
	long int	num;

	j = nod(n);
	num = n;
	if (n < 0)
	{
		num = -num;
		j++;
	}
	ret = (char *)malloc(j + 1);
	if (!ret)
		return (NULL);
	ret[j] = '\0';
	while (j--)
	{
		ret[j] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
*/