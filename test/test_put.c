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
#include <fcntl.h>

static void	suppress_output(int *saved_fd)
{
	*saved_fd = dup(1);
	int	dev_null = open("/dev/null", O_WRONLY);
	dup2(dev_null, 1);
	close(dev_null);
}

static void	restore_output(int saved_fd)
{
	dup2(saved_fd, 1);
	close(saved_fd);
}

static int	test_putchar_fd(void)
{
	int	f;
	int	saved;

	f = 0;
	printf("\n--- ft_putchar_fd ---\n");
	suppress_output(&saved);
	ft_putchar_fd('X', 1);
	restore_output(saved);
	f += check(1, "putchar_fd X");
	return (f);
}

static int	test_putstr_fd(void)
{
	int	f;
	int	saved;

	f = 0;
	printf("\n--- ft_putstr_fd ---\n");
	suppress_output(&saved);
	ft_putstr_fd("hello", 1);
	restore_output(saved);
	f += check(1, "putstr_fd hello");
	return (f);
}

static int	test_putendl_fd(void)
{
	int	f;
	int	saved;

	f = 0;
	printf("\n--- ft_putendl_fd ---\n");
	suppress_output(&saved);
	ft_putendl_fd("hello", 1);
	restore_output(saved);
	f += check(1, "putendl_fd hello");
	return (f);
}

static int	test_putnbr_fd(void)
{
	int	f;
	int	saved;

	f = 0;
	printf("\n--- ft_putnbr_fd ---\n");
	suppress_output(&saved);
	ft_putnbr_fd(42, 1);
	ft_putnbr_fd(-42, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putnbr_fd(-2147483648, 1);
	restore_output(saved);
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
