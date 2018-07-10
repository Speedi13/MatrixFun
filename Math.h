#pragma once

/////////////////////////////////////////////////////////// Data structures ////////////////////////////////////////////////////////////
#pragma region DataStructures
//Definition of the data types that get used:
struct Vec3
{
    union{ 
		// a union allows access same data in different ways
        struct{ //first way are the three variables below
            double x;
            double y;
            double z;
        };
		//the second way is an array with 3 entries
        double a[3];
    };
};

struct Vec4
{
    union{ 
        struct{
            double x;
            double y;
            double z;
			double w;
        };
        double a[4];
    };
};

struct Vec2
{
    union{ 
        struct{
            double x;
            double y;
        };
        double a[2];
    };
};

struct Matrix_2x2{
    union{ 
        struct{
            Vec2 vec1; //0 | [ 0, 1 ]
            Vec2 vec2; //1 | [ 0, 1 ]
        };
        Vec2 v[2];
        double a[2][2];

		struct
		{
			double _a;
			double _c;
			double _b;
			double _d;
		};
    };
};


struct Matrix{
    union{ 
        struct{
            Vec3 vec1; //0 | [ 0, 1, 2 ]
            Vec3 vec2; //1 | [ 0, 1, 2 ]
            Vec3 vec3; //2 | [ 0, 1, 2 ]
        };
        Vec3 v[3];
        double a[3][3];
    };
};

struct Matrix_4x4{
    union{ 
        struct{
            Vec4 vec1; //0 | [ 0, 1, 2, 3 ]
            Vec4 vec2; //1 | [ 0, 1, 2, 3 ]
            Vec4 vec3; //2 | [ 0, 1, 2, 3 ]
			Vec4 vec4; //3 | [ 0, 1, 2, 3 ]
        };
        Vec4 v[4];
        double a[4][4];
    };
};
#pragma endregion DataStructures
/////////////////////////////////////////////////////////// Structures end /////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////// Function prototypes ////////////////////////////////////////////////////////////
#pragma region FunctionPrototypes
//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
/// <summary>Calculates the Determinant from a 2x2 Determinant matrix</summary>
/// <param name="m">a pointer to a 2x2 matrix</param>
/// <returns>returns Determinant</returns>
double Determinant_2x2( /*IN*/Matrix_2x2* m );

//Laplace Expansion 
//https://www.sophia.org/tutorials/finding-the-determinant-of-a-3-x-3-matrix-using-la
//this function is not needed when a transposed CoFactor matrix is created
/// <summary>Calculates the Determinant from a 3x3 matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <returns>returns Determinant</returns>
double Determinant_3x3( /*IN*/Matrix* m );

/// <summary>Calculates the Determinant from a 3x3 transposed CoFactor matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="DetMatrix">a pointer to a 3x3 transposed CoFactor matrix</param>
/// <returns>returns Determinant</returns>
double DeterminantFromTransposedMatrixOfCofactors_3x3( /*IN*/Matrix* m, /*OUT*/Matrix* TransposeMatOfCoFactors );

//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
//http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/threeD/index.htm
/// <summary>creates a 3x3 matrix with the transposed CoFactors from the input 3x3 matrix</summary>
/// <param name="m">a pointer to the 3x3 input matrix</param>
/// <param name="out">a pointer to the 3x3 output matrix</param>
void CreateTransposedMatrixOfCofactors_3x3( /*IN*/Matrix* m, /*OUT*/Matrix* _out_ );

//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
/// <summary>creates a 4x4 matrix with the transposed CoFactors from the input 4x4 matrix</summary>
/// <param name="m">a pointer to the 4x4 input matrix</param>
/// <param name="out">a pointer to the 4x4 output matrix</param>
void CreateTransposedMatrixOfCofactors_4x4( /*IN*/Matrix_4x4* m, /*OUT*/Matrix_4x4* _out_ );

/// <summary>multiply every value of the matrix 4x4 with d</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="d">value to multiply</param>
void Multiply_4x4( /*IN,OUT*/Matrix_4x4* m, /*IN*/double d );

/// <summary>Calculates the Determinant from a 4x4 transposed CoFactor matrix</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="TransposeMatOfCoFactors">a pointer to a 4x4 Determinant matrix</param>
/// <returns>returns Determinant</returns>
double DeterminantFromTransposedMatrixOfCofactors_4x4( /*IN*/Matrix_4x4* m, /*IN*/Matrix_4x4* TransposeMatOfCoFactors );

