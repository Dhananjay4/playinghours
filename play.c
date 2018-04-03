#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

struct tm *t6;time_t t;
pthread_t t1,t2,t3,t4,t5;
pthread_mutex_t l1,l2;
int x,pcnt=0,teach=0,stud=0,staff=0,h;

void *tch()
{   
	pthread_mutex_lock(&l1);
	teach++;
	printf("\nTEACHER %d IS PLAYING\n",teach);
	pcnt++;

	pthread_mutex_unlock(&l1);
	sleep(1);
    if(t6->tm_hour>8&&t6->tm_hour<17)
	{
		pthread_mutex_lock(&l1);
		teach--;
		pcnt--;
		printf("\nyou have been log out\t%d\n",pcnt);
	pthread_mutex_unlock(&l1);
	}
	pthread_exit(NULL);
}
void *stf()
{
	pthread_mutex_lock(&l2);
	staff++;
	pcnt++;
	printf("\nSTAFF %d is PLAYING\n",staff);
	pthread_mutex_unlock(&l2);
		pthread_exit(NULL);
}
void *stu()
{
	pthread_mutex_lock(&l1);
	pcnt++;
	stud++;
	printf("\nSTUDENT %d is PLAYING\n",stud);
	pthread_mutex_unlock(&l1);
	sleep(1);
    if(t6->tm_hour>6&&t6->tm_hour<22)
	{
		pthread_mutex_lock(&l2);
		teach--;
		pcnt--;
		printf("\nyou have been log out\t%d\n",pcnt);
	    pthread_mutex_unlock(&l2);
	}
	pthread_exit(NULL);
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
		printf("\nStf logged in\n");
		pthread_create(&t3,NULL,stf,NULL);
		pthread_join(t3,NULL);
		
		break;
	case 2:
	   t6=localtime(&t);
	   printf("\n%s\n",asctime(t6));
	if(t6->tm_hour>=22||t6->tm_hour<=6)
	    {
		printf("\nStudent  Login \n");
		printf("\nStu logged in\n");pthread_create(&t4,NULL,stu,NULL);
		pthread_join(t4,NULL);
		}
		else 
		{
			printf("\nAccess declined due to time constraint\n");
		}		
		break;
	case 3:
	    t6=localtime(&t);
	    printf("\n%s\n",asctime(t6));
	    if(t6->tm_hour>=17||t6->tm_hour<=8)
	    {
		printf("\nComputer Teacher Login \n");
		printf("\nTec logged in\n");
		pthread_create(&t5,NULL,tch,NULL);
		pthread_join(t5,NULL);}
		else 
		{
			printf("\nAccess declined due to time constraint\n");
		}
		break;
	case 4:
	       pthread_exit(NULL);
	default: printf("\nWrong Entry.\nTry again\n");
	         goto A;
	         }
	pthread_exit(NULL);}
void main()
{time(&t);
	printf("\nEnter number of login :: \n");
	int i;
	scanf("%d",&h);
	for(i=0;i<h;i++)
	{
		pthread_create(&t1,NULL,lgin,NULL);
		pthread_join(t1,NULL);
		printf("TOTAL NO. OF USERS %d",pcnt);
	}
	}
