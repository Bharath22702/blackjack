#include<stdio.h>
#include<time.h>//for changing seeds of rand function
#include<stdlib.h>
int comp(int a, int b);
int RESULT( int dsum, int psum);//returned value passes to cred() function
int CHOICE();
int cred(int o,int credit, int bet);//(RESULT,credit,bet)
	
int main()
{ 
	printf("\t\t\t\t\t\tWELCOME TO BLACKJACK\n");
    char name[20];
    int credit, bet,H;
    int dsum,psum,p,q,r,s,t,z,d[22],y[22],i,w;
    printf("\nENTER PLAYER_NAME:");
    scanf("%s",name);
    printf("ENTER CREDIT AMOUNT: ");
    scanf("%d",&credit);
    printf("\nYour Credit = %d ",credit);
    label2:    	printf("\nBET:");
    	scanf("%d",&bet);

    	printf("\nDEALER\n");
    	srand(time(NULL));
    	for (i=1;i<=22;i++)//generating random numbers
    	{
    		d[i] = rand()%11 + 1;
    		if (i == 21)
    			break;
   		}   
    	printf("%d\tXX\n\n",d[1]);

    	printf("PLAYER\n");
    	for (i=1;i<=21;i++)
  		{	
  			y[i] = rand()%11 + 1;//lower limit is 1 and upper limit is 11
  			if (i == 21)
  				break;
  		}
    
   		printf("%d\t%d\n\n\n",y[1],y[2]);
   		dsum = d[1]+d[2];
   		psum = y[1]+y[2];
   		if (dsum>21 || psum > 21)//check for sum >21
  			{goto label1;}
   		p = CHOICE();
   		if (!p)// for stand
  		{
  			printf("\nDEALER\n");
   			printf("%d\t%d\n\n",d[1],d[2]);
   			printf("PLAYER\n");
   			printf("%d\t%d\n\n",y[1],y[2]);
   			comp(dsum,psum);
    		q =	RESULT(dsum,psum);
   			credit = cred(q,credit,bet);
    		goto label3;
   		}
   		else//for hit
   		{
   			printf("\nDEALER\n");
   	    	printf("\n%d\t%d\tXX\n\n",d[1],d[2]);
   	    	printf("PLAYER\n");
     		printf("%d\t%d\t%d\n\n",y[1],y[2],y[3]);
     		psum = psum + y[3];
     		dsum = dsum + d[3];
        	if(psum>21||dsum>21)
        	{   printf("\nDEALER\n");
        		printf("\n%d\t%d\t%d\n\n",d[1],d[2],d[3]);
   	    		printf("PLAYER\n");
     			printf("%d\t%d\t%d\n\n",y[1],y[2],y[3]);
        		t=RESULT(dsum,psum);
        		credit = cred(t,credit,bet);
        		goto label3;}
        		else{
     		r = CHOICE();
     		if(!r)//for stand
     		{
     		
     			printf("\nDEALER\n");
     			printf("%d\t%d\t%d\n\n",d[1],d[2],d[3]);
     			printf("PLAYER\n");
     			printf("%d\t%d\t%d\n\n",y[1],y[2],y[3]);
     			comp(dsum,psum);
     			label1:	s =RESULT(dsum,psum);
     			credit = cred(s,credit,bet);	
     				goto label3;
     			}
     		else if(r)//for hit
     		{
     			printf("\nDEALER\n");
     			printf("%d\t%d\t%d\tXX",d[1],d[2],d[3]);//draws another card
     			printf("\nPLAYER\n");
     			printf("%d\t%d\t%d\t%d\n",y[1],y[2],y[3],y[4]);
     			dsum= dsum+d[4];
     			psum = psum+y[4];

     			if(dsum>21||psum>21)//checking sum>21
     				{ 	
     					printf("\nDEALER\n");
     					printf("%d\t%d\t%d\t%d",d[1],d[2],d[3],d[4]);
     		    		printf("\nPLAYER\n");
     					printf("%d\t%d\t%d\t%d\n",y[1],y[2],y[3],y[4]);
     			
     					if(dsum>21&&psum<=21){
     					 printf("\nYou won!!\n");
     					credit= credit + bet;
     				    printf("Your credit: %d",credit);
     				 }
     					else if(psum>21&&dsum<=21){
     						printf("\nYou Lost! T_T\n");
     						credit = credit-bet;
     						printf("Your Credit: %d",credit);}
 
     				else if((dsum==psum)||(dsum>21&&psum>21)){
     					printf("\nTie!!\n");
     					printf("YOUR CREDITS: %d",credit);
     					}
     			
     					goto label3;
     				
     				}
     			else{
     				w = CHOICE();
     				if(!w)//for stand
     				{	printf("\nDEALER\n");
     					printf("%d\t%d\t%d\t%d\n",d[1],d[2],d[3],d[4]);
     		    		printf("\nPLAYER\n");
     					printf("%d\t%d\t%d\t%d\n",y[1],y[2],y[3],y[4]);
     					r = RESULT(dsum,psum);
     					credit = cred(r,credit,bet);}
     				else//draw another card
     				{
     					printf("\nDEALER\n");
     					printf("%d\t%d\t%d\t%d\t%d\n",d[1],d[2],d[3],d[4],d[5]);
     					printf("\nPLAYER\n");
     					printf("%d\t%d\t%d\t%d\t%d\n",y[1],y[2],y[3],y[4],y[5]);
     					dsum= dsum+d[5];
     					psum = psum+y[5];
     					comp(dsum,psum);
     					t = RESULT(dsum,psum);
     					credit = cred(t,credit,bet);
     				}	
     				}
     				
     	}
     	else
     	{
     	   	printf("\nINVALID INPUT!\n");
     	}			
     }
     	label3: printf("\nPLAY AGAIN(1)\tQUIT(0)");
     	scanf("%d",&z);
     if(z==1)
     {
     goto label2;
     }
     else
     {
     	printf("\nThanks for playing"); //game ends completely here
    
     }
     }
   return 0;
}