//for result control check http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/fourD/index.htm
/// <summary>Inverses a 4x4 matrix</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="mInv">a pointer to the output 4x4 matrix</param>
void MatrixInverse_4x4( /*IN*/Matrix_4x4* m, /*OUT*/Matrix_4x4* mInv );

/// <summary>multiply every value of the matrix 3x3 with d</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="d">value to multiply</param>
void Multiply( /*IN,OUT*/Matrix* m, /*IN*/double d );

//for result control check http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/threeD/index.htm
/// <summary>Inverses a 3x3 matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="mInv">a pointer to the output 3x3 matrix</param>
void MatrixInverse( /*IN*/Matrix* m, /*OUT*/Matrix* mInv );

/// <summary>multiplies the 3d vector with the matrix 3x3</summary>
/// <param name="m">a pointer to the 3x3 matrix</param>
/// <param name="b">a pointer to hte 3d vector</param>
/// <returns>returns the result</returns>
Vec3 Multiply( /*IN,OUT*/Matrix* m, /*IN*/Vec3* b );

/// <summary>Calculates the Determinant from a matrix, look at Determinant_3x3 for more info</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
/// <returns>returns Determinant</returns>
template <class T>
T Determinant_custom( /*IN*/T* m, /*IN*/int Dimensions );

/// <summary>creates a matrix with the transposed CoFactors from the input matrix, look at CreateTransposedMatrixOfCofactors_3x3 for more info</summary>
/// <param name="m">a pointer to the input matrix</param>
/// <param name="out">a pointer to the output matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void CreateTransposedMatrixOfCofactors_Custom( /*IN*/T* m, /*OUT*/T* _out_, /*IN*/int Dimensions );

/// <summary>multiply every value of the matrix with d</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="d">value to multiply</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T> 
void Multiply_Custom( /*IN,OUT*/T* m, /*IN*/T d, /*IN*/int Dimensions );

/// <summary>Inverses a matrix</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="mInv">a pointer to the output matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void MatrixInverse_Custom( /*IN*/T* m, /*OUT*/T* mInv, /*IN*/int Dimensions );

/// <summary>Multiples a matrix with a vector</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="vec">a pointer to the vector</param>
/// <param name="vecOut">a pointer to the output vector</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void Multiply_Custom( /*IN*/T* m, /*IN*/T* vec, /*OUT*/T* vecOut, /*IN*/DWORD Dimensions );
#pragma endregion FunctionPrototypes
////////////////////////////////////////////////////////////// Prototypes end //////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////// Function definitions ///////////////////////////////////////////////////////////
#pragma region FunctionDefinitions
//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
/// <summary>Calculates the Determinant from a 2x2 Determinant matrix</summary>
/// <param name="m">a pointer to a 2x2 matrix</param>
/// <returns>returns Determinant</returns>
double Determinant_2x2( /*IN*/Matrix_2x2* m )
{
	return (m->_a * m->_d) - (m->_b * m->_c);
}

//Laplace Expansion 
//https://www.sophia.org/tutorials/finding-the-determinant-of-a-3-x-3-matrix-using-la
//this function is not needed when a transposed CoFactor matrix is created
/// <summary>Calculates the Determinant from a 3x3 matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <returns>returns Determinant</returns>
double Determinant_3x3( /*IN*/Matrix* m )
{
	double result = 0;
	double factor = 0;
	Matrix_2x2 m2x2;

	//First Row
	//  1  2  3
	//[ #, !, ! ]
	//[ !, y, y ]
	//[ !, z, z ]
	m2x2.vec1.x = m->vec2.y;
	m2x2.vec1.y = m->vec2.z;
	m2x2.vec2.x = m->vec3.y;
	m2x2.vec2.y = m->vec3.z;
	
	//=> #
	factor = m->vec1.x; //plus
	
	result += factor*Determinant_2x2( &m2x2 );

	//Second Row
	//  1  2  3
	//[ !, #, ! ]
	//[ y, !, y ]
	//[ z, !, z ]
	m2x2.vec1.x = m->vec1.y;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec3.y;
	m2x2.vec2.y = m->vec3.z;
	
	//=> #
	factor = - m->vec2.x; //minus

	result += factor*Determinant_2x2( &m2x2 );

	//Third Row
	//  1  2  3
	//[ !, !, # ]
	//[ y, y, ! ]
	//[ z, z, ! ]
	m2x2.vec1.x = m->vec1.y;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec2.y;
	m2x2.vec2.y = m->vec2.z;
	
	//=> #
	factor = m->vec3.x; //plus

	result += factor*Determinant_2x2( &m2x2 );

	return result;
}

