import math

def kmeans():
	
	data, dim = [], 2
	N, K = map(int, input("Enter N and K: ").split())

	print("Enter N coordinate values: ")
	for i in range(N):
		row = list(map(float, input().split()))
		data.append(row)
		dim  = len(row)

	means = list(map(int, input("Enter indices of initial means: ").split()))
	for i in range(len(means)):
		means[i] = data[means[i]]

	print ("\nData: ", data)
	print ("\nInitial means: ", means)

	while True:

	  # distance matrix  - dist[i][j] is distance of ith point to jth mean
	  dist = [[] for i in range(N)]

	  # euclidean distance
	  for i in range(N):
	    for mean in means:
	      
	      squaredEuclideanDistance = 0
	      for j in range(dim):
	        squaredEuclideanDistance = squaredEuclideanDistance + (data[i][j] - mean[j])**2
	      
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
	  newMeans = []
	  for bucket in buckets:
	    cen = []
	    for j in range(dim):
	      # compute mean over each dimensions
	      sum = 0
	      for i in range(len(bucket)):
	        sum += bucket[i][j]
	      cen.append(sum/len(bucket))
	    newMeans.append(cen)
	  
	  if newMeans == means:
	    return means
	  else:
	   	means = newMeans

	  print ("\nNew means: ", means)

kmeans()