/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:52:13 by tbarbe            #+#    #+#             */
/*   Updated: 2023/06/30 19:19:07 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

static float rotate_x(std::array<float, 3> v, std::array<float, 3> a)
{
	float res;
	float c;

	c = cos(a[0]) * cos(a[1]);
	res = c * v[0];
	c = cos(a[0]) * sin(a[1]) * sin(a[2]) - sin(a[0]) * cos(a[2]);
	res += c * v[1];
	c = cos(a[0]) * sin(a[1]) * cos(a[2]) + sin(a[0]) * sin(a[2]);
	res += c * v[2];
	return (res);
}

static float rotate_y(std::array<float, 3> v, std::array<float, 3> a)
{
	float res;
	float c;

	c = sin(a[0]) * cos(a[1]);
	res = c * v[0];
	c = sin(a[0]) * sin(a[1]) * sin(a[2]) + cos(a[0]) * cos(a[2]);
	res += c * v[1];
	c = sin(a[0]) * sin(a[1]) * cos(a[2]) - cos(a[0]) * sin(a[2]);
	res += c * v[2];
	return (res);
}

static float rotate_z(std::array<float, 3> v, std::array<float, 3> a)
{
	float res;
	float c;

	c = -sin(a[1]);
	res = c * v[0];
	c = cos(a[1]) * sin(a[2]);
	res += c * v[1];
	c = cos(a[1]) * cos(a[2]);
	res += c * v[2];
	return (res);
}

void rotate(std::array<float, 3> &v, std::array<float, 3> const &a)
{
	std::array<float, 3> res;

	res[0] = rotate_x(v, a);
	res[1] = rotate_y(v, a);
	res[2] = rotate_z(v, a);
	v = res;
}
