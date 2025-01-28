#include "graph.c"
#define INFINITY __INT_MAX__

void printPath(int predecessor[], int goal){
	if(predecessor[goal] == -1) return;
	printPath(predecessor, predecessor[goal]);
	printf("%c --> ", goal + 'A');
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
	visited[start] = 1;
	//Populating the distances of the nodes connected to the start node.
	//And marking their predecessor to start node.
	struct Node* curr = adjList[start]->head; 
	while (curr){
		dist[curr->vertex - 'A'] = curr->weight;
		predecessor[curr->vertex - 'A'] = start;
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
			int new_cost = dist[curr_min] + curr_neighbour->weight;
			if(new_cost < dist[neighbour_index]){ 
				// Perform relaxation on the adjacent nodes
				dist[neighbour_index] = new_cost;
				predecessor[neighbour_index] = curr_min;
			}
			curr_neighbour = curr_neighbour->next;
		}
	}
	if(predecessor[goal] == -1){
		printf("Path not found!\n");
	} else {
		printf("The path is: %c -->", start + 'A');
		printPath(predecessor, goal);
		printf("End\nPath Cost: %d", dist[goal]);
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
	printf("The adjacency list is: \n");
	displayAdjList(adjList,V);
	printf("\nEnter the Start Node and the Goal node: ");
	getchar();
	scanf("%c %c",&start, &goal);
	printf("On Applying Dijkstra's Algorithm:\n");
	dijkstraPath(adjList, start - 'A', goal - 'A', V);
	return 0;
}
