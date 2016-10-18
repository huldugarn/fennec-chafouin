/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 12:22:58 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/11 12:23:05 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		pf_as_pad_insert(char **destination, char *insert, int position)
{
	char	*prefix;
	char	*suffix;

	prefix = ft_strndup(*destination, position);
	suffix = ft_strdup(*destination + position);
	free(*destination);
	*destination = ft_strjoin(prefix, insert);
	free(prefix);
	prefix = ft_strdup(*destination);
	free(*destination);
	*destination = ft_strjoin(prefix, suffix);
	free(prefix);
	free(suffix);
}

void		pf_as_pad_append(char **destination, char *insert)
{
	char	*prefix;

	prefix = ft_strdup(*destination);
	free(*destination);
	*destination = ft_strjoin(prefix, insert);
	free(prefix);
}

void		pf_wc_pad_insert(wchar_t **dest, wchar_t *insert, int position)
{
	wchar_t	*prefix;
	wchar_t	*suffix;

	prefix = ft_uni_strndup(*dest, position);
	suffix = ft_uni_strdup(*dest + position);
	free(*dest);
	*dest = ft_uni_strjoin(prefix, insert);
	free(prefix);
	prefix = ft_uni_strdup(*dest);
	free(*dest);
	*dest = ft_uni_strjoin(prefix, suffix);
	free(prefix);
	free(suffix);
}

void		pf_wc_pad_append(wchar_t **dest, wchar_t *insert)
{
	wchar_t	*prefix;

	prefix = ft_uni_strdup(*dest);
	free(*dest);
	*dest = ft_uni_strjoin(prefix, insert);
	free(prefix);
}