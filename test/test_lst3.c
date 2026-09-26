/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static void	ft_print(void *content)
{
	printf("%s", (char *)content);
}

static int	test_lstiter(void)
{
	t_list	*lst;
	int		f;

	f = 0;
	printf("\n--- ft_lstiter ---\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(" ")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	printf("  (visual: 'hello world') ");
	ft_lstiter(lst, ft_print);
	printf("\n");
	f += check(1, "iterates all");
	ft_lstclear(&lst, del);
	return (f);
}

static void	*ft_double(void *content)
{
	char	*s;
	char	*r;

	s = (char *)content;
	r = malloc(strlen(s) * 2 + 1);
	if (!r)
		return (NULL);
	strcpy(r, s);
	strcat(r, s);
	return (r);
}

static void	free_list(t_list *lst)
{
	t_list	*tmp;
	t_list	*nx;

	tmp = lst;
	while (tmp)
	{
		nx = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = nx;
	}
}

static int	test_lstmap(void)
{
	t_list	*lst;
	t_list	*new;
	int		f;

	f = 0;
	printf("\n--- ft_lstmap ---\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ab")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("cd")));
	new = ft_lstmap(lst, ft_double, del);
	f += check(new != NULL, "non-NULL");
	f += check(!strcmp((char *)new->content, "abab"), "first map");
	f += check(!strcmp((char *)new->next->content, "cdcd"), "2nd map");
	f += check(ft_lstsize(new) == 2, "same size");
	free_list(new);
	ft_lstclear(&lst, del);
	return (f);
}

int	main(void)
{
	int	fail;

	g_pass = 0;
	g_fail = 0;
	fail = 0;
	fail += test_lstiter();
	fail += test_lstmap();
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	return (fail);
}