/// <summary>Calculates the Determinant from a 3x3 transposed CoFactor matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="TransposeMatOfCoFactors">a pointer to a 3x3 transposed CoFactor matrix</param>
/// <returns>returns Determinant</returns>
double DeterminantFromTransposedMatrixOfCofactors_3x3( /*IN*/Matrix* m, /*OUT*/Matrix* TransposeMatOfCoFactors )
{

	double result = TransposeMatOfCoFactors->vec1.x * m->vec1.x + 
					TransposeMatOfCoFactors->vec1.y * m->vec2.x + 
					TransposeMatOfCoFactors->vec1.z * m->vec3.x ;

	return result;
}

//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
//http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/threeD/index.htm
/// <summary>creates a 3x3 matrix with the transposed CoFactors from the input 3x3 matrix</summary>
/// <param name="m">a pointer to the 3x3 input matrix</param>
/// <param name="out">a pointer to the 3x3 output matrix</param>
void CreateTransposedMatrixOfCofactors_3x3( /*IN*/Matrix* m, /*OUT*/Matrix* _out_ )
{
	double result = 0;
	double factor = 0;
	double c = 0;
	Matrix_2x2 m2x2;

	Matrix _out;
	Matrix* out = &_out;
	
	//look at https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//The output is a matrix of Cofactors that is Adjoint:
	//  1  2  3
	//[ +x, -y, +z ]
	//[ -x, +y, -z ]
	//[ +x, -y, +z ]

	//First Row
	//  1  2  3
	//[ #, !, ! ]
	//[ !, y, y ]
	//[ !, z, z ]            //Array indexes:
	m2x2.vec1.x = m->vec2.y; //[1][1]
	m2x2.vec1.y = m->vec2.z; //[1][2]
	m2x2.vec2.x = m->vec3.y; //[2][1]
	m2x2.vec2.y = m->vec3.z; //[2][2]

	c = pow(-1.f,1+1); // (-1)^(1+1)

	out->vec1.x = c*Determinant_2x2( &m2x2 );

	//Second Row
	//  1  2  3
	//[ !, #, ! ]
	//[ y, !, y ]
	//[ z, !, z ]
	m2x2.vec1.x = m->vec1.y;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec3.y;
	m2x2.vec2.y = m->vec3.z;
	
	c = pow(-1.f,1+2); // (-1)^(1+2)

	out->vec1.y = c*Determinant_2x2( &m2x2 );


	//Third Row
	//  1  2  3
	//[ !, !, # ]
	//[ y, y, ! ]
	//[ z, z, ! ]
	m2x2.vec1.x = m->vec1.y;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec2.y;
	m2x2.vec2.y = m->vec2.z;
	
	c = pow(-1.f,1+3); // (-1)^(1+3)

	out->vec1.z = c*Determinant_2x2( &m2x2 );
	
	//Column 2
	//First Row
	//  1  2  3
	//[ !, x, x ]
	//[ #, !, ! ]
	//[ !, z, z ]
	m2x2.vec1.x = m->vec2.x;
	m2x2.vec1.y = m->vec2.z;
	m2x2.vec2.x = m->vec3.x;
	m2x2.vec2.y = m->vec3.z;
	
	c = pow(-1.f,2+1); // (-1)^(2+1)

	out->vec2.x = c*Determinant_2x2( &m2x2 );

	//Column 2
	//Second Row
	//  1  2  3
	//[ x, !, x ]
	//[ !, #, ! ]
	//[ z, !, z ]
	m2x2.vec1.x = m->vec1.x;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec3.x;
	m2x2.vec2.y = m->vec3.z;
	
	c = pow(-1.f,2+2); // (-1)^(2+2)

	out->vec2.y = c*Determinant_2x2( &m2x2 );

	//Column 2
	//Third Row
	//  1  2  3
	//[ x, x, ! ]
	//[ !, !, # ]
	//[ z, z, ! ]
	m2x2.vec1.x = m->vec1.x;
	m2x2.vec1.y = m->vec1.z;
	m2x2.vec2.x = m->vec2.x;
	m2x2.vec2.y = m->vec2.z;
	
	c = pow(-1.f,2+3); // (-1)^(2+3)

	out->vec2.z = c*Determinant_2x2( &m2x2 );

	//Column 3
	//First Row
	//  1  2  3
	//[ !, x, x ]
	//[ !, y, y ]
	//[ #, !, ! ]
	m2x2.vec1.x = m->vec2.x;
	m2x2.vec1.y = m->vec2.y;
	m2x2.vec2.x = m->vec3.x;
	m2x2.vec2.y = m->vec3.y;
	
	c = pow(-1.f,3+1); // (-1)^(3+1)

	out->vec3.x = c*Determinant_2x2( &m2x2 );

	//Column 3
	//Second Row
	//  1  2  3
	//[ x, !, x ]
	//[ y, !, y ]
	//[ !, #, ! ]
	m2x2.vec1.x = m->vec1.x;
	m2x2.vec1.y = m->vec1.y;
	m2x2.vec2.x = m->vec3.x;
	m2x2.vec2.y = m->vec3.y;
	
	c = pow(-1.f,3+2); // (-1)^(3+2)

	out->vec3.y = c*Determinant_2x2( &m2x2 );

	//Column 3
	//Third Row
	//  1  2  3
	//[ x, x, ! ]
	//[ y, y, ! ]
	//[ !, !, # ]
	m2x2.vec1.x = m->vec1.x;
	m2x2.vec1.y = m->vec1.y;
	m2x2.vec2.x = m->vec2.x;
	m2x2.vec2.y = m->vec2.y;
	
	c = pow(-1.f,3+3); // (-1)^(3+3)

	out->vec3.z = c*Determinant_2x2( &m2x2 );

	//copy from _out to out matrix in case the input matrix and output matrix are the same
	*(Matrix*)_out_ = _out;

	return;
}

