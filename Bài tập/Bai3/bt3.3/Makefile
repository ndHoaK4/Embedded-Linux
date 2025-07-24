# Biến định nghĩa tên các file nguồn và chương trình
CC = gcc                    # Trình biên dịch C
CFLAGS = -Wall -g          # Tùy chọn cảnh báo và bật debug
TARGETS = zombie orphan    # Danh sách các chương trình cần build

# Mục mặc định khi gõ 'make'
all: $(TARGETS)

# Build zombie
zombie: zombie.c
	$(CC) $(CFLAGS) -o zombie zombie.c

# Build orphan
orphan: orphan.c
	$(CC) $(CFLAGS) -o orphan orphan.c

# Dọn dẹp file biên dịch
clean:
	rm -f $(TARGETS)
