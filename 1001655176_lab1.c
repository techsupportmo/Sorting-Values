//  Mohammed Ahmed
//  1001655176
//  Lab 1
//  gcc 1001655176_lab1.c


#include <stdio.h>
#include <stdlib.h>

//struct for numbers - contains numID (key) and numValue
struct number
{
    int numID;
    int numValue;
};


//compare function for comparing value of number
int compareValues(const void *a, const void *b)
{
    const struct number *num1 = a;
    const struct number *num2 = b;
    return num1->numValue - num2->numValue;
}

//compare function for comparing key of number
int compareKeys(const void *a, const void *b)
{
    const struct number *num1 = a;
    const struct number *num2 = b;
    return num1->numID - num2->numID;
}



int main(int argc, const char * argv[]) {
    
    int count;
    
    
    //1st element in array is number of integers
    //printf("How many numbers: ");
    scanf("%d",&count);
    
    //array of structures to hold numbers
    struct number NumList[count];

    
    //prompt for numbers depending on how many integers there are
    int i;
    for(i = 0; i < count;i++)
    {
        //inputs integer
        //printf("\nEnter a number: ");
        scanf("%d",&NumList[i].numValue);
        
        //Number ID (key)
        NumList[i].numID = i;

        
    }
    
    //prints out array BEFORE sort
    /*
    for(i = 0; i < count; i++)
    {
        //value and key
        printf("%d:%5d  %5d\n",i,NumList[i].numValue, NumList[i].numID);
        
        
    }
    */
    
    //sorts array
    qsort(NumList,count,sizeof(struct number),compareValues);
    
    //prints out array AFTER sort
    /*
    printf("\n\n");
    for(i = 0; i < count; i++)
    {
        //value and key
        printf("%d:%5d  %5d\n",i,NumList[i].numValue, NumList[i].numID);
    }
    */
    
    //STEP 2 - REMOVE DUPLICATES
    
    int newCount = count;
    
    //loop through the array of structure and marks duplicates
    for(i = 0; i < count-1; i++)
    {
        //if there are duplicate values, change ID to -1
        if(NumList[i].numValue == NumList[i+1].numValue)
        {
            NumList[i+1].numID = -1;
            newCount--;
        }
        
    }
    
    
    //prints out array with marked values
    /*
    printf("\n\n");
    for(i = 0; i < count; i++)
    {
        //value and key
        printf("%d:%5d  %5d\n",i,NumList[i].numValue, NumList[i].numID);
    }
    */
    
    //new struct without duplicate values
    struct number NewNumList[newCount];
    
    int j = 0; //keeps track of how many NewNumList values there are
    
    //loops through old array and copies values without duplicates
    for(i = 0; i < count; i++)
    {
        //int j = 0; //keeps track of how many NewNumList values there are
        
        //checks if value is duplicate
        if(NumList[i].numID != -1)
        {
            //copies numValue and numID
            NewNumList[j].numValue = NumList[i].numValue;
            NewNumList[j].numID = NumList[i].numID;
            j++;
        }
    }
    
    
    
    
    //prints out array AFTER removing duplicates
    /*
    printf("\n\n");
    for(i = 0; i < newCount; i++)
    {
        //value and key
        printf("%d:%5d  %5d\n",i,NewNumList[i].numValue, NewNumList[i].numID);
    }
    */
    
    //sort the values based on numID (key)
    qsort(NewNumList,newCount,sizeof(struct number),compareKeys);
    
    //prints out array after sorting keys
    /*
    printf("\n\n");
    for(i = 0; i < newCount; i++)
    {
        //value and key
        printf("%d:%5d  %5d\n",i,NewNumList[i].numValue, NewNumList[i].numID);
    }
    */
    
    //FINAL OUTPUT
    
    //print out number of values
    printf("%d\n", newCount);
    
    //list out all output values
    for(i = 0; i < newCount; i++)
    {
        printf("%d\n", NewNumList[i].numValue);
    }

    
    return 0;
}
