/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:10:24 by rle-corr          #+#    #+#             */
/*   Updated: 2017/01/17 12:10:30 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


static void		display_list(t_lmn *s)
{
	t_list	*cursor;
	t_room	*room;

	cursor = s->rooms;
	printf("\n");
	while (cursor != NULL)
	{
		room = cursor->content;
		if (room->name != NULL)
			printf("->{%s}", room->name);
		cursor = cursor->next;
	}
	printf("\n");
}


static void		get_links(t_lmn *s)
{
	
	printf("GET %i LINKS !\n", s->n_links);
	++s->n_links;
}

static void		get_peri_hyphen_names(char *b, char **a, char **p)
{
	int			i;
	int			j;

//	printf(" |	 |	 |	get phn IN		> OK\n");
	i = 0;
	while (b[i] != '\n' && (!ft_isprint(b[i]) || b[i] == ' '))
		++i;
	j = i;
	while (b[j] != '\n' && ft_isprint(b[j]) && b[j] != '-')
		++j;
	*a = ft_strndup(&(b[i]), j - i);
	if (j + 1 < (int)ft_strlen(b))
	{
		i = j + 1;
		j = j + 1;
		while (b[j] != '\n' && ft_isprint(b[j]) && b[j] != ' ')
			++j;
		*p = ft_strndup(&(b[i]), (j + 1) - i);
	}
//	printf(" |	 |	 |	get phn OUT		> OK |");
}

static int		valid_room_name(t_lmn *s, char *n)
{
	t_list	*cursor;
	t_room	*room;

//	printf(" |	 |	 |	valid_room_name IN	> OK\n");
	cursor = s->rooms;
	while (cursor != NULL)
	{
		room = cursor->content;
		if (ft_strcmp(room->name, n) == 0)
			return (1);
		else
			cursor = cursor->next;
	}
	return (0);
}

static int		line_is_link(t_lmn *s)
{
	char		*ante_hyphen;
	char		*post_hyphen;

//	printf(" |	 |	is line_is_link ? IN		> OK | line is %s\n", s->buffer);
	ante_hyphen = NULL;
	post_hyphen = NULL;
	get_peri_hyphen_names(s->buffer, &ante_hyphen, &post_hyphen);
//	printf(" ante = %s	post = %s\n", ante_hyphen, post_hyphen);
	if (post_hyphen != NULL && 
		valid_room_name(s, ante_hyphen) && valid_room_name(s, post_hyphen))
	{
		free(ante_hyphen);
		free(post_hyphen);
		s->n_rooms = s->c_rooms;
		s->n_links = 0;
//		printf(" |	 |	is line_is_link ? OUT		> YES\n");
		return (1);
	}
	free(ante_hyphen);
	free(post_hyphen);
//	printf(" |	 |	is line_is_link ? OUT		> NO\n");
	return (0);
}

static void		record_buffer(t_lmn *s)
{
	char		*tmp;

	tmp = NULL;
	tmp = s->record == NULL ? s->buffer : ft_strjoin(s->record, s->buffer);
	tmp = ft_strjoin(tmp, "\n");
	s->record = ft_strdup(tmp);
	free(tmp);
}

static void		get_rooms_input(t_lmn *s, t_room *r) // remplacer par int valid_room_input
{
	int			i;
	int			j;

	i = 0;
	r->p.x = 0;
	r->p.y = 0;
	while (!(ft_isprint(s->buffer[i])) || s->buffer[i] == ' ')
		++i;
	while (s->buffer[i] == ' ')
		++i;
	j = i;
	while (ft_isprint(s->buffer[j]) && s->buffer[j] != ' ')
		++j;
	r->name = ft_strndup(&(s->buffer[i]), j - i); // leak
	while (!ft_isprint(s->buffer[j]) || s->buffer[j] == ' ')
		++j;
	while (ft_isdigit(s->buffer[j]) && s->buffer[j])
		r->p.x = r->p.x * 10 + (s->buffer[j++] - '0');
	while (!ft_isprint(s->buffer[j]) || s->buffer[j] == ' ')
		++j;
	while (ft_isdigit(s->buffer[j]) && s->buffer[j])
		r->p.y = r->p.y * 10 + (s->buffer[j++] - '0');
}

static t_room	*get_rooms(t_lmn *s)
{
	t_room		*r;

	if (line_is_link(s))
	{
		s->n_rooms = 0;
		get_links(s);
		return(NULL);
	}
	if (!(r = (t_room*)ft_memalloc(sizeof(t_room)))) // leak
		return (NULL);
	get_rooms_input(s, r); //remplacer par if valid_room_input, then lst_add and c_rooms++
//	printf(" |	get_rooms IN				> OK | %s\n", r->name);
	ft_lstadd(&(s->rooms), ft_lstnew(r, sizeof(t_room)));
	++(s->c_rooms);
//	printf(" |	get_rooms OUT				> OK | %s\n", ((t_room*)(s->rooms->content))->name);
	display_list(s);
	return (r);
}


static int		get_comms(t_lmn *s)
{
	printf(" |	get_comms IN				> OK | %s\n", s->buffer);
	if (s)
		if (s->buffer[1] && s->buffer[1] == '#')
		{
			if (ft_strcmp(&(s->buffer[2]), "start") == 0)
			{
				get_next_line(0, &(s->buffer));
				record_buffer(s);
				s->s_room = get_rooms(s);
			}
			if (ft_strcmp(&(s->buffer[2]), "end") == 0)
			{
				get_next_line(0, &(s->buffer));
				record_buffer(s);
				s->e_room = get_rooms(s);
			}
		}
	return (0);
}

static void		get_ants(t_lmn *s)
{
	int			i;

	i = 0;
	s->n_ants = 0;
	while (s->buffer[i] && !ft_isdigit(s->buffer[i]))
		++i;
	while (s->buffer[i] && ft_isdigit(s->buffer[i]))
		s->n_ants = s->n_ants * 10 + (s->buffer[i++] - '0');
	s->n_ants = s->n_ants == 0 ? -1 : s->n_ants;
	printf(" |	get_ants OUT				> OK | %i\n", s->n_ants);
}


int				lem_in_read(t_lmn *s)
{
	while (get_next_line(0, &(s->buffer)) != 0)
	{
		record_buffer(s);
		printf("\nread LOOP					> %s\n", s->buffer);
		if (*s->buffer ==  '\0')
			break ;
		else if (*s->buffer == '#') // possible segfault
			get_comms(s);
		else if (s->n_ants == -1)
			get_ants(s);
		else if (s->n_rooms == -1)
			get_rooms(s);
		else if (line_is_link(s))
			get_links(s);
	}
	return (0);
}
