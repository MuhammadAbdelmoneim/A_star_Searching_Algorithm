#A_star_Searching_Algorithm

This is a repo for the implementation of A* searching algorithm and and an explanatory application                      ,                                          
Th e explanatory Application is an application used to find the shortest path between two points                        ,                     
##Input 
 A matrix of 1's ans 0's the 0 represents a empty path and the 1 represents an obstacle like this                       .                                  
  0, 1, 1, 0, 0, 0,                                                                                                     .                                                                                                                 
  0, 1, 1, 0, 0, 0,                                                                                                     .            
  0, 1, 0, 1, 0, 0,                                                                                                     .            
  0, 1, 0, 0, 1, 0,                                                                                                     .           
  0, 0, 0, 0, 0, 0,                                                                                                     .
  this a 5x6 matrix for example if we wish to find the shortest path from the point [0,0] to [4,5]                      .            
 ##Output             
  🚦 ⛰️  ⛰️  0  0  0                                                                                                     .                                                                                                               
  🚗 ⛰️  ⛰️  0  0  0                                                                                                     .           
  🚗 ⛰️  0  ⛰️  0  0                                                                                                     .          
  🚗 ⛰️  0  0  ⛰️  0                                                                                                     .         
  🚗  🚗  🚗  🚗  🚗   🏁                                                                                                       .            
  The output will be something like that                                                                                .           
## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PathFinder`.# A_star_Searching_Algorithm
