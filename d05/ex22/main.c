/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:08:15 by kyork             #+#    #+#             */
/*   Updated: 2016/08/16 13:31:07 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr_non_printable(char *str);

char	g_putchar[1000];
int		g_putchar_idx;
int		g_putchar_save_off;

int		ft_putchar(char c)
{
	if (!g_putchar_save_off)
		g_putchar[g_putchar_idx++] = c;
	write(1, &c, 1);
	return (0);
}

char	g_expected[] = "\\01\\02\\03\\04\\05\\06\\07\\08\\09\\0A\\0B\\0C\\0D"
"\\0E\\0F\\10\\11\\12\\13\\14\\15\\16\\17\\18\\19\\1A\\1B\\1C\\1D\\1E\\1F"
" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdef"
"ghijklmnopqrstuvwxyz{|}~\\7F\\80\\81\\82\\83\\84\\85\\86\\87\\88\\89\\8A"
"\\8B\\8C\\8D\\8E\\8F\\90\\91\\92\\93\\94\\95\\96\\97\\98\\99\\9A\\9B\\9C"
"\\9D\\9E\\9F\\A0\\A1\\A2\\A3\\A4\\A5\\A6\\A7\\A8\\A9\\AA\\AB\\AC\\AD\\AE"
"\\AF\\B0\\B1\\B2\\B3\\B4\\B5\\B6\\B7\\B8\\B9\\BA\\BB\\BC\\BD\\BE\\BF\\C0"
"\\C1\\C2\\C3\\C4\\C5\\C6\\C7\\C8\\C9\\CA\\CB\\CC\\CD\\CE\\CF\\D0\\D1\\D2"
"\\D3\\D4\\D5\\D6\\D7\\D8\\D9\\DA\\DB\\DC\\DD\\DE\\DF\\E0\\E1\\E2\\E3\\E4"
"\\E5\\E6\\E7\\E8\\E9\\EA\\EB\\EC\\ED\\EE\\EF\\F0\\F1\\F2\\F3\\F4\\F5\\F6"
"\\F7\\F8\\F9\\FA\\FB\\FC\\FD\\FE\\FF";

int		main(void)
{
	char	buf[257];
	int		i;

	i = 0;
	while (++i < 256)
		buf[i - 1] = i;
	buf[256] = 0;
	if (!buf[0])
		ft_putchar('X');
	g_putchar_save_off = 0;
	ft_putstr_non_printable(buf);
	g_putchar_save_off = 1;
	ft_putchar('\n');
	if (strcmp(g_expected, g_putchar))
		printf("FAIL\n");
	printf("%s\n", g_expected);
}
