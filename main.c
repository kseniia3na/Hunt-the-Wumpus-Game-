/*
Program 2: Wumpus, version 2

Course: CS 211, Fall 2022. Wed 12pm Lab
System: Mac using Replit
Author: Kasey Nastahunina

*/

#include <stdio.h>
#include <stdlib.h> // for srand
#include <stdbool.h>	// for the bool type in C

#define NUMBER_OF_ROOMS 20

//--------------------------------------------------------------------------------
void displayCave() {
  printf("\n"
         "       ______18______             \n"
         "      /      |       \\           \n"
         "     /      _9__      \\          \n"
         "    /      /    \\      \\        \n"
         "   /      /      \\      \\       \n"
         "  17     8        10     19       \n"
         "  | \\   / \\      /  \\   / |    \n"
         "  |  \\ /   \\    /    \\ /  |    \n"
         "  |   7     1---2     11  |       \n"
         "  |   |    /     \\    |   |      \n"
         "  |   6----5     3---12   |       \n"
         "  |   |     \\   /     |   |      \n"
         "  |   \\       4      /    |      \n"
         "  |    \\      |     /     |      \n"
         "  \\     15---14---13     /       \n"
         "   \\   /            \\   /       \n"
         "    \\ /              \\ /        \n"
         "    16---------------20           \n"
         "\n");
}

//--------------------------------------------------------------------------------
void displayInstructions() {
  printf("Hunt the Wumpus:                                             \n"
         "The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
         "room has 3 tunnels leading to other rooms.                   \n"
         "                                                             \n"
         "Hazards:                                                     \n"
         "1. Two rooms have bottomless pits in them.  If you go there you fall "
         "and die.   \n"
         "2. Two other rooms have super-bats.  If you go there, the bats grab "
         "you and     \n"
         "   fly you to some random room, which could be troublesome.  Then "
         "those bats go \n"
         "   to a new room different from where they came from and from the "
         "other bats.   \n"
         "3. The Wumpus is not bothered by the pits or bats, as he has sucker "
         "feet and    \n"
         "   is too heavy for bats to lift.  Usually he is asleep.  Two things "
         "wake       \n"
         "    him up: Anytime you shoot an arrow, or you entering his room.  "
         "The Wumpus   \n"
         "    will move into the lowest-numbered adjacent room anytime you "
         "shoot an arrow.\n"
         "    When you move into the Wumpus' room, then he wakes and moves if "
         "he is in an \n"
         "    odd-numbered room, but stays still otherwise.  After that, if he "
         "is in your \n"
         "    room, he snaps your neck and you die!                            "
         "           \n"
         "                                                                     "
         "           \n"
         "Moves:                                                               "
         "           \n"
         "On each move you can do the following, where input can be upper or "
         "lower-case:  \n"
         "1. Move into an adjacent room.  To move enter 'M' followed by a "
         "space and       \n"
         "   then a room number.                                               "
         "           \n"
         "2. Shoot your guided arrow through a list of up to three adjacent "
         "rooms, which  \n"
         "   you specify.  Your arrow ends up in the final room.               "
         "           \n"
         "   To shoot enter 'S' followed by the number of rooms (1..3), and "
         "then the      \n"
         "   list of the desired number (up to 3) of adjacent room numbers, "
         "separated     \n"
         "   by spaces. If an arrow can't go a direction because there is no "
         "connecting   \n"
         "   tunnel, it ricochets and moves to the lowest-numbered adjacent "
         "room and      \n"
         "   continues doing this until it has traveled the designated number "
         "of rooms.   \n"
         "   If the arrow hits the Wumpus, you win! If the arrow hits you, you "
         "lose. You  \n"
         "   automatically pick up the arrow if you go through a room with the "
         "arrow in   \n"
         "   it.                                                               "
         "           \n"
         "3. Enter 'R' to reset the person and hazard locations, useful for "
         "testing.      \n"
         "4. Enter 'C' to cheat and display current board positions.           "
         "           \n"
         "5. Enter 'D' to display this set of instructions.                    "
         "           \n"
         "6. Enter 'P' to print the maze room layout.                          "
         "           \n"
         "7. Enter 'X' to exit the game.                                       "
         "           \n"
         "                                                                     "
         "           \n"
         "Good luck!                                                           "
         "           \n"
         " \n\n");
} // end displayInstructions()


