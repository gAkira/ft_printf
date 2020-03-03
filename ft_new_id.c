/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:27:27 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/02 21:53:30 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_id		*ft_new_id(const char *str)
{
	int		i;
	t_id	*new_id;

	i = 1;
	if(!(new_id = (t_id*)ft_calloc(1, sizeof(t_id))))
		return (NULL);
	ft_get_flag(&str[i], new_id, &i);
	ft_get_width(&str[i], new_id, &i);
	ft_get_precision(&str[i], new_id, &i);
	if (!ft_get_type(&str[i], new_id, &i))
		return (NULL);
	new_id->length = i;
	return (new_id);
}
