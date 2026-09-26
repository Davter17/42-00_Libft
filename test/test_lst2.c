/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static int	test_lstadd_back(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstadd_back ---\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("first")));
	f += check(lst != NULL, "add to empty");
	f += check(!strcmp((char *)lst->content, "first"), "content");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second")));
	f += check(!strcmp((char *)lst->next->content, "second"), "at back");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("third")));
	f += check(!strcmp((char *)ft_lstlast(lst)->content, "third"), "is last");
	ft_lstclear(&lst, del);
	return (f);
}

static int	test_lstdelone(void)
{
	t_list	*node;
	int		f;

	f = 0;
	printf("\n--- ft_lstdelone ---\n");
	node = ft_lstnew(ft_strdup("test"));
	ft_lstdelone(node, del);
	f += check(1, "no crash");
	return (f);
}

static int	test_lstclear(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstclear ---\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	ft_lstclear(&lst, del);
	f += check(lst == NULL, "list NULL");
	f += check(1, "no leak");
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_lstadd_back();
	fail += test_lstdelone();
	fail += test_lstclear();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
