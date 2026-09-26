/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_split_basic(void)
{
	char	**r;
	int		f;

	f = 0;
	printf("\n--- ft_split ---\n");
	r = ft_split("hello world foo", ' ');
	f += check(r && r[0] && !strcmp(r[0], "hello"), "w0");
	f += check(r && r[1] && !strcmp(r[1], "world"), "w1");
	f += check(r && r[2] && !strcmp(r[2], "foo"), "w2");
	f += check(r && r[3] == NULL, "null term");
	free_split(r);
	return (f);
}

static int	test_split_edges(void)
{
	char	**r;
	int		f;

	f = 0;
	r = ft_split("  hello  world  ", ' ');
	f += check(r && r[0] && !strcmp(r[0], "hello"), "lead 0");
	f += check(r && r[1] && !strcmp(r[1], "world"), "lead 1");
	f += check(r && r[2] == NULL, "lead null");
	free_split(r);
	r = ft_split("hello", 'x');
	f += check(r && r[0] && !strcmp(r[0], "hello"), "no delim");
	free_split(r);
	r = ft_split("", 'x');
	f += check(r && r[0] == NULL, "empty");
	free_split(r);
	r = ft_split("aaa", 'a');
	f += check(r && r[0] == NULL, "all delim");
	free_split(r);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_split_basic();
	fail += test_split_edges();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
