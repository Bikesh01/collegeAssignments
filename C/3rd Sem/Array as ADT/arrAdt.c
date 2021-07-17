#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>



struct myArray{
	int totalSize;	//Total Size of Array
	int alloSize;	//Current Allocation/Used Size
	int *ptr;		//Pointer For allocating Array
};



//Text Color Changing
//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors
void textcolor(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



//Function Prototypes
void create(struct myArray * a);							//Creates Array
void insert(struct myArray * a,int element);				//Inserts X element in any location
//void delete(struct myArray * a, int index);				//To delete element using index
void delete(struct myArray * a, int element);				//Deletes the X element
void modify(struct myArray * a,int oElement,int nElement);	//Replaces Old Element(oElement) by New Element(nElement)
void travels(struct myArray * a);							//Displays all the elements of Array
void merge(struct myArray *a, struct myArray *b, struct myArray *c);


int choseArray();		//Function To choose between 3 Arrays


//Main Function
int main()
{
	struct myArray arr[3];
	//For A Array
	arr[0].alloSize=0;
	arr[0].totalSize=0;
	//For B Array
	arr[1].alloSize=0;
	arr[1].totalSize=0;
	//For C Array
	arr[2].alloSize=0;
	arr[2].totalSize=0;
	int ins,del,nElement,oElement,option=0,merge1=0,merge2=0;
	char ch;
	//Looping the Menu
	loop:while(1)
	{
		system("cls");
		textcolor(8);
		printf("			     Array as an ADT\n");
		textcolor(7);
		 printf(" _______________________________________________________________________\n");
		printf("|									|\n");
		printf("|				1.Create				|\n");
		printf("|				2.Insert				|\n");
        printf("|				3.Delete 				|\n");
        printf("|				4.Modify				|\n");
        printf("|				5.Travels				|\n");
        printf("|				6.Merge					|\n");
        printf("|_______________________________________________________________________|\n");
        textcolor(13);
        printf("\n			      ***Recommended***\n");
        printf("	  		     Create an array first\n");
        textcolor(1);
        printf("\nChoose any option:");
        textcolor(7);
        int choice=0;
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1: system("cls");
					textcolor(3);
					printf("------------CREATING ARRAY------------\n");
					option=choseArray();
					if(option==1)
					{
						create(&arr[0]);
					}
					if(option==2)
					{
						create(&arr[1]);
					}
					if(option==3)
					{
						create(&arr[2]);
					}
        			break;

        	case 2: system("cls");
					textcolor(3);
    				printf("------------INSERTING ELEMENT------------\n");
    				option=choseArray();
					textcolor(1);
        			printf("\nEnter the element:");
        			textcolor(7);
        			scanf("%d",&ins);
					if(option==1)
					{
						insert(&arr[0],ins);
					}
					if(option==2)
					{
						insert(&arr[1],ins);
					}
					if(option==3)
					{
						insert(&arr[2],ins);
					}
        			break;

        	case 3: system("cls");
        			textcolor(3);
				    printf("------------DELETING ELEMENT------------\n");
				    option=choseArray();
					textcolor(1);
        			printf("\nEnter the element for deletion:");
        			textcolor(7);
        			scanf("%d",&del);
					if(option==1)
					{
						delete(&arr[0],del);
					}
					if(option==2)
					{
						delete(&arr[1],del);
					}
					if(option==3)
					{
						delete(&arr[2],del);
					}
        			break;

        	case 4: system("cls");
        			textcolor(3);
				    printf("------------MODIFYING ELEMENT------------\n");
				    option=choseArray();
				    textcolor(1);
				    printf("\nEnter the element you wanna replace:");
				    textcolor(7);
				    scanf("%d",&oElement);
				    textcolor(1);
				    printf("\nEnter the element you wanna replace %d by:",oElement);
				    textcolor(7);
				    scanf("%d",&nElement);
				    if(option==1)
					{
						modify(&arr[0],oElement,nElement);
					}
					if(option==2)
					{
						modify(&arr[1],oElement,nElement);
					}
					if(option==3)
					{
						modify(&arr[2],oElement,nElement);
					}
					break;


        	case 5: system("cls");
					textcolor(3);
    				printf("------------DISPLAYING ELEMENT------------\n");
    				option=choseArray();
					if(option==1)
					{
						travels(&arr[0]);
					}
					if(option==2)
					{
						travels(&arr[1]);
					}
					if(option==3)
					{
						travels(&arr[2]);
					}
        			break;

        	case 6: system("cls");
        			textcolor(3);
        			printf("------------MERGING ELEMENT------------\n");
        			textcolor(5);
        			printf("\n			Merge This");
        			printf("\n			___________\n");
        			merge1=choseArray();
        			textcolor(5);
        			printf("\n			Merge That");
        			printf("\n			___________\n");
        			merge2=choseArray();
        			textcolor(12);
        			printf("\nMerging Array %d & Array %d into another Array will result in the lose of data of that Array.",merge1,merge2);
        			printf("\nAre You Sure You Wanna Proceed?(Y/N):");
        			ch=getch();
        			if (ch=='Y'||ch=='y')
        			{
        				if(merge1==1 || merge1==2 && merge2==2 || merge2==1)
						{
							merge(&arr[0],&arr[1],&arr[2]);
						}
						if(merge1==2 || merge1==3 && merge2==3 || merge2==2)
						{
							merge(&arr[1],&arr[2],&arr[0]);
						}
						if(merge1==1 || merge1==3 && merge2==3 || merge2==1)
						{
							merge(&arr[0],&arr[2],&arr[1]);
						}
        			}
        			else
        			{
        				goto loop;
        			}
        			
        			break;

        	default: free(arr->ptr);
        			exit(1);
        }
	}
}

