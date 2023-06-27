#include <iostream>
using namespace std;

// Creature class
class Creature {
    
	private:
	
		double chanceOfRep = 0.5;
		double chanceOfDeath = 0.5;
		int health = 50;
		bool alive = true;
		
	public:
	    
	    // takeDamage deals damage to the creature.
	    // If the damage is more than the remaining health,
	    // then it sets health to 0 and calls die().
	    void takeDamage(int x) {
	        if ((health - x) >= 0) {
	            health -= x;
	            printf("Creature took %d damage.\n", x);
	        }
	        else {
	            health = 0;
	            printf("Creature's health hit zero. It will have a chance to survive w/ 10 health, or it dies.\n");
	            die();
	        }
	    }
	    
	    // Gives the creature the chance to die, or live with 10 health.
		void die() {
		    int r = rand() % 10;
		    if ((r * chanceOfDeath) > 5) {
		        printf("Creature died.\n");
		        alive = false;
		    }
		    else {
		        health = 10;
		        printf("Creature survived with 10 health.\n");
		    }
		}
		
		// Gives the creature the chance to 'reproduce', resetting health to 50.
		void reproduce() {
		    int r = rand() % 10;
		    if ((r * chanceOfRep) > 5) {
		        health = 50;
		        printf("Creature reproduced. Health is now at 50.\n");
		    }
		    else {
		        printf("Creature did not reproduce.\n");
		    }
		}
		
		// Sets the chance of reproducing variable if in bounds.
		void setChanceOfRep (double x) {
		    if (x >= 0 && x <= 1) {
		        chanceOfRep = x;
		    }
		    else {
		        printf("Not within bounds.\n");
		    }
		}
		
		// Sets the chance of death variable if in bounds.
		void setChanceOfDeath (double x) {
		    if (x >= 0 && x <= 1) {
		        chanceOfDeath = x;
		    }
		    else {
		        printf("Not within bounds.\n");
		    }
		}
		
		// Returns the alive variable.
		bool getAlive() {
		    return alive;
		}
		
		// Kills the creature.
		void kill() {
		    alive = false;
		}
		
		// Prints the creature's stats.
		void print() {
		    printf("Creature stats:\n");
		    printf("Chance of reproducing: %f\n", chanceOfRep);
		    printf("Chance of death: %f\n", chanceOfDeath);
		    printf("Health: %d\n", health);
		    if (alive) {
		        printf("Alive: true\n");
		    }
		    else {
		        printf("Alive: false\n");
		    }
		}
		
		int attack() {
		    int r = rand() % 10;
		    if (r > 3) {
		        return 1 + rand() % 10;
		    }
		    else {
		        return 0;
		    }
		}
		
		int getHealth() {
		    return health;
		}
		
};

// Predator class
class Predator {
    
	private:
	
		double chanceOfSpawn = 0.5;
		double chanceOfCatch = 0.5;
		double chanceOfDeath = 0.5;
		int health = 20;
		bool alive = true;
		
	public:
	    
	    // takeDamage deals damage to the predator.
	    // If the damage is more than the remaining health,
	    // then it sets health to 0 and calls die().
	    void takeDamage(int x) {
	        if ((health - x) >= 0) {
	            health -= x;
	            printf("Predator took %d damage.\n", x);
	        }
	        else {
	            health = 0;
	            printf("Predator's health hit zero. It will have a chance to survive w/ 3 health, or it dies.\n");
	            die();
	        }
	    }
	    
	    // Gives the predator the chance to die, or live with 10 health.
		void die() {
		    int r = rand() % 10;
		    if ((r * chanceOfDeath) > 2) {
		        alive = false;
		        printf("Predator died.\n");
		    }
		    else {
		        health = 3;
		        printf("Predator survived with 3 health.\n");
		    }
		}
		
		// Gives the predator a chance to catch the creature,
		// deals a random integer of damage.
		void catchPrey(Creature c) {
		    int r = rand() % 10;
		    if ((r * chanceOfCatch) > 5) {
		        int r1 = rand() % 5;
		        c.takeDamage(r1);
		    }
		}
		
		// Sets the chance of spawn variable within bounds.
		void setChanceOfSpawn (double x) {
		    if (x >= 0 && x <= 1) {
		        chanceOfSpawn = x;
		    }
		    else {
		        printf("Not within bounds.\n");
		    } 
		}
		
		// Sets the chance of catch variable within bounds.
		void setChanceOfCatch (double x) {
		    if (x >= 0 && x <= 1) {
		        chanceOfCatch = x;
		    }
		    else {
		        printf("Not within bounds.\n");
		    }
		}
		
