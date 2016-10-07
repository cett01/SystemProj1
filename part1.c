#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int assemblySubroutine(int rule, int left, int center, int right);
 // we send  rule number, and the cell that the subroutine should check the filled boxes such as left, center and, right
 // then return value of the subroutine will be the next element of the current position
int main(int argc, char **argv)
{
 
	
	FILE *fp;
	int *line;
	int *tempLine;
	int length;
	int rule;
	
	printf("Please input the rule number:\n");
	scanf("%d", &rule);
	
    fp = fopen(argv[1], "r+");
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
		//printf("%d ", line[i]);
	}

	int row=length/2+1;// Generation Count

/*	///////////// Trial/////////////
	sayi = assemblySubroutine(rule, 0,0, 1);
	printf("\nresult1:%d", sayi);
	
	sayi = assemblySubroutine(rule, 0,1, 0);
	printf("\nresult2:%d", sayi);
	
	sayi = assemblySubroutine(rule, 0,1, 1);
	printf("\nresult3:%d", sayi);
	
	sayi = assemblySubroutine(rule, 1,0, 0);
	printf("\nresult4:%d", sayi);
	
	sayi = assemblySubroutine(rule, 1,0, 1);
	printf("\nresult5:%d", sayi);
	
	sayi = assemblySubroutine(rule, 1,1, 0);
	printf("\nresult6:%d", sayi);
	
	sayi = assemblySubroutine(rule, 1,1,1);
	printf("\nresult7:%d", sayi);
*/
	
	for(i=0;i<row;i++){//Generation Count
		for(j=0; j<length; j++){
			if(j==0){
				 int sayi= assemblySubroutine(rule, 0, line[j], line[j+1]);	//left control
				tempLine[j]=sayi;
			}
			else if(j==length-1){
				int sayi= assemblySubroutine(rule, line[j-1], line[j], 0);  //right control
					tempLine[j] =sayi;
			}
			else{
				int sayi= assemblySubroutine(rule, line[j-1], line[j], line[j+1]);  //others
			tempLine[j] =sayi;
			}
		
		}
		////////Print all element
		for(j=0; j<length; j++){
				if(line[j]==1)
					printf("%c",(char)35);// For 1
				else
					printf("%c",(char)95);// for 0
			line[j] = tempLine[j];
		
		}
			printf("\n");// End of Line
	}
	
	
		
	
	return 0;

}
