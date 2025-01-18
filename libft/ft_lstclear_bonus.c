#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (!del || !lst)
		return ;
	while (*lst && lst)
	{
		a = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
	*lst = 0;
}
