University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Harish Ramesh, worked with Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/, https://www.linkedin.com/in/sugata-sen/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
    
### Modifications implemented:
We used the code from part-03 as the base framework. Its description is:
In the embedded side of the code, we set up different functions to take inputs from the boot button and blink the Neopixel based on boot button inputs. Record data instantiates a very large array filled with zeroes and then based on pressing the boot button, the elements of the array are changed to 1s to switch the neopixel on and 0s when it remains off. The replay data function will replay data from the array we pass and blink the neopixel accordingly. The corresponding 1s and 0s will also be printed in the serial output. We use a python code this time around as a host for the sequencer on the board. The python code will either record or play data based on macro inputs it gets and the data is printed on a text file each time data is played. 
Required code has been uploaded too.

On top of that we implemented another function in our C file with delays in the playback. This function was activated with using s as a macro. Code has been uploaded.

### Output
https://user-images.githubusercontent.com/38978733/201554021-cbb9cb53-083c-4530-9da9-cb492a051ae2.mp4

