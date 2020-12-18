import math

def kmeans():
	
	data, dim = [], 2
	N, K = map(int, input("Enter N and K: ").split())

	print("Enter N coordinate values: ")
	for i in range(N):
		x, y = map(float, input().split())
		data.append([x,y])

	centers = list(map(int, input("Enter indices of initial means: ").split()))
	for i in range(len(centers)):
		centers[i] = data[centers[i]]

	print ("\nData: ", data)
	print ("\nInitial means: ", centers)

	while True:

	  # distance matrix  inititalize
	  dist = [[] for i in range(N)]

	  # euclidean distance
	  for i in range(N):
	    for c in centers:
	      
	      squaredEuclideanDistance = 0
	      for j in range(dim):
	        squaredEuclideanDistance = squaredEuclideanDistance + (data[i][j] - c[j])**2
	      
	      euclidianDistance = math.sqrt(squaredEuclideanDistance)
	      dist[i].append(euclidianDistance);
	  
	  print("\nEuclidean Distance: ", dist)

	  buckets = [ [] for i in range(K) ]

	  # classify each data with index of center as class label
	  for i in range(N):
	    closestBucketIndex = 0
	    for j in range(1, K):
	      if dist[i][closestBucketIndex] > dist[i][j]:
	        closestBucketIndex = j

	    buckets[closestBucketIndex].append(data[i])

	  for i, bucket in enumerate(buckets):
	  	print(f'Bucket {i}: {bucket}')
	  print('\n--------------\n')

	  # compute new mean
	  newCenters = []
	  for bucket in buckets:
	    cen = []
	    for j in range(dim):
	      # compute mean over each dimensions
	      sum = 0
	      for i in range(len(bucket)):
	        sum += bucket[i][j]
	      cen.append(sum/len(bucket))
	    newCenters.append(cen)
	  
	  if newCenters == centers:
	    return centers
	  else:
	   	centers = newCenters

	  print ("\nNew means: ", centers)

kmeans()