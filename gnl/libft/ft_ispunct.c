/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:18:37 by aillia            #+#    #+#             */
/*   Updated: 2018/11/16 13:26:52 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ispunct(int c)
{
	if ((c > 32 && c < 48) || (c > 57 && c < 65)
			|| (c > 90 && c < 97) || (c > 122 && c < 127))
		return (1);
	else
		return (0);
}