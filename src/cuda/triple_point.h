#pragma once

#include <cuda_runtime.h>
#include <string>
#include <sstream>

namespace popart {

/*************************************************************
 * TriplePoint
 * A simplified version of EdgePoint in the C++ code.
 *************************************************************/
struct TriplePoint
{
    int2  coord;
    int2  d;     // hold d.x = dx, d.y = dy
    struct {
        int2  befor;
        int2  after;
    } descending;

    // in the original code, chosen keeps list of voters
    // no possible here; we must invert this
    // int   my_vote;
    // float chosen_flow_length;

    int   _winnerSize;
    float _flowLength;
#ifndef NDEBUG
    int   _coords_collect_idx;
    int   _coords_idx;
    int2  _coords[12];

    __device__ inline void debug_init( );
    __device__ inline void debug_add( int2 c );
    __device__ inline void debug_commit( );

    __host__
    void debug_out( std::ostream& ostr ) const;

    __host__
    std::string debug_out( ) const;
#endif
};

#ifndef NDEBUG
__device__
inline void TriplePoint::debug_init( )
{
    _coords_idx         = 0;
    _coords_collect_idx = 0;
}

__device__
inline void TriplePoint::debug_add( int2 c )
{
    if( _coords_collect_idx >= 12 ) return;
    _coords[_coords_collect_idx].x = c.x;
    _coords[_coords_collect_idx].y = c.y;
    _coords_collect_idx++;
}

__device__
inline void TriplePoint::debug_commit( )
{
    _coords_idx = _coords_collect_idx;
}
#endif

}; // namespace popart

