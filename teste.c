/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 20:53:11 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*fmt	=	"Esse eh % % o %-0*d yeah\t";
	int		star1	=	-12;
	//int		star2	=	3;
	//char	*arg	=	"lalala";
	int		arg		=	12;

	printf("%d\n", ft_printf(fmt, star1, arg));
	printf("%d\n", printf(fmt, star1, arg));
}
