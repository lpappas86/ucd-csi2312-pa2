#ifndef CLUSTERING_KMEANS_H
#define CLUSTERING_KMEANS_H

#include "Cluster.h"
#include<fstream>

namespace clustering {

	// terminates kmeans loop
	static const double SCORE_DIFF_THRESHOLD = .0001;				
	typedef Cluster *cPtr;

	class KMeans {

	private:

		/*******************************************************************
		    *************      Member Variables      *******************
		*******************************************************************/

		// points to a dynamically allocated
		// array of Cluster pointers 
		cPtr *point_space;

		// number of clusters
		int K;

		// pointer to ifstream file for input
		std::ifstream *in;

		std::ofstream *out;

		// BetaCV score
		double score;

		// Difference of score between iterations
		double scoreDiff;

	public:


		/*******************************************************************
		    *************         Constructor        *******************
		*******************************************************************/

		// Takes K and in file
		KMeans(unsigned int, std::ifstream &, std::ofstream &);



		/*******************************************************************
		    *************       Mutator Functions        ***************
		*******************************************************************/

		// creates K clusters
		void createClusters();

		// reads points to first cluster
		void readPoints();

		// picks k centroids and assigns one to each cluster
		void setCentroids();

		// computes BetaCV score
		// returns 99999 if (K-1) clusters are empty
		double computeClusteringScore();

		void recomputeClusters();



		/*******************************************************************
	 	     ***********       Accessor Functions        ***************
		*******************************************************************/
		
		// gets cluster at array index
		cPtr getClusters(int);

		void printResults();
	};

};
#endif 