/* The function is creating and returning a dynamicaly allocated array. */
int** createDynamicArray(){
  int row = 20, col = 3;
  
  int **rooms = (int**) malloc(row * sizeof(int*));
  for(int i = 0; i < row; i++){
    rooms[i] = (int*) malloc(col*sizeof(int)); //finding space using malloc
  }
  // array with adjacent rooms
  rooms[0][0] = 2;rooms[0][1] = 5;rooms[0][2] = 8;
  rooms[1][0] = 1;rooms[1][1] = 3;rooms[1][2] = 10;
  rooms[2][0] = 2;rooms[2][1] = 4;rooms[2][2] = 12;
  rooms[3][0] = 3;rooms[3][1] = 5;rooms[3][2] = 14;
  rooms[4][0] = 1;rooms[4][1] = 4;rooms[4][2] = 6;
  rooms[5][0] = 5;rooms[5][1] = 7;rooms[5][2] = 15;
  rooms[6][0] = 6;rooms[6][1] = 8;rooms[6][2] = 17;
  rooms[7][0] = 1;rooms[7][1] = 7;rooms[7][2] = 9;
  rooms[8][0] = 8;rooms[8][1] = 10;rooms[8][2] = 18;
  rooms[9][0] = 2;rooms[9][1] = 9;rooms[9][2] = 11;
  rooms[10][0] = 10;rooms[10][1] = 12;rooms[10][2] = 19;
  rooms[11][0] = 3;rooms[11][1] = 11;rooms[11][2] = 13;
  rooms[12][0] = 12;rooms[12][1] = 14;rooms[12][2] = 20;
  rooms[13][0] = 4;rooms[13][1] = 13;rooms[13][2] = 15;
  rooms[14][0] = 6;rooms[14][1] = 14;rooms[14][2] = 16;
  rooms[15][0] = 15;rooms[15][1] = 17;rooms[15][2] = 20;
  rooms[16][0] = 7;rooms[16][1] = 16;rooms[16][2] = 18;
  rooms[17][0] = 9;rooms[17][1] = 17;rooms[17][2] = 19;
  rooms[18][0] = 11;rooms[18][1] = 18;rooms[18][2] = 20;
  rooms[19][0] = 13;rooms[19][1] = 16;rooms[19][2] = 19;
  
  return rooms;
}


/*The function is deallocating the array every time the program ends to prevent memory leaks.*/
void deallocation(int **rooms){
  free(rooms);
}

//Copyright: Taken from Program 1 solution
/*The function is checking if the values for random assignment is already taken.*/
int alreadyFound(int randomValue,      // New number we're checking
                 int randomNumbers[],  // Set of numbers previously found
                 int limit)            // How many numbers previously found
{
    int returnValue = false;
    
    // compare random value against all previously found values
    for( int i = 0; i<limit; i++) {
        if( randomValue == randomNumbers[i]) {
            returnValue = true;   // It is already there
            break;
        }
    }
    
    return returnValue;
} 


//--------------------------------------------------------------------------------
//Copyright: Taken from Program 1 solution
//Fill this array with unique random integers 1..20
void setUniqueValues(int randomNumbers[],   // Array of random numbers
                     int size)              // Size of random numbers array
{
    int randomValue = -1;
    
    for( int i = 0; i<size; i++) {
        do {
            randomValue = rand() % NUMBER_OF_ROOMS + 1;   // random number 1..20
        } while (alreadyFound(randomValue, randomNumbers, i));
        randomNumbers[i] = randomValue;
    }
}

