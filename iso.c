/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:42:34 by srupp             #+#    #+#             */
/*   Updated: 2020/02/24 21:42:37 by srupp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	helper_to_iso_l(b_list *co, double **m1, coords *sav, coords *sav2)
{
	int *p1;
	int *p2;

	p2 = malloc(sizeof(int) * 2);
	while (sav2->y1 < co->issues.len)
	{
		while (sav2->x1 < co->issues.height - 1)
		{
			p2[0] = sav2->x1;
			p2[1] = sav2->y1;
			p1 = mltpl_mtrx4(m1, p2, co->issues.init_arr[sav2->x1][sav2->y1],
			sav2->x2);
			sav->x1 = WHIDTH / 3 + p1[0];
			sav->y1 = HIDHT / 3 + p1[1] + 50;
			free(p1);
			sav2->x1++;
			p2[0] = sav2->x1;
			p1 = mltpl_mtrx4(m1, p2, co->issues.init_arr[sav2->x1][sav2->y1],
			sav2->x2);
			sav->x2 = WHIDTH / 3 + p1[0];
			sav->y2 = HIDHT / 3 + p1[1] + 50;
			free(p1);
			drawline(sav, co->conn_id, co->win_id);
		}
		sav2->x1 = 0;
		sav2->y1++;
	}
	free(p2);
}

void	helper_to_iso_h(b_list *co, double **m1, coords *sav, coords *sav2)
{
	int		*p1;
	int		*p2;

	p2 = malloc(sizeof(int) * 2);
	while (sav2->x1 < co->issues.height)
	{
		while (sav2->y1 < co->issues.len - 1)
		{
			p2[0] = sav2->x1;
			p2[1] = sav2->y1;
			p1 = mltpl_mtrx4(m1, p2, co->issues.init_arr[sav2->x1][sav2->y1],
			sav2->x2);
			sav->x1 = WHIDTH / 3  + p1[0];
			sav->y1 = HIDHT / 3  + p1[1] + 50;
			free(p1);
			sav2->y1++;
			p2[1] = sav2->y1;
			p1 = mltpl_mtrx4(m1, p2, co->issues.init_arr[sav2->x1][sav2->y1],
			sav2->x2);
			sav->x2 = WHIDTH / 3   + p1[0];
			sav->y2 = HIDHT / 3  + p1[1] + 50;
			free(p1);
			drawline(sav, co->conn_id, co->win_id);
		}
		sav2->y1 = 0;
		sav2->x1++;
	}
	free(p2);
}

void	to_iso_len(b_list *co, double **m1, int c)
{
	coords	*sav;
	coords	*sav2;

	sav2 = malloc(sizeof(coords));
	sav2->x1 = 0;
	sav2->y1 = 0;
	sav2->x2 = c;
	sav = (coords *)malloc(sizeof(coords));
	helper_to_iso_l(co, m1, sav, sav2);
	free(sav);
	free(sav2);
}

void	to_iso_height(b_list *co, double **m1, int c)
{
	coords	*sav;
	coords	*sav2;

	sav2 = malloc(sizeof(coords));
	sav2->x1 = 0;
	sav2->y1 = 0;
	sav2->x2 = c;
	sav = (coords *)malloc(sizeof(coords));
	helper_to_iso_h(co, m1, sav, sav2);
	free(sav);
	free(sav2);
}

void		to_iso(b_list *co, double **m1)
{
	int max_z;
	int min_z;
	int c;

	max_z = arr_max((co->issues));
	min_z = arr_min((co->issues));
	c = sqrt(co->issues.len * co->issues.len + co->issues.height *
	co->issues.height);
	if (fabs((double)max_z) + fabs((double)min_z) > c)
		c = fabs((double)max_z) + fabs((double)min_z) / 3;
	c = HIDHT / (2 * c);
	if (c == 0)
		c = 1;
	to_iso_len(co, m1, c);
	to_iso_height(co, m1, c);
}
