/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:27:27 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/01 09:31:43 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_inside(char c, const char *set)
{
	int		i;

	i = 0;
	while (c == '\0' || set[i] != '\0')
	{
		if (set[i] == c)
			return (42);
		i++;
	}
	return (0);
}

static int	get_flag(const char *str, t_id *id, int *pos)
{
	int		f_cnt;

	f_cnt = 0;
	while (is_inside(str[f_cnt], ID_FLAGS))
	{
		if (str[f_cnt] == '-')
			id->flags |= FLG_MINUS;
		else if (str[f_cnt] == '0')
			id->flags |= FLG_ZERO;
		f_cnt++;
	}
	*pos += f_cnt;
	return (f_cnt);
}

static int	get_width(const char *str, t_id *id, int *pos)
{
	int		i;

	i = 0;
	while (str[i] == '*' || ft_isdigit((int)str[i]))
		i++;
	id->width = ft_substr(str, 0, i + 1);
	return (i);
}

t_id		*ft_new_id(const char *str)
{
	int		i;
	t_id	*new_id;

	i = 1;
	new_id = (t_id*)ft_calloc(1, sizeof(t_id));
	if (new_id == NULL)
		return (NULL);
	get_flag(&str[i], new_id, &i);
	get_width(&str[i], new_id, &i);
}
