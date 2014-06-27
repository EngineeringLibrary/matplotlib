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
#include "MatrixPlotWindow.h"

MatrixPlot::MatrixPlot(int subplotCols, int subplotRows)
{
	this->Alpha(0);
	this->Light(true);

	this->autoRange = true;
	this->subplotCols = subplotCols;
	this->subplotRows = subplotRows;

}

void MatrixPlot::plot1d(Matrix & referenceMatrix, int subplotIndex){

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

	//Subplotagem

	this->SubPlot(
			this->subplotCols,
			this->subplotRows,
			subplotIndex, "");

	this->Axis("xy");

	if (this->autoRange)
	{
		this->SetRange('x', matrixRange.x_min, matrixRange.x_max);
		this->SetRange('y', matrixRange.y_min, matrixRange.y_max);
	}

	this->Plot(matrix_X_coordinates, matrix_Y_coordinates);

}

void MatrixPlot::plot1d(Matrix & xMatrix, Matrix & yMatrix){

	if (xMatrix.getRows() != yMatrix.getRows() && xMatrix.getCols() != yMatrix.getCols())
		cerr << "Matrizes de coordenadas incompativeis. Encerrando aplicativo";

	int matrixPlotRows = xMatrix.getRows();
	int subplotAmount = xMatrix.getCols();

	mglData matrix_X_coordinates(matrixPlotRows);
	mglData matrix_Y_coordinates(matrixPlotRows);

	range matrixRange;

	float matrixDataPoint;
	for (int subplotIndex=0; subplotIndex < subplotAmount; subplotIndex++)
	{
		for (int matrixPlotRowIndex=0; matrixPlotRowIndex < matrixPlotRows; matrixPlotRowIndex++)
		{
			float x = xMatrix.getMat((matrixPlotRowIndex+1), (subplotIndex+1));
			float y = yMatrix.getMat((matrixPlotRowIndex+1), (subplotIndex+1));

			matrix_X_coordinates.a[matrixPlotRowIndex] = x;
			matrix_Y_coordinates.a[matrixPlotRowIndex] = y;

			//minMax x
			try {
				if (x < matrixRange.x_min)
					matrixRange.x_min = x;
			} catch (...) {
				matrixRange.x_min = x;
			}

			try {
				if (x > matrixRange.x_max)
					matrixRange.x_max = x;
			} catch (...) {
				matrixRange.x_max = x;
			}

			//minMax y
			//minMax x
			try {
				if (y < matrixRange.y_min)
					matrixRange.y_min = y;
			} catch (...) {
				matrixRange.y_min = y;
			}

			try {
				if (y > matrixRange.y_max)
					matrixRange.y_max = y;
			} catch (...) {
				matrixRange.y_max = y;
			}
		}

		this->SetOrigin(0,0,0);

		//Subplotagem

		/*this->SubPlot(
				this->subplotCols,
				this->subplotRows,
				0, "");

		this->Axis("xy");*/

		string color = "";
		switch (subplotIndex)
		{
		case 0:
			color = "r";
			break;
		case 1:
			color = "g";
			break;
		case 2:
			color = "b";
			break;
		}

		if (this->autoRange && subplotIndex == (subplotAmount-1))
		{
			this->SetRange('x', matrixRange.x_min, matrixRange.x_max);
			this->SetRange('y', matrixRange.y_min, matrixRange.y_max);
		}

		this->Axis("xy");
		this->Plot(matrix_X_coordinates, matrix_Y_coordinates, color.c_str());
		this->AddLegend("Plot",color.c_str());
	}

	this->Legend();

}

void MatrixPlot::plotbox(Matrix & referenceMatrix, int subplotIndex)
{
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

		//Subplotagem

		this->SubPlot(
				this->subplotCols,
				this->subplotRows,
				subplotIndex, "");

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

void MatrixPlot::saveToFile(const string filename)
{
	this->WriteEPS(filename.c_str());
}
