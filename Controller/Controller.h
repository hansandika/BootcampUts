#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../Model/Models.h"

Node *createNewNode(int tanggal, char *bulan, int tahun, char *name, long long sum)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    strcpy(newNode->bulan,bulan);
    newNode->tanggal = tanggal;
    newNode->tahun = tahun;
    newNode->sum = sum;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void showCured(int pasien,int temp);
void pushMid(int tanggal, char *bulan, int tahun, char *name, long long sum);

void scan()
{
    int a,b;
    scanf("%d %d",&a,&b); getchar();
    for(int i = 0;i<a;i++)
    {
        int tanggal,tahun;
        long long sum = 0;
        char bulan[255],name[255];
        scanf("%d %s %d - %[^\n]",&tanggal,bulan,&tahun,name); getchar();
        sum += tanggal;
        if(strcmp(bulan,"january") == 0)  sum += 30;
        else if(strcmp(bulan,"february") == 0) sum += 60;
        else if(strcmp(bulan,"march") == 0) sum += 60;
        else if(strcmp(bulan,"april") == 0) sum += 90;
        else if(strcmp(bulan,"june") == 0) sum += 120;
        else if(strcmp(bulan,"july") == 0) sum += 150;
        else if(strcmp(bulan,"august") == 0) sum += 90;
        else if(strcmp(bulan,"september") == 0) sum += 120;
        else if(strcmp(bulan,"october") == 0) sum += 150;
        else if(strcmp(bulan,"november") == 0) sum += 180;
        else if(strcmp(bulan,"decemver") == 0) sum += 210;
        sum += tahun * 360;
        pushMid(tanggal,bulan,tahun,name,sum);
    }
    showCured(a-b,a);
}

void pushMid(int tanggal, char *bulan, int tahun, char *name, long long sum)
{
    Node *newNode = createNewNode(tanggal,bulan,tahun,name,sum);
    if(!head)
    {
        head = tail = newNode;
    }
    else if(sum > head->sum)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }    
    else if(sum < tail->sum)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else{
        Node *curr = head;
        while(curr && curr->next->sum > sum)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
}

void showCured(int pasien,int temp)
{    
    Node *curr = tail;
    printf("Need %d more cure\n",pasien);
    for(int i = 0;i<temp,curr;curr = curr->prev,i++)
    {
        printf("%d %s %d - %s\n",curr->tanggal,curr->bulan,curr->tahun,curr->name);
    }
}