/*The function takes player, wumpus, pits, bats and arrow positions and adjasent rooms as
parameters. It check if there are any pits, bats or a wumpus nearby player. Returns count 
that is used for printing in move function. If count is more than 0, then the players location is already printed and it is not needed.*/
int checkNearby(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms) {
  int foundPit = 0;    // used to check for pits near player
  int foundWumpus = 0; // used to check for wumpus near player
  int foundBat = 0; //used to check for bat near player

  int count = 0; //returns count if any of hazards found

  for (int i = 0; i < 3; i++) {
    // checks if there are pit found near player's room
    if (*player == rooms[*pit1 - 1][i] || *player == rooms[*pit2 - 1][i]) {
      foundPit = 1;
      count++;
    }
    // checks if there is wumpus found near player's room
    if (*player == rooms[*wumpus - 1][i]) {
      foundWumpus = 1;
      count++;
    }
    // checks if tehre is a bat found near player's room
    if(*player == rooms[*bat1 - 1][i] || *player == rooms[*bat2 - 1][i]){
      foundBat = 1;
      count++;
    }
    
  }
  //prints only is any of the hazards were found
  if(foundWumpus == 1 || foundPit == 1 || foundBat == 1){
    printf("You are in room %d. ", *player);
  }
  //prints messeges according to founded hazard
  if (foundWumpus == 1) {
    printf("You smell a stench. ");
  }
  if (foundPit == 1) {
    printf("You feel a draft. ");
  }
  if(foundBat == 1){
    printf("You hear rustling of bat wings. ");
  }
  return count;
}

/*The function takes player, wumpus, pits, bats and arrow positions and adjasent rooms as parameters. Checks if the user found the arrow. Returns count that is used for printing in move function. If count is more than 0, then the players location is already printed and it is not needed */
int checkForArrow(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms){
  int count = 0;
  if(*player == *arrow){
      printf("Congratulations, you found the arrow and can once again shoot.");
      *arrow = -1;
    count++;
    }
  return count;
                    }

/*The function takes player, wumpus, pits, bats and arrow positions and adjasent rooms as parameters. It check if there are any pits of a wumpus in player's room and checks if player is in bats room. If player is in the bats room then it moves the player into a random room.*/
void checkForDeath(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow,
                   int **rooms) {
  int newBatRoom[3]; // creates an array with number of new rooms for bats to move to, creates 7 to have multiple to move to another if one is already taken
  // checks if player is in the pit
  if ((*player == *pit1) || (*player == *pit2)) {
    printf("Aaaaaaaaahhhhhh....   \n    You fall into a pit and die. \n");
    deallocation(rooms);
    printf("\nExiting Program ...\n");
    exit(0);
  }
  // checks if layer is in the rooms with wumpus and it is even
  else if ((*player == *wumpus && ((*wumpus % 2) == 0))) {
    printf("You briefly feel a slimy tentacled arm as your neck is snapped. \n"
           "It is over.\n");
    deallocation(rooms);
    printf("\nExiting Program ...\n");
    exit(0);
  }
  else if(*player == *bat1){
    printf("Woah... you're flying! \n");
    setUniqueValues(newBatRoom, 3);
    *player = newBatRoom[0];
    if(newBatRoom[1] != *bat1){
      *bat1 = newBatRoom[1];
    }
    else{
      for(int j = 1; j < 3; j++){
        if(newBatRoom[j] != *bat1 && newBatRoom[j] != *bat2 && newBatRoom[j] != *player){
          *bat1 = newBatRoom[j];
          }
      }
      }
    printf("You've just been transported by bats to room %d.\n", *player);
    checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  }
  else if(*player == *bat2){
    printf("Woah... you're flying! \n");
    setUniqueValues(newBatRoom, 3);
    *player = newBatRoom[0];
    if(newBatRoom[1] != *bat2){
      *bat2 = newBatRoom[1];
    }
    else{
      for(int j = 1; j < 3; j++){
      if(newBatRoom[j] != *bat1 && newBatRoom[j] != *bat2 && newBatRoom[j] != *player){
        *bat2 = newBatRoom[j];
        }
      }
    }
    
    printf("You've just been transported by bats to room %d.\n", *player);
    checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
     
  }
}

