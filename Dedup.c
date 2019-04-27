#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#define CHUNK_SIZE 6

void search( char* txt) 

{ 
	int N = strlen(txt); 
	char pat[CHUNK_SIZE+1]="ABC";
	char output[100]="";
	char redup[100]="";
	int chunk=CHUNK_SIZE;
	char hyp[2]="-";
	char append[3];
	char comma[2]=",";
	char str[36]="";
	
	    char* input = output; 
        char* output2;
	    char* ptr;
	    char* ptr2;
	
	int step;
	
	/* A loop to slide pat[] one by one */
	
for (int i = 0; i < N; i+=chunk) { 
     
   strncpy(pat,txt+i,chunk);
   //printf("Pattern : %s \n", pat);
   
   if(!strstr(output,pat))
   {
       
    
       for (int j = i; j<N;j+=chunk){
       
        if (!strstr(output,pat))
        {
            strncat(output,pat,chunk);
            //strcat(output,hyp);
            sprintf(append,"-%d",j/chunk);
            //printf("Append0:%s",append);
            strcat(output,append);
            //printf("Output0: %s \n", output);
    
        }
        else 
        {
            if (strncmp(txt+j,pat,chunk)==0){
            sprintf(append,"-%d",j/chunk);
            //printf("Found J:%d Append:%s\n",j,append);
            strcat(output,append);
            //printf("Output1: %s \n", output);
            }
        }
        
       }//end of second for
       
    sprintf(append,"%s",comma);
    strcat(output,append);
   }

   
}//end of first for
printf("%s\n",output);

//char *ptr = strtok(output, comma);

	while (ptr = strtok_r(input, ",", &input))
	{
		printf("PTR'%s'\n", ptr);
		
		ptr2 = strtok_r(ptr, "-", &ptr);
		sprintf(pat,"%s",ptr2);
		printf("PAT'%s'\n", pat);

		while (ptr2 != NULL)
	    {
		ptr2 = strtok_r(NULL, "-", &ptr);
    		if (ptr2 != NULL)
    	    {
    	        printf("PTR2'%d'\n", atoi(ptr2));
    	        //sprintf(str+(atoi(ptr2)*chunk),"%s",pat);
    	        strncpy(str+(atoi(ptr2)*chunk),pat,5);
    	    }
		}
		
	}
    printf("%s\n",str);

    
} //end of search

/* Driver program to test above function */
int main() 
{ 
    //set chunk size in #define section
	char txt[36] = "ABCDEPQRSTABCDELMNOPABCDELMNOPABCDE"; 
	search( txt);
	printf("\nEnd");
	return 0; 
}