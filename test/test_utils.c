/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int	g_pass;
int	g_fail;

int	check(int ok, const char *name)
{
	if (ok)
	{
		printf("  \033[32mPASS\033[0m %s\n", name);
		g_pass++;
	}
	else
	{
		printf("  \033[31mFAIL\033[0m %s\n", name);
		g_fail++;
	}
	return (!ok);
}

void	del(void *content)
{
	free(content);
}

void	free_split(char **r)
{
	int	i;

	if (!r)
		return ;
	i = 0;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
}

char	ft_toupper_f(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_inc_iter(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}
