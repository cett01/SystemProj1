/*System Programming PROJECT1
*150110125 Ekrem Cihad Cetin
*150110132 Kutay Hekimoglu
*150120061 Metahan Gultekin
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int assSbr(int *rule, int *);
int *directions(int **inc, int row, int column){
	int *dir = (int *)malloc(5 * sizeof(int));
	dir[0] = inc[row][column]; //center
	dir[1] = inc[row-1][column]; //north
	dir[2] = inc[row][column+1]; //east
	dir[3] = inc[row+1][column]; //south
	dir[4] = inc[row][column-1]; //west
	return dir;
}

int main(int argc, char **argv)
{
	FILE *input;
	FILE *rule;
	int *dirArr;
	int **resArr;
	int rsize,csize;
	int i,j;
	int **array;
	int *rarray;
	//Dosya islemleri
	input = fopen(/*argv[1]*/ "input2d.txt", "r+");
	rule = fopen(/*argv[2]*/ "rule2d.txt", "r+");
	if(!input || !rule){
		printf("There was a problem opening one of the files, please check file names");
	}
	else
	{
		fscanf(input, "%d %d", &rsize, &csize);          //dosyadan boyutlar alindi
		// Double array icin yer aldik
		resArr = (int **)malloc(rsize * sizeof(int*));    
		
		for(i = 0; i<rsize; i++)
		{
			resArr[i] = (int *)malloc(csize * sizeof(int));
		}
		////////////////////////////////////
		//Boyutlari birer arttirdik ki kontrol daha kolay olsun.
		rsize = rsize +2; 
		csize = csize +2;
		/////////////////////////
		//Boyutları arttirilan array icin yer alindi
		array = (int **)malloc(rsize * sizeof(int*));
		for(i = 0; i<rsize; i++)
		{
			array[i] = (int *)malloc(csize * sizeof(int));
		}
		///////////////////
		//tum elemanlari  0'a eşitledik
		for(i = 0; i < rsize; i++){
			for(j = 0; j < csize; j++){
				array[i][j]= 0;
			}
		}
		///////////////////////////
		
		
		//////////////////////////////
		//Input dosyasindan uzunluklari büyüttügümüz arrayi doldurduk
		for(i = 1; i<rsize-1; i++)
		{
			for(j = 1; j<csize-1; j++)
			{
				fscanf(input, "%d", &array[i][j]);
			}
		}
		//Rule dosyasindan rarray icini doldurduk
		rarray = (int *) malloc(32 * sizeof(int));
		i = 0;
		while(!feof(rule))
		{
			fscanf(rule, "%d", &rarray[i]);
			i++;
		}
	}
	fclose(input);
	fclose(rule);
	////////////////////////////////////////////////////
	//Dosya işlemleri bitti
	
	////////Direction Array.. CNESW
	dirArr = (int *)malloc(5 * sizeof(int));
	////////
	int count=0;
	while(1){//Kullanici programi kapatana kadar devam edecek
		printf("\nStep %d\n",count);
		for(i = 1; i<rsize-1; i++)
		{
			for(j = 1; j<csize-1; j++)
			{
				printf("%d ",array[i][j]);
				dirArr = directions(array, i, j);
				resArr[i-1][j-1] = assSbr(rarray,dirArr);
				
			}
			printf("\n");
		}	
		count++;
		printf("\nStep %d\n",count);
		//////////Yazdirma ve esitleme islemleri
		for(i = 0; i<rsize-2; i++)
		{
			for(j = 0; j<csize-2; j++)
			{
				printf("%d ", resArr[i][j]);
				array[i+1][j+1]=resArr[i][j];
			}
			printf("\n");
		}
		
		////////////////////
		getchar();
		system("clear");
	}
		
	printf("\n \n");
	return 0;
}