//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
/// <summary>creates a 4x4 matrix with the transposed CoFactors from the input 4x4 matrix</summary>
/// <param name="m">a pointer to the 4x4 input matrix</param>
/// <param name="out">a pointer to the 4x4 output matrix</param>
void CreateTransposedMatrixOfCofactors_4x4( /*IN*/Matrix_4x4* m, /*OUT*/Matrix_4x4* _out_ )
{
	Matrix_4x4 _out;
	Matrix_4x4* out = &_out;

	double result = 0;
	double factor = 0;
	double c = 0;
	Matrix m3x3;

	//The output is a matrix of Cofactors that is Adjoint:
	//   1   2   3   4
	//[ +x, -y, +z, -w ]
	//[ -x, +y, -z, +w ]
	//[ +x, -y, +z, -w ]
	//[ -x, +y, -z, +w ]

	//First Row
	//  1  2  3  4
	//[ #, !, !, ! ]
	//[ !, y, y, y ]
	//[ !, z, z, z ]
	//[ !, w, w, w ]		 // some thoughts on similarities to create an algorithm
							 //[1][0] <= removed
	m3x3.vec1.x = m->vec2.y; //[1][1]
	m3x3.vec1.y = m->vec2.z; //[1][2]
	m3x3.vec1.z = m->vec2.w; //[1][3]
							 //[2][0] <= removed
	m3x3.vec2.x = m->vec3.y; //[2][1]
	m3x3.vec2.y = m->vec3.z; //[2][2]
	m3x3.vec2.z = m->vec3.w; //[2][3]
							 //[3][0] <= removed
	m3x3.vec3.x = m->vec4.y; //[3][1]
	m3x3.vec3.y = m->vec4.z; //[3][2]
	m3x3.vec3.z = m->vec4.w; //[3][3]

	c = pow(-1.f,1+1); // (-1)^(1+1)

	out->vec1.x = c*Determinant_3x3( &m3x3 );

	//Second Row
	//  1  2  3  4
	//[ !, #, !, ! ]
	//[ y, !, y, y ]
	//[ z, !, z, z ]
	//[ W, !, w, w ]
	m3x3.vec1.x = m->vec1.y;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec3.y;
	m3x3.vec2.y = m->vec3.z;
	m3x3.vec2.z = m->vec3.w;
	m3x3.vec3.x = m->vec4.y;
	m3x3.vec3.y = m->vec4.z;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,1+2); // (-1)^(1+2)

	out->vec1.y = c*Determinant_3x3( &m3x3 );

	//Third Row
	//  1  2  3  4
	//[ !, !, #, ! ]
	//[ y, y, !, y ]
	//[ z, z, !, z ]
	//[ W, w, !, w ]
	m3x3.vec1.x = m->vec1.y;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.y;
	m3x3.vec2.y = m->vec2.z;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec4.y;
	m3x3.vec3.y = m->vec4.z;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,1+3); // (-1)^(1+3)

	out->vec1.z = c*Determinant_3x3( &m3x3 );

	//Fourth Row
	//  1  2  3  4
	//[ !, !, !, # ]
	//[ y, y, y, ! ]
	//[ z, z, z, ! ]
	//[ W, w, w, ! ]
	m3x3.vec1.x = m->vec1.y;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.y;
	m3x3.vec2.y = m->vec2.z;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec3.y;
	m3x3.vec3.y = m->vec3.z;
	m3x3.vec3.z = m->vec3.w;

	c = pow(-1.f,1+4); // (-1)^(1+4)

	out->vec1.w = c*Determinant_3x3( &m3x3 );

	//remove y

	//Column 2
	//First Row
	//  1  2  3  4
	//[ !, x, x, x ]
	//[ #, !, !, ! ]
	//[ !, z, z, z ]
	//[ !, w, w, w ]
	m3x3.vec1.x = m->vec2.x;
	m3x3.vec1.y = m->vec2.z;
	m3x3.vec1.z = m->vec2.w;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.z;
	m3x3.vec2.z = m->vec3.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.z;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,2+1); // (-1)^(1+1)

	out->vec2.x = c*Determinant_3x3( &m3x3 );

	//Column 2
	//Second Row
	//  1  2  3  4
	//[ x, !, x, x ]
	//[ !, #, !, ! ]
	//[ z, !, z, z ]
	//[ w, !, w, w ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.z;
	m3x3.vec2.z = m->vec3.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.z;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,2+2); // (-1)^(1+2)

	out->vec2.y = c*Determinant_3x3( &m3x3 );

	//Column 2
	//Third Row
	//  1  2  3  4
	//[ x, x, !, x ]
	//[ !, !, #, ! ]
	//[ z, z, !, z ]
	//[ w, w, !, w ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.z;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.z;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,2+3); // (-1)^(2+3)

	out->vec2.z = c*Determinant_3x3( &m3x3 );

	//Column 2
	//Fourth Row
	//  1  2  3  4
	//[ x, x, x, ! ]
	//[ !, !, !, # ]
	//[ z, z, z, ! ]
	//[ w, w, w, ! ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.z;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.z;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec3.x;
	m3x3.vec3.y = m->vec3.z;
	m3x3.vec3.z = m->vec3.w;

	c = pow(-1.f,2+4); // (-1)^(2+4)

	out->vec2.w = c*Determinant_3x3( &m3x3 );

	//remove Z

	//Column 3
	//First Row
	//  1  2  3  4
	//[ !, x, x, x ]
	//[ !, y, y, y ]
	//[ #, !, !, ! ]
	//[ !, w, w, w ]
	m3x3.vec1.x = m->vec2.x;
	m3x3.vec1.y = m->vec2.y;
	m3x3.vec1.z = m->vec2.w;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.y;
	m3x3.vec2.z = m->vec3.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,3+1); // (-1)^(3+1)

	out->vec3.x = c*Determinant_3x3( &m3x3 );

	//Column 3
	//Second Row
	//  1  2  3  4
	//[ x, !, x, x ]
	//[ y, !, y, y ]
	//[ !, #, !, ! ]
	//[ w, !, w, w ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.y;
	m3x3.vec2.z = m->vec3.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,3+2); // (-1)^(3+2)

	out->vec3.y = c*Determinant_3x3( &m3x3 );

	//Column 3
	//Third Row
	//  1  2  3  4
	//[ x, x, !, x ]
	//[ y, y, !, y ]
	//[ !, !, #, ! ]
	//[ w, w, !, w ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.y;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.w;

	c = pow(-1.f,3+3); // (-1)^(3+3)

	out->vec3.z = c*Determinant_3x3( &m3x3 );

	//Column 3
	//Fourth Row
	//  1  2  3  4
	//[ x, x, x, ! ]
	//[ y, y, y, ! ]
	//[ !, !, !, # ]
	//[ w, w, w, ! ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.w;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.y;
	m3x3.vec2.z = m->vec2.w;
	m3x3.vec3.x = m->vec3.x;
	m3x3.vec3.y = m->vec3.y;
	m3x3.vec3.z = m->vec3.w;

	c = pow(-1.f,3+4); // (-1)^(3+4)

	out->vec3.w = c*Determinant_3x3( &m3x3 );

	//remove W

	//Column 4
	//First Row
	//  1  2  3  4
	//[ !, x, x, x ]
	//[ !, y, y, y ]
	//[ !, z, z, z ]
	//[ #, !, !, ! ]
	m3x3.vec1.x = m->vec2.x;
	m3x3.vec1.y = m->vec2.y;
	m3x3.vec1.z = m->vec2.z;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.y;
	m3x3.vec2.z = m->vec3.z;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.z;

	c = pow(-1.f,4+1); // (-1)^(4+1)

	out->vec4.x = c*Determinant_3x3( &m3x3 );

	//Column 4
	//Second Row
	//  1  2  3  4
	//[ x, !, x, x ]
	//[ y, !, y, y ]
	//[ z, !, z, z ]
	//[ !, #, !, ! ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.z;
	m3x3.vec2.x = m->vec3.x;
	m3x3.vec2.y = m->vec3.y;
	m3x3.vec2.z = m->vec3.z;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.z;

	c = pow(-1.f,4+2); // (-1)^(4+2)

	out->vec4.y = c*Determinant_3x3( &m3x3 );

	//Column 4
	//Third Row
	//  1  2  3  4
	//[ x, x, !, x ]
	//[ y, y, !, y ]
	//[ z, z, !, z ]
	//[ !, !, #, ! ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.z;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.y;
	m3x3.vec2.z = m->vec2.z;
	m3x3.vec3.x = m->vec4.x;
	m3x3.vec3.y = m->vec4.y;
	m3x3.vec3.z = m->vec4.z;

	c = pow(-1.f,4+3); // (-1)^(4+3)

	out->vec4.z = c*Determinant_3x3( &m3x3 );

	//Column 3
	//Fourth Row
	//  1  2  3  4
	//[ x, x, x, ! ]
	//[ y, y, y, ! ]
	//[ z, z, z, ! ]
	//[ !, !, !, # ]
	m3x3.vec1.x = m->vec1.x;
	m3x3.vec1.y = m->vec1.y;
	m3x3.vec1.z = m->vec1.z;
	m3x3.vec2.x = m->vec2.x;
	m3x3.vec2.y = m->vec2.y;
	m3x3.vec2.z = m->vec2.z;
	m3x3.vec3.x = m->vec3.x;
	m3x3.vec3.y = m->vec3.y;
	m3x3.vec3.z = m->vec3.z;

	c = pow(-1.f,4+4); // (-1)^(4+4)

	out->vec4.w = c*Determinant_3x3( &m3x3 );

	//copy from _out to out matrix in case the input matrix and output matrix are the same
	*(Matrix_4x4*)_out_ = _out;

	return;
}

