/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * matrix-plot.cc
 * Copyright (C) 2014 Jonhnatha Jorge R. Trigueiro <joepreludian@gmail.com>
 *
 * unpplotlib is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * unpplotlib is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include "matrix-plot.h"

MatrixPlot::MatrixPlot(const Matrix &referenceMatrix)
{
	this->matrix = referenceMatrix;
	this->rows = this->matrix.getRows();
	this->cols = this->matrix.getCols();
}
