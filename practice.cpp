
SAMSUNG QUESTIONS

-----------------------------------------------------------------------------------------

1. Write the code of heap sort and complexity in different cases.

A. The process of rearranging the heap by comparing each parent with its children recursively
is known as heapify.

Insert (element) = O(logn)
Search(element) = O(n)
Find_min() = O(1)
Delete_min() = O(logn)

If heap array size = n, range of leaves ==> [floor(n / 2), n - 1] and internal nodes [0, floor(n/2) - 1]

---------------------------------------------------------------------------------------

2. Kadane's algorithm


 Tell brute force approach, divide and conquer approach and pref sum approach
A. Works in O(n) time and O(1) space

The idea there for a position i in an array ans variable contains the max subarray sum ending at i.
For a new element if it is negative, better do not consider it as it only decreases the sum. 

int kadane(vector<int> a, int n) {
	int sum = 0, ans = -1e9;

	for(int i = 0 ; i < n ; ++i) {
		sum += a[i];
		ans = max(ans, sum);
		sum = max(0, sum);
	}
	return ans;
}


int pref_sum(vector<int>&a, int n) {
	vector<int> pref(n, a[0]);
	for(int i = 1 ; i < n ; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}

	int min_pref_so_far = 0;
	int ans = -1e9;

	for(int i = 0 ; i < n ; ++i) {
		ans = max(ans, pref[i] - min_pref_so_far);
		min_pref_so_far = min(pref[i], min_pref_so_far);
	}

	return ans;

}

--------------------------------------------------------------------------------------


3. Kahn's algorithm for topo sort

A. A linear ordering of the vertices in such a way that for every edge u->v u comes before v in the that linear ordering.
A graph can have many topological orderings. Only defined for directed graphs.'

Inorder to reach a point we must complete all its dependencies.  

void kahn_algo( vector<vector<int>> &adj ) {
	int n = adj.size();
	vector<int> indegree(n, 0);

	for(int i = 0 ; i < n ; ++i) {
		for(auto val : adj[i]) indegree[val]++;
	}

	queue<int> q;
	for(int i = 0 ; i < n ; ++i) {
		if(indegree[i] == 0) q.push(i);
	}

	while( !q.empty() ) {
		int curr = q.front();
		q.pop();
		cout << curr << ' ';

		for(int neighbor : adj[curr]) {
			indegree[neighbor]--;
			if(indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}
}

---------------------------------------------------------------------------------------------

4. Write code for Dijkstra's algorithm

'
void dijkstra(vector<vector<pair<int,int>>> &adj) {
	int n = adj.size();
	vector<bool> vis(n, false);
	vector<int> dist(n, INT_MAX);

	set<pair<int,int>> s;     // (dist, node index);

	int src = 0;
	dist[src] = 0;
	s.insert(make_pair(0, src));

	while ( !s.empty() ) {
		int curr = (*s.begin()).second;
		s.erase(s.begin());

		if(vis[curr]) continue;
		vis[curr] = true;

		for(auto val : adj[curr]) {
			int neighbor = val.first;
			int cost = val.second
			if (dist[curr] + cost < dist[neighbor]) {
				dist[neighbor] = dist[curr] + cost;
				s.insert(make_pair(dist[neighbor], neighbor));
			}
		}
	}
}

---------------------------------------------------------------------------------------------

5. circular queue

class Queue {
private:
  int items[SIZE], front, rear;

public:
  Queue() {
    front = -1;
    rear = -1;
  }
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  

  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
    }
  }
  
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display() {
    // Function to display status of Circular Queue
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << "Front -> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i];
      cout << items[i];
      cout << endl
         << "Rear -> " << rear;
    }
  }
};

int main() {
  Queue q;
  q.deQueue();

  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  q.enQueue(6);

  q.display();

  int elem = q.deQueue();

  if (elem != -1)
    cout << endl
       << "Deleted Element is " << elem;

  q.display();

  q.enQueue(7);

  q.display();

  q.enQueue(8);

  return 0;
}

-------------------------------------------------------------------------------------



Final topics to revise

subsets
permutations
dynamic programming
n-brackets generation using backtracking
tree revision
project async javascript and promises.
mst using prim's algorithm
mst using kruskal's algorithm 

trie 
lru

----------------------------------------





