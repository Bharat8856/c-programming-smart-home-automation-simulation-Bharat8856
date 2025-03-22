/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 #define MAX_ROOMS 5  // Max number of rooms
 
 // Function prototypes
 void initializeSystem();
 void displayMenu();
 void controlLights();
 void readTemperature();
 void detectMotion();
 void securitySystem();
 void analyzeHouseStatus();
 
 // Global arrays for storing states
 int lightSystem[MAX_ROOMS];        
 int temperatureSensors[MAX_ROOMS]; 
 int motionSensors[MAX_ROOMS];      
 int securityLocks[MAX_ROOMS];      

 int numRooms;                     
 int main() {
     printf("Enter number of rooms: ");
     scanf("%d", &numRooms);
 
     if (numRooms < 1 || numRooms > MAX_ROOMS) {
         printf("Invalid number of rooms! Please enter a number between 1 and %d.\n", MAX_ROOMS);
         return 1;
     }
 
     initializeSystem();
 
     int choice;
     do {
         displayMenu();
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 controlLights();
                 break;
             case 2:
                 readTemperature();
                 break;
             case 3:
                 detectMotion();
                 break;
             case 4:
                 securitySystem();
                 break;
             case 5:
                 analyzeHouseStatus();
                 break;
             case 6:
                 printf("Exiting...\n");
                 break;
             default:
                 printf("Invalid choice! Please try again.\n");
         }
     } while (choice != 6);
 
     return 0;
 }
 
 void initializeSystem() {
     // Set default states (Lights OFF, Doors Locked, No motion detected)
     for (int i = 0; i < numRooms; i++) {
         lightSystem[i] = 0;         
         temperatureSensors[i] = 22;
         motionSensors[i] = 0;      
         securityLocks[i] = 1;      
     }
     printf("Initializing system...\n");
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 
 void controlLights() {
     int room;
     printf("Enter room number to toggle light (1-%d): ", numRooms);
     scanf("%d", &room);
     if (room < 1 || room > numRooms) {
         printf("Invalid room number!\n");
         return;
     }
     room--; // Convert to 0-based index
 
     // Toggle the light state
     lightSystem[room] = !lightSystem[room];
     printf("Light in Room %d is now %s.\n", room + 1, lightSystem[room] ? "ON" : "OFF");
 }
 
 void readTemperature() {
     int room;
     printf("Enter room number to read temperature (1-%d): ", numRooms);
     scanf("%d", &room);
     if (room < 1 || room > numRooms) {
         printf("Invalid room number!\n");
         return;
     }
     room--; // Convert to 0-based index
 
     printf("Temperature in Room %d: %d°C\n", room + 1, temperatureSensors[room]);
 }
 
 void detectMotion() {
     int room;
     printf("Enter room number to check motion (1-%d): ", numRooms);
     scanf("%d", &room);
     if (room < 1 || room > numRooms) {
         printf("Invalid room number!\n");
         return;
     }
     room--; // Convert to 0-based index
 
     if (motionSensors[room] == 1) {
         printf("Motion detected in Room %d!\n", room + 1);
     } else {
         printf("No motion detected in Room %d.\n", room + 1);
     }
 }
 
 void securitySystem() {
     int room;
     printf("Enter room number to lock/unlock security system (1-%d): ", numRooms);
     scanf("%d", &room);
     if (room < 1 || room > numRooms) {
         printf("Invalid room number!\n");
         return;
     }
     room--; // Convert to 0-based index
 
     // Toggle the lock state
     securityLocks[room] = !securityLocks[room];
     printf("Security in Room %d is now %s.\n", room + 1, securityLocks[room] ? "Locked" : "Unlocked");
 }
 
 void analyzeHouseStatus() {
     printf("\nHouse Status:\n");
     for (int i = 0; i < numRooms; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
             lightSystem[i] ? "ON" : "OFF",
             temperatureSensors[i],
             motionSensors[i] ? "Motion Detected" : "No Motion",
             securityLocks[i] ? "Locked" : "Unlocked");
     }
 }
 