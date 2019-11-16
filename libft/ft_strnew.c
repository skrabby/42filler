/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:58:12 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/15 15:23:57 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size == SIZE_MAX)
		return (0);
	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (0);
	ft_bzero(mem, size + 1);
	return (mem);
}
