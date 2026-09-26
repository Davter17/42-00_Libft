/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <unistd.h>

static int	test_putchar_fd(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_putchar_fd ---\n");
	printf("  (visual: expect 'X') ");
	ft_putchar_fd('X', 1);
	printf("\n");
	f += check(1, "putchar_fd X");
	return (f);
}

static int	test_putstr_fd(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_putstr_fd ---\n");
	printf("  (visual: expect 'hello') ");
	ft_putstr_fd("hello", 1);
	printf("\n");
	f += check(1, "putstr_fd hello");
	return (f);
}

static int	test_putendl_fd(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_putendl_fd ---\n");
	printf("  (visual: expect 'hello\\n') ");
	ft_putendl_fd("hello", 1);
	f += check(1, "putendl_fd hello");
	return (f);
}

static int	test_putnbr_fd(void)
{
	int	f;

	f = 0;
	printf("\n--- ft_putnbr_fd ---\n");
	printf("  (visual: 42 -42 0 MAX MIN) ");
	ft_putnbr_fd(42, 1);
	write(1, " ", 1);
	ft_putnbr_fd(-42, 1);
	write(1, " ", 1);
	ft_putnbr_fd(0, 1);
	write(1, " ", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, " ", 1);
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	f += check(1, "putnbr_fd vals");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_putchar_fd();
	fail += test_putstr_fd();
	fail += test_putendl_fd();
	fail += test_putnbr_fd();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
