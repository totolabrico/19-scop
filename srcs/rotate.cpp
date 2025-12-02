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

std::array<std::array<float, 3>, 3> rotation_matrix(float ax, float ay, float az)
{
	float cx = cos(ax), sx = sin(ax);
	float cy = cos(ay), sy = sin(ay);
	float cz = cos(az), sz = sin(az);

	static std::array<std::array<float, 3>, 3> res;

	res[0] = {cy * cz, cz * sx * sy - cx * sz, cx * cz * sy + sx * sz};
	res[1] = {cy * sz, cx * cz + sx * sy * sz, -cz * sx + cx * sy * sz};
	res[2] = {-sy, cy * sx, cx * cy};
	return res;
}

static float dot(std::array<float, 3> v, std::array<float, 3> a)
{
	return v[0] * a[0] + v[1] * a[1] + v[2] * a[2];
}

void rotate(std::array<float, 3> &v, std::array<std::array<float, 3>, 3> const &m)
{
	std::array<float, 3> res;

	res[0] = dot(v, m[0]);
	res[1] = dot(v, m[1]);
	res[2] = dot(v, m[2]);
	v = res;
}
