#include <bits/stdc++.h>
using namespace std;

bool in(int n, vector<int> a){
	for(auto i : a){
		if(i == n)
			return true;
	}
	return false;
}

bool same(vector<int> a, vector<int> b){
	for(int i = 0, j = 0; i < a.size(), j < b.size(); i++, j++){
		if(a[i] != b[i])
			return false;
	}
	if(a.size() == b.size())
		return true;
	return false;
}

int avg(vector<int> a){
	int sum = 0;
	for(auto i : a)
		sum += i;
	return sum/a.size();
}

vector<vector<int>> kmeans(vector<int> dataset, int num_clusters){
	srand(time(NULL));
	int n;
	vector<int> done;
	int i = 0;
	while(i<num_clusters){
		n = rand()%dataset.size();
		if(!in(n,done)){
			done.push_back(n);
			i++;
		}
	}
	vector<int> means;
	for(auto itr : done){
		means.push_back(dataset[itr]);
	}
	
	vector<int> cur_means = means;
	vector<int> prev_means = means;
	vector<vector<int>> final_clusters;
	//int in = 0;
	while(1){
	      	vector<vector<int>> clusters(num_clusters);
		for(auto itr : dataset){
			int i, diff = INT_MAX, index;
			for(i = 0; i < prev_means.size(); i++){
				if(fabs(prev_means[i] - itr) < diff){
					index = i;
					diff = fabs(prev_means[i] - itr);
				}
			}
			clusters[index].push_back(itr);
		}
		/* update the means */

		for(int p = 0; p < cur_means.size(); p++)
			cur_means[p] = avg(clusters[p]);
	

		
		if(same(cur_means,prev_means)){
			final_clusters = clusters;
			break;
		}
		prev_means = cur_means;
		//in++;
	}

	return final_clusters;
}

int main(){
	vector<int>dataset = {1,2,3,4,5,6,7,8,9};
        int num_clusters = 4;
	vector<vector<int>> result = kmeans(dataset, num_clusters);
	for(auto i : result){
		for(auto j : i)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}
