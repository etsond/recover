# Image Recovery Program
This is a simple program that recovers images from a digital memory card file that has been "deleted". It is written in C and uses the CS50 library.

## How to Use
- Compile the program by running 

```ruby
make recover
``` 
- Run the program with the name of the memory card file as an argument, like so:
```ruby
./recover card.raw
```
The program will recover any "deleted" images from the memory card and save them as individual files in the same directory as the program.
## How it Works
The program reads the memory card file 512 bytes at a time, looking for the beginning of a JPEG image file. Once it finds the beginning of a JPEG image, it creates a new file with a unique name and writes the data to that file until the end of the JPEG image is reached. The program continues this process until it reaches the end of the memory card file.

### Dependencies
[This Library](https://github.com/cs50/libcs50)
