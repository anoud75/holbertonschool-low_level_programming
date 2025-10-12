#include "main.h"
#include <stdio.h>

void close_file(int fd);
void error_read(char *filename, int fd_from, int fd_to);
void error_write(char *filename, int fd_from, int fd_to);

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	int result;

	result = close(fd);
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error_read - handles read error
 * @filename: name of file
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void error_read(char *filename, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	if (fd_from != -1)
		close(fd_from);
	if (fd_to != -1)
		close(fd_to);
	exit(98);
}

/**
 * error_write - handles write error
 * @filename: name of file
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void error_write(char *filename, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	if (fd_from != -1)
		close(fd_from);
	if (fd_to != -1)
		close(fd_to);
	exit(99);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_read(argv[1], -1, -1);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_write(argv[2], fd_from, -1);

	bytes_read = read(fd_from, buffer, 1024);
	if (bytes_read == -1)
		error_read(argv[1], fd_from, fd_to);

	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			error_write(argv[2], fd_from, fd_to);
		bytes_read = read(fd_from, buffer, 1024);
		if (bytes_read == -1)
			error_read(argv[1], fd_from, fd_to);
	}

	close_file(fd_from);
	close_file(fd_to);
	return (0);
}/**
