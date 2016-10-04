#include <stdio.h>
#include <math.h>

int seq[]= {0,0,0,1,1,1,1,0};
int gen_count = 15;
char start[]= {'0','1','1','0','0','1'};


	
int next(char * coming){
		int a=(coming[0]-'0')*4;
		int b=(coming[1]-'0')*2;
		int c=(coming[2]-'0')*1;
	return seq[7-(a+b+c)];
}
int main(){
	
	
	int len_of_start=sizeof(start)/sizeof(start[0]);
	int column=2*(gen_count-1)+len_of_start;
	int row=gen_count+1;
	char matrix[row][column];
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			matrix[i][j]='0';	
		}
	}
		
	i=0;
	for(j=gen_count-1;j<gen_count+len_of_start-1;j++){
		matrix[0][j]=start[i++];	
	}
	

	
	for(i=0;i<row-1;i++){
		for(j=0;j<column;j++){
			char temp[3];
			temp[0]=matrix[i][j-1];
			temp[1]=matrix[i][j];
			temp[2]=matrix[i][j+1];
			if(j==0)
				temp[0]='0';
			else if( j==column-1)
				temp[2]='0';
			int xx=next(temp);
			if(xx==1)
				matrix[i+1][j]='1';
			
			
		}	
	}

	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%c ",matrix[i][j]);	
		}
		printf("\n");
	}
	
	return 0;

}
