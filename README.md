# ucd-csi2312-pa2

This project conatains two classes: Point and Cluster
Point represents a point in n dimensional space 

  Member Variables:
    dim = dimension of the point
    values = 1Xdim array to hold values of each dimension


Cluster represents a collection of points. It uses a dynamically allocated singly linked list to hold the points.
  
  Member Variables:
    size = number of points in linked list
    points = pointer to the first node of the singly linked list
    
  
This was origionally compiled in Visual Studio Proffessional 2015 and checked to run in CLION with GCC

The KMeans class implements cluster and point. It takes in K = number of clusters to create, and an input file with comma       delimited  points. It outputs the points with the cluster ID in output.txt. The constructor is the only function that needs to be called by the user.
