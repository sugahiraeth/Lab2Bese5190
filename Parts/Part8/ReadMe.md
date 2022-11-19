
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Harish Ramesh, worked with Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/, https://www.linkedin.com/in/sugata-sen/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
    
### Modifications implemented:
Used pico-examples example for i2c bus scan in PIO. We could not get the proximity sensor to give values of not, just a 230 or a 231 based on how close to the sensor the obstruction was. The color data was slightly erratic as we were in a well-lit room. Upon covering the sensor completely, we saw expected values of 0 for R,G,B and a standard value of C. Code used and output have been attached.

### Output





https://user-images.githubusercontent.com/38978733/202360094-717b55c3-5267-4b8b-9e0c-71e33ec1b061.mp4


