/*
===============================================================================
AF_MATH_H
AUTHOR: jhalldevelop
Extra helper functions that can be called to perform math operations.
Compile flag to switch between fixed and floating-point operations.
Fixed operations are not implemented yet.
===============================================================================
*/
#ifndef AF_MATH_H
#define AF_MATH_H
#include "AF_Math_Define.h"

#ifdef __cplusplus
extern "C" {
#endif

// Conditional compilation for fixed-point arithmetic
#ifdef USE_FIXED

/*
=========================
AF_Math_Sqrt
Calculates the square root of a given value using fixed-point arithmetic.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Sqrt(AF_FLOAT _value){
    printf("AF_Math_Sqrt: TODO\n");
    AF_FLOAT returnValue = _value * _value / _value;	
    return returnValue;
}

/*
=========================
AF_Math_Atan2
Calculates the arctangent of two values, returning the angle in radians.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Atan2(AF_FLOAT _value1, AF_FLOAT _value2){
    printf("AF_Math_Atan2: TODO\n");	
    return _value1 + _value2;
}

/*
=========================
AF_Math_Tan
Calculates the tangent of a given angle in radians.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Tan(AF_FLOAT _value1){
    printf("AF_Math_Tan: TODO\n");	
    return _value1 + _value1;
}

/*
=========================
AF_Math_Sin
Calculates the sine of a given angle in radians.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Sin(AF_FLOAT _value){
    printf("AF_Math_Sin: TODO\n");
    return _value + _value;
}

/*
=========================
AF_Math_Cos
Calculates the cosine of a given angle in radians.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Cos(AF_FLOAT _value){
    printf("AF_Math_Cos: TODO\n");
    return _value + _value;
}

/*
=========================
AF_Math_Radians
Converts degrees to radians.
Currently a placeholder implementation that needs to be completed.
=========================
*/
static inline AF_FLOAT AF_Math_Radians(AF_FLOAT _degrees){
    printf("AF_Math_Radians: TODO \n");
    return _degrees + _degrees; 
}

#else

// Include necessary headers for vector and matrix operations
#include "AF_Vec3.h"
#include "AF_Vec4.h"
#include "AF_Mat4.h"

#define AF_PI 3.14159265358979323846  // Define the value of Pi

#include "math.h"  // Standard math library

/*
=========================
AF_Math_Sqrt
Calculates the square root of a given value using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Sqrt(AF_FLOAT _value){
    return sqrt(_value);
}

/*
=========================
AF_Math_Atan2
Calculates the arctangent of two values, returning the angle in radians using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Atan2(AF_FLOAT _value1, AF_FLOAT _value2){
    return atan2(_value1, _value2);
}

/*
=========================
AF_Math_Tan
Calculates the tangent of a given angle in radians using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Tan(AF_FLOAT _value1){
    return tan(_value1);
}

/*
=========================
AF_Math_Sin
Calculates the sine of a given angle in radians using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Sin(AF_FLOAT _value){
    return sin(_value);
}

/*
=========================
AF_Math_Cos
Calculates the cosine of a given angle in radians using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Cos(AF_FLOAT _value){
    return cos(_value);
}

/*
=========================
AF_Math_Radians
Converts degrees to radians using floating-point arithmetic.
=========================
*/
static inline AF_FLOAT AF_Math_Radians(AF_FLOAT _degrees){
    return (_degrees * AF_PI) / 180; 
}

/*
=========================
area_of_triangle
Calculates the area of a triangle defined by three vertices.
Uses the determinant method to compute the area.
Parameters:
    _v1: First vertex of the triangle
    _v2: Second vertex of the triangle
    _v3: Third vertex of the triangle
Returns:
    The area of the triangle.
=========================
*/
static inline AF_FLOAT area_of_triangle(const Vec3 _v1, const Vec3 _v2, const Vec3 _v3)
{
    return fabs((_v1.x * (_v2.y - _v3.y) + _v2.x * (_v3.y - _v1.y) + _v3.x * (_v1.y - _v2.y)) / 2);
}

/*
=========================
AF_Math_Lookat
Creates a view matrix that transforms coordinates from world space to view space.
Parameters:
    _target: The target position to look at.
    _position: The position of the camera.
    _up: The up direction vector.
Returns:
    A 4x4 view matrix.
=========================
*/
static inline Mat4 AF_Math_Lookat(Vec3 _target, Vec3 _position, Vec3 _up){
    Vec3 normZ = Vec3_NORMALIZE(Vec3_MINUS(_target, _position));
    Vec3 xaxis = Vec3_NORMALIZE(Vec3_CROSS(normZ, _up));
    Vec3 yaxis = Vec3_CROSS(xaxis, normZ);
    Vec3 zaxis = {-normZ.x, -normZ.y, -normZ.z};

    Vec4 row1 = {xaxis.x, yaxis.x, zaxis.x, 0};
    Vec4 row2 = {xaxis.y, yaxis.y, zaxis.y, 0};
    Vec4 row3 = {xaxis.z, yaxis.z, zaxis.z, 0};

    AF_FLOAT dotX = -Vec3_DOT(xaxis, _position);
    AF_FLOAT dotY = -Vec3_DOT(yaxis, _position);
    AF_FLOAT dotZ = -Vec3_DOT(zaxis, _position);

    Vec4 row4 = {dotX, dotY, dotZ, 1};

    Mat4 viewMatrix;
    viewMatrix.rows[0] = row1;
    viewMatrix.rows[1] = row2;
    viewMatrix.rows[2] = row3;
    viewMatrix.rows[3] = row4;
    return viewMatrix;
}
#endif

#ifdef __cplusplus
}
#endif

#endif  // AF_MATH_H
