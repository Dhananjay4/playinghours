#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<math.h>

pthread_t t1,t2,t3,t4,t5;
pthread_mutex_t l1;
char usrnm[5];
int x,pcnt=0,teach=0,stud=0,staff=0,h;
int t=1600;
void *tch()
{   
int a=5;
sleep(a);
	pthread_mutex_lock(&l1);
	teach++;
	printf("\nTEACHER %d IS PLAYING\n",teach);
	pcnt++;
	pthread_mutex_unlock(&l1);
	pthread_exit(NULL);
}
void *stf()
{
	pthread_mutex_lock(&l1);
	staff++;
	pcnt++;
	printf("\nSTAFF %d is PLAYING\n",staff);
	pthread_mutex_unlock(&l1);
	t=t+200;
	pthread_exit(NULL);
}
void *stu()
{
	pthread_mutex_lock(&l1);
	pcnt++;
	stud++;
	printf("\nSTUDENT %d is PLAYING\n",stud);
	pthread_mutex_unlock(&l1);
	pthread_exit(NULL);
}
void *stgm()
{
	printf("\nGame start\n");
}
void *lgin()
{
	A:
printf("\n1. For Staff\n2. Fosr Student\n3. For Teacher\n4.For Exit\nEnter Your choice :: ");
scanf("%d",&x);

int pswd;
switch(x){
	case 1:	
		printf("\nComputer Staff Login \n");
		printf("Enter username :: ");
		scanf("%s",&usrnm);
		printf("\nStf logged in\n");
		pthread_create(&t3,NULL,stf,NULL);
		pthread_join(t3,NULL);
		
		break;
	case 2:
	{   
	int pswd;
		printf("\nStudent  Login \n");
		printf("Enter username :: ");
		scanf("%s",&usrnm);
		printf("\nStu logged in\n");pthread_create(&t4,NULL,stu,NULL);
		pthread_join(t4,NULL);
		}
		break;
	case 3://if((tm>=17%24)&&(tm<=8%24))
	{
	    int pswd;
		printf("\nComputer Staff Login \n");
		printf("Enter username :: ");
		scanf("%s",&usrnm);
		printf("\nTec logged in\n");
		pthread_create(&t5,NULL,tch,NULL);
		pthread_join(t5,NULL);}
		break;
	case 4:
	       pthread_exit(NULL);
	default: printf("\nWrong Entry.\nTry again\n");
	         goto A;
	         }
	pthread_exit(NULL);}
void main()
{
	printf("\nEnter number of login :: \n");
	int i;
	scanf("%d",&h);
	printf("write now time is 1600 hrs")
	for(i=0;i<h;i++)
	{
		pthread_create(&t1,NULL,lgin,NULL);
		pthread_join(t1,NULL);
		printf("TOTAL NO. OF USERS %d",pcnt);
	}
	}
