#include"InsertNode.h"
int id=0;
Node* Record_List = NULL;
void DisplayListInRecordFile()
{
	Node* nptr;
	nptr = Record_List;
	FILE* fp;
	fp = fopen("records.txt","w");
	while(nptr!=NULL)
	{
		DisplayInRecordFile(&nptr->data,fp);
		nptr=nptr->next;
	}
	fclose(fp);//Programers duty
}
int main()
{
	Node* lptr;
	lptr = Record_List;
	//lptr = StoreRecords();
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
		printf("Please enter 6 to promote passengers for particular train_id and date\n");
		printf("Please enter -1 to exit: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Insert();
				DisplayList(lptr);
				DisplayListInRecordFile();//DisplayInRecordFile()
				break;
			case 2:
				Record_List = DeleteNode();
				printf("Now Record_List is as follows: \n");
				DisplayList(Record_List);
				DisplayListInRecordFile();
				break;
			case 3:
				getListDestination();
				break;
			case 4:
				SortByTravelDate();
				break;
			case 5:
				SortTrains();
				break;
			case 6:
				Record_List = PromotePassengers();
				DisplayList(Record_List);
				break;
		}
	} while (choice != -1);
	
	//DisplayTrains();
	//Insert();
	DeleteList(lptr);
	Delete(train_array);
	free(station_array);
}
