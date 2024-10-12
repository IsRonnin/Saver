CC = g++

# Опции компиляции
CFLAGS = -Wall -Wextra -std=c++17

# Имя исполняемого файла
TARGET = Execute_me

# Список файлов с исходным кодом
SRCS = main.cpp control.cpp

# Список заголовочных файлов
HEADERS = control.h Message.h User.h

# Список объектных файлов
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию (сборка)
all: $(TARGET)

# Правило для компиляции исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции объектных файлов
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJS) $(TARGET)
