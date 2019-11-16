/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:37:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/11 16:29:32 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		s3 = (char*)malloc(sizeof(s2) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s3)
			return (0);
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
		return (s3);
	}
	return (NULL);
}