/// <summary>multiply every value of the matrix 4x4 with d</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="d">value to multiply</param>
void Multiply_4x4( /*IN,OUT*/Matrix_4x4* m, /*IN*/double d )
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			m->a[j][i] *= d;
		}
	}
}

/// <summary>Calculates the Determinant from a 4x4 transposed CoFactor matrix</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="TransposeMatOfCoFactors">a pointer to a 4x4 Determinant matrix</param>
/// <returns>returns Determinant</returns>
double DeterminantFromTransposedMatrixOfCofactors_4x4( /*IN*/Matrix_4x4* m, /*IN*/Matrix_4x4* TransposeMatOfCoFactors )
{

	double result = TransposeMatOfCoFactors->vec1.x * m->vec1.x + 
					TransposeMatOfCoFactors->vec1.y * m->vec2.x + 
					TransposeMatOfCoFactors->vec1.z * m->vec3.x +
					TransposeMatOfCoFactors->vec1.w * m->vec4.x ;

	return result;
}

//for result control check http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/fourD/index.htm
/// <summary>Inverses a 4x4 matrix</summary>
/// <param name="m">a pointer to a 4x4 matrix</param>
/// <param name="mInv">a pointer to the output 4x4 matrix</param>
void MatrixInverse_4x4( /*IN*/Matrix_4x4* m, /*OUT*/Matrix_4x4* mInv )
{
	Matrix_4x4* TmpMat = (Matrix_4x4*)alloca( sizeof(Matrix_4x4) );

	CreateTransposedMatrixOfCofactors_4x4( m, TmpMat );
	double det = 1/DeterminantFromTransposedMatrixOfCofactors_4x4( m, TmpMat );
	Multiply_4x4( TmpMat, det );

	//copy from TmpMat to out matrix in case the input matrix and output matrix are the same
	memcpy( mInv, TmpMat, sizeof(Matrix_4x4) );
}

