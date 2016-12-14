/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:41:29 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:33:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}