CC = clang++
FLAGS = -Werror -lstdc++ -lc
OBJECTS_SERVER = src/server/*.cpp 
OBJECTS_CLIENT = src/client/*.cpp
TARGET_SERVER = src/server/server.o 
TARGET_CLIENT = src/client/client.o


all: server client
server: $(OBJECTS_SERVER)
	$(CC) $(OBJECTS_SERVER) -o $(TARGET_SERVER) $(FLAGS)  

client: $(OBJECT_CLIENT)
	$(CC) $(OBJECTS_CLIENT) -o $(TARGET_CLIENT) $(FLAGS)
