// Contact Book - stores contacts in text file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILEC "contacts.txt"


void add(){
char name[100], phone[30], email[100];
printf("Name: "); scanf(" %99[^"]", name);
printf("Phone: "); scanf(" %29[^"]", phone);
printf("Email: "); scanf(" %99[^"]", email);
FILE *f = fopen(FILEC, "a"); if(!f){ perror("fopen"); return; }
fprintf(f, "%s|%s|%s\n", name, phone, email);
fclose(f);
printf("Saved.\n");
}


void list(){
char line[300]; FILE *f=fopen(FILEC,"r"); if(!f){ printf("No contacts.\n"); return; }
while(fgets(line, sizeof line, f)){
char *n = strtok(line, "|"), *p = strtok(NULL, "|"), *e = strtok(NULL, "|\n");
if(n) printf("Name: %s, Phone: %s, Email: %s\n", n, p? p: "", e? e: "");
}
fclose(f);
}


void search(){
char key[100]; printf("Search name: "); scanf(" %99[^"]", key);
char line[300]; FILE *f=fopen(FILEC,"r"); if(!f){ printf("No contacts.\n"); return; }
while(fgets(line,sizeof line,f)) if(strcasestr(line, key)) printf("%s", line);
fclose(f);
}


int main(){
int c; while(1){
printf("1.Add 2.List 3.Search 4.Exit\nChoice: "); if(scanf("%d", &c)!=1) break;
if(c==1) add(); else if(c==2) list(); else if(c==3) search(); else break;
}
}