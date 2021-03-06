/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * matrix-plot.h
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

#ifndef _MATRIX_PLOT_H_
#define _MATRIX_PLOT_H_
#include "lib/Matrizes/matrix.h"
#include <iostream>
#include <mgl2/mgl.h>
#include <mgl2/fltk.h>

class MatrixPlot : public mglFLTK
{
public:

	MatrixPlot(int subplotCols = 1, int subplotRows = 1);

	void plot1d(Matrix &, int = 0);
	void plot1d(Matrix &, Matrix &);

	void plotbox(Matrix &, int = 0);

	void setAutoRange(bool);
	void saveToFile(const string);

private:
	bool autoRange;
	int subplotCols, subplotRows;
};

struct range
{
  float x_min;
  float x_max;

  float y_min;
  float y_max;
};

#endif // _MATRIX_PLOT_H_
