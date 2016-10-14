#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int* assemblySubroutine(int rule, int *line, int *tempLine, int length);
 // we send  rule number, and line for each iteration and calculate the next line using our perfect algorithm
 // The returned array is hold in array called "tempLine" 
void printLine(int line[], int length);		//For the sake of using Functional Programming principles, we designed a printLine function


int main(int argc, char **argv)
{
	FILE *fp;
	int *line;			//Real array read from input file
	int *tempLine;		//The returned array from assembly function
	int *tLine;			//Swap array
	int length;
	int rule;			//Rule number
	
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
		line = (int *)malloc((length+2)*sizeof(int));
		tempLine =(int *)malloc((length+2)*sizeof(int));
		tLine =(int *)malloc((length+2)*sizeof(int));

		int i=1;
		while(!feof(fp)){
			fscanf(fp, "%d", &line[i]);
			i++;
		}
			
	}
    fclose(fp);
	
	int i;
	
	for(i=0; i<length+2; i++){
		tempLine[i]=0;
	}

	int row=(length)/2+1;// Generation Count

	for(i=0;i<row;i++){//Generation Count
		printLine(line, length+2);
		tLine = assemblySubroutine(rule, line, tempLine, length+2);	//Assembly function takes rule, line and the result will be obtained and length of the row as parameters
		int j;
		for (j = 0; j < length+2 ; j++)
		{
			line[j]=tLine[j];		//This is used for swapping
		}
		
	}
	
	return 0;
}

void printLine(int line[], int length){
	int i;
	for(i=1; i<length-1; i++){
		if(line[i]==1)
			printf("%c",(char)35);// For 1
		else
			printf("%c",(char)95);// for 0
	}
	printf("\n");
}

