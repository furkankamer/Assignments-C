#include<stdio.h>
#include<stdlib.h>

int main()
{
	int park[50][50],size,car_number,car_location_x,car_location_y,distance=0,distance3=0;
	int best_car_location_x=0;
	int best_car_location_y=0;
	printf("Size: ");
	scanf("%d",&size);
	if(size > 50)
	{
		printf("Size must be between 50 and 1\n");
		printf("Size: ");
		scanf("%d",&size);
	}
	int l;
	for(l=0;l<size;l++)
	{	int t;
		for(t=0;t<size;t++){
		
		park[l][t]=0;
	}
	}
	printf("Cars: ");
	scanf("%d",&car_number);
	if(car_number>=size*size)
	{
		printf("Best Slot Found In: 0 0\n");
		return EXIT_SUCCESS;
		}
	int q;
	for(q=0;q<car_number;q++)
	{
		printf("Locations: ");
		scanf("%d %d",&car_location_x,&car_location_y);
		park[car_location_x-1][car_location_y-1]=1;
	}
	
	int c;
	for(c=0;c<size;c++)
	{	int t;
		for(t=0;t<size;t++)
		{
			if(park[c][t]== 0)
			{
			int	distance2 = 500;
				int e;
				for(e=0;e<size;e++)
				{	int f;
					for(f=0;f<size;f++)
					{
                        
						if(park[e][f]==1)
						{
						
							if(c>e && t>f)
							{
								distance = (c-e) + (t-f);
							}
							
							else if(c>e && t<=f)
							{
								distance = (c-e) + (f-t);
							}
							else if(c<=e && t>f)
							{
								distance = (e-c) + (t-f);
							}
							else if(c<=e && t<=f)
							{
								distance = (e-c) + (f-t);
							}							
							if(distance2>distance )
							{                              
								distance2=distance;	
							}
				   		
						}
					}
				}
				if(distance2>distance3)
				{
					distance3=distance2;
					best_car_location_x = c;
					best_car_location_y = t; 			
				}
				
			}					
               
		}
			
	}
		
	printf("Best Slot Found In: %d %d\n",best_car_location_x+1,best_car_location_y+1);		
	
	return 0;
		
}
