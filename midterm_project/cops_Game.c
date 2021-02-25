#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
	int cop,robber,policestation,xr,yr,xp,yp,h=0,movexp=0,moveyp=0,movexr=0,moveyr=0,s,movecops=0,moverobber=0,g[3000],z[3000],xrr,yrr,l,u;
	int m,n,i,j;
	int k=1;
	int a[3000],b[3000];
	int matrix[3000][3000];
	int t=1;
void print(){
	sleep(1);
	system("cls");
	printf("\n\n\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(matrix[i][j]==-1){
				printf("\033[0;36m");
				printf("T\t");
				printf("\033[0m");
			}
			else if(matrix[i][j]>0){
				printf("\033[1;35m");
				printf("D%d\t",matrix[i][j]);
				printf("\033[0m");
			}
			else {
				printf("\033[0;33m");
				printf("-\t");
				printf("\033[0m");
			}
			}
			printf("\n\n");
		}

}
 void clear(){
 		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				matrix[i][j]=0;
		}
	}
 }
int game(){
	clear();
		srand(time(NULL));
		if(h==0){
			xr=rand()%n+1;
			yr=rand()%m+1;
			moverobber++;
			if(xr==xp&&yr==yp)
				return 0;
			while(k<=policestation){
				while(b[k]>0){
					xp=rand()%n+1;
					yp=rand()%m+1;
					g[k]=xp;
					z[k]=yp;
					matrix[xp][yp]=t;
					movecops++;
					if(xr==xp&&yr==yp)
					return 0;
					
					matrix[xr][yr]=-1;
					b[k]--;
			}
			k++;
			t++;

		}
	}
	else{
			xrr=(rand()%3)-1;
			yrr=(rand()%3)-1;
			while(xr+xrr>n||xr+xrr<1||yr+yrr<1||yr+yrr>m){
                xrr=(rand()%3)-1;
                yrr=(rand()%3)-1;
			}
			xr +=xrr;
			yr +=yrr;
			if(xrr!=0||yrr!=0)
			moverobber++;
			if(xr==xp&&yr==yp)
				return 0;
				clear();
		while(k<=policestation){
			while(b[k]>0){
			if(abs(g[k]-xr)<=2&&abs(z[k]-yr)<=2){
				if(g[k]<xr&&g[k]+1<=n)
						g[k]+=1;
					if(z[k]<yr&&z[k]+1<=m)
						z[k]+=1;
					if(g[k]>xr&&g[k]-1>=1)
						g[k]-=1;
					if(z[k]>yr&&z[k]-1>=1)
						z[k]-=1;
					l=g[k];
					u=z[k];
					matrix[l][u]=t;
				}
				else{
					
					xrr=(rand()%3)-1;
               		yrr=(rand()%3)-1;
                	while(g[k]+xrr>n||g[k]+xrr<1||z[k]+yrr<1||z[k]+yrr>m){
                    	xrr=(rand()%3)-1;
                    	yrr=(rand()%3)-1;
					}	
					g[k]+=xrr;
					z[k]+=yrr;
					u=z[k];
					l=g[k];
					matrix[l][u]=t;
				}
				matrix[xr][yr]=-1;
				if(xrr!=0||yrr!=0)
					movecops++;
				if(xr==g[k]&&yr==z[k])
					return 0;
				b[k]--;
			}
			k++;
			t++;
		}
	}

	print();
	h++;
	return 1;
}
int main(){
	printf("set the premeter!:");
	scanf("%d%d" , &n,&m);

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			matrix[i][j]=0;
		}
	}
	printf("how many policestation?:");
	scanf("%d" , &policestation);

	while(k<=policestation){
		printf("cops of policestation %d:",k);
		scanf("%d",&a[k]);
		b[k]=a[k];
		k++;
	}
	k=1;
	while(game()){
		s=1;
		while(s<=policestation){
			b[s]=a[s];
			s++;
}
		k=1;
		t=1;
}
	printf("\033[0;31m");
	printf("finally you caught the robber\nrobber moves are %d\ncops moves are %d" , moverobber,movecops);
	printf("\033[0m");
	}
