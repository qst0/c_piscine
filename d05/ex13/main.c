/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:04:56 by kyork             #+#    #+#             */
/*   Updated: 2016/08/16 12:01:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef char		*t_testcase;

int					ft_str_is_lowercase(char *str);

t_testcase			g_testcases[] = {
	"",
	"46804",
	"by",
	"ab123cd",
	"éèâ, î or ôñü or ïç",
	"by",
	"short long string",
	"shortLONGstring",
	"short",
	"The rain in Spain",
	"The rain in sPain",
};

int					main(void)
{
	int		i;
	int		result;

	i = 0;
	while (i < (int)(sizeof(g_testcases) / sizeof(t_testcase)))
	{
		result = ft_str_is_lowercase(g_testcases[i]);
		printf("str_is_lowercase(%s) = %d\n", g_testcases[i], result);
		i++;
	}
	return (0);
}
