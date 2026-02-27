# mp3-tag-reader-c
# Overview
MP3 Tag Reader is a console-based C program that reads metadata (ID3v2 tags) from MP3 files. It displays information such as title, artist, album, year, and genre. This project demonstrates file handling, structures, and pointers in C while providing a simple tool to explore MP3 file information.

# Features
Read MP3 tags (ID3v2 format) from a single file.
Display metadata in a clean and readable format.
Handle multiple MP3 files (optional batch processing).
Lightweight and implemented entirely in C.
# How to Run
Clone the repository: git clone https://github.com/kaavya221103/mp3-tag-reader-c/tree/main

# Compile the program
gcc mp3_tag_reader.c -o mp3_tag_reader

# Run the program
./mp3_tag_reader

# Usage
View MP3 Tags ./mp3_tag_reader -v sample.mp3

Edit MP3 Tags ./mp3_tag_reader -e <-tag> sample.mp3

Then view the details we can see the changes ./mp3_tag_reader -v sample.mp3
Use -v to view ID3 tag information Use -e to edit ID3 tag information

# Notes
Follow the prompts to enter the MP3 file path and view its metadata.

This project already has a sample mp3 file named sample.mp3.
Here we are taking 1 additional mp3 file named temp.mp3 to make changes to the original data.
After editing, the temporary file is renamed to replace the original file.
It was done to make sure the original data won't be disturbed.
# Skills Learned
C programming: file handling, structures, and pointers
Reading and interpreting binary data (ID3v1 tags)
Console-based user interface design
Working with multimedia file formats
# Dependencies
GCC or any C compiler
# Screenshots
# Help
![image alt](https://github.com/kaavya221103/mp3-tag-reader-c/blob/193f149e3de913771b2a85f3cd3e2c8872304cbf/Screenshots/1mp3.jpg)
# View
![image alt](https://github.com/kaavya221103/mp3-tag-reader-c/blob/193f149e3de913771b2a85f3cd3e2c8872304cbf/Screenshots/2mp3.jpg)
# Editing
![image alt](https://github.com/kaavya221103/mp3-tag-reader-c/blob/193f149e3de913771b2a85f3cd3e2c8872304cbf/Screenshots/3.mp3.jpg)
# View after edit
![image alt](https://github.com/kaavya221103/mp3-tag-reader-c/blob/193f149e3de913771b2a85f3cd3e2c8872304cbf/Screenshots/4.mp3.jpg)
Project Structure
mp3-tag-reader-c/ │ ├─ sample.mp3 ├─ temp.mp3 ├─ images/ │ ├─ help.png │ ├─ view.png │ ├─ edit.png │ └─ v_after_edit.png ├─ README.md └─ .gitignore
