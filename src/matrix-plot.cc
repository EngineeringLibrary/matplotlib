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

MatrixPlot::MatrixPlot()
{
	this->Alpha(0);
	this->Light(true);

	this->autoRange = true;

}

void MatrixPlot::saveToFile(const string filename)
{
	this->WritePNG(filename.c_str());
}

void MatrixPlot::plot1d(Matrix & referenceMatrix, const string plotTitle){

	int matrixRows = referenceMatrix.getRows();
	int matrixCols = referenceMatrix.getCols();

	mglData matrix_X_coordinates(matrixRows);
	mglData matrix_Y_coordinates(matrixRows);

	range matrixRange;

	float matrixData[matrixRows][matrixCols];

	for (int i=0; i < matrixRows; i++)
	{

		for (int j=0; j < matrixCols; j++)
		{
			float dataPoint = referenceMatrix.getMat(i+1,j+1);

			if (j == 0)
			{

				//Min_x
				try {
					if (dataPoint < matrixRange.x_min)
						matrixRange.x_min = dataPoint;
				} catch (...) {
					matrixRange.x_min = dataPoint;
				}

				//Max_x
				try {
					if (dataPoint > matrixRange.x_max)
						matrixRange.x_max = dataPoint;
				} catch (...) {
					matrixRange.x_max = dataPoint;
				}


				matrix_X_coordinates.a[i] = dataPoint;
			}
			else
			{
				//Min_x
				try {
					if (dataPoint < matrixRange.y_min)
						matrixRange.y_min = dataPoint;
				} catch (...) {
					matrixRange.y_min = dataPoint;
				}

				//Max_x
				try {
					if (dataPoint > matrixRange.y_max)
						matrixRange.y_max = dataPoint;
				} catch (...) {
					matrixRange.y_max = dataPoint;
				}

				matrix_Y_coordinates.a[i] = dataPoint;
			}

		}

	}

	this->SetOrigin(0,0,0);

	this->SubPlot(1, 1, 0,""); //cols; lines; 3o 0 <t 1 t> 2 <b 3 b> (POSICAO INDICE)

	if (plotTitle != "")
		this->Title(plotTitle.c_str());

	this->Axis("xy");

	if (this->autoRange)
	{
		this->SetRange('x', matrixRange.x_min, matrixRange.x_max);
		this->SetRange('y', matrixRange.y_min, matrixRange.y_max);
	}

	this->Plot(matrix_X_coordinates, matrix_Y_coordinates);

}

void MatrixPlot::setAutoRange(bool option)
{
	this->autoRange = option;
}