void create(struct myArray * a)
{
	//recreate:system("cls");
	system("cls");
	int tsize,usize;
	textcolor(3);
	printf("------------CREATING ARRAY------------\n");
    textcolor(1);
	printf("Enter the Total Elements in Array:");
	textcolor(7);
	scanf("%d",&tsize);
	textcolor(1);
	printf("\nEnter the Current entry Element:");
	textcolor(7);
	scanf("%d",&usize);
	if(usize > tsize)
		{
			textcolor(12);
			printf("\nCurrent Allocation Size Can't be Greater Than Total Size.\n");
			textcolor(1);
			printf("\nPress any key to re-allocate.");
			getch();
			//goto recreate;
			create(a);
		}
	else
	{
		//(*a).totalSize=tsize;
		a->totalSize=tsize;
		a->alloSize=usize;
		a->ptr = (int *)malloc(tsize * sizeof(int));
		for (int i = 0; i < a->alloSize; ++i)
		{
			textcolor(1);
			printf("Enter the Element %d:",i);
			// int n;
			// scanf("%d",&n);
			// (a->ptr)[i]=n;
			textcolor(7);
			scanf("%d",&(a->ptr)[i]);
		}
	}
	
}

void insert(struct myArray *a, int element)
{
	//int tsize,usize;
	int fsize;
	// tsize=a->totalSize;
	// usize=a->alloSize;
	fsize=a->totalSize - a->alloSize;
	if(a->totalSize!=0)
	{
		if (a->alloSize < a->totalSize)		//Checks if array is empty or full
		{
			textcolor(8);
			printf("Used Size:%d\n",a->alloSize);
			a->ptr[a->alloSize]=element;
			a->alloSize++;
			textcolor(2);
			printf("Insertion of element %d in %d index is complete.\n",element,a->alloSize-1);
			travels(a);
		}
		else
		{
			textcolor(12);
			printf("Error occured!\n");
			printf("Insertion Failed!\n");
			textcolor(8);
			printf("Total Size:%d\nUsed Size:%d\nFree size:%d\n",a->totalSize,a->alloSize,fsize);
			textcolor(12);
			printf("No Further Space For Insertion.\n");
			textcolor(7);
			getch();
		}
	}
	else
	{
		textcolor(12);
		printf("Element Insertion Can't be Performed Right Now!\n");
		textcolor(7);
		printf("Press Any Key To Continue...");
		getch();
	}
	
}

/*
void delete(struct myArray *a,int index)
{
	int element=a->ptr[index];
	for (int i = index; i < a->alloSize-1; i++)
	{
		a->ptr[i]=a->ptr[i+1];
	}
	a->alloSize--;
	textcolor(12);
	system("cls");
	printf("Successfully deleted %d element from %d index.",element,index);
	textcolor(7);
	getch();
}
*/

