#include <stdio.h> 
#include <string.h> 

int check(char* txt) 
{ 
	int M = strlen(txt); 
	int ret= 0;

	for (int i = 0; i <= M/2; i++) { 
        ret = strncmp(txt+i,txt+M-1-i,1);
        if (ret == 0) 
        continue;
        else
        return 1;
        
	} 
	return 0;
} 

/* Driver program to test above function */
int main() 
{ 
	char txt[] = "ABCVBA"; 
	
	if (!check(txt))
	printf("Palindrome");
	else
	printf("Not a palindrome");
	
	return 0; 
}