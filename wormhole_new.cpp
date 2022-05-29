
#include<bits/stdc++.h>
using namespace std;


int dist(pair<int,int> x, pair<int,int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

void solve() {
	int n; cin >> n;
	int nodes = 2*n + 2;

	vector<pair<int,int>> location(nodes);
	vector<vector<int>> cost(nodes, vector<int>(nodes, -1));

	pair<int,int> start, finish;
	cin >> start.first >> start.second;
	cin >> finish.first >> finish.second;
	
	location[0] = start;
	location[nodes - 1] = finish;

	for(int i = 0 ; i < n ; ++i) {

		int x1, y1, x2, y2, w;
		cin >> x1 >> y1 >> x2 >> y2 >> w;
		pair<int,int> temp = make_pair(x1, y1);
		pair<int,int> temp2 = make_pair(x2, y2);

		location[2*i + 1] = temp;
		location[2*i + 2] = temp2;
		cost[2*i + 1][2*i + 2] = cost[2*i + 2][2*i + 1] = w;
	}


	for(int i = 0 ; i < nodes ; ++i) {
		for(int j = 0 ; j < nodes ; ++j) {
			if(cost[i][j] == -1) {
				cost[i][j] = dist(location[i], location[j]);
			}
		}
	}


	for(int k = 0 ; k < nodes ; ++k) {
		for(int i = 0 ; i < nodes ; ++i) {
			for(int j = 0 ; j < nodes ; ++j) {
				if( i == k || j == k) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]); 
			}
		}
	}
	cout << cost[0][nodes - 1] << endl;
}



int main() {
	int t; cin >> t;
	while(t--) solve();
}

// #include<iostream>
// using namespace std;
// struct node{   
//     int x, y;
// };

// int abs(int x){
//     return (x<0) ? -x : x;
// }

// int finddist(struct node *first,struct node *second){
// 	int dstx = abs(first->x - second->x);
// 	int dsty = abs(first->y - second->y);
// 	return dstx + dsty;
// }


// int main(){
//     int test;
//     cin >> test;
//     for(int t=1;t<=test;t++){
//         int warmholes;    
//         cin>>warmholes;

//         /* Initialise Code */
// 	    int nodes = 2 * warmholes + 2;
// 	  	struct node *location[nodes];
	  	
//         int cost[nodes][nodes];
// 	  	for(int i=0;i<nodes;i++){
// 	  		for(int j=0;j<nodes;j++){
// 	  			cost[i][j]=-1;
// 			}
// 		}

// 		//source
// 		  int sx, sy;
// 		  cin>>sx>>sy;
// 		  struct node *src=new struct node;
// 		  src->x=sx;
// 		  src->y=sy;
// 		  location[0]=src;

// 		//destination
// 		  int dox,doy;
// 		  cin>>dox>>doy;
// 		  struct node *temp=new node;
// 		  temp->x=dox;
// 		  temp->y=doy;
// 		  location[nodes-1]=temp;

//         //warmhole
// 		  for(int i=0;i<warmholes;i++){
// 		  	int six, siy;
// 		  	cin>>six>>siy;
// 		  	struct node *temp=new node;
// 			  	temp->x=six;
// 			  	temp->y=siy;
				
//             int dix,diy;
// 		  	cin>>dix>>diy;
// 		  	struct node *temp1=new node;
// 			  	temp1->x=dix;
// 			  	temp1->y=diy;
			
// 			int w;
// 		  	cin>>w;
		  	
//             location[2*i+1]=temp;
// 		  	location[2*i+2]=temp1;
// 		  	cost[2*i+1][2*i+2]=w;
// 		  	cost[2*i+2][2*i+1]=w;
//           }

//         // Initialise cost matrix      
//             for(int i=0;i<nodes;i++){
//                 for(int j=0;j<nodes;j++){
// 		  		    if(cost[i][j] == -1){
// 		  			cost[i][j] = finddist(location[i],location[j]);
// 				    }
// 			    }
//     		}

//        // Floyd Warshall
//             for(int k=0;k<nodes;k++){
//                 for(int i=0;i<nodes;i++){
//                     for(int j=0;j<nodes;j++){
//                         if(i==k||j==k)
//                             continue;
//                         cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
//                     }
//                 }
//             }

//         cout << "#" << t << " : " << cost[0][nodes-1] << "\n";
//     }
//     return 0;
// }


