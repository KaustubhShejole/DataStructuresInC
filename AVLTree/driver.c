#include"Insertion.h"
int id=0;
Tree_Node* Record_Root;
int main()
{
	Tree_Node* Root;
	Record_Root = NULL;
	Root = Record_Root;
	//Root = StoreRecords();
	StoreStations();
	StoreTrains();
	//DisplayTrains();
	//DisplayStations();
	int choice;
	StoreRecords();
	do
	{
		printf("Please enter 1 to insert list of passengers : \n");
		printf("Please enter 2 to delete all records of particular passenger id:\n");
		printf("Please enter 3 to get list of passengers with same train and same destination\n");
		printf("Please enter 4 to See destination station for a particular passenger as per the dates of travel\n");
		printf("Please enter 5 to Display the train number and the travel date\n");
		printf("in the sorted order of number  of passengers on the train.\n");
		printf("Please enter 6 to display all the trains having train-number within the range defined by From-train-Number - To-Train-Number.\n");
		printf("Please enter -1 to exit: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Insert();
				printf("\t\t***********\tNow records are as follows :\t***********\t\t\n");
				DisplayTree(Record_Root);
				DisplayTreeInRecordFile();
				break;
			case 2:
				Record_Root = DeleteNode();
				printf("Now Record_Root is as follows: \n");
				DisplayTree(Record_Root);
				//DisplayListInRecordFile();
				break;
			case 3:
				getTreeDestination();
				break;
			case 4:
				SortByTravelDate();
				break;
			case 5:
				SortTrains();
				break;
			case 6:
				RangeSearch();
				break;
		}
	} while (choice != -1);
	
	//DisplayTrains();
	//Insert();
	DeleteTree(Root);
	free(station_array);
	Delete(train_array);
}
