/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_lstnew(void)
{
	t_list	*node;
	int		f;

	f = 0;
	printf("\n--- ft_lstnew ---\n");
	node = ft_lstnew(ft_strdup("hello"));
	f += check(node != NULL, "non-NULL");
	f += check(node->next == NULL, "next NULL");
	f += check(!strcmp((char *)node->content, "hello"), "content");
	ft_lstclear(&node, del);
	node = ft_lstnew(NULL);
	f += check(node != NULL && node->content == NULL, "NULL content");
	free(node);
	return (f);
}

static int	test_lstadd_front(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstadd_front ---\n");
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("first")));
	f += check(lst != NULL, "add to empty");
	f += check(!strcmp((char *)lst->content, "first"), "content ok");
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("second")));
	f += check(!strcmp((char *)lst->content, "second"), "new first");
	f += check(!strcmp((char *)lst->next->content, "first"), "old second");
	ft_lstclear(&lst, del);
	return (f);
}

static int	test_lstsize(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstsize ---\n");
	lst = NULL;
	f += check(ft_lstsize(lst) == 0, "empty = 0");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("a")));
	f += check(ft_lstsize(lst) == 1, "one = 1");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	f += check(ft_lstsize(lst) == 3, "three = 3");
	ft_lstclear(&lst, del);
	return (f);
}

static int	test_lstlast(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstlast ---\n");
	lst = NULL;
	f += check(ft_lstlast(lst) == NULL, "empty NULL");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	f += check(!strcmp((char *)ft_lstlast(lst)->content, "c"), "last node");
	ft_lstclear(&lst, del);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_lstnew();
	fail += test_lstadd_front();
	fail += test_lstsize();
	fail += test_lstlast();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
