# Biến tên tệp mã nguồn
SRC = process.c

# Biến tên file thực thi sau khi biên dịch
TARGET = process

# Biến trình biên dịch
CC = gcc

# Biến tuỳ chọn biên dịch (gồm cả cảnh báo và gỡ lỗi)
CFLAGS = -Wall -g

# Mục tiêu mặc định (khi chỉ gọi 'make' hoặc 'make all')
all: $(TARGET)

# Quy tắc biên dịch file thực thi từ file .c
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Lệnh dọn sạch file thực thi (make clean)
clean:
	rm -f $(TARGET)