int CHOICE()//choice between hit & stand is returned to result
{   int x;
    printf("\nSTAND(0)\tHIT(1)");
    scanf("%d",&x);
    if(x==0){
    return 0;}
    else if (x==1)
    {return 1;}
    else{
    printf("INVALID");
    	return 2;}
}
int comp(int a, int b)//compares dsum and psum
{ int credit,bet;
	if(a<=21 && b<=21)
	{   if(a>b)
		    return a;
		else if(b>a) { 
			return b;}
			else if(a==b){
			return 0;}
			}
	else if(a>21&&b<=21)
		{return b;}
		
	else if(b>21&&a<=21)
		{return a;}
	else if(a>21&&b>21) 
		{return 0;}
				}				
int RESULT(int dsum,int psum) /*result of the match up and returns values to credit function*/
	{int H,credit,bet;
		H = comp(dsum,psum);
		if (H==dsum&&(psum>21&&dsum<=21))
			{
				printf("\nYOU LOST! T_T\n");
				return 1;
				}
		else if(H==psum&&(dsum>21&&psum<=21)){
				printf("\nYou Won!!!\n");
			return 0;}
		else if(H==0||(dsum>21&&psum>21)){
				printf("\nTie!!\n");
				return 2;}
		else if(H==dsum)
			{   printf("\nYou Lost!!\n");
				return 1;}
		else if(H==psum)
			{   printf("\nYou Won!!!\n");
				return 0;}
	
			}
int cred(int o,int credit, int bet)//calculates credit score after result
{
if(o==0)
   	{
   	credit = credit + bet;
   		printf("\nYOUR CREDIT: %d",credit);}
 else if(o==1){
   		credit = credit - bet;
   			printf("\nYOUR CREDIT: %d",credit);
   			}
 else if(o==2){
   			printf("\nYOUR CREDIT: %d",credit);
   			}
   		return credit;
   	}
     
