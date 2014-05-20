all: main.o C_Point.o C_Vector.o Game_Object.o Candy_Mine.o Tower.o Person.o Miner.o  Warrior.o View.o Model.o Game_Command.o Inspector.o
	g++ -o main main.o C_Point.o C_Vector.o Game_Object.o Candy_Mine.o Tower.o Person.o Miner.o  Warrior.o View.o Model.o Game_Command.o Inspector.o

clean:
	rm *.o main