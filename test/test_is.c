/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <ctype.h>

static int	test_isalpha(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_isalpha ---\n");
	f += check(ft_isalpha('a') && ft_isalpha('Z'), "letters");
	f += check(!ft_isalpha('0') && !ft_isalpha(' '), "non-letters");
	f += check((ft_isalpha('m') != 0) == (isalpha('m') != 0), "match m");
	f += check((ft_isalpha('3') != 0) == (isalpha('3') != 0), "match 3");
	return (f);
}

static int	test_isdigit(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_isdigit ---\n");
	f += check(ft_isdigit('0') && ft_isdigit('9'), "digits");
	f += check(!ft_isdigit('a') && !ft_isdigit(' '), "non-digits");
	f += check((ft_isdigit('7') != 0) == (isdigit('7') != 0), "match 7");
	return (f);
}

static int	test_isalnum(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_isalnum ---\n");
	f += check(ft_isalnum('a') && ft_isalnum('0'), "alnum");
	f += check(!ft_isalnum(' ') && !ft_isalnum('@'), "non-alnum");
	f += check((ft_isalnum('k') != 0) == (isalnum('k') != 0), "match k");
	return (f);
}

static int	test_isascii(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_isascii ---\n");
	f += check(ft_isascii(0) && ft_isascii(127), "valid");
	f += check(!ft_isascii(128) && !ft_isascii(-1), "invalid");
	f += check(ft_isascii(100) == isascii(100), "match 100");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_isalpha();
	fail += test_isdigit();
	fail += test_isalnum();
	fail += test_isascii();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
