/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <limits.h>
#include <ctype.h>

static int	test_toupper(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_toupper ---\n");
	f += check(ft_toupper('a') == 'A', "a to A");
	f += check(ft_toupper('z') == 'Z', "z to Z");
	f += check(ft_toupper('A') == 'A', "A stays");
	f += check(ft_toupper('0') == '0', "0 stays");
	f += check(ft_toupper('m') == toupper('m'), "match m");
	return (f);
}

static int	test_tolower(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_tolower ---\n");
	f += check(ft_tolower('A') == 'a', "A to a");
	f += check(ft_tolower('Z') == 'z', "Z to z");
	f += check(ft_tolower('a') == 'a', "a stays");
	f += check(ft_tolower('5') == '5', "5 stays");
	f += check(ft_tolower('K') == tolower('K'), "match K");
	return (f);
}

static int	test_atoi(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_atoi ---\n");
	f += check(ft_atoi("42") == 42, "positive");
	f += check(ft_atoi("-42") == -42, "negative");
	f += check(ft_atoi("0") == 0, "zero");
	f += check(ft_atoi("+42") == 42, "explicit +");
	f += check(ft_atoi("  +42") == 42, "spaces");
	f += check(ft_atoi("\t\n42") == 42, "whitespace");
	f += check(ft_atoi("--42") == 0, "double -");
	f += check(ft_atoi("abc") == 0, "non-numeric");
	f += check(ft_atoi("2147483647") == 2147483647, "INT_MAX");
	return (f);
}

static int	test_itoa(void)
{
	char	*s;
	int		f;

	f = 0;
	printf("\n--- ft_itoa ---\n");
	s = ft_itoa(42);
	f += check(s && !strcmp(s, "42"), "positive");
	free(s);
	s = ft_itoa(-42);
	f += check(s && !strcmp(s, "-42"), "negative");
	free(s);
	s = ft_itoa(0);
	f += check(s && !strcmp(s, "0"), "zero");
	free(s);
	s = ft_itoa(INT_MIN);
	f += check(s && !strcmp(s, "-2147483648"), "INT_MIN");
	free(s);
	s = ft_itoa(INT_MAX);
	f += check(s && !strcmp(s, "2147483647"), "INT_MAX");
	free(s);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_toupper();
	fail += test_tolower();
	fail += test_atoi();
	fail += test_itoa();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
