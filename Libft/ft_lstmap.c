/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:19:51 by mikkhach          #+#    #+#             */
/*   Updated: 2023/03/16 15:20:08 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	const t_list	*lstp = lst;
	void			*is_success;
	t_list			*ret;
	t_list			*new;

	ret = NULL;
	new = NULL;
	while (lstp)
	{
		is_success = f(lstp->content);
		if (is_success)
		{
			new = ft_lstnew(is_success);
			if (!(new))
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, new);
		}
		lstp = lstp->next;
	}
	return (ret);
}
