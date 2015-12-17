//
// John-Marc Cloer
//

#include "KMeans.h"
#include <vector>
#include <cmath>

namespace Clustering {

    point** point_space;    //Array

    // destructor
    KMeans::~KMeans()
    {
        for (int i = 0; i < __k; i++)
            delete point_space[i];
        delete[] point_space;
    }

    Cluster &KMeans::operator[](unsigned int u)
    {
        return PointPtr:: **__initCentroids[u];
    }
    
    const Cluster::Cluster &KMeans::operator[](unsigned int u) const
    {
        return PointPtr:: **__initCentroids[u];
    }

    void KMeans::setCentroid(int point)
    {
        PointPtr *centrs = new Point* point_space[point];
        point_space[0]->pickPoints(KMeans::k, centrs);
        for (int i = 0; i < KMeans::k; i++) 
        {
            point_space[i]->setCentroid(*centrs[i]);
        }
    }

    std::ostream &operator<<(std::ostream &os, const KMeans &kmeans)
    {
        for (int i = 0; i < *kmeans; i++)
        {
            os << point_space[i] << ", ";
        }
    }
    
    
