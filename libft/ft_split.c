/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 13:37:52 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 14:55:50 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_split(char **split)
{
	size_t i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	i;
	size_t	counter;
	size_t	indicator;

	i = 0;
	counter = 0;
	indicator = 0;
	if (s[0] == 0)
		return (0);
	if (s[0] == c)
		++indicator;
	if (s[ft_strlen(s) - 1] == c)
		++indicator;
	while (s[i])
	{
		if (s[i] == c)
		{
			++counter;
			while (s[i + 1] == c)
				++i;
		}
		++i;
	}
	return (counter + 1 - indicator);
}

static char		*ft_split_part(char **spl, char const *s, char c, size_t j)
{
	size_t	i;
	size_t	start;
	size_t	counter;
	char	*tab;

	i = 0;
	start = j;
	counter = 0;
	while (s[j] && s[j] != c)
	{
		++counter;
		++j;
	}
	if (!(tab = malloc(sizeof(char) * (counter + 1))))
	{
		ft_free_split(spl);
		return (NULL);
	}
	while (i < counter)
	{
		tab[i] = s[start + i];
		++i;
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**split_tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(split_tab = malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (NULL);
	if (!(s[0]))
	{
		split_tab[0] = 0;
		return (split_tab);
	}
	split_tab[ft_word_count(s, c)] = 0;
	while (i < ft_word_count(s, c))
	{
		while (s[j] == c && s[j])
			++j;
		split_tab[i] = ft_split_part(split_tab, s, c, j);
		j += ft_strlen(split_tab[i]);
		++i;
	}
	return (split_tab);
}
