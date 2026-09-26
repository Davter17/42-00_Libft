/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_H
# define TEST_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

extern int	g_pass;
extern int	g_fail;

int		check(int ok, const char *name);
void	del(void *content);
void	free_split(char **r);
char	ft_toupper_f(unsigned int i, char c);
void	ft_inc_iter(unsigned int i, char *c);

#endif
