/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:55:58 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/27 15:14:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "~/Projects/Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	va_start(va_list vl, derniere);
type	va_arg(va_list vl, type);
void	va_end(va_list vl);
int		ft_printf(const char * restrict format, ...);

#endif
