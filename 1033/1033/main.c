//
//  main.c
//  1033
//
//  Created by ERICx86 on 13-10-28.
//  Copyright (c) 2013年 ERICx86. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int i,n,j,k;
    char s[100050][20];
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char t[20];
        scanf("%s",t);
        for(j=0;j<strlen(t);j++)
        {
            if(t[j]=='A'||t[j]=='B'||t[j]=='C') t[j]='2';
            if(t[j]=='D'||t[j]=='E'||t[j]=='F') t[j]='3';
            
            if(t[j]=='G'||t[j]=='H'||t[j]=='I') t[j]='4';
            if(t[j]=='J'||t[j]=='K'||t[j]=='L') t[j]='5';
            if(t[j]=='M'||t[j]=='N'||t[j]=='O') t[j]='6';
            
            if(t[j]=='P'||t[j]=='R'||t[j]=='S') t[j]='7';
            if(t[j]=='T'||t[j]=='U'||t[j]=='V') t[j]='8';
            if(t[j]=='W'||t[j]=='X'||t[j]=='Y') t[j]='9';
        }
        for(j=0,k=0;j<strlen(t);j++)
            if(t[j]!='-')
                s[i][k]=t[j],k++;
    }
    
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
        {
            if(strcmp(s[j], s[j+1])>0)
            {
                char swap[20];
                strcpy(swap, s[j]);
                strcpy(s[j], s[j+1]);
                strcpy(s[j+1], swap);
            }
        }
    for(i=0;i<n-1;i++)
    {
        if(strcmp(s[i], s[i+1])==0)
        {
            int sum=1,flag=0;
            for(j=i;j<n-1;j++)
                if(strcmp(s[j], s[j+1])==0)
                    sum++;
                else break;
            flag=j+1;
            printf("%c%c%c-",s[i][0],s[i][1],s[i][2]);
            for(j=3;j<7;j++)
                printf("%c",s[i][j]);
            printf(" %d\n",sum);
            i=flag;
        }
    }
    
    return 0;
}

