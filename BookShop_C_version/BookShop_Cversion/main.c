#include <stdio.h>
#include <stdlib.h>

typedef struct book{
    char author[20], title[20];
    int *price;
    int *stocks;
}BookS;

void feeddata(BookS* bk){
    printf("Enter Author name: ");
    scanf("%s", (bk->author));
    printf("Enter book title: ");
    scanf("%s", (bk->title));
    printf("Enter book price: ");
    scanf("%d", &(bk->price));
    printf("Enter book stocks: ");
    scanf("%d", &(bk->stocks));
}

int search(char* sb, char *tb){

    if(strcmp(sb, tb)==0){
        return 1;
    }
    else{
        return 0;
    }
}

void show_data(BookS *b){
    printf("************************\n");
    printf("Author name: %s\n", b->author);
    printf("Book title: %s\n", b->title);
    printf("Book prices: %d\n", b->price);
    printf("Book stock: %d\n", b->stocks);
    printf("========================\n");
}

void Buy_book(BookS *b){
    int cnt, p=b->price, s=b->stocks;
    printf("Input the number of book want to buy: ");
    scanf("%d", &cnt);

    if(cnt <= s){
        b->stocks = s - cnt;
        printf("\nBook bought successfully\n");
        printf("Amount: %d.NT$\n\n", p * cnt);
    }
    else
        printf("\nThe required copies not sufficient\n");

}


int main()
{
    BookS *B[3];
    int i=0, r,t,choice,j;
    char titleBuy[20], authorBuy[20];

    while(1){
        printf("\tMENU \n");
        printf("1. Enter new books\n");
        printf("2. Search book\n");
        printf("3. Show data\n");
        printf("4. Buy book\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                fflush(stdin);
                B[i] = (BookS*) malloc(sizeof(BookS));
                feeddata(B[i]);
                i++;
                //printf("i= %d\n", i);
                break;
            case 2:
                fflush(stdin);
                printf("Input search author name: ");
                scanf("%s", &authorBuy);
                printf("Input search title: ");
                scanf("%s", &titleBuy);
                for(t=0; t<i; t++){
                    int s_author = search(B[t]->author, authorBuy);
                    int s_title = search(B[t]->title, titleBuy);
                    //printf("%d  %d\n", s_author, s_title);
                    if(s_author==1 && s_title==1){
                        printf("Book found it!!\n");
                        break;
                    }
                }
                if(t==i)
                    printf("Not found!\n");
                break;

            case 3:
                fflush(stdin);
                printf("  Stock remaining: \n");
                for(j=0; j<i; j++){
                    show_data(B[j]);
                }
                break;

            case 4:
                fflush(stdin);
                printf("Input author: ");
                scanf("%s", &authorBuy);
                printf("Input book title: ");
                scanf("%s", &titleBuy);
                for(t=0; t<i; t++){
                    int s_author = search(B[t]->author, authorBuy);
                    int s_title = search(B[t]->title, titleBuy);
                    if(s_author==1 && s_title==1){
                        Buy_book(B[t]);
                        break;
                    }
                }
                if(t==i)
                    printf("The book is not in stocks\n");
                break;

            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again\n");
        }
    }
    system("pause");
    return 0;
}
