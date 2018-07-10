#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "Math.h"

//only up to 26 different var names
char GetMathVarName( DWORD dwIndex );

/// <summary>Outputs a matrix to the console</summary>
/// <param name="pMatrix">a pointer to a matrix</param>
/// <param name="dwMatrixSize">how much dimensions the matrix has</param>
void PrintMatrix( double* pMatrix, DWORD dwMatrixSize );

/// <summary>Reads a matrix from Console Input</summary>
/// <param name="pMatrix">a pointer to a output matrix</param>
/// <param name="dwMatrixSize">how much dimensions the matrix has</param>
void InputMatrix( double* pMatrix, DWORD dwMatrixSize );

/// <summary>Outputs a vector to the console</summary>
/// <param name="pVec">a pointer to a vector</param>
/// <param name="dwVecSize">how much dimensions the vector has</param>
void PrintVector( double* pVec, DWORD dwVecSize );

/// <summary>Reads a vector from Console Input</summary>
/// <param name="pVec">a pointer to a output vector</param>
/// <param name="dwVecSize">how much dimensions the vector has</param>
void InputVector( double* pVec, DWORD dwVecSize );


int main()
{
	DWORD dwDimensions = NULL;
	printf("Enter the Dimensions you want to process: ");
	scanf( "%u", &dwDimensions );

	double* pVector = (double*)alloca( (dwDimensions)*sizeof(double) );
	double* pMatrix = (double*)alloca( (dwDimensions*dwDimensions)*sizeof(double) );
	DWORD dwInput = NULL;
	while (true)
	{
		printf("\nEnter (1)Matrix, (2)Vector, (3)Finished: ");
		scanf( "%u", &dwInput );

		if ( dwInput == 1 )
			InputMatrix( pMatrix, dwDimensions );
		if ( dwInput == 2 )
			InputVector( pVector, dwDimensions );
		if ( dwInput == 3 )
			break; //exit the loop
	}

	dwInput = NULL;
	while (true)
	{
		printf("\nEnter (1)Inverse Matrix, (2)Multiply with Vector, (3)Finished: ");
		scanf( "%u", &dwInput );

		if ( dwInput == 1 )
		{
			MatrixInverse_Custom( pMatrix, pMatrix, dwDimensions );
			printf("The Inversed Matrix:\n");
			PrintMatrix( pMatrix, dwDimensions );
		}
		if ( dwInput == 2 )
		{
			Multiply_Custom( pMatrix, pVector, pVector, dwDimensions );
			printf("The new Vector:\n");
			PrintVector( pVector, dwDimensions );
		}
		if ( dwInput == 3 )
			break; //exit the loop
	}
};

//only up to 26 different var names
char GetMathVarName( DWORD dwIndex )
{
	// X[88], Y[89], Z[90], W[87], V[86], ...

	DWORD OutPut = 'X' + dwIndex;

	if ( OutPut > 'Z' )
	{
		OutPut = 'X' - ( OutPut-'Z' );
	}

	if ( OutPut < 'A' )
		OutPut = '~';

	return OutPut;
}

/// <summary>Outputs a matrix to the console</summary>
/// <param name="pMatrix">a pointer to a matrix</param>
/// <param name="dwMatrixSize">how much dimensions the matrix has</param>
void PrintMatrix( double* pMatrix, DWORD dwMatrixSize )
{
	printf("[ ");
	for (DWORD dwMatOffset = 0, dwVecOffset = 0; ;  )
	{
		double out = pMatrix[ (dwMatOffset*(dwMatrixSize)) + dwVecOffset ];
		if ( out == 0 ) //to prevent "-0.00" output
			out = 0;
		printf("%14.7f", out );
		dwMatOffset++;
		if ( dwMatOffset >= dwMatrixSize )
		{
			printf(" ]\n");
			dwMatOffset = NULL;
			dwVecOffset++;
			if ( dwVecOffset >= dwMatrixSize )
				break;
			printf("[ ");
		}
		else
			printf(" | ");
	}
}

/// <summary>Reads a matrix from Console Input</summary>
/// <param name="pMatrix">a pointer to a output matrix</param>
/// <param name="dwMatrixSize">how much dimensions the matrix has</param>
void InputMatrix( double* pMatrix, DWORD dwMatrixSize )
{
	printf("Enter vector %u\n",1);
	for (DWORD dwMatOffset = 0, dwVecOffset = 0; ; )
	{
		printf("\t -> %c = ",GetMathVarName(dwVecOffset));
		float value = 0.0f;
		scanf( "%f", &value );
		pMatrix[ (dwMatOffset*(dwMatrixSize)) + dwVecOffset ] = value;
		dwVecOffset++;
		if ( dwVecOffset >= dwMatrixSize )
		{
			dwVecOffset = NULL;
			dwMatOffset++;
			if ( dwMatOffset >= dwMatrixSize )
				break;
			printf("Enter vector %u\n",dwMatOffset+1);
		}
	}
}

/// <summary>Outputs a vector to the console</summary>
/// <param name="pVec">a pointer to a vector</param>
/// <param name="dwVecSize">how much dimensions the vector has</param>
void PrintVector( double* pVec, DWORD dwVecSize )
{
	for (DWORD dwVecOffset = 0; dwVecOffset < dwVecSize ; dwVecOffset++ )
	{
		printf("[ %14.7f ]\n", pVec[ dwVecOffset ] );
	}
}

/// <summary>Reads a vector from Console Input</summary>
/// <param name="pVec">a pointer to a output vector</param>
/// <param name="dwVecSize">how much dimensions the vector has</param>
void InputVector( double* pVec, DWORD dwVecSize )
{
	printf("Enter vector:\n");
	for (DWORD dwVecOffset = 0; dwVecOffset < dwVecSize ; dwVecOffset++ )
	{
		printf("\t -> %c = ",GetMathVarName(dwVecOffset));
		float value = 0.0f;
		scanf( "%f", &value );
		pVec[ dwVecOffset ] = value;
	}
}
