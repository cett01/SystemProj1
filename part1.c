#include <stdio.h>
#include <math.h>
#include <string.h>

   
int seq[]= {0,0,0,1,1,1,1,0};
//int gen_count = 15;
//char start[]= {'0','1','1','0','0','1'};

int assemblySubroutine(int rule, int left, int center, int right);
 
/*
int next(char * coming){
		int a=(coming[0]-'0')*4;
		int b=(coming[1]-'0')*2;
		int c=(coming[2]-'0')*1;
	return seq[7-(a+b+c)];
}
*/

int main(int argc, char **argv)
{
 
	
	FILE *fp;
	int *line;
	int *tempLine;
	int length;
	int rule;
	
	printf("Please input the rule number:\n");
	scanf("%d", &rule);
	
    fp = fopen("input1d.txt", "r+");
	if(!fp)
	{
		printf("ERROR!! Opening");
	}
	else
	{
		fscanf(fp, "%d", &length);
		//printf("%d", length);
		line = (int *)malloc(length*sizeof(int));
		tempLine = (int *)malloc(length*sizeof(int));

		int i=0;
		while(!feof(fp)){
			fscanf(fp, "%d", &line[i]);
			//printf("%c", line[i]);
			i++;
		}
			
	}
    fclose(fp);
	
	//printf("\n%s\n", line);
	int i, j;
	for(i=0; i<length; i++){
		printf("%d ", line[i]);
	}
    
	int row=length/2+1;
	int sayi = assemblySubroutine(rule, 0, 0, 1);
	printf("\n%d\n", sayi);

/*
	for(i=0;i<row;i++){
		for(j=0; j<length; j++){
			if(j==0){
				tempLine[j] = assemblySubroutine(rule, 0, line[j], line[j+1]);	//left control

			}
			else if(j==length-1){
				tempLine[j] = assemblySubroutine(rule, line[j-1], line[j], 0);  //right control

			}
			else{
				tempLine[j] = assemblySubroutine(rule, line[j-1], line[j], line[j+1]);  //others
			}
		//printf("%s\n", line);
		}
		
		for(k=0; k<length; k++){
			line[k] = tempLine[k];
		}
	}
		
	*/
	return 0;

}
