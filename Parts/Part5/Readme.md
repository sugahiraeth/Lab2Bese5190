University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Sugata Sen, worked with Harish Ramesh
    https://www.linkedin.com/in/sugata-sen/, https://www.linkedin.com/in/harishramesh1998/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10

## I2C communication oscilloscope traces and explanation:

1. We connect X to the SCL(yellow) and Y to the SDA(blue) cable, using the I2c daisy-chained connection out of the APDS sensor using jumpers
( This is a comvenient way to access the I2C without any need for breadboards, soldering or loose jumper contacts to the SDA,SCL, GND of board)

2. Firstly we tried using Analog probes( attached to X and Y channel on oscilloscope), with "Fine Analysis mode" of the oscilloscope, to zoom into and see the idle vs with-stimulus bit communications.

during Idle mode of operation, i.e. no stimulus to APDS gesture sensor:
![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/Idle_mode.png)

during the moment a stimulus is impressed upon the APDS gesture sensor:
![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/start_of_operation.png)


3. Next we used the Digital Analyser input of the oscilloscope to get clean waveforms without capacitive distortions, and can see the waveforms clearer. Here, D0 is connected to SCL, and D1 is connected to SDA, and GND to ground of I2C.

### During idle mode of operation :

i.zoomed out: 
![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/idle_digital_zout.png)

ii. zoomed in :

![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/idle_digital_zin.png)

### During stimulus:

i.zoomed out: 
![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/dig_data_zout.png)

ii. zoomed in :

![](https://github.com/sugahiraeth/Lab2Bese5190/blob/main/Parts/Part5/dig_data_zin.png)