/// <summary>multiply every value of the matrix 3x3 with d</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="d">value to multiply</param>
void Multiply( /*IN,OUT*/Matrix* m, /*IN*/double d )
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			m->a[j][i] *= d;
		}
	}
}

//for result control check http://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/threeD/index.htm
/// <summary>Inverses a 3x3 matrix</summary>
/// <param name="m">a pointer to a 3x3 matrix</param>
/// <param name="mInv">a pointer to the output 3x3 matrix</param>
void MatrixInverse( /*IN*/Matrix* m, /*OUT*/Matrix* mInv )
{
	Matrix* TmpMat = (Matrix*)alloca( sizeof(Matrix) );

	CreateTransposedMatrixOfCofactors_3x3( m, TmpMat );
	double det = 1/DeterminantFromTransposedMatrixOfCofactors_3x3( m, TmpMat );
	Multiply( TmpMat, det );

	//copy from TmpMat to out matrix in case the input matrix and output matrix are the same
	memcpy( mInv, TmpMat, sizeof(Matrix) );
}

/// <summary>multiplies the 3d vector with the matrix 3x3</summary>
/// <param name="m">a pointer to the 3x3 matrix</param>
/// <param name="b">a pointer to hte 3d vector</param>
/// <returns>returns the result</returns>
Vec3 Multiply( /*IN,OUT*/Matrix* m, /*IN*/Vec3* b )
{
	Vec3 out;
	out.x = m->a[0][0] * b->x + m->a[0][1] * b->y + m->a[0][2] * b->z;
	out.y = m->a[1][0] * b->x + m->a[1][1] * b->y + m->a[1][2] * b->z;
	out.z = m->a[2][0] * b->x + m->a[2][1] * b->y + m->a[2][2] * b->z;
	return out;
}

