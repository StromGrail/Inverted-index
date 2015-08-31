 #include <stdio.h>
 #include <dirent.h>
 #include <string.h>
 #include <iostream>
#include <bits/stdc++.h>
 using namespace std;

    int main (int c, char *v[]) {
        int len;
        struct dirent *pDirent;
        DIR *pDir;
        string s[100];
        int i=0;
        if (c < 2) {
            printf ("Usage: testprog <dirname>\n");
            return 1;
        }
        pDir = opendir (v[1]);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", v[1]);
            return 1;
        }

        FILE *fp1,*fp2;
        //fp1= fopen("/home/mohit/Desktop/irdm/source/indexing.txt","w+");
      //  strcat(pDir,pDirent->d_name);
       int j=0;
        while ((pDirent = readdir(pDir)) != NULL) {
            s[i++]=pDirent->d_name;
            //printf ("[%s]\n", pDirent->d_name);
        
        char *path=pDirent->d_name;
        j++;
        if(j!=2 ){
          fp2=fopen(path,"r");
          char ch; 
          while( ( ch = fgetc(fp2) ) != EOF && ch!='#'  )
                cout<<ch<<" ";
            fclose(fp2);
        cout<<endl;
        }

    }
       
        while ((pDirent = readdir(pDir)) != NULL) {
            s[i++]=pDirent->d_name;
            //printf ("[%s]\n", pDirent->d_name);
        }
        closedir (pDir);

        for(int j=0;j<i;++j)
            cout<<s[j]<<" ";

        
        return 0;
    }