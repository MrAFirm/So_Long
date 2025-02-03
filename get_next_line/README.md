# get_next_line
get_next_line is pretty much reading lines from one or some files. We utilise the Read, Extract, Update methods on retrieving the lines and moving them to a static buffer and printing them.

# Steps
We utilise a file reader to read the file lines via byte_size, then it'll read until it hits a newline character or null terminator. Then followed by extracting the lines by reading the characters using BUFFER_SIZE, then using a buffer and strjoin, then followed by updating the next lines into the buffer. Followed by freeing if the byte_size reaches a null terminator.
