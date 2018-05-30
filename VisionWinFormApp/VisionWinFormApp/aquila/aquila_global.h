/**
 * @file global.h
 *
 * Global library typedefs and constants.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2014
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 2.4.1
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#if !defined(__STRICT_ANSI__) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_USE_MATH_DEFINES)
#define M_E		2.7182818284590452354
#define M_LOG2E		1.4426950408889634074
#define M_LOG10E	0.43429448190325182765
#define M_LN2		0.69314718055994530942
#define M_LN10		2.30258509299404568402
#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define M_PI_4		0.78539816339744830962
#define M_1_PI		0.31830988618379067154
#define M_2_PI		0.63661977236758134308
#define M_2_SQRTPI	1.12837916709551257390
#define M_SQRT2		1.41421356237309504880
#define M_SQRT1_2	0.70710678118654752440
#endif

#include <complex>
#include <vector>

#if defined (_WIN32) && defined(BUILD_SHARED_LIBS)
#  if defined(Aquila_EXPORTS)
#    define AQUILA_EXPORT  __declspec(dllexport)
#  else
#    define AQUILA_EXPORT  __declspec(dllimport)
#  endif
#else
#    define AQUILA_EXPORT
#endif

/**
 * Main library namespace.
 */
namespace Aquila
{
    /**
     * Library version in an easily comparable format.
     */
    const long VERSION_NUMBER = 0x300000;

    /**
     * Library version as a string.
     */
    //const char* const VERSION_STRING = "3.0.0-dev";

    /**
     * Sample value type.
     */
    typedef double SampleType;

    /**
     * Sample frequency type.
     */
    typedef double FrequencyType;

    /**
     * Our standard complex number type, using double precision.
     */
    typedef std::complex<double> ComplexType;

    /**
     * Spectrum type - a vector of complex values.
     */
    typedef std::vector<ComplexType> SpectrumType;
}

#endif // GLOBAL_H
