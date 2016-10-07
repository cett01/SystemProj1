#include <stdio.h>
#include <math.h>
#include <string.h>


int assemblySubroutine(int rule, int left, int center, int right);
 

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
		line = (int *)malloc((length+1)*sizeof(int));
		tempLine = (int *)malloc((length+1)*sizeof(int));

		int i=0;
		while(!feof(fp)){
			fscanf(fp, "%d", &line[i]);
			i++;
		}
			
	}
    fclose(fp);
	
	int i, j,k;
	for(i=0; i<length; i++){
		printf("%d ", line[i]);
	}

	int row=length/2+1;

	int sayi = assemblySubroutine(rule, 1,0, 0);
	printf("\nresult:%d\n", sayi);
	

			/*for(i=0;i<row;i++){
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
		
for(j=0; j<length; j++){
			line[j] = tempLine[j];
		}
	}*/
		
	
	return 0;

}
