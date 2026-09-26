/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <ctype.h>

static int	test_isprint(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_isprint ---\n");
	f += check(ft_isprint(' ') && ft_isprint('~'), "printable");
	f += check(!ft_isprint(0) && !ft_isprint(127), "non-print");
	f += check((ft_isprint('x') != 0) == (isprint('x') != 0), "match x");
	return (f);
}

static int	test_memchr(void)
{
	char	str[12];
	int		f;

	f = 0;
	strcpy(str, "hello world");
	printf("\n--- ft_memchr ---\n");
	f += check(ft_memchr(str, 'w', 11) == memchr(str, 'w', 11), "finds w");
	f += check(ft_memchr(str, 'z', 11) == NULL, "null miss");
	f += check(ft_memchr(str, 'l', 3) == memchr(str, 'l', 3), "in range");
	return (f);
}

static int	test_memcmp(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_memcmp ---\n");
	f += check(ft_memcmp("hello", "hello", 5) == 0, "equal");
	f += check(ft_memcmp("hello", "hella", 5) > 0, "o > a");
	f += check(ft_memcmp("hella", "hello", 5) < 0, "a < o");
	f += check(ft_memcmp("abc", "abd", 3) < 0, "c < d");
	f += check(ft_memcmp("abc", "xyz", 0) == 0, "n=0 ret 0");
	return (f);
}

static int	test_calloc(void)
{
	char	*p;
	int		all_zero;
	int		i;
	int		f;

	f = 0;
	printf("\n--- ft_calloc ---\n");
	p = ft_calloc(10, sizeof(char));
	f += check(p != NULL, "non-NULL");
	all_zero = 1;
	i = 0;
	while (i < 10)
	{
		if (p[i] != 0)
			all_zero = 0;
		i++;
	}
	f += check(all_zero, "zeroed");
	free(p);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_isprint();
	fail += test_memchr();
	fail += test_memcmp();
	fail += test_calloc();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
