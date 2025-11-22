#include <stdio.h>
int arr[200],n=0;
int create(){
	int i;
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	return 0;
}
int display(){
	int i;
	if (n==0) printf("\nArray empty");
	if(n>0){
		printf("\nThe elements are:\n");
		for(i=0;i<n;i++){
			printf("%d\t",arr[i]);
		}
		
	}
	return 0;
}
int insert(){
	int pos=0,i;
	printf("\nEnter position to insert start from 0:");
	scanf("%d",&pos);
	for(i=n;i>=pos;i--){
		arr[i]=arr[i-1];
	}
	n++;
	printf("\nEnter element to insert:");
	scanf("%d",&arr[pos]);
	return 0;
}
int deletion(){
	int pos=0,i;
	printf("\nEnter position to delete start from 0:");
	scanf("%d",&pos);
	for(i=pos;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	n--;
	return 0;
}
int search(){
	int i,b=0,num;
	printf("\nEnter element to search:");
	scanf("%d",&num);
	for(i=0;i<n;i++){
		if(arr[i]==num){
			b=1;break;
		}
	}
	if(b==1) printf("\nFound at index %d",i);
	else printf("Not found");
	return 0;
}
int main(){
	printf("--MENU--\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Linear Search\n6.Exit");
	int a;
	do{
		printf("\nEnter option number:");
		scanf("%d",&a);
		switch(a){
			case 1:create();break;
			case 2:display();break;
			case 3:insert();break;
			case 4:deletion();break;
			case 5:search();break;
			case 6:printf("\nExiting");break;
			default:printf("\nInvalid");break;
		}	
	}while(a!=6);
}
