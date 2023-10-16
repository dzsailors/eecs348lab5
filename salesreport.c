#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char *months[] = {"January", "February", "March", "April", "May", "June","July","August","September","October","November","December"};
	float sales[12];
	FILE* sales_report = fopen("salesreport.txt", "r");
	if (!sales_report)
    {
		printf("File Error");
		exit(-1);
	}
	for(int i = 0; i < 12; i++)
    {
		fscanf(sales_report, "%f", &sales[i]);
	}
	fclose(sales_report); 
	printf("Monthly sales report for 2022:\nMonth      Sales\n");
	for(int i = 0; i < 12; i++)
    {
		printf("%-10s $%.2f\n", months[i],sales[i]);
	}
	float sum = 0; 
	float avg;
	for (int j = 0; j < 12; j++)
    {
		sum = sum + sales[j];
	}
	avg = sum / 12; 
	float max = sales[0];
	for (int k = 1; k < 12; k++)
    {
		if (sales[k] > max)
        {
			max = sales[k];
		}
	}
	float min = sales[0]; 
	for (int k = 1; k < 12; k++)
    {
		if (sales[k] < min)
        {
			min = sales[k];
		}
	}
	int index_max = -1;
	for (int h = 0; h < 12; h++)
    {
		if (sales[h] == max)
        {
			index_max = h;
			break;
		}
	}
	int index_min = -1;
	for (int h = 0; h < 12; h++)
    {
		if (sales[h] == min)
        {
			index_min = h;
			break;
		}
	}
	printf("\nSales summary:\n");
	printf("Minimum Sales: $%.2f (%s)\n", min, months[index_min]);
	printf("Maximum Sales: $%.2f (%s)\n", max, months[index_max]);
	printf("Average sales: $%.2f\n", avg);

	float sum1 = 0;
	for (int a = 0; a < 6; a++)
    { 
		sum1 = sum1 + sales[a];
	}
	float avg1 = sum1 / 6;
	printf("\nSix-Month Moving Average Report:\n");
	printf("%-10s - %10s $%.2f", months[0], months[5], avg1);
	float sum2 = 0;
	for (int b = 1; b < 7; b++)
    {
		sum2 = sum2 + sales[b];
	}
	float avg2 = sum2 / 6;
	printf("\n%-10s - %10s $%.2f", months[1], months[6], avg2);
	float sum3 = 0;
	for (int c = 2; c < 8; c++)
    {
		sum3 = sum3 + sales[c];
	}
	float avg3 = sum3 / 6;
	printf("\n%-10s - %10s $%.2f", months[2], months[7], avg3);
	float sum4 = 0;
	for (int d = 3; d < 9; d++)
    {
		sum4 = sum4 + sales[d];
	}
	float avg4 = sum4 / 6;
	printf("\n%-10s - %10s $%.2f", months[3], months[8], avg4);
	float sum5 = 0;
	for (int e = 4; e < 10; e++)
    {
		sum5 = sum5 + sales[e];
	}
	float avg5 = sum5 / 6;
	printf("\n%-10s - %10s $%.2f", months[4], months[9], avg5);
	float sum6 = 0;
	for (int f = 5; f < 11; f++)
    {
		sum6 = sum6 + sales[f];
	}
	float avg6 = sum6 / 6;
	printf("\n%-10s - %10s $%.2f", months[5], months[10], avg6);
	float sum7 = 0;
	for (int g = 6; g < 12; g++)
    {
		sum7 = sum7 + sales[g];
	}
	float avg7 = sum7 / 6;
	printf("\n%-10s - %10s $%.2f\n", months[6], months[11], avg7);
printf("\nSales Report (Highest to Lowest)\nMonth      Sales\n");
float temp = 0;
 for (int i = 0; i < 12; i++) 
 {
        for (int j = i+1; j < 12; j++) 
        {
           if(sales[i] < sales[j]) 
           {
				const char* temp2 = months[i];
				months[i] = months[j];
				months[j] = temp2;
				temp = sales[i];
				sales[i] = sales[j];
				sales[j] = temp;
           }
        }
    }
    for (int i = 0; i < 12; i++) 
    {
        printf("%-10s $%0.2f\n ", months[i],sales[i]);
    }
return 0;
}