/*The function takes player's room and room to move arrow to and the array of rooms as parameters. Returns true if the two rooms are adjacent.*/
bool isAdj(int *player, int shoot, int **rooms){
  for (int i = 0; i < 3; i++) {
    if (*player == rooms[shoot - 1][i]) {
      return true;
    }
  }
  return false;
}

/*The function takes the room the arrow is in, the room to move arrow to and the array of rooms as parameters. Returns true if the two rooms are adjacent.*/
bool isAdjToPrevious(int shoot1, int shoot2, int **rooms){
  for (int i = 0; i < 3; i++) {
    if (shoot1 == rooms[shoot2 - 1][i]) {
      return true;
    }
  }
  return false;
}

/*The function takes, players, wumpus, pits , bats and arrow positions, the array with rooms and number of moves as parameters. Moves arrow number of moves times if the room is not adjacent. Checks if ricochet accidentaly killed the player or wumpus.*/
void notAdj (int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow,
int **rooms, int numOfMoves){

  for(int i = 0; i < numOfMoves; i++){ //moves arrow to lowest numbered room number of moves times
    if(rooms[*arrow - 1][0] != *pit1 && rooms[*arrow - 1][0] != *pit2 && rooms[*arrow - 1][0] != *bat1 && rooms[*arrow - 1][0] != *bat2){
      *arrow = rooms[*arrow - 1][0];
    }
    if(*player == *arrow){ //if arrow ricocheted into player
      printf("\nYou just shot yourself, and are dying.\n"
         "It didn't take long, you're dead.\n");
      deallocation(rooms);
      printf("\nExiting Program ...\n");
      exit(0);
    }
    else if(*wumpus == *arrow){  //if arrow ricocheted into wumpus
      printf("\nYour arrow ricochet killed the Wumpus, you lucky dog!\n"
         "Accidental victory, but still you win!\n");
      deallocation(rooms);
      printf("\nExiting Program ...\n");
      exit(0);
    }
  }
  printf("\nYou are in room %d. ", *player);
}

/*The function takes, players, the array with rooms and position to move arrow to as parameters. Checks if user inputted its room to shot and killed itself.*/
void shotPlayer(int *player, int roomToShoot1, int **rooms){
  if(*player == roomToShoot1){
        printf("You just shot yourself.\nMaybe Darwin was right. You're dead.\n");
        deallocation(rooms);
        printf("\nExiting Program ...\n");
        exit(0);
      }
}

/*The function takes, players, wumpus, pits , bats and arrow positions, the array with rooms and position to move to as parameters. It moves wumpus everytime the arrow is shot.*/
void moveWumpus(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms){
   *wumpus = rooms[*wumpus - 1][0]; //moves wumpus to lowes adjacent room      
}

/*The function takes, players, wumpus, pits , bats and arrow positions, the array with rooms and position to move to as parameters. The function checks if player's arrow shot wumpus or player.*/
void arrowResult(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms){
 if(*arrow == *wumpus){
    printf("Wumpus has just been pierced by your deadly arrow!\nCongratulations on your victory, you awesome hunter you.\n");
    deallocation(rooms);
    printf("\nExiting Program ...\n");
    exit(0);
  }
  else if(*player == *arrow){
    printf("You just shot yourself.\nMaybe Darwin was right. You're dead.\n");
    deallocation(rooms);
    printf("\nExiting Program ...\n");
    exit(0);
  }
}

/*Function to shoot arrow. Takes players, wumpus, pits, bats and arrow positions, the array with rooms and and the room to move to as parameters. Checks if the room is adjacent to players room.*/
void shootArrowOneRoom(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int roomToShoot1, int **rooms, int numOfRooms){
  
      if(isAdj(player, roomToShoot1, rooms)) { //checks that the first room is adjacent
        *arrow = roomToShoot1; //moves arrow to the first room
        numOfRooms--; //decreases number of moves in case the arrow ricochets later
        arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
        printf("You are in room %d. ", *player);
        }
      else{ //if the first room is not adjacent
        printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot1);
        notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
        }
}

