//Solusi pencarian dengan kompleksitas O(1) -> binary search

//contoh code:
#include<stdio.h>

int main(){
	
	//misal mencari angka dalam array "angka"
	int angka[7]={1,4,6,3,2,9,7};
	
	
	//disort terlebih dahulu
	for(int i=0;i<7;i++){
		for(int j=6;j>i;j--){
			if(angka[j]<angka[j-1]){
				int temp;
				temp = angka[j];
				angka[j]=angka[j-1];
				angka[j-1]=temp;
			}
		}
	}
	
	int cari=7; //misal ingin cari angka 7
	
	//binary search
	int awal=0,akhir=6;
	int tengah=(awal+akhir)/2;
	
	while(awal<=akhir){
		
		//jika ketemu 
		if(angka[tengah]==cari){
			printf("Found at %d index",tengah);
			return 0;
		}
		
		//jika tidak ketemu dan angka yang dicari lebih kecil dari angka pada index tengah
		if(cari<angka[tengah]){
			akhir=tengah-1;
			tengah=(awal+akhir)/2;
		}
		
		//jika tidak ketemu dan angka yang dicari lebih besar dari angka pada index tengah
		if(cari>angka[tengah]){
			awal=tengah+1;
			tengah=(awal+akhir)/2;
		}
	}
	
	//Jika tidak ketemu
	printf("Not Found\n");
	return 0;
}