/// <summary>Calculates the Determinant from a matrix, look at Determinant_3x3 for more info</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
/// <returns>returns Determinant</returns>
template <class T>
T Determinant_custom( /*IN*/T* m, /*IN*/int Dimensions )
{
	//look at Determinant_3x3 for more details
	if ( Dimensions == 1 ) //in case its a 1x1 matrix:
		return m[0];
	if ( Dimensions == 2 ) //in case its a 2x2 matrix
		return Determinant_2x2( (Matrix_2x2*)m );

	T result = 0;
	T factor = 0;
	
	//allocate a buffer on the stack
	T* tmp = (T*)alloca( ((Dimensions*Dimensions) * sizeof( T ))  );

	//First Row
	//  1  2  3
	//[ #, !, ! ]
	//[ !, y, y ]
	//[ !, z, z ]
	int skipX = 0;
	int skipY = 0;


	//=> walking this way
	//  1  2  3
	//-----------
	//[ 1, 3, 1 ]
	//[-1,-2, 0 ]
	//[ 6,.5, 4 ]

	//iterate all rows in column 1
	for (int k = 0; k < Dimensions; k++)
	{
		int curPosX = 0;
		//First Row
		for (int j = 0; j < Dimensions; j++)
		{
			if ( j == skipX ) //skip X-Coordinate in matrix
				continue;
			//printf("j = %i\n",j);
			int curPosY = 0;
			for (int i = 0; i < Dimensions; i++)
			{
				if ( i == skipY ) //skip Y-Coordinate in matrix
					continue;

				tmp[curPosX*(Dimensions-1)+curPosY] = m[j*Dimensions+i];
				curPosY++;
			}
			curPosX++;
		}

		T c = pow(-1.f,(skipX+1)+(skipY+1)); // (-1)^(1+skip) //=> to determen if the algebraic sign is negative or positive 

		c *= m[skipX*Dimensions+skipY];

		double det = Determinant_custom<T>( tmp, Dimensions - 1 ) * c;

		result += det;

		skipX++;

	}

	return result;
}

