CC=gcc
C_Flag = -c -Wall

all: final.exe

final.exe : storestations.o storetrains.o helping.o ListFunctions.o InsertNode.o reservation.o helping_reservation.o reservation_functions.o filledListAppend.o getListDestination.o SortTrains.o SortByTravelDate.o AddToFreeList.o PromotePassengers.o RemoveFromFilledList.o driver.o 
	$(CC) storestations.o storetrains.o helping.o ListFunctions.o InsertNode.o reservation.o helping_reservation.o reservation_functions.o filledListAppend.o getListDestination.o SortTrains.o SortByTravelDate.o AddToFreeList.o PromotePassengers.o RemoveFromFilledList.o driver.o -o final.exe
storestations.o: storestations.c
	$(CC) $(C_Flag) storestations.c -o storestations.o
storetrains.o : storetrains.c
	$(CC) $(C_Flag) storetrains.c -o storetrains.o
ListFunctions.o : ListFunctions.c
	$(CC) $(C_Flag) ListFunctions.c -o ListFunctions.o
helping.o : helping.c
	$(CC) $(C_Flag) helping.c -o helping.o
InsertNode.o : InsertNode.c
	$(CC) $(C_Flag) InsertNode.c -o InsertNode.o
reservation.o : reservation.c
	$(CC) $(C_Flag) reservation.c -o reservation.o
helping_reservation.o : helping_reservation.c
	$(CC) $(C_Flag) helping_reservation.c -o helping_reservation.o
filledListAppend.o : filledListAppend.c
	$(CC) $(C_Flag) filledListAppend.c -o filledListAppend.o
reservation_functions.o : reservation_functions.c
	$(CC) $(C_Flag) reservation_functions.c -o reservation_functions.o
getListDestination.o : getListDestination.c
	$(CC) $(C_Flag) getListDestination.c -o getListDestination.o
SortTrains.o : SortTrains.c
	$(CC) $(C_Flag) SortTrains.c -o SortTrains.o
SortByTravelDate.o : SortByTravelDate.c
	$(CC) $(C_Flag) SortByTravelDate.c -o SortByTravelDate.o
AddToFreeList.o : AddToFreeList.c
	$(CC) $(C_Flag) AddToFreeList.c -o AddToFreeList.o
RemoveFromFilledList.o : RemoveFromFilledList.c
	$(CC) $(C_Flag) RemoveFromFilledList.c -o RemoveFromFilledList.o
PromotePassengers.o : PromotePassengers.c
	$(CC) $(C_Flag) PromotePassengers.c -o PromotePassengers.o
driver.o: driver.c
	$(CC) $(C_Flag) driver.c -o driver.o
clean:
	del *.o
	del final.exe
