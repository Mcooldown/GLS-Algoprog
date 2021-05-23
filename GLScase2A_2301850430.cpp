#include<stdio.h>
#include<string.h>

int main(){
	
	//data terdapat
	char id[60][110]={},first_name[60][110]={},city[60][110]={};
	char gender[60][110]={},has_car[60][110]={},has_property[60][110]={};
	
	//FILE CSV sudah ada di zip
	FILE *fp= fopen("testdata.csv","r");	
	
	fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",&id[0],&first_name[0],&city[0],&gender[0],&has_car[0],&has_property[0]);
//	printf("%s %s %s %s %s %s\n",id[0],first_name[0],city[0],gender[0],has_car[0],has_property[0]);
	
	int i=1;
	while(!feof(fp)){
		fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",&id[i],&first_name[i],&city[i],&gender[i],&has_car[i],&has_property[i]);
		i++;
	}
	
	do{
		
	//nampung nilai searching
	char cari[110]={},key[110]="nodata",value[110]={};

	//tanda buat ditampilkan atau tidak
	int tampil[110]={},temp;	
		
	gets(cari);
	if(strcmp(cari,"\0")==0)break;
	
	int awal,akhir;
	int j=0,cek=0,array=0;
	char search[60][110]={};
	
	while(cari[j]!=NULL){
		
		if(cari[j]==' ')cek++;
		
		//EQUALS
		if(cari[j]==' '&&cek==5 ){
			awal=j+1;
			akhir=awal;
			
			while(cari[akhir]!=NULL||cari[akhir]!='\n'){
				
				if(cari[akhir+1]==NULL||cari[akhir+1]=='\n'){
					int urut=0;
					for(int k=awal;k<=akhir;k++){
						value[urut]=cari[k];
						urut++;}
					
					break;
				}
				akhir++;
			}
		}
		
		//WHERE...
		if(cari[j]==' '&&cek==3){
			awal=j+1;
			akhir=awal;
			
			while(cari[akhir]!=' '){
				
				if(cari[akhir+1]==' '){
					int urut=0;
					for(int k=awal;k<=akhir;k++){
						key[urut]=cari[k];
						urut++;
					}
				}
				akhir++;
			}	
			
		}
		
		
		//SHOW ....
		if(cari[j]==' '&&cek==1){
			
			awal=j+1;
			akhir=awal;
			int array=0;
			if(cari[awal]=='*'){
				strcpy(search[array],"*");
				akhir=awal+1;
			}
			
			//looping sampe ketemu space
			while(cari[akhir]!=' '){
				
				//buat sebelum koma			
				if(cari[akhir]==','){
					int urut=0;
					for(int k=awal;k<akhir;k++){
						search[array][urut]=cari[k];
						urut++;
					}
//					printf("%s\n",search[array]);
					awal=akhir+1;
					array++;
				}
				
				//buat sebelum space
				else if(cari[akhir+1]==' '){
					int urut=0;
					for(int k=awal;k<=akhir;k++){
						search[array][urut]=cari[k];
						
						urut++;
					}
					
//					printf("%s\n",search[array]);
					temp=array;
				}
				
				//sebelum enter
				else if(cari[akhir+1]=='\n'){
					int urut=0;
					for(int k=awal;k<=akhir;k++){
						search[array][urut]=cari[k];
						
						urut++;
					}
					
//					printf("%s\n",search[array]);
					temp=array;
				}
				
				akhir++;
			}
			cek=1;
			
		}
		
		j++;
	}

		
//NANDAIN YANG MAU DISHOW DATANYA APA AJA
	for(int j=0;j<=4;j++){
		
		if(strcmp("*",search[0])==0){
			for(int k=0;k<=5;k++){
				tampil[k]=1;
			}
		}
		
		else{
			
			for(int k=0;k<=temp;k++){
				if(strcmp(id[0],search[k])==0)tampil[0]=1;
				else if(strcmp(first_name[0],search[k])==0)tampil[1]=1;
				else if(strcmp(city[0],search[k])==0)tampil[2]=1;
				else if(strcmp(gender[0],search[k])==0)tampil[3]=1;
				else if(strcmp(has_car[0],search[k])==0)tampil[4]=1;
				else if(strcmp(has_property[0],search[k])==0)tampil[5]=1;
			}
		}
	}

//SEARCHING
	if(strcmp(key,"nodata")==0){
		for(int j=1;j<i;j++){
			if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
			if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
			if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
			if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
			if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
			if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
			printf("\b\b \n");
		}
		
	}
	
	else{
		for(int j=1;j<i;j++){
			if(strcmp(id[0],key)==0){
				if(strcmp(id[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
				}
			}
			
			else if(strcmp(first_name[0],key)==0){
				if(strcmp(first_name[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
				}
			}
			
			if(strcmp(city[0],key)==0){
				if(strcmp(city[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
				}
			}
			
			if(strcmp(gender[0],key)==0){
				if(strcmp(gender[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
				}
			}
			
			if(strcmp(has_car[0],key)==0){
				if(strcmp(has_car[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
				}
			}
			
			if(strcmp(has_property[0],key)==0){
				if(strcmp(has_property[j],value)==0){
					if(tampil[0]==1)printf("%s: %s, ",id[0],id[j]);
					if(tampil[1]==1)printf("%s: %s, ",first_name[0],first_name[j]);
					if(tampil[2]==1)printf("%s: %s, ",city[0],city[j]);
					if(tampil[3]==1)printf("%s: %s, ",gender[0],gender[j]);
					if(tampil[4]==1)printf("%s: %s, ",has_car[0],has_car[j]);
					if(tampil[5]==1)printf("%s: %s, ",has_property[0],has_property[j]);
					printf("\b\b \n");
					}
				}
			}
		}
	
	}while(true);
	
	
	fclose(fp);
	return 0;
}
