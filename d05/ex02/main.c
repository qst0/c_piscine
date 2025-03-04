/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:35:48 by kyork             #+#    #+#             */
/*   Updated: 2016/08/17 20:05:20 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

char	*g_testcases[] = {
	"1000",
	"0000123",
	"   +42",
	"   -42",
	"a+42",
	"- 42",
	"+-42",
	"\r\n\t\v42",
	"",
	"\\1",
	"+1",
	"-1",
	"-+1",
	"+-1",
	"--1",
	"++1",
	"2147483647",
	"2147483648",
	"2147483649",
	"-2147483647",
	"-2147483648",
	"-2147483649",
	"1789324638",
	"11221f11",
	"42 43 44 45 46",
	"9223372036854775807",
	"9223372036854775808",
	"9223372036854775809",
	"-9223372036854775807",
	"-9223372036854775808",
	"-9223372036854775809",
	"      9223372036854775809",
	"  \r\n\t\v\f    9223372036854775806",
	"18446744073709551615",
	"18446744073709551616",
	"18446744073709551617",
	"-18446744073709551615",
	"-18446744073709551616",
	"-18446744073709551617",
	"10000000000000000000",
	"-10000000000000000000",
	"-33333333333333333333",
	"-333333333333333333333",
	"36893488147419103237",
	"00000000000000000000000000042",
	"  +00000000000000000000000000042",
};

int		main(void)
{
	int i;
	int result;
	int stdlib;

	i = 0;
	while (i < (int)(sizeof(g_testcases) / sizeof(char*)))
	{
		result = ft_atoi(g_testcases[i]);
		stdlib = atoi(g_testcases[i]);
		printf("atoi(%s)\nLib: %d\nYou: %d\n", g_testcases[i], stdlib, result);
		if (stdlib != result)
			printf("FAIL\n");
		i++;
	}
}
