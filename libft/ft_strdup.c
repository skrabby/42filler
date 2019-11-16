/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:19:44 by skrabby           #+#    #+#             */
/*   Updated: 2019/10/04 22:40:00 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	int		i;
	char	*temp;

	i = 0;
	if (str == NULL)
		return (NULL);
	length = ft_strlen(str);
	temp = (char*)malloc(sizeof(char) * (length + 1));
	if (!temp)
		return (0);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
