Image Encription
================

## Description
It's a very specific staganography project 


## Specification

**Input Image Specification**
- Size: 128 x 128 px
- Color Depth: 24 bpp (bits per pixel)
- Type: BitMap (.bmp) Only

**Input Message Specification**
- File type: Text (.txt)
- Maximum size: 6 Kbyte

**Files and its uses**
- *Black.bmp:* This is Image file used as input image
- *sample.txt:* This is text file used as input message
- *merge.c:* This is C programe that merge text message into image and create a another image file namely 'black_enc.bmp'
- *saparate.c:* This is C programe that saparate message from encripted image file 'black_enc.bmp' and save that message into a new file namely 'sample_new.txt'

## Merge

**Follow command in terminal**

    gcc -c merge.c
    gcc -o merge merge.c
    ./merge

## Saparate

**Follow command in terminal**

    gcc -c saparate.c
    gcc -o saparate saparate.c
    ./saparate
