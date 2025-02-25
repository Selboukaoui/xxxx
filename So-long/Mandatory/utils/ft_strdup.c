/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:51:18 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/22 17:52:47 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = ft_strlen(src);
	p = ft_malloc(i + 1, 1);
	if (!p)
		err(26);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}