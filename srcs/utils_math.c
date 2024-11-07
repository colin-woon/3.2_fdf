/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:30:18 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:53:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt	matrix_calc(t_matrix3x3 mat, t_pt pt);
t_pt	add_vector(t_pt pt1, t_pt pt2);
t_pt	subtract_vector(t_pt pt1, t_pt pt2);

t_pt	matrix_calc(t_matrix3x3 mat, t_pt pt)
{
	t_pt	result;

	result.x = pt.x * mat.c1r1 + pt.y * mat.c2r1 + pt.z * mat.c3r1;
	result.y = pt.x * mat.c1r2 + pt.y * mat.c2r2 + pt.z * mat.c3r2;
	result.z = pt.x * mat.c1r3 + pt.y * mat.c2r3 + pt.z * mat.c3r3;
	result.colour = pt.colour;
	return (result);
}

t_pt	add_vector(t_pt pt1, t_pt pt2)
{
	t_pt	sum;

	sum.x = pt1.x + pt2.x;
	sum.y = pt1.y + pt2.y;
	sum.z = pt1.z + pt2.z;
	sum.colour = pt1.colour;
	return (sum);
}

t_pt	subtract_vector(t_pt pt1, t_pt pt2)
{
	t_pt	diff;

	diff.x = pt1.x - pt2.x;
	diff.y = pt1.y - pt2.y;
	diff.z = pt1.z - pt2.z;
	diff.colour = pt1.colour;
	return (diff);
}