		// Returns the alive variable.
		bool getAlive() {
		    return alive;
		}
		
		// Kills the predator.
		void kill() {
		    alive = false;
		}
		
		// Prints out predator stats.
		void print() {
		    printf("Predator stats:\n");
		    printf("Chance of spawn: %f\n", chanceOfSpawn);
		    printf("Chance of catch: %f\n", chanceOfCatch);
		    printf("Chance of death: %f\n", chanceOfDeath);
		    printf("Health: %d\n", health);
		    if (alive) {
		        printf("Alive: true\n");
		    }
		    else {
		        printf("Alive: false\n");
		    }
		}
		
		int attack() {
		    int r = rand() % 10;
		    if (r > 5) {
		        return 1 + rand() % 5;
		    }
		    else {
		        return 0;
		    }
		}
		
};

class World {
    
	Creature creature;
	Predator predator;
	
	private:
	
		double chanceOfSpawn = 0.5;
		int numberOfRolls = 10;
		
	public:
	    
	    // Returns a random number of rolls.
		int getNumRolls() {
		    int r = rand() % 5;
		    if (r == 0) {
		        return 0;
		    }
		    else {
		        return r;
		    }
		}
		
		// Sets the chance of spawn variable within bounds.
		void setChanceOfSpawn (double x) {
		    if (x >= 0 && x <= 1) {
		        chanceOfSpawn = x;
		    }
		    else {
		        printf("Not within bounds\n");
		    }
		}
		
		// Sets the number of rolls variable within bounds.
		void setNumOfRolls (int x) {
		    if (x >= 1 && x <= 10) {
		        if ((numberOfRolls + x) > 10) {
		            numberOfRolls = 10;
		        }
		        else {
		            numberOfRolls += x;
		        }
		        printf("%d rolls added. You now have %d rolls.\n", x, numberOfRolls);
		    }
		    else {
		        printf("No rolls added.\n");
		    }
		}
		
		// Returns whether the creature is alive.
		bool isAlive() {
		    return creature.getAlive();
		}
		
		// Kills the creature.
		void kill() {
		    creature.kill();
		}
		
		// Prints creature and predator stats.
		void print() {
		    predator.print();
		    printf("\n");
		    creature.print();
		    printf("\n");
		}
		
		void roll() {
		    setNumOfRolls(getNumRolls());
		}
		
		void attack() {
		    predator.takeDamage(creature.attack());
		    creature.takeDamage(predator.attack());
		    numberOfRolls -= 1;
		    printf("Number of rolls remaining: %d\n", numberOfRolls);
		}
		
		int getRolls() {
		    return numberOfRolls;
		}
		
		int getHealth() {
		    return creature.getHealth();
		}
		
		void repr() {
		    creature.reproduce();
		}
		
		bool prAlive() {
		    return predator.getAlive();
		}
		
};

int main(void) {
    
    World w;
    int x1;
    
    // Main game loop
    while (w.isAlive()) {
        
        if (w.getRolls() == 0 || w.getHealth() <= 0 || !w.prAlive()) {
            if (w.getRolls() == 0) {
                printf("Ran out of rolls!\n");
                w.kill();
            }
            if (w.getHealth() <= 0) {
                printf("Ran out of health!\n");
                w.kill();
            }
            if (!w.prAlive()) {
                printf("Predator died!\n");
                w.kill();
            }
            continue;
        }
        
        // Presents choices for player
        printf("Choices: \n");
        printf("Press ('1') to see all stats\n");
        printf("Press ('2') to roll for more chances, MAX of 10\n");
        printf("Press ('3') to roll for creature's attack. Uses a roll.\n");
        printf("Press ('4') to try for reproduction.\n");
        printf("Press ('0') to exit.\n");
        
        // Gets player's input
        cin >> x1;
        
        // Does things based on player's correct input
        if (x1 >= 0 && x1 <= 4) {
            if (x1 == 1) {
                w.print();
                continue;
            }
            else if (x1 == 2) {
                w.roll();
            }
            else if (x1 == 3) {
                w.attack();
            }
            else if (x1 == 4) {
                w.repr();
            }
            else if (x1 == 0) {
                w.kill();
            }
            else {
                printf("This should be unreachable.\n");
            }
        }
        
        // Exits with invalid input
        else if (isdigit(x1) == 0) {
            printf("Not a valid option.\n");
            cin.clear();
            cin.ignore(10000000,'\n');
            continue;
        }
        
        // Else statement
        else {
            printf("This should be unreachable.\n");
        }
        
    }
    
    return 0;
}