// C program for Naive Pattern Searching algorithm 
#include <stdio.h> 
#include <string.h> 

void search(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int ret= 0;

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) { 
        ret = strncmp(txt+i,pat,strlen(pat));
        if (ret == 0) 
        printf("Pattern found at index %d \n", i); 
	} 
} 

/* Driver program to test above function */
int main() 
{ 
	char txt[] = "AABAACAADAABAAABAA"; 
	char pat[] = "AABA"; 
	search(pat, txt); 
	return 0; 
}