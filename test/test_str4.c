/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_strtrim(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_strtrim ---\n");
	s = ft_strtrim("  hello  ", " ");
	f += check(s && !strcmp(s, "hello"), "spaces");
	free(s);
	s = ft_strtrim("xxxhelloxxx", "x");
	f += check(s && !strcmp(s, "hello"), "custom");
	free(s);
	s = ft_strtrim("hello", "xyz");
	f += check(s && !strcmp(s, "hello"), "no trim");
	free(s);
	s = ft_strtrim("aaa", "a");
	f += check(s && !strcmp(s, ""), "all trim");
	free(s);
	s = ft_strtrim("abcba", "ab");
	f += check(s && !strcmp(s, "c"), "both sides");
	free(s);
	return (f);
}

static int	test_strmapi(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_strmapi ---\n");
	s = ft_strmapi("hello", ft_toupper_f);
	f += check(s && !strcmp(s, "HELLO"), "toupper");
	free(s);
	s = ft_strmapi("", ft_toupper_f);
	f += check(s && !strcmp(s, ""), "empty");
	free(s);
	return (f);
}

static int	test_striteri(void)
{
	char	s[4];
	char	s2[1];
	int		f;

	f = 0;
	printf("\n--- ft_striteri ---\n");
	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = '\0';
	s2[0] = '\0';
	ft_striteri(s, ft_inc_iter);
	f += check(!strcmp(s, "bcd"), "inc chars");
	ft_striteri(s2, ft_inc_iter);
	f += check(!strcmp(s2, ""), "empty ok");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_strtrim();
	fail += test_strmapi();
	fail += test_striteri();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
