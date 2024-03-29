/*
Name:		Sharjeel Sohail
Student#:	c3316130
Date:		May 26th, 2019
Program:	Assignment 02
Task:		Olympics data
*/

#include "stdafx.h"
#include <string.h>
#include <math.h>

#define MAX_COUNTRIES 196	 /* defines the maximum countries */
#define MAX_CHAR 16			 /* the maximum characters any country could hold */

void outputData(void); /* function displaying the output 01 */

typedef struct
{
	char p_name[MAX_CHAR];		/* participant name */
	int t_score = 0;				/* sum of all medals of the country */
	int score_gold = 0,				/* gold medals of the country */
		score_silver = 0,			/* silver medals of the country */
		score_bronze = 0;			/* bronze medals of the country */
} result_s;

int main()
{
	result_s participants[MAX_COUNTRIES]; /* creates an array of the structure*/
	result_s temp;
	result_s temp02; /* temp array of the structure for swapping */
	FILE *countries;			/* declare data file of countries */
	FILE *medals;				/* declare a data file of olympics data */
	errno_t err;				/* variables decalred for checking errors for file1*/
	errno_t err_2;				/* variable declared for checking errors for file2*/
	char sportPlayed[MAX_CHAR];  /* temp variables to save the medals data */
	char countryOne[MAX_CHAR];
	char countryTwo[MAX_CHAR];
	char countryThree[MAX_CHAR];
	int t_countries;			/* Total number of countries */
	int t_sets;					/* Total number of sets of data */
	int i = 0, n = 0;			/* Used in loop for file 1 and file 2 */
	int k, j;					/* Used for sorting algorithm alphabetically */
	int g, h;					/* Used for sorting algorithm in decreasing order acc to scores */
	int v, m;					/* Used for printing outputs */

	/* opening both files to read */
	err = fopen_s(&countries, "countries.dat", "r");
	err_2 = fopen_s(&medals, "medals.dat", "r");
	
	/* FILE ONE */
	/* if no errors found scan and process the data */
	if (err == 0) 
	{
		while (!feof(countries))
		{
			fscanf_s(countries, "%s", participants[i].p_name, 16);
			i++;
		}
	}
	/* if errors, display the message */
	else
	{
		printf_s("The file # 1 is non-existent"); /* error as required */
	}

	/* Saving total number of countries into t_countries variable */
	t_countries = i;

	/* FILE TWO */
	/* if no errors found scan and process the data */
	if (err_2 == 0)
	{
		while (!feof(medals))
		{
			fscanf_s(medals, "%s %s %s %s", sportPlayed, 16, countryOne, 16, countryTwo, 16, countryThree, 16);
			n++;
			
			/* Looking the data into both arrays and if found add the points in that particular country array */
			for (int q = 0; q < t_countries; q++)
			{

				if (strcmp(countryOne, participants[q].p_name) == 0)
				{
					participants[q].score_gold = participants[q].score_gold +1 *3;		/* Multiplying it here as Gold medal holds 3 points */
					participants[q].t_score = participants[q].t_score +1 *3;			/* adding them scores into their total points */
				}

				if (strcmp(countryTwo, participants[q].p_name) == 0)
				{
					participants[q].score_silver = participants[q].score_silver +1 *2;	/* Multiplying it here as silver medal holds 2 points */
					participants[q].t_score = participants[q].t_score +1 *2;			/* adding them scores into their total points */
				}

				if (strcmp(countryThree, participants[q].p_name) == 0)
				{
					participants[q].score_bronze = participants[q].score_bronze + 1;	/*Not  Multiplying here because bronze medal holds 1 point */
					participants[q].t_score = participants[q].t_score + 1;				/* adding them scores into their total points */
				} 
				
			}
		}
	}
	/* if errors, display the message */
	else
	{
		printf_s("The file # 2 is non-existent"); /* error as required */
	}

	
	/* Saving total number of data into t_sets variable */
	t_sets = n;
	
	/* Sort all the countries and their data in aplhabetical order */
	/* Sorting algorithm below */

	for (k = 0; k < t_countries; k++)
	{
		for (j = 0; j < t_countries; j++)
		{
			if (strcmp(participants[j].p_name, participants[j + 1].p_name) > 0)
			{
				temp = participants[j];
				participants[j] = participants[j + 1];
				participants[j + 1] = temp;
			}
		}
	}

	/* OUTPUT NUMBER ONE */
	/* Prints the final output for the olympics data */

	outputData(); /* Calling the function to prints out the output structure */
	for (v = 0; v < t_countries; v++) {
		printf_s("%-16s%3d%14d%14d%15d\n", participants[v].p_name, participants[v].t_score, participants[v].score_gold, participants[v].score_silver, participants[v].score_bronze);
	} 

	/* Sort all the countries in decreasing order according to their scores FOR OUTPUT NUMBER TWO*/
	/* Sorting algorithm below */

	for (g = 0; g < t_countries; g++)
	{
		for (h = 0; h < t_countries; h++)
		{
			if (participants[h].t_score < participants[h + 1].t_score)
			{
				temp02 = participants[h];
				participants[h] = participants[h + 1];
				participants[h + 1] = temp02;
			}
		}
	}

	/* OUTPUT NUMBER TWO */
	printf_s("\n\nBelow are the results of the countries in decreasing order according to their scores:\n\n");
	printf_s("----------------------------------------\n");
	printf_s("Countries Result  |   Performance Order\n");
	printf_s("----------------------------------------\n");
	for (m = 0; m < t_countries; m++) {
		printf_s("%-16s %7d\n", participants[m].p_name, participants[m].t_score);
	}

	/* closes all the file opened */
	_fcloseall();
	
	return 0;
}


/*
Function: This function prints the structure of the output data as required
input: No input given
output: No output, Just prints / display out the data
*/

void outputData(void)
{
	/* print the data to represent clearly the olympics result */

	printf_s("The Olympics is one of the main sporting events in the world\n");
	printf_s("Following is the result of the Olympics which took place last year:\n\n\n");
	printf_s("-------------------------------------------------------------------------\n");
	printf_s("				Olympic Games						\n");
	printf_s("-------------------------------------------------------------------------\n");
	printf_s("		Countries Results - Alphabetical Order		\n");
	printf_s("-------------------------------------------------------------------------\n");
	printf_s("Country   |    Points    | Gold Medals |Silver Medals|Bronze Medals\n");
	printf_s("-------------------------------------------------------------------------\n");
}