/// <summary>creates a matrix with the transposed CoFactors from the input matrix, look at CreateTransposedMatrixOfCofactors_3x3 for more info</summary>
/// <param name="m">a pointer to the input matrix</param>
/// <param name="out">a pointer to the output matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void CreateTransposedMatrixOfCofactors_Custom( /*IN*/T* m, /*OUT*/T* _out_, /*IN*/int Dimensions )
{
	//look at CreateTransposedMatrixOfCofactors_3x3 for more details
	T result = 0;
	T factor = 0;
	//allocate a buffer on the stack
	T* tmp = (T*)alloca( ((Dimensions*Dimensions) * sizeof( T ))  );
	T* out = (T*)alloca( ((Dimensions*Dimensions) * sizeof( T ))  );

	int skipY = 0;

	//go through all columns
	for (int k = 0; k < Dimensions; k++)
	{
		int skipX = 0;
		//iterate all rows in column k
		for (int k = 0; k < Dimensions; k++)
		{
			int curPosX = 0;
			//First Row
			for (int j = 0; j < Dimensions; j++)
			{
				if ( j == skipX ) //skip X-Coordinate in matrix
					continue;

				int curPosY = 0;
				for (int i = 0; i < Dimensions; i++)
				{
					if ( i == skipY ) //skip Y-Coordinate in matrix
						continue;

					tmp[curPosX*(Dimensions-1)+curPosY] = m[j*Dimensions+i];

					curPosY++;
				}
				curPosX++;
			}

			T c = pow(-1.f,(skipX+1)+(skipY+1)); // (-1)^(1+skip) //=> to determen if the algebraic sign is negative or positive 

			T det = Determinant_custom( tmp, Dimensions - 1 ) * c;

			out[skipY*Dimensions+skipX] = det;
			skipX++;

		}
		skipY++;
	}
	//copy from out to out matrix in case the input matrix and output matrix are the same
	memcpy( _out_, out, ((Dimensions*Dimensions) * sizeof( T )) );
}

/// <summary>multiply every value of the matrix with d</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="d">value to multiply</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T> 
void Multiply_Custom( /*IN,OUT*/T* m, /*IN*/T d, /*IN*/int Dimensions )
{
	for (int j = 0; j < Dimensions; j++)
	{
		for (int i = 0; i < Dimensions; i++)
		{
			m[j*Dimensions+i] *= d;
		}
	}
}

/// <summary>Inverses a matrix</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="mInv">a pointer to the output matrix</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void MatrixInverse_Custom( /*IN*/T* m, /*OUT*/T* mInv, /*IN*/int Dimensions )
{
	double* TmpMat = (double*)alloca( (Dimensions*Dimensions)*sizeof(T) );

	CreateTransposedMatrixOfCofactors_Custom<T>( m, TmpMat, Dimensions );
	T det = 1/Determinant_custom<T>( m, Dimensions );
	
	Multiply_Custom<T>( TmpMat, det, Dimensions );

	//copy from TmpMat to out matrix in case the input matrix and output matrix are the same
	memcpy( mInv, TmpMat, (Dimensions*Dimensions)*sizeof(T) );
}

/// <summary>Multiples a matrix with a vector</summary>
/// <param name="m">a pointer to the matrix</param>
/// <param name="vec">a pointer to the vector</param>
/// <param name="vecOut">a pointer to the output vector</param>
/// <param name="Dimensions">how much dimensions the matrix has</param>
template <class T>
void Multiply_Custom( /*IN*/T* m, /*IN*/T* vec, /*OUT*/T* vecOut, /*IN*/DWORD Dimensions )
{
	double* TmpVec = (double*)alloca( (Dimensions)*sizeof(T) );
	for (DWORD dwMatOffset = 0; dwMatOffset < Dimensions; dwMatOffset++ )
	{
		TmpVec[ dwMatOffset ] = 0.0f;
		for (DWORD i = 0; i < Dimensions; i++)
		{
			TmpVec[ dwMatOffset ] += vec[i] * m[ (dwMatOffset*(Dimensions)) + i ];
		}
	}
	//copy from TmpVec to out vector in case the input vector and output vector are the same
	memcpy( vecOut, TmpVec, (Dimensions)*sizeof(T) );
}
#pragma endregion FunctionDefinitions
///////////////////////////////////////////////////////////// Definitions end //////////////////////////////////////////////////////////////