/*Function to shoot arrow. Takes players, wumpus, pits , bats and arrow positions, the array with rooms and and the 2 rooms to move to as parameters. Checks if the first room is adjacent to players room and the other room is adjasent to the first room.*/
void shootArrowTwoRooms(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int roomToShoot1, int roomToShoot2, int **rooms, int numOfRooms){
  
  if (isAdj(player, roomToShoot1, rooms) ) { //checks that the first room is adjacent
        *arrow = roomToShoot1; //moves arrow to the first room
        numOfRooms--;
        arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
        
        if(isAdjToPrevious(roomToShoot1, roomToShoot2, rooms)){ //checks that the second room is adjacent
          *arrow = roomToShoot2; //moves arrow to the second room
          numOfRooms--;
          arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
          printf("You are in room %d. ", *player);
          }
        else { //if the second room is not adjacent
          printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot2);
          notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
        }
      }
      else{ //if the first room is not adjacent
        printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot1);
        notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
        }
}

/*Function to shoot arrow. Takes players, wumpus, pits , bats and arrow positions, the array with rooms and and the 3 rooms to move to as parameters. Checks if the first room is adjacent to players room and the other rooms are adjasent to each other.*/
void shootArrowThreeRooms(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int roomToShoot1, int roomToShoot2, int roomToShoot3, int **rooms, int numOfRooms){
  if (isAdj(player, roomToShoot1, rooms)  ){ //checks that the first room is adjacent
        *arrow = roomToShoot1; //moves arrow to the first room
        numOfRooms--; //decreases number of moves in case the arrow ricochets later
        arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms); //checks if there are any hazards in the room
        
        if(isAdjToPrevious(roomToShoot1, roomToShoot2, rooms)){ //checks that the second room is adjacent
          *arrow = roomToShoot2; //moves arrow to the second room
          numOfRooms--;
          arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
          
          if(isAdjToPrevious(roomToShoot2, roomToShoot3, rooms)){
            *arrow = roomToShoot3; //moves rrow to the third room
            numOfRooms--;
            arrowResult(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
            printf("You are in room %d. ", *player);
          }
          else{ //if the third room is not adjacent
            printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot3);
            notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
          }
        }
        else { //if the second room is not adjacent
          printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot2);
          notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
        }
    }
    else{ //if the first room in not adjacent
       printf("Room %d is not adjacent.  Arrow ricochets...", roomToShoot1);
        notAdj(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms, numOfRooms);
        }
    }

