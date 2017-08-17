/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_ENGINE_VECTOR2_H )
#define INC__OCO_ENGINE_VECTOR2_H ( 1 )

///
/// C INTERFACE
///

#if !defined( __cplusplus )

typedef struct
{
    double x, y;
}
OCoVector2;

void ocoVector2Set( OCoVector2* in, OCoVector2* out );

void ocoVector2Neg( OCoVector2* vec );

bool ocoVector2Equal( OCoVector2* vecA, OCoVector2* vecB );

void ocoVector2Add( OCoVector2* in, OCoVector2* out );

void ocoVector2Sub( OCoVector2* in, OCoVector2* out );

void ocoVector2Mul( OCoVector2* in, OCoVector2* out );

void ocoVector2Div( OCoVector2* in, OCoVector2* out );

double ocoVector2Len( OCoVector2* vec );

double ocoVector2LenSq( OCoVector2* vec );

double ocoVector2Dist( OCoVector2* vecA, OCoVector2* vecB );

double ocoVector2DistSq( OCoVector2* vecA, OCoVector2* vecB );

double ocoVector2Dot( OCoVector2* vecA, OCoVector2* vecB );

double ocoVector2Cross( OCoVector2* vecA, OCoVector2* vecB );

void ocoVector2Normal( OCoVector2* vec );

void ocoVector2Normalise( OCoVector2* vec );

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

struct OCoVector2
{
    double x, y;
    
    OCoVector2( ) : x{0.0f}, y{0.0f} { }
};

extern "C" void ocoVector2Neg( OCoVector2* vec );
extern "C" bool ocoVector2Equal( OCoVector2* vecA, OCoVector2* vecB );
extern "C" void ocoVector2Add( OCoVector2* in, OCoVector2* out );
extern "C" void ocoVector2Sub( OCoVector2* in, OCoVector2* out );
extern "C" void ocoVector2Mul( OCoVector2* in, OCoVector2* out );
extern "C" void ocoVector2Div( OCoVector2* in, OCoVector2* out );
extern "C" double ocoVector2Len( OCoVector2* vec );
extern "C" double ocoVector2LenSq( OCoVector2* vec );
extern "C" double ocoVector2Dist( OCoVector2* vecA, OCoVector2* vecB );
extern "C" double ocoVector2DistSq( OCoVector2* vecA, OCoVector2* vecB );
extern "C" double ocoVector2Dot( OCoVector2* vecA, OCoVector2* vecB );
extern "C" double ocoVector2Cross( OCoVector2* vecA, OCoVector2* vecB );
extern "C" void ocoVector2Normal( OCoVector2* vec );
extern "C" void ocoVector2Normalise( OCoVector2* vec );

namespace OCo
{

class Vector2
{
public:
    double x, y;
    
    Vector2( )
        : x( 0.0f )
        , y( 0.0f ) { }
    Vector2( double val )
        : x( val )
        , y( val ) { }
    Vector2( double xVal, double yVal )
        : x( xVal )
        , y( yVal ) { }
    
    inline Vector2& operator-( )
    {
        this.x = -this.x;
        this.y = -this.y;
        
        return *this;
    }
    
    inline Vector2& operator=( const Vector2& vec )
    {
        this.x = vec.x;
        this.y = vec.y;
        
        return *this;
    }
    
    inline Vector2& operator=( const double& val )
    {
        this.x = val;
        this.y = val;
        
        return *this;
    }
};

}

#endif // !defined( INC__OCO_ENGINE_VECTOR2_H )
