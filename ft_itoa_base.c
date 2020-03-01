/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:05:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 22:56:19 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*lst_to_str(t_list *lst)
{
	int		i;
	int		length;
	t_list	*init;
	char	*str;

	init = lst;
	if (lst == NULL)
		return (NULL);
	i = 0;
	length = ft_lstsize(lst);
	str = (char*)ft_calloc(length + 1, sizeof(char));
	while (str != NULL && i < length)
	{
		str[i] = *(char*)(lst->content);
		lst = lst->next;
		i++;
	}
	ft_lstclear(&init, &free);
	return (str);
}

char		*ft_itoa_base(int nbr, const char *base)
{
	int				sign;
	unsigned int	u_nbr;
	t_list			*num;
	t_list			*aux;

	num = NULL;
	if (ft_strlen(base) < 2)
		return (NULL);
	sign = (nbr < 0 ? -1 : 1);
	u_nbr = (nbr < 0 ? -nbr : nbr);
	if (u_nbr == 0)
		return (ft_substr(base, 0, 1));
	while (u_nbr > 0)
	{
		if (!(aux = ft_lstnew(ft_substr(base, u_nbr % ft_strlen(base), 1))))
		{
			ft_lstclear(&num, &free);
			return (NULL);
		}
		ft_lstadd_front(&num, aux);
		u_nbr /= ft_strlen(base);
	}
	if (sign < 0)
		ft_lstadd_front(&num, ft_lstnew("-"));
	return (lst_to_str(num));
}
