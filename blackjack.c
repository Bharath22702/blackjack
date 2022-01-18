#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int player,dealer;

struct node{
    int info;
    struct node * link;
};

struct node *headp=NULL;
struct node *headd=NULL;

void p_insert_beg(int ele){
    struct node *temp;
    temp=malloc(sizeof(struct node *));
    temp->info=ele;
    temp->link=NULL;
    player = player+ele;
    if(headp==NULL){
        headp=temp;
        return;
    }
    temp->link=headp;
    headp=temp;
}

void d_insert_beg(int ele){
    struct node *temp;
    temp=malloc(sizeof(struct node *));
    temp->info=ele;
    temp->link=NULL;
    dealer = dealer+ele;
    if(headd==NULL){
        headd=temp;
        return;
    }
    temp->link=headd;
    headd=temp;
}

void d_freeMemory(){
    struct node *temp;
    if(headd==NULL){
        return;
    }
    temp=headd;
    headd=headd->link;
    free(temp);
    d_freeMemory();
}

void p_freeMemory(){
    struct node *temp;
    if(headp==NULL){
        return;
    }
    temp=headp;
    headp=headp->link;
    free(temp);
    p_freeMemory();
}

void displayp(struct node *head){
    struct node *temp1=head;
    if(head==NULL){
        printf("\nError: Empty");
        return;
    }
    while(temp1!=NULL){
        printf("%d\t",temp1->info);
        temp1=temp1->link;
    }
}

void displayd(struct node *head){
    struct node *temp1=head;
    if(head==NULL){
        printf("\nError: Empty");
        return;
    }
    while(temp1->link!=NULL){
        printf("%d\t",temp1->info);
        temp1=temp1->link;
    }
    printf("XX");
}

int checkWin(int a){
    if(a>21)
        return 1;
    return 0;
}

int main(){
    system("clear");
    int choice,pg,credit,bet,ele;
    char name[32];
    printf("Welcom to BlackJack\n");
    printf("Enter your name: ");
    gets(name);
    printf("Enter the credit: ");
    scanf("%d", &credit);
    while(1){
        srand(time(NULL));
        player=0;
        dealer=0;
        printf("Enter the bet: ");
        scanf("%d", &bet);
        ele=(rand()%11)+1;
        p_insert_beg(ele);
        ele=(rand()%11)+1;
        d_insert_beg(ele); 
        ele=(rand()%11)+1;
        p_insert_beg(ele);
        ele=(rand()%11)+1;
        d_insert_beg(ele);
        if(checkWin(player)){
                    printf("\nThe dealer won");
                    credit = credit - bet;
                    printf("\n%s's credit: %d", name, credit);
                    break;
                }
        if(checkWin(dealer)){
            printf("You Won!!!");
            credit = credit + bet;
            printf("\n%s's credit: %d", name, credit);
            break;
                }
        while (1)
        {   
            printf("\nDealer: ");
            displayd(headd);
            printf("\nPlayer: ");
            displayp(headp);
            printf("\nEnter your choice:\n1.Hit\n2.Stand\n");
            scanf("%d", &choice);
            if(choice==1)
            {
                ele=(rand()%11)+1;
                p_insert_beg(ele);
                ele=(rand()%11)+1;
                d_insert_beg(ele);
                if(checkWin(player)){
                    printf("\nDealer: ");
                    displayp(headd);
                    printf("\nPlayer: ");
                    displayp(headp);
                    printf("\nThe dealer won");
                    credit = credit - bet;
                    printf("\n%s's credit: %d", name, credit);
                    break;
                }
                if(checkWin(dealer)){
                    printf("\nDealer: ");
                    displayp(headd);
                    printf("\nPlayer: ");
                    displayp(headp);
                    printf("\nYou Won!!!");
                    credit = credit + bet;
                    printf("\n%s's credit: %d", name, credit);
                    break;
                }
            }
            else{
                if(player>dealer){
                    printf("\nDealer: ");
                    displayp(headd);
                    printf("\nPlayer: ");
                    displayp(headp);
                    printf("\nYou Won!!!");
                    credit = credit + bet;
                    printf("\n%s's credit: %d",name, credit);
                    break;
                }
                else{
                    printf("\nDealer: ");
                    displayp(headd);
                    printf("\nPlayer: ");
                    displayp(headp);
                    printf("\nThe Dealer won!!!");
                    credit = credit - bet;
                    printf("\n%s's credit: %d", name, credit);
                    break;
                }
            }
        }
        printf("\n%d", player);
        printf("\n%d", dealer);
        
        printf("\nPlay Again(1)   Quit(0)\n");
        scanf("%d", &pg);
        if(!pg){
            p_freeMemory();
            d_freeMemory();
            system("clear");
            printf("\nThank You for playing\n");
            exit(0);
        }
        p_freeMemory();
        d_freeMemory();
    }
    return 0;
}
