#include <iostream>
#include <queue>
#include <vector>
#include <sstream>


using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    vector<bool> forbidden(10000, false);
    vector<bool> visited(10000, false);
    

    int start = 0;
    for (int i=0; i<4; ++i){
      int x; scanf("%d", &x);
      start = (start * 10) + x;
    }

    int end = 0;
    for (int i=0; i<4; ++i){
      int x; scanf("%d", &x);
      end = (end * 10) + x;
    }
    
    int n;
    cin >> n;
    while (n--){
      int f=0;
      for (int i=0; i<4; ++i){
	int x; scanf("%d", &x);
	f = (f * 10) + x;
      }
      forbidden[f] = true;
    }

    queue<pair<int, int> > q;
    //El primer numero es el nodo que voy a visitar, el segundo es la minima distancia en que lo puedo visitar
    int answer = -1;
    q.push(make_pair(start, 0));
    while (!q.empty()){
      int node = q.front().first;
      int dist = q.front().second;
      q.pop();
      
      if (node == end){
	answer = dist;
	break;
      }
      
      if (!visited[node]){
	visited[node] = true;
	for (int i=1; i<=4; ++i){
	  int pow10 = 1; for (int j=1; j<=i; ++j) pow10 *= 10;
	  int digit = (node % pow10)* 10/pow10;

	  int v = node - digit * pow10/10;

	  int x = v + pow10/10 * ((digit+1)%10);
	  int y = v + pow10/10 * ((digit+9)%10);

	  if (!forbidden[x] && !visited[x]){
	    q.push(make_pair(x, dist + 1));
	  }
	  if (!forbidden[y] && !visited[y]){
	    q.push(make_pair(y, dist + 1));
	  }
	
	}
      }
    }
    cout << answer << endl;
  }
  return 0;
}
