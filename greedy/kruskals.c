#include<stdio.h> 
#define SIZE 100
struct edge { 
	int a; 
	int b; 
	int w; 
} edges[SIZE];

int par[SIZE], rank[SIZE];

// find root parent of a disjoint set
int find(int a)  { 
	if(par[a] == -1) { 
		return a; 
	} 
	return par[a] = find(par[a]);  
} 

// union by rank in disjoint set
void merge(int a,int b)  { 
	if(rank[a] < rank[b]) { 
		par[a] = b;
	} else if(rank[b] < rank[a]) { 
		par[b] = a;
	} else {
		par[a] = b;
		rank[b] += 1;
	}
} 
 
int main() { 
	int n, m, a, b, w, i, j, temp, sum = 0;  
	printf("enter the number of vertices: "); 
	scanf("%d",&n); 
	printf("enter the number of edges: "); 
	scanf("%d",&m); 
	for(i=0; i<n; i++) { 
		par[i] = -1; 
		rank[i] = 0; 
	} 
	printf("Enter the source, destination and weight for %d edges:\n",m); 
	for(i=0; i<m; i++) { 
		scanf("%d",&edges[i].a); 
		scanf("%d",&edges[i].b); 
		scanf("%d",&edges[i].w); 
	} 

	// for sorting the edges array according to their weights
	for(i=0; i<m; i++) { 
		for(j=0; j<m-1-i; j++) { 
			if(edges[j].w > edges[j+1].w) { 
				temp=edges[j].w; 
				edges[j].w=edges[j+1].w; 
				edges[j+1].w=temp; 
				
				temp=edges[j].a; 
				edges[j].a=edges[j+1].a; 
				edges[j+1].a=temp; 
				
				temp=edges[j].b; 
				edges[j].b=edges[j+1].b; 
				edges[j+1].b=temp; 
			} 
		} 
	} 

	printf("The edges required to construct minimum cost spanning tree are: \n"); 
	for(i=0; i<m; i++) { 
		// ensuring that new edge when added results a cycle in MST
		a = find(edges[i].a); 
		b = find(edges[i].b);
		if(a != b) { 
			sum += edges[i].w; 
			printf("Vertex %d to %d with weight %d\n",edges[i].a,edges[i].b,edges[i].w); 
			merge(a,b); 
		} 
	} 
	printf("The sum of the edge weights in the minimum cost spanning tree is %d\n",sum); 
} 