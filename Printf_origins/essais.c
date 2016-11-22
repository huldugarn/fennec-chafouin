/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:04:24 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/25 14:04:27 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int			main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	printf("Test [%%] no flag	:_%3$6.3hh%\n");
	printf("Test [%%] altf		:_%3$#6.3h%\n");
	printf("Test [%%] zpad		:_%3$06.3l%\n");
	printf("Test [%%] bpad		:_%3$-6.3ll%\n");
	printf("Test [%%] asig		:_%3$ 6.3j%\n");
	printf("Test [%%] esig		:_%3$+6.3t%\n");
	printf("Test [%%] tsep		:_%3$'6.3z%\n");
/*
	printf("Test [c] no flag	:_%6c\n", '@');
	printf("Test [c] altf		:_%#6c\n", '@');
	printf("Test [c] zpad		:_%06c\n", '@');
	printf("Test [c] bpad		:_%-6c\n", '@');
	printf("Test [c] asig		:_% 6c\n", '@');
	printf("Test [c] esig		:_%+6c\n", '@');
	printf("Test [c] tsep		:_%'6c\n", '@');
*/
//	printf("Test []:_\n");
	return (0);
}
