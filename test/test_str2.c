/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_strnstr(void)
{
	char	*res;
	int		f;

	f = 0;
	printf("\n--- ft_strnstr ---\n");
	res = ft_strnstr("hello world", "world", 11);
	f += check(res && !strcmp(res, "world"), "finds");
	f += check(ft_strnstr("hello world", "xyz", 11) == NULL, "null miss");
	f += check(ft_strnstr("hello", "hello", 3) == NULL, "no room");
	res = ft_strnstr("abcdef", "cd", 6);
	f += check(res && !strcmp(res, "cdef"), "middle");
	return (f);
}

static int	test_strjoin(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_strjoin ---\n");
	s = ft_strjoin("hello", " world");
	f += check(s && !strcmp(s, "hello world"), "basic");
	free(s);
	s = ft_strjoin("", "world");
	f += check(s && !strcmp(s, "world"), "empty s1");
	free(s);
	s = ft_strjoin("hello", "");
	f += check(s && !strcmp(s, "hello"), "empty s2");
	free(s);
	s = ft_strjoin("", "");
	f += check(s && !strcmp(s, ""), "both empty");
	free(s);
	return (f);
}

static int	test_substr(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_substr ---\n");
	s = ft_substr("hello world", 6, 5);
	f += check(s && !strcmp(s, "world"), "basic");
	free(s);
	s = ft_substr("hello", 0, 5);
	f += check(s && !strcmp(s, "hello"), "full");
	free(s);
	s = ft_substr("hello", 0, 100);
	f += check(s && !strcmp(s, "hello"), "len big");
	free(s);
	s = ft_substr("hello", 10, 5);
	f += check(s && !strcmp(s, ""), "start big");
	free(s);
	s = ft_substr("hello", 3, 10);
	f += check(s && !strcmp(s, "lo"), "exceeds");
	free(s);
	return (f);
}

static int	test_strdup(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_strdup ---\n");
	s = ft_strdup("hello");
	f += check(s && !strcmp(s, "hello"), "dups str");
	free(s);
	s = ft_strdup("");
	f += check(s && !strcmp(s, ""), "dups empty");
	free(s);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_strnstr();
	fail += test_strjoin();
	fail += test_substr();
	fail += test_strdup();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
