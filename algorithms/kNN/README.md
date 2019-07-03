# K Nearest Neighbors
Simple algorithm that 'steals' neigbor's label

## Approach
- Store each datapoint in the Datapoint struct. Simply calculate the Euclidean Distance between each value from the datapoints and get the most common label in the first 'n' neighbors.