#include<stdio.h>
void STACK1(int pnt,int tm);
void STACK2(int pnt,int tm);
void AddQue(int pnt);
int n,at[10],bt[10],i,tq,j;
int ct[50]={0},tat[10],rt[10];
int rqi[50]={0},c=0,st,tm=0,noe=0,pnt=0,btm[50]={0},tt,wt;
float att,awt;
int flag=0;
int main()
{
	
	printf("*********************************Round Robin Algorithm********************************************\n");
	printf("\nEnter the no. of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Process No. [P%d]\n",i+1);
		printf("Enter the Arrival Time:-\n");
		scanf("%d",&at[i]);
		printf("Enter the Burst time:-\n");
		scanf("%d",&bt[i]);
		btm[i]=bt[i];
	}
	printf("Enter the Time Quantum\n");
	scanf("%d",&tq);
	printf("GANT CHART\n");
	printf("%d",at[0]);
	do{
		if(flag==0){
			st=at[0];
			if(btm[0]<=tq){
				tm=st+btm[0];
				btm[0]=0;
				STACK1(pnt,tm);
			}
			else{
				btm[0]=btm[0]-tq;
				tm=st+tq;
				STACK1(pnt,tm);
				AddQue(pnt);
			}
		}
		else{
			pnt=rqi[0]-1;
			st=tm;
			for(i=0;i<noe && noe!=1;i++){
				rqi[i]=rqi[i+1];
			}
			noe--;
			if(btm[pnt]<=tq){
				tm=st+btm[pnt];
				btm[pnt]=0;
				STACK2(pnt,tm);
			}
			else{
				btm[pnt]=btm[pnt]-tq;
				tm=st+tq;
				STACK2(pnt,tm);
				AddQue(pnt);
			}
		}
		if(btm[pnt]==0){
			ct[pnt]=tm;
		}
		flag++;
		printf("]-P%d -[ %d",pnt+1,tm);
	}
	while(noe!=0);
	for(i=0;i<n;i++){
		rt[i]=at[i];
		
	}	
	printf("\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\t RT\n ");
	for(i=0;i<n;i++){
		tt=ct[i]-at[i];
        wt=tt-bt[i];
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t %d\n ",i+1,at[i],bt[i],ct[i],tt,wt,rt[i]);
        awt=awt+wt;
        att=att+tt;   
	}
	printf("\nAVERAGE TT: %f",att/n);
	printf("\nAVERAGE WT: %f",awt/n);
	
}
void STACK1(int pnt,int tm){
	for(i=pnt+1;i<n+1;i++){
		if(at[i]<=tm){
			rqi[noe]=i+1;
			noe++;
		}
	}
}
void STACK2(int pnt,int tm){
	for(i=pnt+1;i<n+1;i++){
		int f1=0;
		for(j=0;j<noe;j++){
			if(rqi[j]==i+1){
				f1++;
			}
		}
		if(at[i]<=tm && f1==0 && btm[i]!=0){
			rqi[noe]=i+1;
            noe++;
	}
}
}
void AddQue(int pnt){
	rqi[noe]=pnt+1;
	noe++;
}
