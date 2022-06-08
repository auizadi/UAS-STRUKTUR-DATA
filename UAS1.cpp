#include<iostream>
#define MAX 100

using namespace std;

int adjMtx[MAX][MAX];

void inisialisasiMtx(int v){
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			adjMtx[i][j] = 0;
		}
	}
}

void tambahEdge(int u, int v, int w){
	adjMtx[u][v] = w;
	adjMtx[v][u] = w;
}

void cetakMtx(int v){
	for(int i = 1; i <= v; i++){
		cout<<"\t"<<"("<<i<<")";
	}
	cout<<endl;
	for(int i = 1; i <= v; i++){
		cout<<"("<<i<<")"<<"\t";
		
		for(int j = 1; j <= v; j++){
			cout<<adjMtx[i][j]<<"\t";
		}
		cout<<endl;
	}
}
	
int main(){
	int vertex = 3;
	
	inisialisasiMtx(vertex);
	
	tambahEdge(2, 1, 10);
	tambahEdge(3, 1, 15);
	tambahEdge(3, 2, 13);
	
	cetakMtx(vertex);
	
}
