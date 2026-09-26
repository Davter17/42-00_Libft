/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_memset(void)
{
	char	buf1[20];
	char	buf2[20];
	int		f;

	f = 0;
	printf("\n--- ft_memset ---\n");
	memset(buf1, 'A', 10);
	buf1[10] = '\0';
	ft_memset(buf2, 'A', 10);
	buf2[10] = '\0';
	f += check(!memcmp(buf1, buf2, 10), "fill A");
	memset(buf1, 0, 20);
	ft_memset(buf2, 0, 20);
	f += check(!memcmp(buf1, buf2, 20), "fill 0");
	f += check(ft_memset(buf1, 'x', 0) == buf1, "n=0 ret s");
	return (f);
}

static int	test_bzero(void)
{
	char	buf[20];
	int		f;

	f = 0;
	printf("\n--- ft_bzero ---\n");
	memset(buf, 'A', 20);
	ft_bzero(buf, 10);
	f += check(buf[0] == 0 && buf[9] == 0, "zeros 10");
	f += check(buf[10] == 'A', "preserves");
	memset(buf, 'B', 20);
	ft_bzero(buf, 0);
	f += check(buf[0] == 'B', "n=0 noop");
	return (f);
}

static int	test_memcpy(void)
{
	char	src[12];
	char	dst1[20];
	char	dst2[20];
	int		f;

	f = 0;
	strcpy(src, "hello world");
	printf("\n--- ft_memcpy ---\n");
	memcpy(dst1, src, 11);
	ft_memcpy(dst2, src, 11);
	f += check(!memcmp(dst1, dst2, 11), "copies str");
	f += check(ft_memcpy(dst1, src, 0) == dst1, "n=0 ret dst");
	ft_memcpy(dst2, src, 5);
	dst2[5] = '\0';
	f += check(!strcmp(dst2, "hello"), "copies bytes");
	return (f);
}

static int	test_memmove(void)
{
	char	o1[11];
	char	o2[11];
	char	o3[11];
	char	o4[11];
	int		f;

	f = 0;
	strcpy(o1, "abcdefghij");
	strcpy(o2, "abcdefghij");
	strcpy(o3, "abcdefghij");
	strcpy(o4, "abcdefghij");
	printf("\n--- ft_memmove ---\n");
	memmove(o1 + 2, o1, 5);
	ft_memmove(o2 + 2, o2, 5);
	f += check(!memcmp(o1, o2, 10), "overlap fwd");
	memmove(o3, o3 + 2, 5);
	ft_memmove(o4, o4 + 2, 5);
	f += check(!memcmp(o3, o4, 10), "overlap bwd");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_memset();
	fail += test_bzero();
	fail += test_memcpy();
	fail += test_memmove();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
