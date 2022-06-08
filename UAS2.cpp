#include<stdio.h>
#include<stdbool.h>
#define infinite 999
 
 int n;
 int tabel[100][100];
 
 int dijkstra(int awal, int akhir){
		int jarak[n];
		bool visit[n];
		int i, j, v;
		
		//inisialisasi dari jarak[] = infinite
		for(i = 1; i <= n; i++){
			jarak[i] = infinite;
		}
		
		//inisialisasi dari jarak visit[] = false
		for(i = 1; i <= n; i++){
			visit[i] = false;
		}
		
		jarak[awal] = 0;
		while(true){
			int u = -1;
			int jarakMin = infinite;
			//mencari vertex yang belum dikunjungi
			for(i = 1; i <= n; i++){
				if((visit[i] == false) && (jarak[i] < jarakMin)){
					u = i;
					jarakMin = jarak[i];
				}
			}
			//untuk mengakhiri perulangan while
			if((u == -1) || (jarak[u] == infinite)){
				break;
			}
			visit[u] = true;
			//melakukan relax untuk semua neighbor u
			for(v = 1; v <= n; v++){
				if(tabel[u][v] != 0){
					if(jarak[v] > jarak[u] + tabel[u][v]){
						jarak[v] = jarak[u] + tabel[u][v];
					}
				}
			}
		}
		//mengembalikan jarak terdekat dari kedua vertex
		return jarak[akhir];
 }
 
 int main(){
 	
 	int awal, akhir;
 	int i, j;
 	
 	printf("Masukkan Banyak Kota\t: ");
 	scanf("%d", &n);
 	
 	printf("Masukkan Jarak Vertex secara Matriks :\n");
 	
 	for(i = 1; i <= n; i++){
 		for(j = 1; j <= n; j++){
 			scanf("%d", &tabel[i][j]);
		 }
	 }
	 
	 int jawab = 0, x;
	 //menggunakan perulangan agar bisa di tes berulang kali
	 while(jawab == 0){
	 	printf("Kota Tempat Pedagang Berada\t: ");
	 	scanf("%d", &awal);
	 	printf("Kota Tempat Kastil\t\t: ");
	 	scanf("%d", &akhir);
	 	
	 	// fungsi dijkstra
	 	printf("Jarak minimal dari kota (Pedagang) %d ke (Kastil) %d: %d\n ", awal, akhir, dijkstra(awal, akhir));
	 	
	 	
	 	ulang :
	 		printf("Apakah ingin melanjutkan program? <y/n>");
	 		scanf("%s", &x);
	 		if(x == 'y' || x == 'Y'){
				jawab = 0;
				}else if(x == 'n' || x == 'N'){
					printf("Terima Kasih");
					jawab = 1;
				}else{
					printf("Input salah masukkaan y atau n");
					goto ulang;
	 		
				};
				
	 }
	 
 } 
 
 
