#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

struct estab {
char csname[10];
char extsym[10];
int address;
int length;
}es[MAX];

void main()
{
    char input[10],name[10],symbol[10];
    int progaddr,csaddr,add,count=0,len;
    FILE *fp1,*fp2;

    fp1=fopen("linkinput.txt","r");
    fp2=fopen("loadmap.txt","w");
    printf("Enter the location where the program is to be loaded :");
    scanf("%d",&progaddr);
    csaddr=progaddr;

    fprintf(fp2,"CS_NAME\tEXT_SYM_NAME\tADDRESS\tLENGTH\n");
    fprintf(fp2,"---------------------------------------\n");

    fscanf(fp1,"%s",input);
    while(strcmp(input,"END")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%s",name);
            strcpy(es[count].csname,name);
            strcpy(es[count].extsym,"**");
            fscanf(fp1,"%d",&add);
            es[count].address=csaddr+add;
            fscanf(fp1,"%d",&len);
            es[count].length=len;
            fprintf(fp2,"%s\t%s\t%d\t%d\n",es[count].csname,es[count].extsym,es[count].address,es[count].length);
            count++;
        }

        else if(strcmp(input,"D")==0)
        {
            fscanf(fp1,"%s",input);
            //printf("%s",input);
            while(strcmp(input,"R")!=0)
            {
                strcpy(es[count].csname,"**");
                strcpy(es[count].extsym,input);
                fscanf(fp1,"%d",&add);
                es[count].address=add+csaddr;
                es[count].length=0;
                fprintf(fp2,"%s\t%s\t%d\t%d\n",es[count].csname,es[count].extsym,es[count].address,es[count].length);
                count++;
                fscanf(fp1,"%s",input);

            }
            csaddr=csaddr+len;
        }
        else if(strcmp(input,"T")==0)
        {
            while(strcmp(input,"E")!=0)
                fscanf(fp1,"%s",input);
        }
        fscanf(fp1,"%s",input);
    }
    fprintf(fp2,"-----------------------------------------\n");
    fclose(fp1);
    fclose(fp2);
    printf("Finished\n");



}
