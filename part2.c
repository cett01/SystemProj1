#include <stdio.h>
#include <math.h>

int row=5,column=5;
int matrix[5][5]={   {0,1,1,0,1},
					 {1,0,0,1,1},
					 {1,0,1,0,0},
					 {0,1,1,1,1},
					 {1,0,0,1,0}
						};
int tempmat[5][5]={};
int rule[32]={0,1,1,0,1,0,0,1,
		      1,0,0,1,0,1,1,0,
		      1,0,0,1,0,1,1,0,
		      0,1,1,0,1,0,0,1};				

int calc_state(int coming[5])
{	

	int total=0;
	int len=5;
		int i;
		for(i=0;i<len;i++)
		{
			int  us=len-i-1;
			int a=(int)pow(2,us);
			total+=coming[i]*a;
		}
		
		return rule[total];
}

void calc_all()
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			
			int temp[5];//C,N,E,S,W
						//M,K,D,G,B                                 
			
			if(j==0 && i==0)// SOL UST
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=0;//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=0;//W   sol
			}
			else if(j==column-1 && i==0)//en sag ust
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=0;//N   Ust				    	 
				temp[2]=0;//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
			else if(i==row-1 &&j==0 )//en sol alt
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=0;//S   alt                           
				temp[4]=0;//W   sol
			}
			else if(i==row-1 && j==column-1)//en sag alt
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=0;//E   Sað					   
				temp[3]=0;//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
			else if(i==row-1 )//alt
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=0;//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
			else if(j==column-1)//sag
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=0;//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
			else if(i==0)// ust
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=0;//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
			else if( j==0)//sol
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=0;//W   sol
			}
			else // orta hucreler
			{
				temp[0]=matrix[i][j];//C   Merkez	                    
				temp[1]=matrix[i-1][j];//N   Ust				    	 
				temp[2]=matrix[i][j+1];//E   Sað					   
				temp[3]=matrix[i+1][j];//S   alt                           
				temp[4]=matrix[i][j-1];//W   sol
			}
	
			
					
			tempmat[i][j]=calc_state(temp);
		
		/*	temp[0]=matrix[i][j];//C   Merkez	                       N
			temp[1]=matrix[i-1][j];//N   Ust				    	   |
			temp[2]=matrix[i][j+1];//E   Sað					  W <--C--> E    
			temp[3]=matrix[i+1][j];//S   alt                           |
			temp[4]=matrix[i][j-1];//W   sol						   S 
			* */
		}
	
	
	}
}

void printall()
{
	int i,j;
	for (i = 0; i <row ; i++)
	{
		for (j = 0; j <column ; j++)
		{
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	
}

void copy_to_original()
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <column; j++)
		{
			matrix[i][j]=tempmat[i][j];
		}
		
	}
	
}

int main(void)
{
	int step=0;
	printall();
	while (step++>-1)
	{
		getchar();
		printf("\nStep:%d\n",step);
		printf("\n");
		calc_all();
		copy_to_original();
		printall();
	}
	
	
			
	
    return 0;
}