/*Function to shoot arrow. Takes players, wumpus, pits , bats and arrow positions, and the array with rooms as parameters. Checks if player has the arrow, then asks user for input and works accordingly.*/
void shootArrow(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms){
  
  int numOfRooms; // number of rooms to shoot to
  int roomToShoot1 = 0, roomToShoot2 = 0, roomToShoot3 = 0; // number of the room to shoot to
  
  if(*arrow != -1){ //checks if the player has an arrow
    printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
    int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }  
  }   
  else{
    printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
    scanf(" %d", &numOfRooms);
    
    if(numOfRooms > 3 || numOfRooms < 0){ //checks if the user wanted to input more than 3 or less than 1 rooms.
      printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");
      numOfRooms = 3; //sets number of rooms to max
    }
    *arrow = *player; //sets arrow to players position, so it can check if the rooms from users input is adjacent to player
    
    if (numOfRooms == 1){ // if user wants to shoot into one room
      
      scanf(" %d", &roomToShoot1);
      shotPlayer(player, roomToShoot1, rooms);
      
      shootArrowOneRoom(player, wumpus, pit1, pit2, bat1, bat2, arrow, roomToShoot1, rooms, numOfRooms);
      moveWumpus(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
    }
    else if (numOfRooms == 2){ // if user wants to shoot into two rooms
      
      scanf(" %d %d", &roomToShoot1, &roomToShoot2);
      shotPlayer(player, roomToShoot1, rooms);
      
      shootArrowTwoRooms(player, wumpus, pit1,  pit2, bat1,bat2, arrow, roomToShoot1, roomToShoot2, rooms, numOfRooms);
      moveWumpus(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
    }
    else if (numOfRooms == 3){ //if user wants to shoot into 3 rooms
      
      scanf(" %d %d %d", &roomToShoot1, &roomToShoot2, &roomToShoot3);
      shotPlayer(player, roomToShoot1, rooms);
      
      shootArrowThreeRooms(player, wumpus, pit1, pit2, bat1, bat2, arrow, roomToShoot1, roomToShoot2, roomToShoot3, rooms, numOfRooms);
      moveWumpus(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      }
      
    }
}

/* The function takes user respons, players, wumpus, pits , bats and arrow positions, the array with rooms and position to move to as parameters. Used to reset the positions of player, wumpus, and both pits*/
void reset(char res[], int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms){
  int resetOptP, resetOptW, resetOptP2,
      resetOptP1, resetOptB1, resetOptB2, resetOptA; // used to reset all positions
                  // Resets location of player, wumpus, and both pits
  printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: ");
  //changed to take 7 integers insted of 4 like in a previous program
  scanf(" %d %d %d %d %d %d %d", &resetOptP, &resetOptW, &resetOptP1, &resetOptP2, &resetOptB1, &resetOptB2, &resetOptA);
  getchar();
  *player = resetOptP;
  *wumpus = resetOptW;
  *pit1 = resetOptP1;
  *pit2 = resetOptP2;
  *bat1  = resetOptB1;
  *bat2  = resetOptB2;
  *arrow = resetOptA;
  
  printf("\n\n");
  // calls function to check if player is in the same room as pits or wumpus.
  checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  // calls function to check if there are any pits or a wumpus in the adjacent
  // rooms.
  int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }
  checkForArrow(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  
}

/* The function takes user respons, players, wumpus, pits, bats and arrow positions and the array with rooms to as parameters. Used to print out the positions of player, wumpus, both pits, arrow, bats.*/
void cheat(char res[], int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow, int **rooms) {
  // Message for menu option C (cheating) for the player room, wumpus room,
  // pit 1 room, and pit 2 room
  printf("Cheating! Game elements are in the following rooms: \n"
         "Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
         "%4d %5d %6d %5d %5d %5d %5d \n\n",
         *player, *wumpus, *pit1, *pit2, *bat1, *bat2, *arrow);
  // calls funtion to check if player is in the came room as pits ot wumpus.
  checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  // calls funtion to check if there are any pits or wumpus in the adjacent
  // rooms.
  int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }
  checkForArrow(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
}

/*The function takes user respons, players, wumpus, pits, bats and arrow positions and the array with rooms, and number of correct moves as parametrs. checs for the first letter of the user respons and goes accordingly.*/
int checkResponse(char res[], int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow,
                  int **rooms, int count) {
  int guessAnswer;                      // used when user wants to guess answer
  if (res[0] == 'd' || res[0] == 'D') { // option D
    displayCave();
    displayInstructions(); // Displayes instructions and cave map.
    int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }
  } 
  else if (res[0] == 'r' || res[0] == 'R') { // Option R
    reset(res, player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  } 
  else if (res[0] == 'c' || res[0] == 'C') { // option C
    cheat(res, player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
  }
  else if (res[0] == 'p' || res[0] == 'P') { // option P
    displayCave();                             // Displays cave map
    int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }
  }
  else if (res[0] == 'g' || res[0] == 'G') { // option G
    // Prompt for guess of where Wumpus room is
    printf("Enter room (1..20) you think Wumpus is in: ");
    scanf("%d", &guessAnswer);
    if (guessAnswer == *wumpus) { // if users guess is correct
      printf("You won!\n");
      deallocation(rooms);
      printf("\nExiting Program ...\n");
      exit(0);
    } else { // if users guess is incorrect
      printf("You lost.\n");
      deallocation(rooms);
      printf("\nExiting Program ...\n");
      exit(0);
    }
  } 
  else if (res[0] == 'x' || res[0] == 'X') { // Option X
    // Message that prints at the end of the program
    deallocation(rooms);
    printf("\nExiting Program ...\n");
    exit(0);
  } 
  else if (res[0] == 'm' || res[0] == 'M') { // Option M
    int move;
    scanf(" %d", &move);
    int legalMove = 0; // used to check if the user move is correct
    for (int i = 0; i < 3; i++) {
      if (rooms[*player - 1][i] == move) { // checks if users move is to adjacent rooms.
        legalMove = 1;
      }
    }
    if (legalMove) {
      count += 1;     // counts number of correct moves
      *player = move; // moves player to selected room
      
      /*the if statemnet below checks if player is in the same room as wumpus
and the room is odd if so then moves wumpus to adjacent room*/
      if ((*player == *wumpus && ((*wumpus % 2) == 1))) {
        printf("You hear a slithering sound, as the Wumpus slips away. \n"
               "Whew, that was close! \n");
        *wumpus = rooms[*wumpus - 1][0];
      }
      // calls funtion to check if player is in the came room as pits ot wumpus.
      checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      // calls funtion to check if there are any pits or wumpus in the adjacent
      // rooms.
      int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      int arrowFound = checkForArrow(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      
      if(arrowFound > 0 && value == 0){
        printf("\nYou are in room %d. ", *player);
      }
      if(value == 0 && arrowFound == 0){
        printf("You are in room %d. ", *player);
      }
      
    } else {
      printf("Invalid move.  Please retry. \n"); // if users move for invalid
      // calls funtion to check if player is in the came room as pits ot wumpus.
      checkForDeath(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      // calls funtion to check if there are any pits or wumpus in the adjacent
      // rooms.
      int value = checkNearby(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", *player);
      }
      checkForArrow(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
      
    }
  } 
  else if(res[0] == 's' || res[0] == 'S'){//if user wants to shoot arrow
    shootArrow(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms);
    count += 1; 
  }
  else {
    printf("Invalid move.  Please retry. \n"); // if users input was invalid
    printf("You are in room %d. ", *player);
  }
  return count; // returns number of correct moves to printDetails().
}

/*The function takes players, wumpus, pits, bats and arrow positions and the array with rooms as parametrs. Asks user what move they want to make and scans for response. Then calls function that check what move the user wants to make and it is valid.*/
void printDetails(int player, int wumpus, int pit1, int pit2, int bat1, int bat2, int arrow,
                  int **rooms) {
  char response[30];  // char to respons
  int numOfMoves = 1; // number of correct moves.

  while (response[0] != 'x') {

    printf("\n\n%d. Enter your move (or 'D' for directions): ", numOfMoves);
    scanf(" %c", response);

    numOfMoves = checkResponse(response, &player, &wumpus, &pit1, &pit2, &bat1, &bat2, &arrow, rooms, numOfMoves);
  }
}


//--------------------------------------------------------------------------------
int main(void) {
  
  int **rooms = createDynamicArray(); //creates dynamically allocated array every time the game starts
  
  int takenRooms[7] = {0, 0, 0, 0, 0, 0, 0}; // array used to assign random rooms to 7 varibales
  int player = 0;         
  int wumpus = 0;         
  int pit1 = 0;          
  int pit2 = 0;           
  int bat1 = 0;           
  int bat2 = 0;
  int arrow = 0;
  int randomValue;
  
  srand(1);
  
  /*assigns random values to components of the array takenRooms and checks
  if any of the numbers has been taken*/
  setUniqueValues(takenRooms, 7);
  
  /*assigns random values form array takenRooms to
  the pits, wumpus, player, bats and arrow*/
  player = takenRooms[0];
  wumpus = takenRooms[1];
  pit1 = takenRooms[2];
  pit2 = takenRooms[3];
  bat1 = takenRooms[4];
  bat2 = takenRooms[5];
  arrow = takenRooms[6];

  int value = checkNearby(&player, &wumpus, &pit1, &pit2, &bat1, &bat2, &arrow, rooms);
      if(value == 0){
        printf("You are in room %d. ", player);
      }
  checkForArrow(&player, &wumpus, &pit1, &pit2, &bat1, &bat2, &arrow, rooms);

  printDetails(player, wumpus, pit1, pit2, bat1, bat2, arrow, rooms); // calls function that asks player for input

  return 0;
}