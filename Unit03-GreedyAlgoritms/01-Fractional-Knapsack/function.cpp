// Greedy Knapsack Solution
void GreedyKnapsacck(int m , int n , int* p , int* w){
	// m = max capacity of knapsack
	// n = number of objects
	// p[] = array of profits
	// w[] = array of weights
	
	int i , U = m ;
	float x[n];
	
	for(i = 0 ; i < n ; i++){
		x[i] = 0.0;
	}
	
	for(i = 0 ; i < n ; i++){
		if(w[i] <= U){
			x[i] = 1.0;
			U -= w[i];
		}
		else break;
	}
	
	if(i < n && U > 0){
		x[i] = U/w[i];
	}
}