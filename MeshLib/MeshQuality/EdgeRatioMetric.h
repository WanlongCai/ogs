/**
 * \file   EdgeRatioMetric.h
 * \author Thomas Fischer
 * \date   2011-03-03
 * \brief  Definition of the AreaMetric class.
 *
 * \copyright
 * Copyright (c) 2012-2015, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef EDGERATIOMETRIC_H_
#define EDGERATIOMETRIC_H_

#include "ElementQualityMetric.h"
#include "MathLib/MathPoint.h"

namespace MeshLib
{

/**
 * Calculates the quality of mesh elements based on the ratio between shortest and longest edge of an element
 */
class EdgeRatioMetric : public ElementQualityMetric
{
public:
    EdgeRatioMetric(Mesh const& mesh);
    virtual ~EdgeRatioMetric () {}

    virtual void calculateQuality ();

private:
    double checkTriangle (MathLib::MathPoint const& a,
                          MathLib::MathPoint const& b,
                          MathLib::MathPoint const& c) const;
    double checkQuad (MathLib::MathPoint const& a,
                      MathLib::MathPoint const& b,
                      MathLib::MathPoint const& c,
                      MathLib::MathPoint const& d) const;
    double checkTetrahedron (MathLib::MathPoint const& a,
                             MathLib::MathPoint const& b,
                             MathLib::MathPoint const& c,
                             MathLib::MathPoint const& d) const;
    double checkPrism (std::vector<const MathLib::MathPoint*> const& pnts) const;
    double checkPyramid (std::vector<const MathLib::MathPoint*> const& pnts) const;
    double checkHexahedron (std::vector<const MathLib::MathPoint*> const& pnts) const;
};
}

#endif /* EDGERATIOMETRIC_H_ */
