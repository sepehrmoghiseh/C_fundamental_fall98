#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct cell {
	int x;
	int y;
	int point;
	char name[300];
	char value;
	struct cell *next;
};
struct energy{
	
	int x;
	int y;
	int point;
	struct energy *next;
};
	int choosecell;
	int i,j;
	int n;
	char visual[3000][3000];
	char map[3000][3000];
	struct cell *headcell=NULL;
	char mapname[300];
	struct cell *headcell2=NULL;
	struct energy *headenergy=NULL;
	int flag=1;
	FILE *fpin;
	int flag_load=0;
	int sum;
struct cell * create_cell(int x,int y){
	struct cell * nn;
	nn = (struct cell *) malloc(sizeof(struct cell));
	nn->x = x;
	nn->y=y;
	nn->point=0;
	nn->next = NULL;
	nn->value=map[x][y];
	getchar();
	scanf("%[^\n]s",nn->name);
	if(y%2!=0)
		visual[x*2+1][y*4+2]='X';
	else
		visual[x*2][y*4+2]='X';
	return nn;
}
struct cell * create_cell3(int x,int y){
	struct cell * nn;
	nn = (struct cell *) malloc(sizeof(struct cell));
	nn->x = x;
	nn->y=y;
	nn->point=0;
	nn->next = NULL;
	nn->value=map[x][y];
	getchar();
	scanf("%[^\n]s",nn->name);
	if(y%2!=0)
		visual[x*2+1][y*4+2]='O';
	else
		visual[x*2][y*4+2]='O';
	return nn;
}
struct cell * create_cell4(int x,int y){
	struct cell * nn;
	nn = (struct cell *) malloc(sizeof(struct cell));
	nn->x = x;
	nn->y=y;
	nn->point=40;
	nn->next = NULL;
	nn->value=map[x][y];
	printf("Enter the name of cell:\n");
	getchar();
	scanf("%[^\n]s",nn->name);
	if(y%2!=0)
		visual[x*2+1][y*4+2]='O';
	else
		visual[x*2][y*4+2]='O';
	return nn;
}
struct cell * create_cell2(int x,int y){
	struct cell* nn;
	nn = (struct cell *) malloc(sizeof(struct cell));
	nn->x = x;
	nn->y=y;
	nn->point=40;
	nn->next = NULL;
	nn->value=map[x][y];
	printf("Enter the name of cell:\n");
	getchar();
	scanf("%[^\n]s",nn->name);
	if(y%2!=0)
		visual[x*2+1][y*4+2]='X';
	else
		visual[x*2][y*4+2]='X';
	return nn;
}
struct energy * create_energy(int x,int y){
	struct energy * nn;
	nn = (struct energy *) malloc(sizeof(struct energy));
	nn->x = x;
	nn->y=y;
	nn->point=100;
	nn->next = NULL;
	return nn;
}
void add_end_energy(struct energy **head,int x,int y){
	struct energy * current;
	if(*head==NULL)
		*head=create_energy(x,y);
	else {
		for(current=*head;current->next!=NULL;current=current->next);
			current->next=create_energy(x,y);
	}
}
void make_energy(void){
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){
			if(map[i][j]=='1')
				add_end_energy(&headenergy,i,j);
		}
}
void add_end(struct cell **head){
	struct cell *current;
	int x;
	int y;
	srand(time(NULL));
	x=rand()%(n);
	y=rand()%(n);
	while(1){
		while(y%2!=0&&(map[x][y]=='3'||visual[x*2+1][y*4+2]=='X')){
			x=rand()%(n);
			y=rand()%(n);
		}	
		if(y%2!=0&&(map[x][y]!='3'&&visual[x*2+1][y*4+2]!='X'))
			break;
		while(y%2==0&&(map[x][y]=='3'||visual[x*2][y*4+2]=='X')){
			x=rand()%(n);
			y=rand()%(n);
  	 	}	
		if(y%2==0&&(map[x][y]!='3'&&visual[x*2][y*4+2]!='X'))
			break;
	}
	if(*head==NULL)
		*head=create_cell(x,y);
	else {
		for(current=*head;current->next!=NULL;current=current->next);
			current->next=create_cell(x,y);

	}
}
void add_end_3(struct cell **head){
    struct cell *current;
	int x;
	int y;
	srand(time(NULL));
	x=rand()%(n);
	y=rand()%(n);
	while(1){
		while(y%2!=0&&(map[x][y]=='3'||visual[x*2+1][y*4+2]=='X'||visual[x*2+1][y*4+2]=='O')){
			x=rand()%(n);
			y=rand()%(n);
		}
		if(y%2!=0&&(map[x][y]!='3'&&visual[x*2+1][y*4+2]!='X'&&visual[x*2+1][y*4+2]!='O'))
			break;
		while(y%2==0&&(map[x][y]=='3'||visual[x*2][y*4+2]=='X'||visual[x*2][y*4+2]=='O')){
			x=rand()%(n);
			y=rand()%(n);
	   	}
		if(y%2==0&&(map[x][y]!='3'&&visual[x*2][y*4+2]!='X'&&visual[x*2][y*4+2]!='O'))
			break;
	}
	if(*head==NULL)
		*head=create_cell3(x,y);
	else {
		for(current=*head;current->next!=NULL;current=current->next);
			current->next=create_cell3(x,y);

	}
}
void movecell(int curx,int cury,int x,int y){
	int newx;
	int newy;
	newx=curx+x;
	newy=cury+y;
	if(newx<0||newx>=n||newy>=n||newy<0||map[newx][newy]=='3'||visual[newx*2+1][newy*4+2]=='X'||visual[newx*2][newy*4+2]=='X'||visual[newx*2+1][newy*4+2]=='O'||visual[newx*2][newy*4+2]=='O'){
		flag=1;
		return;
	}
	else {
		flag=2;
	}
	int xc,yc;
	xc=curx;
	yc=cury;
	curx=newx;
	cury=newy;
	if(yc%2!=0){
		if(map[xc][yc]=='1')
			visual[xc*2+1][yc*4+2]='e';
		if(map[xc][yc]=='2')
			visual[xc*2+1][yc*4+2]='m';
		if(map[xc][yc]=='4')
			visual[xc*2+1][yc*4+2]='n';
	}
	else{
		if(map[xc][yc]=='1')
			visual[xc*2][yc*4+2]='e';
		if(map[xc][yc]=='2')
			visual[xc*2][yc*4+2]='m';
		if(map[xc][yc]=='4')
			visual[xc*2][yc*4+2]='n';
	}
	
	if(newy%2!=0&&(map[newx][newy]!='3'&&visual[newx*2+1][newy*4+2]!='X'||visual[newx*2+1][newy*4+2]!='O'))
		visual[newx*2+1][newy*4+2]='X';
	if(newy%2==0&&(map[newx][newy]!='3'&&visual[newx*2][newy*4+2]!='X'||visual[newx*2][newy*4+2]!='O'))
	 	visual[newx*2][newy*4+2]='X';
	int found=1;
	struct cell * current;
	for(current=headcell;current!=NULL;current=current->next){
 		if(found==choosecell)
			break;
		found++;
		}
	current->x=newx;
	current->y=newy;
	current->value=map[newx][newy];
}
void movecell2(int curx,int cury,int x,int y){
	int newx;
	int newy;
	newx=curx+x;
	newy=cury+y;
	if(newx<0||newx>=n||newy>=n||newy<0||map[newx][newy]=='3'||visual[newx*2+1][newy*4+2]=='X'||visual[newx*2][newy*4+2]=='X'||visual[newx*2+1][newy*4+2]=='O'||visual[newx*2][newy*4+2]=='O'){
		flag=2;
		return;
	}
	else {
		flag=1;
	}
	int xc,yc;
	xc=curx;
	yc=cury;
	curx=newx;
	cury=newy;
	if(yc%2!=0){
		if(map[xc][yc]=='1')
			visual[xc*2+1][yc*4+2]='e';
		if(map[xc][yc]=='2')
			visual[xc*2+1][yc*4+2]='m';
		if(map[xc][yc]=='4')
			visual[xc*2+1][yc*4+2]='n';
	}
	else{
		if(map[xc][yc]=='1')
			visual[xc*2][yc*4+2]='e';
		if(map[xc][yc]=='2')
			visual[xc*2][yc*4+2]='m';
		if(map[xc][yc]=='4')
			visual[xc*2][yc*4+2]='n';
	}
	
	if(newy%2!=0&&(map[newx][newy]!='3'&&visual[newx*2+1][newy*4+2]!='X'||visual[newx*2+1][newy*4+2]!='O'))
		visual[newx*2+1][newy*4+2]='O';
	if(newy%2==0&&(map[newx][newy]!='3'&&visual[newx*2][newy*4+2]!='X'||visual[newx*2][newy*4+2]!='O'))
	 	visual[newx*2][newy*4+2]='O';
	int found=1;
	struct cell * current;
	for(current=headcell2;current!=NULL;current=current->next){
 		if(found==choosecell)
			break;
		found++;
		}
	current->x=newx;
	current->y=newy;
	current->value=map[newx][newy];
}
void make_cell(int n){
	int k;
	for(k=1;k<=n;k++){
		printf("Enter the name of cell:\n");
		add_end(&headcell);
	}
}
void make_cell2(int n){
	int k;
	for(k=1;k<=n;k++){
		printf("Enter the name of cell:\n");
		add_end_3(&headcell2);
	}
}
void add_end_2(struct cell **head,int x,int y){
	struct cell *current;
	if(*head==NULL)
		*head=create_cell2(x,y);
	else {
		for(current=*head;current->next!=NULL;current=current->next);
		current->next=create_cell2(x,y);

	}
}
void add_end_4(struct cell **head,int x,int y){
	struct cell *current;
	if(*head==NULL)
		*head=create_cell3(x,y);
	else {
		for(current=*head;current->next!=NULL;current=current->next);
		current->next=create_cell4(x,y);

	}
}
void split_cell(int x,int y){
	srand(time(NULL));
	int xrandom=rand()%(3)-1;
	int yrandom=rand()%(3)-1;
	
	while(y%2!=0&&x+xrandom<0||x+xrandom>=n||y+yrandom>=n||y+yrandom<0||map[x+xrandom][y+yrandom]=='3'||visual[(x+xrandom)*2+1][(y+yrandom)*4+2]=='X'||visual[(x+xrandom)*2+1][(y+yrandom)*4+2]=='O'||(xrandom==0&&yrandom==0)||(xrandom==-1&&yrandom==-1)||(xrandom==-1&&yrandom==1)){
		xrandom=rand()%(3)-1;
    	yrandom=rand()%(3)-1;
	}
	while(y%2==0&&x+xrandom<0||x+xrandom>=n||y+yrandom>=n||y+yrandom<0||map[x+xrandom][y+yrandom]=='3'||visual[(x+xrandom)*2][(y+yrandom)*4+2]=='X'||visual[(x+xrandom)*2][(y+yrandom)*4+2]=='O'||(xrandom==0&&yrandom==0)||(xrandom==1&&yrandom==-1)||(xrandom==1&&yrandom==1)){
		xrandom=rand()%(3)-1;
    	yrandom=rand()%(3)-1;
	}
	delete_some(&headcell,x,y);
	add_end_2(&headcell,x+xrandom,y+yrandom);
	add_end_2(&headcell,x,y);

}
void split_cell2(int x,int y){
	srand(time(NULL));
	int xrandom=rand()%(3)-1;
	int yrandom=rand()%(3)-1;
	
	while(y%2!=0&&x+xrandom<0||x+xrandom>=n||y+yrandom>=n||y+yrandom<0||map[x+xrandom][y+yrandom]=='3'||visual[(x+xrandom)*2+1][(y+yrandom)*4+2]=='X'||visual[(x+xrandom)*2+1][(y+yrandom)*4+2]=='O'||(xrandom==0&&yrandom==0)||(xrandom==-1&&yrandom==-1)||(xrandom==-1&&yrandom==1)){
		xrandom=rand()%(3)-1;
    	yrandom=rand()%(3)-1;
	}
	while(y%2==0&&x+xrandom<0||x+xrandom>=n||y+yrandom>=n||y+yrandom<0||map[x+xrandom][y+yrandom]=='3'||visual[(x+xrandom)*2][(y+yrandom)*4+2]=='X'||visual[(x+xrandom)*2][(y+yrandom)*4+2]=='O'||(xrandom==0&&yrandom==0)||(xrandom==1&&yrandom==-1)||(xrandom==1&&yrandom==1)){
		xrandom=rand()%(3)-1;
    	yrandom=rand()%(3)-1;
	}
	delete_some(&headcell2,x,y);
	add_end_4(&headcell2,x+xrandom,y+yrandom);
	add_end_4(&headcell2,x,y);

}
void give_energy(int x,int y,struct energy * headenergy,struct cell *headcell){
	struct energy * current;
	struct cell * current2;
	for(current=headenergy;current!=NULL;current=current->next)
		if(current->x==x&&current->y==y)
			break;
	for(current2=headcell;current2!=NULL;current2=current2->next)
		if(current2->x==x&&current2->y==y)
			break;
		if(current->point==0||current2->point==100)
			return;
		if(current2->point<=85&&current->point>=15){
			current2->point +=15;
			current->point -=15;	
		}
		else if(current2->point>85&&current->point>=15){
			current->point=current->point-(100-current2->point);
			current2->point=100;
		}
		else if(current2->point>85&&current->point<15){
			current2->point=current2->point+current->point;
			current->point=0;
		}
		else if(current2->point<=85&&current->point<15){
			current2->point=current2->point+current->point;
			current->point=0;
		}
}
void  delete_some(struct cell ** list,int x,int y){
	struct cell * temp;
	struct cell * current;
	struct cell * current2;
	 if ((*list)->x==x&&(*list)->y==y){
		temp=*list;
		*list=(*list)->next;
		free(temp);
		}
	else {
		current=*list;
		while(current->next!=NULL&&(current->next)->x!=x&&(current->next)->y!=y){
			current=current->next;
		}
			temp=current->next;
			current->next=current->next->next;
}
}
void print_list_cell(struct cell ** head){
	struct cell * current;
	int j=1;
	for(current=*head;current!=NULL;current=current->next){
		printf("\n[%d] %s (%d,%d) value : %c\n",j,current->name,current->y,n-current->x-1,current->value);
		j++;
	}
}
struct cell* create_load(){
	struct cell* nn;
	nn=(struct cell*)malloc(sizeof(struct cell));
	fread(nn,sizeof(struct cell),1,fpin);
	nn->next=NULL;
	return nn;
}
struct energy* create_load2(){
	struct energy* nn;
	nn=(struct energy*)malloc(sizeof(struct energy));
	fread(nn,sizeof(struct energy),1,fpin);
	nn->next=NULL;
	return nn;
}
void loadlist(struct cell **head){
	struct cell * current;
	if (*head==NULL){
		*head=create_load();			
	}
	else{
		for(current=*head;current->next!=NULL;current=current->next);
		current->next=create_load();
	}
}
void loadlisten(struct energy **head){
	struct energy* current;
	if (*head==NULL){
		*head=create_load2();
	}
	else{
		for(current=*head;current->next!=NULL;current=current->next);
		current->next=create_load2();
	}
}
void saving(){
	FILE* fp;
	struct cell *current;
	struct energy *current2;
	int energynumber=0,player1=0,player2=0;
	for(current=headcell;current!=NULL;current=current->next){
		player1++;
	}
	for(current=headcell2;current!=NULL;current=current->next){
		player2++;
	}
	for(current2=headenergy;current2!=NULL;current2=current2->next){	
		energynumber++;
	}
	printf("Enter the address of the file:\n");
	char filename[300];
	getchar();
	scanf("%s",filename);
	fp=fopen(filename,"wb");
	fwrite(&n,sizeof(int),1,fp);
	fwrite(&player1,sizeof(int),1,fp);
	fwrite(&player2,sizeof(int),1,fp);
	fwrite(&energynumber,sizeof(int),1,fp);
	for(i=0;i<n;i++)
		for (j=0;j<n;j++)
			fwrite(&map[i][j],sizeof(char),1,fp);
	for(i=0;i<2*n;i++)
		for(j=0;j<4*n+1;j++)
			fwrite(&visual[i][j],sizeof(char),1,fp);
	for(current=headcell;current!=NULL;current=current->next){
		fwrite(current,sizeof(struct cell),1,fp);
	}

	for(current=headcell2;current!=NULL;current=current->next){
		fwrite(current,sizeof(struct cell),1,fp);
	}

	for(current2=headenergy;current2!=NULL;current2=current2->next){	
		fwrite(current2,sizeof(struct energy),1,fp);
	}
	fclose(fp);
}
void loading(){
	int energynumber=0,player1=0,player2=0;
	struct cell *current;
	struct energy *current2;
	char filename[300];
	char read;
	printf("Enter the adress of the file:\n");
	scanf("%s",filename);
	fpin=fopen(filename,"rb");
	if(fpin==NULL)
		return ;
	fread(&n,sizeof(int),1,fpin);
    fread(&player1,sizeof(int),1,fpin);
	fread(&player2,sizeof(int),1,fpin);
	fread(&energynumber,sizeof(int),1,fpin);
	for(i=0;i<n;i++)
		for (j=0;j<n;j++)
			fread(&map[i][j],sizeof(char),1,fpin);
	for(i=0;i<2*n;i++){
		for(j=0;j<4*n+1;j++){
			fread(&visual[i][j],sizeof(char),1,fpin);
		}
	}
	if(player2!=0)
		flag_load=2;
	else if(player1!=0)
		flag_load=1;
	else
		flag_load=0;
	while(player1){
		loadlist(&headcell);		
			player1--;
	}
	while(player2){
		loadlist(&headcell2);			
		player2--;
	}	

	while(energynumber!=0){
		loadlisten(&headenergy);			
		energynumber--;
	}
	fclose(fpin);
}
void visual_map(){
	if(n%2==0){
		for(i=0;i<2*n;i++)
			for(j=0;j<4*n+1;j++){
				int x =j%8;
				if(i==0&&j==4*n)
					visual[i][j]=NULL;
				else if(x==0)
					visual[i][j]=(i%2)?'\\':'/';
				else if(x==4)
					visual[i][j]=(i%2) ? '/' : '\\';
				else if(x<4)
					visual[i][j]=(i%2)? '_': ' ';
				else 
					 visual[i][j]=(i%2)? ' ': '_';
			}
		
	}
	else {
		for(i=0;i<2*n;i++)
			for(j=0;j<4*n+1;j++){
				int x =j%8;
				if(x==0){
					visual[i][j]=(i%2)?'\\':'/';
				}
				else if(x==4)
					visual[i][j]=(i%2) ? '/' : '\\';
				else if(x<4)
					visual[i][j]=(i%2)? '_': ' ';
				else 
					 visual[i][j]=(i%2)? ' ': '_';
			}	
	}
}
void print_map(){
	 if(n%2==0){
	 	for(i=0;i<n/2;i++)
	 		printf(" ___\t");
	 	printf("\n");
	 }
	else {
	 	for(i=0;i<n/2+1;i++)
	 		printf(" ___\t");
	 	printf("\n");

	}
	for(i=0;i<2*n;i++){
		for(j=0;j<4*n+1;j++)
			printf("%c",visual[i][j]);
		printf("\n");
	}
	printf("    \\___/");
	for(i=1;i<n/2;i++){
		printf("   \\___/");
	}
}
int main(){
	int chooseaction;
	int choose;
	int number_of_cells;
	int chooseway;
	FILE *fp,*fpsave;
	fp=fopen("C:\\map6.bin","rb");
	fread(&n,sizeof(int),1,fp);
	visual_map();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			fread(&map[i][j],sizeof(char),1,fp);
	}
	fclose(fp);
	fp=fopen("C:\\Users\\ASUS\\Documents\\codes\\save.bin","rb");
	char read;
	fpsave=fopen("C:\\Users\\ASUS\\Documents\\codes\\text2map.txt","w");
	fread(&n,sizeof(int),1,fp);
	fprintf(fpsave,"%d",n);
	for(i=0;i<n*n;i++){
		fread(&read,sizeof(char),1,fp);
		fputc(read,fpsave);
	}
	fclose(fpsave);
	fclose(fp);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(map[i][j]=='1'){
				if(j%2!=0)
					visual[i*2+1][j*4+2]='e';
				else 
					visual[i*2][j*4+2]='e';
			}
			else if(map[i][j]=='2'){
				if(j%2!=0)
					visual[i*2+1][j*4+2]='m';
				else 
					visual[i*2][j*4+2]='m';
			}
			else if(map[i][j]=='3'){
				if(j%2!=0)
					visual[i*2+1][j*4+2]='f';
				else 
				visual[i*2][j*4+2]='f';
			}
			else if(map[i][j]=='4'){
				if(j%2!=0)
					visual[i*2+1][j*4+2]='n';
				else 
					visual[i*2][j*4+2]='n';
			}
			
		}
	make_energy();
	printf("[1] Load\n[2] New Singleplayer Game\n[3] New Multiplayer Game\n[4] Map editor\n[5] Exit\n");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			loading();
		case 2:
			if(flag_load==0){
			printf("Enter the number of cells\n");
			scanf("%d",&number_of_cells);
			make_cell(number_of_cells);
			while(1){
				system("cls");
				print_map();
				printf("\nPlease choose one of your cell: \n");
				print_list_cell(&headcell);
				scanf("%d",&choosecell);
				int found=1;
				struct cell * current;
				for(current=headcell;current!=NULL;current=current->next){
					if(found==choosecell)
						break;
					found++;
				}
				printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
				scanf("%d",&chooseaction);
				switch(chooseaction){
					case 1:
						printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
						scanf("%d",&chooseway);
						if(chooseway==1)
							movecell(current->x,current->y,-1,0);
					    else if(chooseway==2)
							movecell(current->x,current->y,1,0);
						else if(chooseway==3){
							if(current->y%2!=0)
								movecell(current->x,current->y,0,1);
							else
								movecell(current->x,current->y,-1,1);
						}
						else if(chooseway==4){
							if(current->y%2!=0)
								movecell(current->x,current->y,0,-1);
							else
								movecell(current->x,current->y,-1,-1);
						}
						else if(chooseway==5){
							if(current->y%2!=0)
								movecell(current->x,current->y,1,1);
							else
								movecell(current->x,current->y,0,1);
						}
						else if(chooseway==6){
							if(current->y%2!=0)
								movecell(current->x,current->y,1,-1);
							else
								movecell(current->x,current->y,0,-1);
					        }
							break;
					case 2:
						if(map[current->x][current->y]=='2'&&current->point>=80){
							current->point=40;
							split_cell(current->x,current->y);
						}
						break;
					case 3:
						if(map[current->x][current->y]=='1'){
							give_energy(current->x,current->y,headenergy,headcell);	
						}
						break;
					case 4:
						saving();
						return 0;
						break;
					case 5:
						for(current=headcell;current!=NULL;current=current->next)
								sum +=current->point;
						printf("%d is the final score\n",sum);
						return 0;
						break;
				}
			}
		}
			if(flag_load==1){
				while(1){
					system("cls");
					print_map();
					printf("\nPlease choose one of your cell: \n");
					print_list_cell(&headcell);
					scanf("%d",&choosecell);
					int found=1;
					struct cell * current;
					for(current=headcell;current!=NULL;current=current->next){
						if(found==choosecell)
							break;
						found++;
					}
					printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
					scanf("%d",&chooseaction);
					switch(chooseaction){
						case 1:
							printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
							scanf("%d",&chooseway);
							if(chooseway==1)
								movecell(current->x,current->y,-1,0);
					    	else if(chooseway==2)
								movecell(current->x,current->y,1,0);
							else if(chooseway==3){
								if(current->y%2!=0)
									movecell(current->x,current->y,0,1);
								else
									movecell(current->x,current->y,-1,1);
							}
							else if(chooseway==4){
								if(current->y%2!=0)
									movecell(current->x,current->y,0,-1);
								else
									movecell(current->x,current->y,-1,-1);
							}
							else if(chooseway==5){
								if(current->y%2!=0)
									movecell(current->x,current->y,1,1);
								else
									movecell(current->x,current->y,0,1);
							}
							else if(chooseway==6){
								if(current->y%2!=0)
									movecell(current->x,current->y,1,-1);
								else
									movecell(current->x,current->y,0,-1);
					        }
							break;
						case 2:
							if(map[current->x][current->y]=='2'&&current->point>=80){
								current->point=40;
								split_cell(current->x,current->y);
							}
							break;
						case 3:
							if(map[current->x][current->y]=='1'){
								give_energy(current->x,current->y,headenergy,headcell);	
							}
							break;
						case 4:
							saving();
							return 0;
							break;
						case 5:
							for(current=headcell;current!=NULL;current=current->next)
								sum +=current->point;
							printf("%d is the final score\n",sum);
							return 0;
							break;
					}
		
				}
			}
		case 3:
			if(flag_load==0){
				printf("Enter the number of cells player X:\n");
				scanf("%d",&number_of_cells);
				make_cell(number_of_cells);	
				printf("Enter the number of cells player O:\n");
				scanf("%d",&number_of_cells);
				make_cell2(number_of_cells);
			}
			while(1){
				system("cls");
				print_map();
				if(flag==1){
					printf("\nPlease choose one of your cell player X: \n");
					print_list_cell(&headcell);
					scanf("%d",&choosecell);
					int found=1;
					struct cell * current;
					for(current=headcell;current!=NULL;current=current->next){
						if(found==choosecell)
							break;
						found++;
					}
					printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
					scanf("%d",&chooseaction);
					switch(chooseaction){
						case 1:
							printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
							scanf("%d",&chooseway);
							if(chooseway==1)
								movecell(current->x,current->y,-1,0);
					    	else if(chooseway==2)
								movecell(current->x,current->y,1,0);
							else if(chooseway==3){
								if(current->y%2!=0)
									movecell(current->x,current->y,0,1);
								else
									movecell(current->x,current->y,-1,1);
							}
							else if(chooseway==4){
								if(current->y%2!=0)
									movecell(current->x,current->y,0,-1);
								else
									movecell(current->x,current->y,-1,-1);
							}
							else if(chooseway==5){
								if(current->y%2!=0)
									movecell(current->x,current->y,1,1);
								else
									movecell(current->x,current->y,0,1);
							}
							else if(chooseway==6){
								if(current->y%2!=0)
									movecell(current->x,current->y,1,-1);
								else
									movecell(current->x,current->y,0,-1);
					        }
							break;
						case 2:
							if(map[current->x][current->y]=='2'&&current->point>=80){
								current->point=40;
								split_cell(current->x,current->y);
								flag=2;
							}
							else {
								flag=1;
							}
							break;
						case 3:
							if(map[current->x][current->y]=='1'){
								give_energy(current->x,current->y,headenergy,headcell);	
								flag=2;
							}
							else
								flag=1;
							break;
						case 4:
							saving();
							return 0;
							break;
						case 5:
							for(current=headcell;current!=NULL;current=current->next)
								sum +=current->point;
							for(current=headcell2;current!=NULL;current=current->next)
								sum +=current->point;
							printf("%d is the final score\n",sum);
							return 0;
					}
				}
				else {
					printf("\nPlease choose one of your cell player O: \n");
					print_list_cell(&headcell2);
					scanf("%d",&choosecell);
					int found=1;
					struct cell * current;
					for(current=headcell2;current!=NULL;current=current->next){
						if(found==choosecell)
						break;
					found++;
					}
					printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
					scanf("%d",&chooseaction);
					switch(chooseaction){
						case 1:
							printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
							scanf("%d",&chooseway);
							if(chooseway==1)
								movecell2(current->x,current->y,-1,0);
					    	else if(chooseway==2)
								movecell2(current->x,current->y,1,0);
							else if(chooseway==3){
								if(current->y%2!=0)
									movecell2(current->x,current->y,0,1);
								else
									movecell2(current->x,current->y,-1,1);
							}
							else if(chooseway==4){
								if(current->y%2!=0)
									movecell2(current->x,current->y,0,-1);
								else
									movecell2(current->x,current->y,-1,-1);
							}
							else if(chooseway==5){
								if(current->y%2!=0)
									movecell2(current->x,current->y,1,1);
								else
									movecell2(current->x,current->y,0,1);
							}
							else if(chooseway==6){
								if(current->y%2!=0)
									movecell2(current->x,current->y,1,-1);
								else
									movecell2(current->x,current->y,0,-1);
					        }
							break;
						case 2:
							if(map[current->x][current->y]=='2'&&current->point>=80){
								current->point=40;
								split_cell2(current->x,current->y);
								flag=1;
							}
							else {
								flag=2;
							}
							break;
						case 3:
							if(map[current->x][current->y]=='1'){
								give_energy(current->x,current->y,headenergy,headcell2);	
								flag=1;
							}
							else
								flag=2;
							break;
							case 4:
								saving();
								return 0;
								break;
							case 5:
								for(current=headcell;current!=NULL;current=current->next)
									sum +=current->point;
								for(current=headcell2;current!=NULL;current=current->next)
									sum +=current->point;
								printf("%d is the final score\n",sum);
								return 0;	
					}
				}
			}
		case 4:
			
			printf("Enter the name of the map file:\n");
			scanf("%s",mapname);
			fpin=fopen(mapname,"wb");
			int number;
			char value;
			printf("Enter the n:\n ");
			scanf("%d",&number);
			fwrite(&number,sizeof(int),1,fpin);
			printf("Enter the value of the houses:\n");
			for(i=1;i<=number*number;i++){
				getchar();
				scanf("%c",&value);
				fwrite(&value,sizeof(char),1,fpin);
			}
			fclose(fpin);
			break;	
		case 5:
			return 0;
	}	
	getchar();
}

