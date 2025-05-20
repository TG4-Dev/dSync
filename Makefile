CC = clang
FLAGS = -Werror
OBJECTS_SERVER = src/server/main.cpp 
OBJECTS_CLIENT = src/client/main.cpp
TARGET_SERVER = src/server/server.o 
TARGET_CLIENT = src/client/client.o


all: server client
server: $(OBJECTS_SERVER)
	$(CC) $(FLAGS) $(OBJECTS_SERVER) -o $(TARGET_SERVER)

client: $(OBJECT_CLIENT)
	$(CC) $(FLAGS) $(OBJECTS_CLIENT) -o $(TARGET_CLIENT)
