
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Harish Ramesh, worked with Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/, https://www.linkedin.com/in/sugata-sen/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
    
### Functionality implemented:
For part 9 we are using the APDS sensor data, and checking the colour packet sent, 
1. to the pio
2. to the ws2812 ( Neopixel LED )

We also noted the "C" channel value, as a suitable proxy for the ambient brightness level during the experiment. We conducted the experiment in both dark and bright room conditions, and adjusted the ADATA register to suitably small integration time, so the Neopixel closely tracks the colour and brightness that is sensed by APDS coour sensor, so that it reacts to both ambient "white"/Mixed colour stimuli, and monochromatic lights incident on APDS.


### Output
dark room :


https://user-images.githubusercontent.com/113575268/202831324-d4e10575-0716-43b0-b342-266ed0801e3c.mp4




bright room :


https://user-images.githubusercontent.com/113575268/202831330-67ec3a23-82b4-4242-a092-ac599e38f2ee.mp4




