#include "KMeans.h"
#include<vector>
#include<cmath>
#include <limits>

namespace Clustering {
	KMeans::KMeans(unsigned int dim, unsigned int k, std::string fileName)
	{
		// set members
		K = k;
		std::ifstream inFile;
		inFile.open(fileName);
		//std:: cout << inFile.is_open();
		in = &inFile;
		dimension = dim;
		out.open("Output.txt");
		scoreDiff = SCORE_DIFF_THRESHOLD + 1;

		createClusters();
		readPoints();
		//run();					
		
	}

	void KMeans::createClusters()
	{
		point_space = new Cluster*[K];
		for (int i = 0; i < K; i++)
			point_space[i] = new Cluster(dimension);
	}

	void KMeans::readPoints()
	{
		// read all points into first
		*in >> *point_space[0];	
	}

	void KMeans::setCentroids()
	{
		// array of point pointers to hold cenroid points
		PointPtr *centroids = new Point*[K];

		// pick centroid points
		point_space[0]->pickPoints(K, centroids);

		// assign centroids
		for (int i = 0; i < K; i++)
			point_space[i]->setCentroid(*centroids[i]);
	}

	double KMeans::computeClusteringScore()
	{
		// sum of: intracluster distance / intercluster distance / intracluster edges / intercluster edges (respectively)
		double Din = 0, Dout = 0, Pin = 0, Pout = 0; 

		for (int i = 0; i < K; i++) {

			// sum intracluster distance/edges
			Din += point_space[i]->intraClusterDistance();
			Pin += point_space[i]->getClusterEdges();
		
			for (int j = (i + 1); j < K; j++) {

				// sum intercluster distance/edges 
				Dout += interClusterDistance(*point_space[i], *point_space[j]);

				Pout += interClusterEdges(*point_space[i], *point_space[j]);

			}				
		}

		//  BetaCV = (intraClusterDistance / intraClusterEdges) / (interClusterDistance / interClusterEdges)
		if (Din == 0 && Pin == 0)				
			return 0;		// Avoid dividing by zero if there is only one point in cluster	
		if (Dout == 0 && Pout == 0) {
			Dout = 1;
			Pout = 1;
		}
		return (Din / Pin) / (Dout / Pout);
	}

	void KMeans::recomputeClusters()
	{

		double minDistance;

		do {		// loops until score difference < SCORE_DIFF_THRESHOLD
			//loop through all clusters
			for (int i = 0; i < K; i++) {

				if (point_space[i]->getSize() == 0)
					continue;

				

				// newIndex holds the index of closest cluster
				int newIndex = i;	

				//	loop through all points
				for (int j = (point_space[i]->getSize() - 1); j >= 0 ; j--) {
					// set minDistance of cluster's first point to the distance to its own centroid
					minDistance = std::numeric_limits<double>::max();
					//	find the min distance(point, centroid)
					for (int h = 0; h < K; h++ ) {
						Point p = point_space[h]->getCentroid();
						double newDistance = (*point_space[i])[j]->distanceTo(p);					
						if (newDistance < minDistance) {
							minDistance = newDistance;
							newIndex = h;
						}
					}

					//	if centroid not of current cluster
					if (newIndex != i) {
						// perform move(point, current, other)
						Cluster::Move((*point_space[i])[j], point_space[i], point_space[newIndex]).perform();			
					}
				}
			}

			//	loop through all clusters
			for (int i = 0; i < K; i++) {

				//	if centroid invalid
				if (point_space[i]->isCentroidValid() == false) {
					// compute and set valid to true
					if(point_space[i]->getSize() > 0)
						point_space[i]->computeCentroid();
				}
			
			}
			//	compute new clustering score
			double newScore = computeClusteringScore();

			//	compute absolute difference and set scoreDiff
			scoreDiff = std::abs(score - newScore);
			score = newScore;
			
		} while (scoreDiff >= SCORE_DIFF_THRESHOLD);
	}

	void KMeans::deleteClusters()
	{
		for (int i = 0; i < K; i++)
			delete point_space[i];
		delete[] point_space;
	}

	void KMeans::run()
	{
		// The algorithm
		
		setCentroids();
		recomputeClusters();
		printResults();
	}

	Cluster & KMeans::operator[](unsigned int index)
	{
		return *point_space[index];
	}

	const Cluster & KMeans::operator[](unsigned int index) const
	{
		return *point_space[index];
	}

	cPtr KMeans::getClusters(int index)
	{
		return point_space[index];
	}

	void KMeans::printResults()
	{
		for (int i = 0; i < K; i++)
			out << *point_space[i];
	}

	std::ostream & operator<<(std::ostream & os, const KMeans & kmeans)
	{
		for (int i = 0; i < kmeans.K; i++) {
			os << *(kmeans.point_space[i]);
		}
		return os;
	}

}