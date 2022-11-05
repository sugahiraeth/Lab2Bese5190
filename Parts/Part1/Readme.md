University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Harish Ramesh, worked with Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/, https://www.linkedin.com/in/sugata-sen/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
    
### Modifications implemented:
In order to simulate a register and use it to control the LED, we used a user defined 32-bit structure. Based on the value stored in that register, based on input from the boot button, which is mapped to pin 21 according to the pin diagram. Using this we trigger the ws2812 every time the boot button was pressed.

### Output
![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part1/lab1_op.gif)
