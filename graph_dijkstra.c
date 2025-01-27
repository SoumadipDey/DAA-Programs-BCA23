#include "graph.c"
#define INFINITY __INT_MAX__

void printPath(){

}

int edgeCost(struct List** adjList, int u, int v){
	int cost = INFINITY;
	struct Node* curr = adjList[u]->head;
	while (curr){
		if(curr->vertex == 'A' + v) {
			cost = curr->weight;
			break;
		} 
		curr = curr->next;
	}
	return cost;
}

int findMinimum(int dist[], int visited[], int V){
	int min_index = -1;
	int min_dist = INFINITY;
	for (int i = 0; i < V; i++){
		if((dist[i] < min_dist) && (!visited[i])){
			min_dist = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void dijkstraPath(struct List** adjList, int start, int goal, int V){
	int dist[V], visited[V], predecessor[V];
	for (int i = 0; i < V; i++){
		dist[i] = INFINITY;
		visited[i] = 0;
		predecessor[i] = -1;
	}
	dist[start] = 0;
	//Populating the distances of the nodes connected to the start node.
	struct Node* curr = adjList[start]->head; 
	while (curr){
		dist[curr->vertex - 'A'] = curr->weight;	
		curr = curr->next;
	}
	struct Node* curr_neighbour; 
	while (visited[goal] != 1){ //Loop untill the goal node becomes visited;
		// Find the node having the minimum distance from the start node which is unvisited.
		int curr_min = findMinimum(dist, visited,V);
		// If no such node exists that means all viable nodes are visited. Break out of loop.
		if (curr_min == -1) break;
		visited[curr_min] = 1;
		// Else perform relaxation on the current neighbours
		curr_neighbour = adjList[curr_min]->head;
		// Loop through adjacent unvisited nodes
		while(curr_neighbour){ 
			int neighbour_index = curr_neighbour->vertex - 'A';
			int new_cost = dist[curr_min] + edgeCost(adjList, curr_min, neighbour_index);
			if((new_cost < dist[neighbour_index]) && (!visited[curr_neighbour->vertex - 'A'])){ 
				// Perform relaxation on the adjacent nodes
				dist[neighbour_index] = new_cost;
				predecessor[neighbour_index] = curr_min;
			}
			curr_neighbour = curr_neighbour->next;
		}
	}
}

int main(){
	int V,E;
	char start, goal;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V,E);
	printf("Enter the Start Node and the Goal node: ");
	scanf("%c %c",&start, &goal);
	printf("On Applying Dijkstra's Algorithm:\n");
	dijkstraPath(adjList, start - 'A', goal - 'A', V);
	return 0;
}
