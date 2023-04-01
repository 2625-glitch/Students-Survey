#include <stdio.h>

struct student
{
    int id;
    char name[80];
    int marks;
};

void accept(struct student[], int);
void display(struct student[], int);
void search(struct student[], int, int);
int findMax(struct student[], int);
void toppers(struct student[], int);

int main()
{
    int n, x, number;
    printf("How many number of records you want to enter? : ");
    scanf("%d", &n);
    struct student std[n];
    FILE *fp;
    fp=fopen("username.txt","wb");
    if(fp==NULL)
    {
    	puts("\n error opening the file!!!");
    	exit(1);
	}
	accept(std,n);
	fwrite(std,sizeof(struct student),n,fp);
	if(fwrite!=0)
	{
		printf("\n contents to the file written successfully");
	}
	else
	{
		printf("\n error writing to file!!!");
	}
	fclose(fp);
    do
    {

        printf("\nResult Menu :\n");
        printf("Press 1 to display the records of all the students.\n");
        printf("Press 2 to search a record based on the id.\n");
        printf("Press 3 to display toppers name from the entered record.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-3) : ");
        scanf("%d", &x);
        switch (x)
        {
            case 1:
                display(std, n);
                break;
            case 2:
                printf("Enter id number to search : ");
                scanf("%d", &number);
                search(std, n, number);
                break;
            case 3:
                toppers(std, n);
        }
    }
    while (x != 0);

    return 0;
}

void accept(struct student std[80], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter id : ");
        scanf("%d", &std[i].id);
        fflush(stdin);
        printf("Enter name : ");
        gets(std[i].name);

        printf("Enter marks : ");
        scanf("%d", &std[i].marks);
    } 
}

void display(struct student std[80], int s)
{
    int i;

    printf("\n\nID\tName\tMarks\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", std[i].id, std[i].name, std[i].marks);
    } 
}

void search(struct student std[80], int n, int number)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (std[i].id == number)
        {
            printf("id : %d\nName : %s\nMarks : %d\n", std[i].id,
                std[i].name, std[i].marks);
            return ;
        } 
    }
    printf("Record not Found\n");
}

int findMax(struct student std[], int n)
{
    int i, max;

    max = std[0].marks;
    for (i = 1; i < n; i++)
    {
        if (std[i].marks > max)
        {
            max = std[i].marks;
        } 
    }
    return max;
}

void toppers(struct student std[], int n)
{
    int i,j;
    struct student temp;
    for (i = 0; i < n; i++)
    {
        if (std[i].marks == findMax(std, n))
        {
            printf("%s\n", std[i].name);
        } 
    }
    printf("\n details of all students from highest to lowest marks is");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-1;j++)
    	{
    		if(std[j].marks<std[j+1].marks)
    		{
    		temp=std[j];
    		std[j]=std[j+1];
    		std[j+1]=temp;
    	    }
		}
	}
	printf("\n id\t\t\tname\t\t\tmarks");
	printf("\n------------------------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%s\t\t\t%d",std[i].id,std[i].name,std[i].marks);
	}
    
}
