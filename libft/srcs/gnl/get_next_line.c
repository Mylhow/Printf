/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:28:45 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 09:53:12 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static t_gnl	*gnl_new(int fd, char *buffer)
{
	t_gnl *current;

	if (!(current = malloc(sizeof(t_gnl))))
		return (NULL);
	if (!buffer)
	{
		if (!(current->buffer = ft_substr("", 0, 1)))
		{
			free(current);
			return (NULL);
		}
	}
	else
		current->buffer = buffer;
	current->fd = fd;
	current->next = NULL;
	return (current);
}

static t_gnl	*gnl_fct(t_gnl **lsts, int fd)
{
	t_gnl *current;

	if (!(current = (*lsts)))
		return (((*lsts) = gnl_new(fd, NULL)));
	while (current)
	{
		if (current->fd == fd)
			break ;
		else if (!(current->next))
		{
			current->next = gnl_new(fd, NULL);
			return (current->next);
		}
		(current) = (current)->next;
	}
	return (current);
}

static int		gnl_check(int fd, char **buffer)
{
	char	*str;
	int		read_size;
	int		state;
	char	*buffer_save;

	state = 1;
	if (!(str = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (ERROR);
	if ((read_size = read(fd, str, BUFFER_SIZE)) == -1)
	{
		free(str);
		return (ERROR);
	}
	str[read_size] = '\0';
	(!ft_strlen(str)) ? state = 0 : 0;
	buffer_save = *buffer;
	if (!(*buffer = ft_strjoin(*buffer, str)))
	{
		free(str);
		return (ERROR);
	}
	free(buffer_save);
	free(str);
	return (state);
}

static int		gnl_free_mail(t_gnl **buffer, t_gnl *current, int ret)
{
	t_gnl *tmp;
	t_gnl *tmp_prev;

	tmp_prev = NULL;
	if ((tmp = (*buffer)) == current)
		(current->next) ? (*buffer) = current->next : 0;
	while (tmp)
	{
		if (tmp == current)
		{
			if (tmp_prev != NULL)
				tmp_prev->next = tmp->next;
			if (current == (*buffer))
				(*buffer) = NULL;
			free(current);
			current = NULL;
			break ;
		}
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*buffer;
	t_gnl			*current;
	char			*n_buff;
	int				i;
	int				state_gnlcheck;

	n_buff = NULL;
	if (!(fd >= 0 && BUFFER_SIZE > 0 && (current = gnl_fct(&buffer, fd))))
		return (ERROR);
	while (!(i = ft_strichr(current->buffer, '\n')))
		if ((state_gnlcheck = gnl_check(fd, &current->buffer)) == -1)
			return (ERROR);
		else if (state_gnlcheck == 0)
			break ;
	if ((i > 0) &&
		!(n_buff = ft_substr(current->buffer, i, ft_strlen(current->buffer))))
		return (ERROR);
	if (gnl_line(current->buffer, line, i) == -1)
		return (ERROR);
	free(current->buffer);
	current->buffer = n_buff;
	return ((i == 0) ? gnl_free_mail(&buffer, current, ENDFILE) : SUCCESS);
}