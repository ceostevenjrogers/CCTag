#include "cuda_edge_point.h"

namespace popart {

__host__
void CudaEdgePoint::debug_out( std::ostream& ostr ) const
{
    ostr << "(" << _coord.x << "," << _coord.y << ") "
         << "[" << _grad.x << "," << _grad.y << "] "
         << "FL " << _flowLength << " "
         << "before " << _dev_befor << " "
         << "after " << _dev_after;
}

}; // namespace popart
