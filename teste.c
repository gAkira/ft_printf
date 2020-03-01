/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/01 14:30:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	//char	*fmt	=	"%%\t%c\t%-8.4s\t%-8.4d\t%-8.4i\t%-8.4u\t%-8.4x\t%-8.4X\t%-8.4p\t";
	char	*fmt	=	"%";
	//int		star1	=	-12;
	//int		star2	=	3;
	//char	*arg	=	"lalala";
	//int		arg		=	255;
	
	printf("%d\n", ft_printf(fmt));
	printf("%d\n", printf("% "));

	//printf("%d\n", ft_printf(fmt, 'c', "kk eae men", -42, -42, -42, -42, -42, &arg));
	//printf("%d\n", printf(fmt, 'c', "kk eae men", -42, -42, -42, -42, -42, &arg));
}
