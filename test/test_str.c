/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_strlen(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_strlen ---\n");
	f += check(ft_strlen("hello") == 5, "hello = 5");
	f += check(ft_strlen("") == 0, "empty = 0");
	f += check(ft_strlen("abcdef") == strlen("abcdef"), "match len");
	f += check(ft_strlen("a") == 1, "single = 1");
	return (f);
}

static int	test_strlcpy(void)
{
	char	dst1[20];
	char	dst2[20];
	size_t	r1;
	size_t	r2;
	int		f;

	f = 0;
	printf("\n--- ft_strlcpy ---\n");
	r1 = strlcpy(dst1, "hello", 20);
	r2 = ft_strlcpy(dst2, "hello", 20);
	f += check(r1 == r2, "return full");
	f += check(!strcmp(dst1, dst2), "copies str");
	f += check(ft_strlcpy(dst1, "hi", 0) == 2, "dsize=0");
	return (f);
}

static int	test_strlcat(void)
{
	char	dst1[20];
	char	dst2[20];
	size_t	r1;
	size_t	r2;
	int		f;

	f = 0;
	printf("\n--- ft_strlcat ---\n");
	memset(dst1, 0, 20);
	memset(dst2, 0, 20);
	strcpy(dst1, "hello");
	strcpy(dst2, "hello");
	r1 = strlcat(dst1, " world", 20);
	r2 = ft_strlcat(dst2, " world", 20);
	f += check(r1 == r2, "return val");
	f += check(!strcmp(dst1, dst2), "concat ok");
	return (f);
}

static int	test_strncmp(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_strncmp ---\n");
	f += check(ft_strncmp("hello", "hello", 5) == 0, "equal");
	f += check(ft_strncmp("hello", "hella", 5) > 0, "o > a");
	f += check(ft_strncmp("hella", "hello", 5) < 0, "a < o");
	f += check(ft_strncmp("hello", "hello", 3) == 0, "prefix 3");
	f += check(ft_strncmp("abc", "abd", 2) == 0, "prefix 2");
	f += check(ft_strncmp("\x01", "\x02", 1) < 0, "unsigned");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_strlen();
	fail += test_strlcpy();
	fail += test_strlcat();
	fail += test_strncmp();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