void delete(struct myArray * a,int element)
{
	//int lenDecr;
	//lenDecr=a->alloSize;
	int finalIndex;
	for(int index = 0; index < a->alloSize; index++)
	{
		if (a->ptr[index]==element)	//Searches the array for the element
		{
			for (int i = index; i < a->alloSize-1; i++)
			{
				a->ptr[i]=a->ptr[i+1];	//Changes the element position/index to the left by one
			}
			//lenDecr--;
			a->alloSize--;
			textcolor(12);
			printf("Successfully deleted %d element from %d index.\n\n",element,index);
		}
		finalIndex=index+1;
	}
	if(finalIndex>=a->alloSize)
	{
		textcolor(12);
		printf("Error occured!\n");
		printf("Couldn't Find the %d element in the array.\n\n",element);
	}
	travels(a);
	//a->alloSize=lenDecr;
	textcolor(7);
}

void modify(struct myArray * a,int oElement,int nElement)
{
	int old;
	if(a->alloSize < a->totalSize)		//Checks whether array is full or not
	{
		for (int i = 0; i < a->alloSize; i++)
		{
			if (a->ptr[i]==oElement)
			{
				old=oElement;
				a->ptr[i]=nElement;
				textcolor(2);
				printf("\nModification of element %d by %d in %d index is complete.\n",old,nElement,i);
				travels(a);
			}
		}
	}
}

void travels(struct myArray * a)
{
		char createArray,insertArray;
		textcolor(3);
	    printf("------------DISPLAYING ARRAY------------\n");
	    textcolor(8);
		printf("Total Size:%d\nUsed Size:%d\n\n",a->totalSize,a->alloSize);
		textcolor(7);
		if (a->totalSize==0)
		{
			textcolor(6);
			printf("Do you wanna create an array?(Y/N):");
			createArray=getch();
			if (createArray=='Y'||createArray=='y')
			{
				create(a);
			}
		}
		else
		{
			printf("Array is:[");
			for (int i = 0; i < a->alloSize; i++)
			{
				printf("%d,",(a->ptr)[i]);
			}
			printf("\b]\n");
			printf("Press any key...");
			getch();
		}
}

void merge(struct myArray *a, struct myArray *b, struct myArray *c)
{
	int i=0,j=0,k=0;
	c->totalSize = a->totalSize + b -> totalSize;
    c->alloSize = a->alloSize + b->alloSize;
    if (a->totalSize!=0 || b->totalSize!=0)
    {
    	while(i<a->alloSize && j<a->alloSize)
    	{
    		if(a->ptr[i]<=b->ptr[j])
    		{
	            c->ptr[k]=a->ptr[i];
	            i++;
	            k++;
			}
	        if(a->ptr[i]>=b->ptr[j])
	        {
	            c->ptr[k] = b->ptr[j];
	            j++;
	            k++;
	    	}
	    }
	    for(;i<a->alloSize;i++)
	    {
	        c->ptr[k++]=a->ptr[i];
	    }
	    for(;j<b->alloSize;j++)
	    {
	        c->ptr[k++]=b->ptr[j];
		}
		textcolor(2);
		printf("Merge Successful.\n");
		travels(c);   
	}
	else
	{
		textcolor(12);
		printf("Error occured!\n");
		textcolor(8);
		printf("First Array:\n");
		printf("Total Size:%d\nUsed Size:%d\nFree size:%d\n\n",a->totalSize,a->alloSize,a->totalSize - a->alloSize);
		printf("Second Array\n");
		printf("Total Size:%d\nUsed Size:%d\nFree size:%d\n\n",b->totalSize,b->alloSize,b->totalSize - b->alloSize);
		textcolor(12);
		printf("Merge Failed!\n");
		textcolor(7);
		printf("Press Any Key To Continue...");
		getch();
	}
}


int choseArray()
{
	int opt;
	textcolor(1);
	printf("Choose An Array:\n");
	textcolor(7);
	printf("1.Array A\n");
	printf("2.Array B\n");
	printf("3.Array C\n");
	textcolor(1);
	printf("Enter 1,2 or 3:");
	textcolor(7);
	scanf("%d",&opt);
	return opt;
}
