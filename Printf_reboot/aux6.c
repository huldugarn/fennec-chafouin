/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:26:05 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/25 16:26:12 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		pf_as_pad_insert(char **dest, char *insert, int position)
{
	char	*prefix;
	char	*suffix;

	prefix = ft_strndup(*dest, position);
	suffix = ft_strdup(*dest + position);
	*dest = ft_strjoin(prefix, insert);
	free(prefix);
	prefix = ft_strdup(*dest);
	free(*dest);
	*dest = ft_strjoin(prefix, suffix);
	free(prefix);
	free(suffix);
}

void		pf_as_pad_append(char **dest, char *insert)
{
	char	*prefix;

	prefix = ft_strdup(*dest);
	free(*dest);
	*dest = ft_strjoin(prefix, insert);
	free(prefix);
}

void		pf_wc_pad_insert(wchar_t **dest, wchar_t *insert, int position)
{
	wchar_t	*prefix;
	wchar_t	*suffix;

	prefix = ft_wstrndup(*dest, position);
	suffix = ft_wstrdup(*dest + position);
	free(*dest);
	*dest = ft_wstrjoin(prefix, insert);
	free(prefix);
	prefix = ft_wstrdup(*dest);
	free(*dest);
	*dest = ft_wstrjoin(prefix, suffix);
	free(prefix);
	free(suffix);
}

void		pf_wc_pad_append(wchar_t **dest, wchar_t *insert)
{
	wchar_t	*prefix;

	prefix = ft_wstrdup(*dest);
	free(*dest);
	*dest = ft_wstrjoin(prefix, insert);
	free(prefix);
}
