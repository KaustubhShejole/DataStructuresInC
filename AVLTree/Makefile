CC=gcc
C_Flag=-c -g -Wall

all: final.exe

final.exe: Insertion.o storetrains.o storestations.o tree_functions.o driver.o helping.o general.o ListFunctions.o AVL_Insertion.o AVL_Balance.o AVL_Rotate.o helping_reservation.o reservation_functions.o reservation.o filledListAppend.o AVL_Deletion.o Deletion_Balance.o FileFunctions.o getTreeDestination.o SortByTravelDate.o SortTrains.o
	$(CC) -g Insertion.o storetrains.o general.o helping.o storestations.o tree_functions.o driver.o ListFunctions.o AVL_Insertion.o AVL_Balance.o AVL_Rotate.o helping_reservation.o reservation_functions.o reservation.o filledListAppend.o AVL_Deletion.o Deletion_Balance.o FileFunctions.o getTreeDestination.o SortByTravelDate.o SortTrains.o -o final.exe
Insertion.o : Insertion.c
	$(CC) $(C_Flag) Insertion.c -o Insertion.o
storestations.o : storestations.c
	$(CC) $(C_Flag) storestations.c -o storestations.o
general.o : general.c
	$(CC) $(C_Flag) general.c -o general.o
helping.o : helping.c
	$(CC) $(C_Flag) helping.c -o helping.o
storetrains.o : storetrains.c
	$(CC) $(C_Flag) storetrains.c -o storetrains.o
tree_functions.o : tree_functions.c
	$(CC) $(C_Flag) tree_functions.c -o tree_functions.o
driver.o:driver.c
	$(CC) $(C_Flag) driver.c -o driver.o
ListFunctions.o:ListFunctions.c
	$(CC) $(C_Flag) ListFunctions.c -o ListFunctions.o
AVL_Insertion.o:AVL_Insertion.c
	$(CC) $(C_Flag) AVL_Insertion.c -o AVL_Insertion.o
AVL_Balance.o:AVL_Balance.c
	$(CC) $(C_Flag) AVL_Balance.c -o AVL_Balance.o
AVL_Rotate.o:AVL_Rotate.c
	$(CC) $(C_Flag) AVL_Rotate.c -o AVL_Rotate.o
helping_reservation.o:helping_reservation.c
	$(CC) $(C_Flag) helping_reservation.c -o helping_reservation.o
reservation_functions.o:reservation_functions.c
	$(CC) $(C_Flag) reservation_functions.c -o reservation_functions.o
reservation.o:reservation.c
	$(CC) $(C_Flag) reservation.c -o reservation.o
filledListAppend.o:filledListAppend.c
	$(CC) $(C_Flag) filledListAppend.c -o filledListAppend.o
AVL_Deletion.o:AVL_Deletion.c
	$(CC) $(C_Flag) AVL_Deletion.c -o AVL_Deletion.o
Deletion_Balance.o:Deletion_Balance.c
	$(CC) $(C_Flag) Deletion_Balance.c -o Deletion_Balance.o
FileFunctions.o:FileFunctions.c
	$(CC) $(C_Flag) FileFunctions.c -o FileFunctions.o
getTreeDestination.o:getTreeDestination.c
	$(CC) $(C_Flag) getTreeDestination.c -o getTreeDestination.o
SortByTravelDate.o:SortByTravelDate.c
	$(CC) $(C_Flag) SortByTravelDate.c -o SortByTravelDate.o
SortTrains.o:SortTrains.c
	$(CC) $(C_Flag) SortTrains.c -o SortTrains.o
clean:
	del *.o
	del final.exe