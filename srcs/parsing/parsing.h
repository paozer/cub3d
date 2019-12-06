/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:30:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 13:11:02 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"
# include "../../libft/includes/libft.h"
# include <unistd.h>

int		ft_parsing(char *params, t_map **map);
t_map	*ft_init_map(void);

#endif
